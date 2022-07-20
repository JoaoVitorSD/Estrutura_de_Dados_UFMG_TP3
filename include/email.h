#include <iostream>
class Email{
    public:
    Email(){};
    Email(int part, int _indentifier, std::string _message);
    void printEmail();
    std::string  message;
    int identifier;
    int part;
    bool operator<(Email * &a){
        return identifier<a->identifier;
    }
    bool operator==(Email * &a){
        return identifier==a->identifier;
    }
};