//
// Created by juanp on 16/03/2026.
//

#include "scheduler.h"

//==Getters==

std::vector<QUEUE>& SCHEDULER::getMLQ() {
    return MLQ;
}

TABLE& SCHEDULER::getTable() {
    return dataTable;
}