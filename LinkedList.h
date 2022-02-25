#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

template<class T>
class LinkedList {
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T> &obj);

    ~LinkedList();

    int getSize() const;
    bool isEmpty() const;
    bool contains(Node<T> *node) const;

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void insertAtTheFront(const T &data);
    void insertAtTheEnd(const T &data);
    void insertAfterNode(const T &data, Node<T> *node);
    void insertAsEveryKthNode(const T &data, int k);

    void removeNode(Node<T> *node);
    void removeNode(const T &data);
    void removeAllNodes();
    void removeEveryKthNode(int k);

    void swap(Node<T> *node1, Node<T> *node2);
    void shuffle(int seed);

    void print(bool reverse=false) const;

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;

    int size;
};

template<class T>
LinkedList<T>::LinkedList() {
    /* TODO */
    head = NULL; size= 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj) {
    /* TODO */
    head = NULL; size = 0;
    *this = obj;

}

template<class T>
LinkedList<T>::~LinkedList() {
    /* TODO */
    removeAllNodes();
}

template<class T>
int LinkedList<T>::getSize() const {
    /* TODO */
    return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const {
    /* TODO */
    return size==0;
}

template<class T>
bool LinkedList<T>::contains(Node<T> *node) const {
    /* TODO */
    Node<T>* current = head;
    if(current==NULL&& node!=NULL){
        return false;
    }
    else if(current != NULL && node==NULL){
        return false;
    }
    else if(current!=NULL && node!=NULL){
        while(current->next!=head){
            if(node->next == current->next && node->prev== current->prev){
                return true;
            }
            current = current->next;
        }
        if(current->prev==node->prev&&current->data==node->data){
            return true;
        }
        return false;
    }
    return false;
}

template<class T>
Node<T> *LinkedList<T>::getFirstNode() const {
    /* TODO */
    return head;
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const {
    /* TODO */
    if(head==NULL){
        return NULL;
    }
    else{
        return head->prev;
    }
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const {
    /* TODO */
    int i=0;
    Node<T>* target = head;
    if(head==NULL){
        return NULL;
    }
    while(i<size){
        if(target->data==data){
            return target;
        }
        target = target->next;
        i++;
    }
    return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const {
    /* TODO */
    int i = 0; Node<T>* current = head;
    if(index>=size || index<0){
        return NULL;
    }
    while(i!=index){
        current = current->next;
        i++;
    }
    return current;
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data) {
    /* TODO */
    if(head==NULL){
        Node<T>* new_node = new Node<T>(data);
        new_node->next = new_node;
        new_node->prev = new_node;
        head = new_node;
    }
    else{
    Node<T>* new_node = new Node<T>(data,head->prev,head);
    head->prev->next = new_node;
    head->prev = new_node;
    head = new_node;
    }
    size++;
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data) {
    /* TODO */
    if(head==NULL){
        Node<T>* new_node = new Node<T>(data);
        new_node->next = new_node;
        new_node->prev = new_node;
        head = new_node;
    }
    else{
    Node<T>* new_node = new Node<T>(data, head->prev, head);
    head->prev->next = new_node;
    head->prev = new_node;
    }
    size++;
}

template<class T>
void LinkedList<T>::insertAfterNode(const T &data, Node<T> *node) {
    /* TODO */
    if(contains(node)){
    if(node->next == head){
        insertAtTheEnd(data);
    }
    else{
    Node<T>* new_node = new Node<T>(data,node, node->next);
    node->next->prev = new_node;
    node->next = new_node;
    size++;
    }
    }
   

}

template<class T>
void LinkedList<T>::insertAsEveryKthNode(const T &data, int k) {
    /* TODO */
    if(k>=2){
        int i,j,times;
        Node<T>* current = head;
        times = size/(k-1);
        for(i=1;i<=times;i++){
            j = 1;
            while(j!=k-1){
                current = current->next; j++;
            }
            insertAfterNode(data, current);
            current = current->next->next;
        }
    }

}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node) {
    /* TODO */
    if(head){
    if(contains(node)){
    Node<T>* current = head;
        while(current!=node){
        current = current->next;
    }
    if(current==head && size ==1 ){
        delete head;
        head = NULL;
    }
    else if(current==head){
        current->prev->next = current->next;
        current->next->prev = current->prev;
        head = current->next;
        current->next = NULL; 
        current->prev = NULL;
        delete current;
    }
    else{
    current->prev->next = current->next;
    current->next->prev=  current->prev;
    current->next = NULL; current->prev = NULL;
    delete current;
    }
    size--;
    }
    }
}

template<class T>
void LinkedList<T>::removeNode(const T &data) {
    /* TODO */
    int i =0;
    Node<T>* current = head;
    while(i<size){
        if(current->data == data){
            current = current->next;
            removeNode(current->prev);
        }
        else{
            current = current->next;
        }
        i++;
    }
}

template<class T>
void LinkedList<T>::removeAllNodes() {
    /* TODO */
    while(size!=0){
        removeNode(head);
    }

}

template<class T>
void LinkedList<T>::removeEveryKthNode(int k) {
    /* TODO */
    if(k>=2){
    Node<T>* current = head;
    int i, times , j;
    times = size/(k);
    for(i=1;i<=times;i++){
        j = 1;
        while(j!=k){
            current = current->next; j++;        
        }
        current = current->next;
        removeNode(current->prev);
    }
    }
}

template<class T>
void LinkedList<T>::swap(Node<T> *node1, Node<T> *node2) {
    /* TODO */
    if(node1!=node2){
    if(contains(node1)&& contains(node2)){
        if(size==2){
            head = head->prev;
        }
    else if(size>2){
        Node<T>* temp_next, *temp_prev, *temp_next2, *temp_prev2;
        temp_next = node1->next; temp_prev = node1->prev;
        temp_next2 = node2->next; temp_prev2 = node2->prev;
        if(node2==head && node1->next==head){     //head and tail swap
            node2->next = node1; node2->prev = node1->prev;
            node1->next = temp_next2; node1->prev = node2;
            temp_next2->prev = node1; temp_prev->next = node2;
            head = node1;
        }
        else if(node1==head && node2->next == head){   //head and tail swap
            node1->next = node2; node1->prev = node2->prev;
            node2->next = temp_next; node2->prev = node1;
            temp_next->prev = node2; temp_prev2->next = node1;
            head = node2;
        }
        else if(node1->next == node2){ //adjacent nodes swap
            node1->next = node2->next; node2->next->prev = node1;
            node1->prev = node2; temp_prev->next = node2; node2->prev = temp_prev;
            node2->next = node1;
            if(node1==head){
                head = node2;
            }
        }
        else if(node2->next==node1){ //adjacent nodes swap
          node2->next = node1->next; node1->next->prev = node2;
            node2->prev = node1; temp_prev2->next = node1; node1->prev = temp_prev2;
            node1->next = node2;
            if(node2==head){
                head = node1;
            }  
        }
        else if(node1==head){  //head and middle node swap
        node1->next = temp_next2; node1->prev = temp_prev2;
        node2->next = temp_next; node2->prev = temp_prev;
        temp_next->prev = node2; temp_prev->next = node2;
        temp_next2->prev = node1; temp_prev2->next = node1;
        head = node2;
        }
        else if(node2==head){ // head and middle node swap
        node1->next = temp_next2; node1->prev = temp_prev2;
        node2->next = temp_next; node2->prev = temp_prev;
        temp_next->prev = node2; temp_prev->next = node2;
        temp_next2->prev = node1; temp_prev2->next = node1;
        head = node1;
        }
        else{
        node1->next = temp_next2; node1->prev = temp_prev2;
        node2->next = temp_next; node2->prev = temp_prev;
        temp_next->prev = node2; temp_prev->next = node2;
        temp_next2->prev = node1; temp_prev2->next = node1;
        }
        }
        }
    }
}

template<class T>
void LinkedList<T>::shuffle(int seed) {
    /* TODO */
    int i,ind; Node<T>* node1, *node2;
    for(i=0;i<size;i++){
        ind = (i*i+seed)%size;
        node1 = getNodeAtIndex(i);
        node2 = getNodeAtIndex(ind);
        swap(node1,node2);
    }
}

template<class T>
void LinkedList<T>::print(bool reverse) const {
    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    if (reverse) {
        // traverse in reverse order (last node to first node).

        Node<T> *node = this->getLastNode();

        do {
            std::cout << *node << std::endl;
            node = node->prev;
        }
        while (node != this->getLastNode());
    } else {
        // traverse in normal order (first node to last node).

        Node<T> *node = this->getFirstNode();

        do {
            std::cout << *node << std::endl;
            node = node->next;
        }
        while (node != this->getFirstNode());
    }
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    /* TODO */
    int i=0;
    int s;
    removeAllNodes();
    const Node<T>* current = rhs.getFirstNode();
    s = rhs.getSize();
    while(i<s){
        insertAtTheEnd(current->data);
        current = current->next;
        i++;
    }
return *this;
}

#endif //LINKEDLIST_H
