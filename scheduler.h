//
// Created by juanp on 16/03/2026.
//

#ifndef SCHEDULINGSIMSO_SCHEDULER_H
#define SCHEDULINGSIMSO_SCHEDULER_H

#include "table.h"
#include "queue.h"

class SCHEDULER {
private:
    std::vector<QUEUE> MLQ;
    TABLE dataTable;
public:
    SCHEDULER(std::vector<std::string> &arguments); //Debe incluir el nombre del archivo para mandar a la TABLE a leerlo

    //==Métodos Principales==
    void simulation(); //Al final la tabla queda con todos los datos necesarios
    void updateTable(); //Ya seleccionado el algoritmo que toca usar (cola) determinar el proceso que hay que ejecutar y actualizar tabla

    //==Getters==
    std::vector<QUEUE>& getMLQ();
    TABLE& getTable();
};


#endif //SCHEDULINGSIMSO_SCHEDULER_H