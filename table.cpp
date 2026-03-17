//
// Created by juanp on 16/03/2026.
//

#include "table.h"

void TABLE::extractDataFromFile(std::string fileName) {
    //Falta implementar
    ;
}

//==Getters==

std::vector<std::string>& TABLE::getProcessTag() {
    return processTag;
}

std::vector<int>& TABLE::getBurstTime() {
    return burstTime;
}

std::vector<int>& TABLE::getArrivalTime() {
    return arrivalTime;
}

std::vector<int>& TABLE::getQueue() {
    return queue;
}

std::vector<int>& TABLE::getPriority() {
    return priority;
}

std::vector<int>& TABLE::getResponseTime() {
    return responseTime;
}

std::vector<int>& TABLE::getCompletionTime() {
    return completionTime;
}

std::vector<int>& TABLE::getTAT() {
    return TAT;
}

std::vector<int>& TABLE::getWaitingTime() {
    return waitingTime;
}

std::vector<int>& TABLE::getRemainingTime() {
    return remainingTime;
}