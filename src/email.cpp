#include "email.h"
Email::Email(int _part,int _indentifier, std::string _message){
    identifier = _indentifier;
    part = _part;
    message = _message;
}
void Email::printEmail(){
    std::cout <<message<<std::endl;
}