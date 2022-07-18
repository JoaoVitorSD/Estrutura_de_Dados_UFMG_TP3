#include "message.h"

Message::Message(std::string _text){
    text = _text;
}
void Message::printMessage(){
    std::cout <<text;
}