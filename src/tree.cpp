#include "tree.h"
Tree::Tree(){
    root = NULL;
}
Tree::~Tree(){
    // clear();
}
void Tree::print(){
    inOrdem(root);
}
void Tree::inOrdem(Node *p){
if(p!=NULL){
    inOrdem(p->esq);
    std::cout<<p->email->identifier<<std::endl;
    inOrdem(p->dir);
}
}
void Tree::insere(Email * email){
    insereRecursivo(root,email);
}
Node* minValueNode(Node* node)
{
    Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->esq != NULL)
        current = current->esq;
 
    return current;
}
Node* deleteNode(Node* aux, int key)
{
    // base case
    if (aux == NULL)
        return aux;
 
    // If the key to be deleted is
    // smaller than the aux's
    // key, then it lies in esq subtree
    if (key < aux->email->identifier)
        aux->esq = deleteNode(aux->esq, key);
 
    // If the key to be deleted is
    // greater than the aux's
    // key, then it lies in dir subtree
    else if (key > aux->email->identifier)
        aux->dir = deleteNode(aux->dir, key);
 
    // if key is same as aux's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (aux->esq==NULL and aux->dir==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (aux->esq == NULL) {
            Node* temp = aux->dir;
            free(aux);
            return temp;
        }
        else if (aux->dir == NULL) {
            Node* temp = aux->esq;
            free(aux);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the dir subtree)
        Node* temp = minValueNode(aux->dir);
 
        // Copy the inorder successor's content to this node
        aux->email = temp->email;
 
        // Delete the inorder successor
        aux->dir = deleteNode(aux->dir, temp->email->identifier);
    }
    return aux;
}
void Tree::apaga(int identifier){
    deleteNode(root,identifier);
}
void Tree::insereRecursivo(Node* &p, Email * &item){
    if(p==NULL){
        p = new Node(item);
    }
    else{
        if(item ->identifier< p->email->identifier)
            insereRecursivo(p->esq, item);
        else
            insereRecursivo(p->dir, item);
}
}