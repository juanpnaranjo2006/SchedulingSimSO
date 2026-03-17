//
// Created by juanp on 16/03/2026.
//

#include "queue.h"

//==Constructor==
QUEUE::QUEUE(const bool isPreemptive, const bool order, const int algID, const int quantum) {
    this->isPreemptive = isPreemptive;
    this->order = order;
    this->algID = algID;
    this->quantum = quantum;
    asociatedProcesses.clear();
}

//==Métodos Principales==
void QUEUE::addProcess(int processID) {
    asociatedProcesses.emplace(processID);
}

void QUEUE::removeProcess(int processID) {
    if (asociatedProcesses.contains(processID)) {
        asociatedProcesses.erase(processID);
    }
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