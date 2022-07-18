#include "email.h"
Email::Email(int _indentifier, Player * _player, Message *_message){
    identifier = _indentifier;
    player = _player;
    message = _message;
}
void Email::printEmail(){
    message->printMessage();
}