#include "tree.h"
Tree::Tree(){
    root = NULL;
}
Tree::~Tree(){
    clear();
}
void Tree::insere(Email * email){
    insereRecursivo(root,email);
}

void Tree::apaga(Email * &email){
    Node * aux = root;
    while(aux!=NULL){
        if(aux->email==email){
            //rotaciona
            return;
        }
        if(email<aux->email){
            aux = aux->esq;
        }else{
            aux = aux->dir;
        }
    }
    std::cout<< "MENSAGEM INEXISTENTE"<<std::endl;
}
void Tree::insereRecursivo(Node* &p, Email * &item){
    if(p==NULL){
        p = new Node(item);
    }
    else{
        if(item < p->email)
            insereRecursivo(p->esq, item);
        else
            insereRecursivo(p->dir, item);
}
}