//
// Created by juanp on 16/03/2026.
//
#ifndef SCHEDULINGSIMSO_QUEUE_H
#define SCHEDULINGSIMSO_QUEUE_H

#include <string>

//Representa una cola con un algoritmo particular
class QUEUE {
private:
    bool order; //0 = desc, 1 = asc
    int algID;
    int quantum;
public:
    QUEUE() = default;
    QUEUE(int algID, int quantum);

    //==Getters==
    int get_algID() const;
    int get_quantum() const;

    //==Setters==
    void set_algID(int value);
    void set_algID(const std::string &value);
    void set_quantum(int value);
};


#endif //SCHEDULINGSIMSO_QUEUE_H