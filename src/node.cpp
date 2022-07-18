#include "node.h"

Node::Node(Email * _email){
    email = _email;
    esq = NULL;
    dir = NULL;
}