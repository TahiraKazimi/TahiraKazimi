#include "AirlineReservationSystem.h"

void AirlineReservationSystem::addPassenger(const std::string &firstname, const std::string &lastname) {
    /* TODO */
    Passenger new_passenger(firstname,lastname);
    passengers.insert(new_passenger);
}

Passenger *AirlineReservationSystem::searchPassenger(const std::string &firstname, const std::string &lastname) {
    /* TODO */
    Passenger searched_passenger(firstname,lastname);
    BSTNode<Passenger>* result;
    result =  passengers.search(searched_passenger);
    if(result) return &(result->data);
    else return NULL;
}

void AirlineReservationSystem::addFlight(const std::string &flightCode, const std::string &departureTime, const std::string &arrivalTime, const std::string &departureCity, const std::string &arrivalCity, int economyCapacity, int businessCapacity) {
    /* TODO */
    Flight new_flight(flightCode,departureTime,arrivalTime,departureCity,arrivalCity,economyCapacity,businessCapacity);
    flights.insert(new_flight);
}
void AirlineReservationSystem:: inorderTraversalSearchFlight(BSTNode<Flight>*  r,const std::string &departureCity, const std::string &arrivalCity , std::vector<Flight *> &v){
    if(r==NULL) return;
    inorderTraversalSearchFlight(r->left,departureCity,arrivalCity,v);
    if(r->data.getDepartureCity()==departureCity && r->data.getArrivalCity()==arrivalCity) {
        v.push_back(&(r->data));
    }
    inorderTraversalSearchFlight(r->right,departureCity,arrivalCity,v);
    
}
std::vector<Flight *> AirlineReservationSystem::searchFlight(const std::string &departureCity, const std::string &arrivalCity) {
    /* TODO */
    std::vector<Flight*> v_result;
    inorderTraversalSearchFlight(flights.getRoot(),departureCity,arrivalCity,v_result);
    return v_result;
}
BSTNode<Flight>* AirlineReservationSystem:: searchFlightCode(BSTNode<Flight>* r, const std::string &flightCode){
    if(r==NULL) return NULL;
    if(r->data.getFlightCode()<flightCode) searchFlightCode(r->right,flightCode);
    else if(r->data.getFlightCode()>flightCode) searchFlightCode(r->left,flightCode);
    else return r;
}
void AirlineReservationSystem::issueTicket(const std::string &firstname, const std::string &lastname, const std::string &flightCode, TicketType ticketType) {
    /* TODO */
    Passenger* thePassenger = searchPassenger(firstname,lastname);
    BSTNode<Flight>* theflight = searchFlightCode(flights.getRoot(),flightCode);
    if(theflight&& thePassenger){
        Ticket new_ticket(thePassenger,&(theflight->data), ticketType);
        theflight->data.addTicket(new_ticket);
    } 
}

void AirlineReservationSystem::saveFreeTicketRequest(const std::string &firstname, const std::string &lastname, const std::string &flightCode, TicketType ticketType) {
    /* TODO */
    Passenger* find_passenger = searchPassenger(firstname,lastname);
    BSTNode<Flight>* free_flightnode = searchFlightCode(flights.getRoot(),flightCode);
    if(find_passenger && free_flightnode){
        Ticket new_free_ticket(find_passenger,&(free_flightnode->data), ticketType);
        freeTicketRequests.enqueue(new_free_ticket);
    }
}

void AirlineReservationSystem::executeTheFlight(const std::string &flightCode) {
    /* TODO */
    Queue<Ticket> temp;bool emptyPlace = true; BSTNode<Flight>* flight = searchFlightCode(flights.getRoot(),flightCode);

    while(!freeTicketRequests.isEmpty() && flight){
        Flight* free_flight = (freeTicketRequests.peek().getFlight());
        if(free_flight->getFlightCode()==flightCode && emptyPlace){
            emptyPlace = flight->data.addTicket(freeTicketRequests.peek());
            if(!emptyPlace) temp.enqueue(freeTicketRequests.dequeue());
            else freeTicketRequests.dequeue();
        }
        else{
            temp.enqueue(freeTicketRequests.dequeue());
        }
    }
    while(!temp.isEmpty()) freeTicketRequests.enqueue(temp.dequeue());
    if(flight) flight->data.setCompleted(true);

}

void AirlineReservationSystem::print() const {
    std::cout << "# Printing the airline reservation system ..." << std::endl;

    std::cout << "# Passengers:" << std::endl;
    passengers.print(inorder);

    std::cout << "# Flights:" << std::endl;
    flights.print(inorder);

    std::cout << "# Free ticket requests:" << std::endl;
    freeTicketRequests.print();

    std::cout << "# Printing is done." << std::endl;
}
