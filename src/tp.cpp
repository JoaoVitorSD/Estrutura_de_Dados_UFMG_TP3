#include <iostream>
#include "tree.h"
int main(){
    Tree * tree = new Tree();
    tree->insere(new Email(10,new Player("joao"),  new Message("text")));
    tree->insere(new Email(9,new Player("riverton"),  new Message("riverton")));
    tree->insere(new Email(5,new Player("ludmila"),  new Message("ludmila")));
    tree->insere(new Email(16,new Player("vitor"),  new Message("vitor")));
    tree->insere(new Email(12,new Player("bruno"),  new Message("bruno")));
    tree->insere(new Email(18,new Player("joaozinho"),  new Message("joaozinho")));
    tree->apaga(12);
    tree->print();
    return 0;
}