#include "node.h"
class Tree
{
public:
Tree();
~Tree();
void insere(Email * item);
void caminha(int tipo);
Node *root;
void print();
void clear();
void apaga(int identifier);
Email * pesquisa(int u,int identifier);
private:
void insereRecursivo(Node* &p, Email * &item);
void Antecessor(Node *q, Node* &r);
void RemoveRecursivo(Node * &no, int chave);
void apagaRecursivob(Node * p, Email * & email);
void apagaRecursivo(Node* p);
void porNivel();
void preOrdem(Node* p);
void inOrdem(Node* p);
void posOrdem(Node* p);
};