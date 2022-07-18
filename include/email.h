#include "message.h"
#include "player.h"

class Email{
    public:
    Email(int _indentifier, Player * _player, Message *_message);
    void printEmail();
    Player * player;
    Message * message;
    int identifier;
    bool operator<(Email * &a){
        return identifier<a->identifier;
    }
};