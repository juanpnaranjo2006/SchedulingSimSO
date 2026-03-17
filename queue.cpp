//
// Created by juanp on 16/03/2026.
//

#include "queue.h"
//==Constructor==
QUEUE::QUEUE(int algID, int quantum) {
    this->algID = algID;
    this->quantum = quantum;
}

//==Getters==
int QUEUE::get_algID() const {
    return algID;
}

int QUEUE::get_quantum() const {
    return quantum;
}

//==Setters==
void QUEUE::set_algID(const int value) {
    algID = value;
}

void QUEUE::set_algID(const std::string &value) {
    //Falta implementar;
}

void QUEUE::set_quantum(const int value) {
    quantum = value;
}