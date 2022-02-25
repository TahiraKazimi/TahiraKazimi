#ifndef BST_H
#define BST_H

#include <iostream>

#include "BSTNode.h"

enum TraversalPlan {preorder, inorder, postorder};

template<class T>
class BST {
public: // DO NOT CHANGE THIS PART.
    BST();
    BST(const BST<T> &obj);

    ~BST();

    BSTNode<T> *getRoot() const;
    bool isEmpty() const;
    bool contains(BSTNode<T> *node) const;

    void insert(const T &data);

    void remove(const T &data);
    void removeAllNodes();

    BSTNode<T> *search(const T &data) const;
    BSTNode<T> *getSuccessor(BSTNode<T> *node, TraversalPlan tp) const;

    void print(TraversalPlan tp=inorder) const;

    BST<T> &operator=(const BST<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
    void print(BSTNode<T> *node, TraversalPlan tp) const;
    void insert_helper(BSTNode<T>* &r, const T& data);
    void remove_helper(BSTNode<T>* &root, const T& data );
    BSTNode<T>* findMin(BSTNode<T>* &root) const;
    BSTNode<T>* find(BSTNode<T>* r, const T& data) const;
    void assignment_helper(const BSTNode<T>* r2);
    bool contains(BSTNode<T>* r, BSTNode<T>* node) const;
    BSTNode<T>* postorderLeftMost(BSTNode<T>* r) const;

private: // DO NOT CHANGE THIS PART.
    BSTNode<T> *root;
};

#endif //BST_H

template<class T>
BST<T>::BST() {
    /* TODO */
    root = NULL;
}

template<class T>
BST<T>::BST(const BST<T> &obj) {
    /* TODO */
    root = NULL;
    *this = obj;
}

template<class T>
BST<T>::~BST() {
    /* TODO */
    removeAllNodes();
}

template<class T>
BSTNode<T> *BST<T>::getRoot() const {
    /* TODO */
    return root;
}

template<class T>
bool BST<T>::isEmpty() const {
    /* TODO */
    return (root==NULL);
}
template<class T>
bool BST<T>::contains(BSTNode<T>* r, BSTNode<T>* node) const{
if(r == NULL){
        return false;
    }
if(r== node && node->left == r->left && node->right == r->right){
        return true;
    }
else{
        return contains(r->left, node)||contains(r->right,node);
}
}
template<class T>
bool BST<T>::contains(BSTNode<T> *node) const {
    /* TODO */
    return contains(root,node);
    
}
template<class T>
void BST<T>::insert_helper(BSTNode<T>* &r, const T& data){
    if(r==NULL){
        r = new BSTNode<T>(data,NULL,NULL);
    }
    else{
        if(r->data>data){
            insert_helper(r->left,data);
        }
        else if(r->data<data){
            insert_helper(r->right, data);
        }
        else
        ;
    }
}
template<class T>
void BST<T>::insert(const T &data) {
    /* TODO */
    insert_helper(root,data);
}
template<class T>
BSTNode<T>* BST<T>::findMin(BSTNode<T>* &root) const{
    if(root==NULL){
        return NULL;
    }
    else if(root->left==NULL){
        return root;
    }
    else{
        return findMin(root->left);
    }
}

template<class T>
void BST<T>::remove_helper(BSTNode<T>* &root, const T& data){
    if(root==NULL){
        return;
    }
   if(root->data<data){
       remove_helper(root->right, data);
   }
   else if(root->data>data){
       remove_helper(root->left,data);
   }
   else{
       if(root->left!=NULL && root->right!=NULL){
           BSTNode<T>* min_node = findMin(root->right);
           root->data = min_node->data;
           remove_helper(root->right,root->data);
       }
       else{
           BSTNode<T>* old_node = root;
           if(root->left!=NULL){
               root = root->left;
           }
           else{
               root = root->right;
           }
           delete old_node;
       }
   }
}
template<class T>
void BST<T>::remove(const T &data) {
    /* TODO */
    remove_helper(root, data);
}

template<class T>
void BST<T>::removeAllNodes() {
    /* TODO */
    while(!isEmpty()){
        remove(root->data);
    }
}
template<class T>
BSTNode<T>* BST<T>::find(BSTNode<T>* r, const T& data) const{
    if(r==NULL){
        return NULL;
    }
    else if(r->data>data){
        return find(r->left, data);
    }
    else if(r->data<data){
        return find(r->right,data);
    }
    else{
        return r;
    }
}
template<class T>
BSTNode<T> *BST<T>::search(const T &data) const {
    /* TODO */
    return find(root,data);
}
template<class T>
BSTNode<T>* BST<T>::postorderLeftMost(BSTNode<T>* r) const{
    if(r==NULL) return NULL;
    if(r->left==NULL && r->right==NULL) return r;
    if(r->left!=NULL) return postorderLeftMost(r->left);
    if(r->left==NULL) return postorderLeftMost(r->right); 
}
template<class T>
BSTNode<T> *BST<T>::getSuccessor(BSTNode<T> *node, TraversalPlan tp) const {
    BSTNode<T>* successor;
    if (tp == inorder) {

        if(node->right!=NULL){
            successor = findMin(node->right);
            return successor;
        }
        else{
            BSTNode<T>* parent = root;
            successor = NULL;
            while(node->data!=parent->data){
                if(node->data<parent->data){
                    successor = parent;
                    parent = parent->left;
                }
                else{
                    parent = parent->right;
                }
            }
            return successor;
        }
    } else if (tp == preorder) {

        successor = NULL; BSTNode<T>* candid_parent = NULL;
        BSTNode<T>* current = root;
        if(node->left) {
            successor = node->left;
        }
        else if(node->right) {
            successor = node->right;
        }
        else{
            while(current->data!=node->data){
            if(current->data>node->data){
                if(current->right){
                    successor = current->right;
                }
                current = current->left;
            }
            else{
                current = current->right;
            }
        } 
        return successor;
        }
    } 
        else if (tp == postorder) {
        
      successor = NULL;
      BSTNode<T>* ancestor=NULL; BSTNode<T>* temp = root; //finding the parent
      while(temp->data!=node->data){
          if(temp->data>node->data){
              ancestor = temp;
              temp = temp->left;
          }
          else{
              ancestor= temp;
              temp = temp->right;
          }
      }
      if(!ancestor) ; //root
      else if(ancestor->right == node){ //if right child, get the parent
          successor = ancestor;
      }
      else if(ancestor->left == node){ //if node is the left child
          if(ancestor->right==NULL) successor = ancestor; //if it has no right sibling
          else{ //if there is a right sibling
            successor = postorderLeftMost(ancestor->right); //find the left most leaf 
          }
      }
      return successor;
    }
    return successor;
}

template<class T>
void BST<T>::print(TraversalPlan tp) const {

    if (tp == inorder) {
        // check if the tree is empty?
        if (isEmpty()) {
            // the tree is empty.
            std::cout << "BST_inorder{}" << std::endl;
            return;
        }

        // the tree is not empty.

        // recursively output the tree.
        std::cout << "BST_inorder{" << std::endl;
        print(root, inorder);
        std::cout << std::endl << "}" << std::endl;
    } else if (tp == preorder) {
        /* TODO */
        if (isEmpty()) {
            // the tree is empty.
            std::cout << "BST_preorder{}" << std::endl;
            return;
        }
        std::cout<<"BST_preorder{" << std::endl;
        print(root,preorder);
        std::cout<<std::endl<<"}"<<std::endl;
    } else if (tp == postorder) {
        if (isEmpty()) {
            // the tree is empty.
            std::cout << "BST_postorder{}" << std::endl;
            return;
        }
        std::cout<<"BST_postorder{" << std::endl;
        print(root,postorder);
        std::cout<<std::endl<<"}"<<std::endl;
        /* TODO */
    }
}
template<class T>
void BST<T>::assignment_helper(const BSTNode<T>* r2){
    if(r2==NULL) return;
    insert_helper(root, r2->data);
    assignment_helper(r2->left);
    assignment_helper(r2->right);
}
template<class T>
BST<T> &BST<T>::operator=(const BST<T> &rhs) {
    /* TODO */
    if(this!=&rhs){
    this->removeAllNodes();
    this->assignment_helper(rhs.root);
    }
    return *this;

}

template<class T>
void BST<T>::print(BSTNode<T> *node, TraversalPlan tp) const {

    // check if the node is NULL?
    if (node == NULL)
        return;

    if (tp == inorder) {
        // first, output left subtree and comma (if needed).
        print(node->left, inorder);
        if (node->left) {
            std::cout << "," << std::endl;
        }

        // then, output the node.
        std::cout << "\t" << node->data;

        // finally, output comma (if needed) and the right subtree.
        if (node->right) {
            std::cout << "," << std::endl;
        }
        print(node->right, inorder);
    } else if (tp == preorder) {
        /* TODO */
        std::cout<<"\t"<<node->data;
        if(node->left){
            std::cout<<","<<std::endl;
        }
        print(node->left,preorder);
        if(node->right){
            std::cout<<","<<std::endl;
        }
        print(node->right,preorder);

    } else if (tp == postorder) {
        /* TODO */
        print(node->left,postorder);
        if(node->left){
            std::cout<<","<<std::endl;
        }
        print(node->right,postorder);
        if(node->right){
            std::cout<<","<<std::endl;
        }
        std::cout<<"\t"<<node->data;
    }
}
