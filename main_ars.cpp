#include <iostream>

#include "AirlineReservationSystem.cpp"
#include "Passenger.cpp"
#include "Flight.cpp"
#include "Ticket.cpp"

int main() {
    AirlineReservationSystem ars;

    ars.print();

    ars.addPassenger("jack", "sophia");
    ars.addPassenger("archie", "rosie");
    ars.addPassenger("harry", "isabella");
    ars.addPassenger("oscar", "lily");
    ars.addPassenger("leo", "ivy");
    ars.addPassenger("kate", "sophia");
    ars.addPassenger("brendon","urie");
    ars.addFlight("QR577LA","7:15","10:15","NYC","LA",40,15);
    ars.addFlight("999","8:50","12:00","London","Istanbul",12,4);
    ars.addFlight("QR577L","7:15","10:15","NYC","LA",30,15);
    std::vector<Flight*> v = ars.searchFlight("NYC","LA");
    if(v.size()!=0) std::cout<<*(v[0])<<std::endl;
    std::cout<<*(v[1])<<std::endl;
    ars.issueTicket("jack","sophia","QR577LA",economy);
    ars.issueTicket("archie","rosie","QR577LA",economy);
    ars.issueTicket("harry","isabella","QR577LA",economy);
    Passenger * one_passenger = ars.searchPassenger("brendon", "urie");
    std::cout<<*one_passenger<<std::endl;
    ars.saveFreeTicketRequest("leo","ivy","999",business);
    ars.saveFreeTicketRequest("beyonce","ivy","999",business);
    ars.saveFreeTicketRequest("brendon","urie","QR577LA",business);
    ars.executeTheFlight("QR577LA");

    ars.print();

    return 0;
}
