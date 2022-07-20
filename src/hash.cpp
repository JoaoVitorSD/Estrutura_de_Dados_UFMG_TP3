#include "hash.h"
Hash_LE::Hash_LE(int _size){
    Tabela = new Tree*[_size];
    for(int i=0; i<_size; i++){
        Tabela[i]= new Tree();
    }
    size = _size;
}
Hash_LE::~Hash_LE(){
    for(int i = 0;i<size;i++){
        Tabela[i]->clear();
        free(Tabela[i]);
    }
}
Email *Hash_LE::Pesquisa(int u,int chave){
    int pos;
    Email * item;
    pos = Hash(u);
    item = Tabela[pos]->pesquisa(u,chave);
    return item;
}
void Hash_LE::Verify(int u,int chave){
    Email * aux = Pesquisa(u,chave);
    if(aux!=NULL){
        std::cout<<"CONSULTA "<<u<< " "<<chave<<": "<<aux->message<<std::endl;
    }else{
        std::cout<<"CONSULTA "<<u<< " "<<chave<<": MENSAGEM INEXISTENTE"<<std::endl;
    }
}
void Hash_LE::Insere(int u,Email *item){
    Email * aux;
    int pos;
    aux = Pesquisa(u,item->identifier);
    if(!aux==NULL)
        throw("Erro: Item já está presente");
    pos = Hash(u);
    Tabela[pos]->insere(item);
    std::cout <<"OK: MENSAGEM "<<item->identifier <<" PARA "<<u<<" ARMAZENADA EM "<< pos<<std::endl;
}
void Hash_LE::Remove(int u,int chave){
    int pos;
    pos = Hash(u);
    Tabela[pos]->apaga(chave);
}