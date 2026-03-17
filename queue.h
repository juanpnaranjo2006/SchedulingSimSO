//
// Created by juanp on 16/03/2026.
//
#ifndef SCHEDULINGSIMSO_QUEUE_H
#define SCHEDULINGSIMSO_QUEUE_H

#include <string>
#include <queue>
#include <set>

//Representa una cola con un algoritmo particular
class QUEUE {
private:
    bool isPreemptive;
    bool order; //False = desc, True = asc
    int algID;
    int quantum;
    std::set<int> asociatedProcesses;
public:
    QUEUE(bool isPreemptive, bool order, int algID, int quantum);

    //==Métodos Principales==
    void addProcess(int processID);
    void removeProcess(int processID);

    //==Getters==
    int get_algID() const;
    int get_quantum() const;

    //==Setters==
    void set_algID(int value);
    void set_algID(const std::string &value);
    void set_quantum(int value);
};


#endif //SCHEDULINGSIMSO_QUEUE_H