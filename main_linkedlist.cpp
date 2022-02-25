#include <iostream>

#include "LinkedList.h"
using namespace std;
int main() {
    LinkedList<int> llist;

    llist.print();

    llist.insertAtTheEnd(3);
    llist.insertAtTheFront(2);
    llist.insertAfterNode(1, llist.getNode(2));
    LinkedList<int> list_copy(llist);
    //list_copy.insertAtTheFront(9);
    list_copy.print();
    //list_copy.print();
    cout<<"******"<< endl;
    llist.insertAtTheEnd(15);
    llist.insertAtTheFront(7);
    //llist.swap(llist.getNode(15), llist.getNode(7));
    llist.insertAtTheEnd(31);
    llist.insertAtTheFront(13);
    llist.print();
    cout<<"size : "<<llist.getSize()<<endl;
    cout<<"******"<< endl;
    //llist.swap(node_1, llist.getNode(3));
    //llist.swap(llist.getNode(31),llist.getNode(13));
    llist.print();
    int seed = 2; int i=0; int size = llist.getSize();int ind;
    Node<int>* node_2; Node<int>* node_1;
       /* node_1 = llist.getNodeAtIndex(0);
        node_2 = llist.getNodeAtIndex(2);
        llist.swap(node_1,node_2);
        node_1 = llist.getNodeAtIndex(1);
        node_2 = llist.getNodeAtIndex(3);
        llist.swap(node_1,node_2);
        node_1 = llist.getNodeAtIndex(2);
        node_2 = llist.getNodeAtIndex(6);
        llist.swap(node_1,node_2);
        node_1 = llist.getNodeAtIndex(3);
        node_2 = llist.getNodeAtIndex(4);
        llist.swap(node_1,node_2);
        node_1 = llist.getNodeAtIndex(4);
        node_2 = llist.getNodeAtIndex(4);
        llist.swap(node_1,node_2);
        node_1 = llist.getNodeAtIndex(5);
        node_2 = llist.getNodeAtIndex(6);
        llist.swap(node_1,node_2);
        node_1 = llist.getNodeAtIndex(6);
        node_2 = llist.getNodeAtIndex(3);
        llist.swap(node_1,node_2);*/
     /*for(i=0;i<size;i++){
        ind = (i*i+seed)%size;
        node_1 = llist.getNodeAtIndex(i);
        node_2 = llist.getNodeAtIndex(ind);
        llist.swap(node_1,node_2);
    }*/
    //llist.shuffle(3);
    cout<<"******"<< endl;
    llist.insertAsEveryKthNode(55,2);
    llist.print();
    //cout<<"******"<< endl;
    //llist.print();
    /*llist.removeAllNodes();
    Node<int>* head = llist.getFirstNode();
    if(!head) cout<<"head NULL"<< endl;
    llist.print();*/

    return 0;
}
