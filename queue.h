//
// Created by juanp on 16/03/2026.
//
#ifndef SCHEDULINGSIMSO_QUEUE_H
#define SCHEDULINGSIMSO_QUEUE_H

#include <string>

class QUEUE {
private:
    int algID;
    int quantum;
public:
    QUEUE() = default;
    QUEUE(int algID, int quantum);

    //==Getters==
    int get_algID();
    int get_quantum();

    //==Setters==
    void set_algID(int value);
    void set_algID(std::string &value);
    void set_quantum(int value);
};


#endif //SCHEDULINGSIMSO_QUEUE_H