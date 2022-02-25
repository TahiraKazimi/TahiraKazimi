#include <iostream>

#include "BST.h"
using namespace std;

int main() {
    BST<int> tree;

    tree.print(inorder);
    tree.print(preorder);
    tree.print(postorder);

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(7);
    tree.insert(6);
    tree.insert(13);
    tree.insert(14);
    tree.insert(17);
    //tree.insert(9);
    tree.insert(11);

    tree.print(inorder);
    tree.print(preorder);
    tree.print(postorder);
    cout<<"is tree empty? "<< tree.isEmpty()<<endl;
    BSTNode<int>* root = tree.getRoot();
    cout<<"does it contain the node? "<< tree.contains(root->left->right->left)<< endl;
    BSTNode<int>* node = tree.search(10);
    cout<<"the node has the value: "<< node->data<<endl;
    /*node = tree.getSuccessor(node,preorder);
    if(node) cout<<"preorder node successor is: "<<node->data<<endl;
    else cout<< "No successor"<<endl;*/
    node = tree.getSuccessor(node,postorder);
    if(node) cout<<"postorder node successor is: "<<node->data<<endl;
    else cout<< "No successor"<<endl;
    return 0;
}
