#include "node.h"
class Tree
{
public:
Tree();
~Tree();
void insere(Email * item);
void caminha(int tipo);
void clear();
private:
void insereRecursivo(Node* &p, Email * &item);
void apaga(Email * &item);
void apagaRecursivo(Node* p);
void porNivel();
void preOrdem(Node* p);
void inOrdem(Node* p);
void posOrdem(Node* p);
Node *root;
};