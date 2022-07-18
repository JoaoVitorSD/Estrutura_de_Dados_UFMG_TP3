#include "email.h"
class Node{
    public:
    Node(Email * email);
    Node * esq;
    Node * dir;
    Email * email;
};