#include <iostream>
#include "cell.h"
int main(){
    Cell * cell1 = new Cell( new Player("joao"), Message("text"));
    Cell * cell2 = new Cell( new Player("riverton"), Message("salve"));
    cell1->next = cell2;
    cell1->next->message.printMessage();
    return 0;
}