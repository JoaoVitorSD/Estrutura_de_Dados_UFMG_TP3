#include <iostream>
class Message{
    public:
    Message(){};
    Message(std::string _text);
    void printMessage();
    std::string text;
};