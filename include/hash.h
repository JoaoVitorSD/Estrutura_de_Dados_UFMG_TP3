#include "tree.h"
class Hash_LE
{
    public:
    Hash_LE(int size);
    ~Hash_LE();
    Email* Pesquisa(int u,int chave);
    void Verify(int u,int chave);
    void Insere(int u,Email * item);
    void Remove(int u, int chave);
    int size;
    int Hash(int chave){
        return chave%size;
    };
    Tree ** Tabela;
};