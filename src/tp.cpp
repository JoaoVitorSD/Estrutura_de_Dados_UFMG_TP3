#include "hash.h"
#include <fstream>
int main(int argc, char *argv[]){
    if(argc<3){
        throw "ARGUMENTOS INSUFICIENTES";
    }
    std::ifstream  f;
    f.open(argv[2]);
    int trees;
    f>>trees;
    Hash_LE * hash = new Hash_LE(trees);
    std::string aux;
    int identDest;
    int words;
    int identEmail;
    std::string email;
    std::string word;
    while(f>>aux){
        email="";
        if(aux=="ENTREGA"){
            f>>identDest;
            f>>identEmail;
            f>>words;
            for(int i =0;i<words;i++){
                f>>word;
                if(i>0){
                email.append(" "+word);
                }else{
                email.append(word);
                }
            }
            hash->Insere(identDest, new Email(identDest,identEmail,email));
        }else if(aux == "CONSULTA"){
            f>>identDest;
            f>>identEmail;
            hash->Verify(identDest,identEmail);
        }else if(aux=="APAGA"){
            f>>identDest;
            f>>identEmail;
            hash->Remove(identDest,identEmail);
        }
    }
    f.close();
    return 0;
}