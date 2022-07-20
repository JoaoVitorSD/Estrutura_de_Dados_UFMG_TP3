#include "tree.h"
Tree::Tree(){
    root = NULL;
}
Tree::~Tree(){
    clear();
}
void Tree::clear(){
apagaRecursivo(root);
root = NULL;
}
void Tree::apagaRecursivo(Node *p){
if(p!=NULL){
apagaRecursivo(p->esq);
apagaRecursivo(p->dir);
delete p;
}
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
void Tree::Antecessor(Node *q, Node* &r){
    if(r->dir != NULL) {
        Antecessor(q, r->dir);
        return;
    }
    q->email->identifier = r->email->identifier;
    q = r;
    r = r->esq;
    free(q);
}
void Tree::RemoveRecursivo(Node* &no, int chave){
    Node *aux;
    if (no == NULL) {
        std::cout<<"ERRO: MENSAGEM INEXISTENTE"<<std::endl;
        return;
    }
    if (chave < no->email->identifier)
        return RemoveRecursivo(no->esq, chave);
    else if (chave>no->email->identifier)
        return RemoveRecursivo(no->dir, chave);
    else if(chave==no->email->identifier){
        std::cout<<"OK: MENSAGEM APAGADA"<<std::endl;
        if (no->dir == NULL) {
        aux = no;
        no = no->esq;
        free(aux);
}
    else if(no->esq == NULL) {
        aux = no;
        no = no->dir;
        free(aux);
}
    else{
        Antecessor(no, no->esq);
    }
}
}
void Tree::apaga(int identifier){
    RemoveRecursivo(root,identifier);
}
void Tree::insereRecursivo(Node* &p, Email * &item){
    if(p==NULL){
        p = new Node(item);
    }
    else{
        if(item ->identifier< p->email->identifier){
            insereRecursivo(p->esq, item);
        }
        else{
            insereRecursivo(p->dir, item);
        }
}
}
Email * Tree::pesquisa(int u,int identifier){
    Node * aux = root;
    while(aux!=NULL){
        if(aux->email->identifier==identifier&&aux->email->part==u){
            return aux->email;
        }
        if(identifier<aux->email->identifier){
            aux = aux->esq;
        }
        else{
            aux = aux->dir;
        }
    }
    return NULL;
}