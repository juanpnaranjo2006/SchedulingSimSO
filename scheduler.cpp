//
// Created by juanp on 16/03/2026.
//

#include "scheduler.h"
#include <stdexcept>
#include <exception>
#include <sstream>
#include <iostream>

//==Constructor==
SCHEDULER::SCHEDULER(std::vector<std::string> &arguments) {
    /*
     Se asume que todos los argumentos vienen ya separados como vienen en la llamada de ejecución
     y aquellos algoritmos de múltiples colas ya tienen cada algoritmo como strings
     Ej: SchedulingSim.exe <inputFile> <schedulingAlgorithm> [params]
     arguments[0] = <inputFile>
     arguments[1] = <schedulingAlgorithm>
     arguments[2] = [param0]
     arguments[3] = [param1]
     ...
     */
    dataTable.extractDataFromFile(arguments[0]);
    MLQ.clear();
    arguments[1] = toUpper(arguments[1]);
    if (arguments[1] == "MLQ") {
        multiQueueType = 1;
        int n = std::stoi(arguments[2]);
        std::string algName;
        std::string algParam;
        std::istringstream algBuffer;
        int i = 0;
        for (i = 0; i < n && i < arguments.size(); i++) {
            // schAlg_i param_i
            algBuffer.clear();
            algBuffer.str(arguments[3 + i]);
            algBuffer >> algName;
            algBuffer >> algParam;
            emplaceAlg(algName, algParam);
        }

        if (i != n) {
            throw std::invalid_argument("The provided queue algorithm has missing algorithms\nN = " + std::to_string(n) + "; Provided = " + std::to_string(i));
        }
    }
    else if (arguments[1] == "MLFQ") {
        multiQueueType = 2;
        int n = std::stoi(arguments[2]);
        std::string algName = "RR";
        std::string algParam;
        int q;
        std::istringstream algBuffer;
        int i = 0;
        for (i = 0; i < n - 1 && i < arguments.size(); i++) {
            // Q_i
            emplaceAlg(algName,arguments[3 + i]);
        }

        if (i == (n - 1)) {
            algBuffer.clear();
            algBuffer.str(arguments[3 + i]);
            algBuffer >> algName;
            algBuffer >> algParam;
            emplaceAlg(algName, algParam);
        }
        else {
            throw std::invalid_argument("The provided queue algorithm has missing algorithms\nN = " + std::to_string(n) + "; Provided = " + std::to_string(i));
        }
    }
    else {
        multiQueueType = 0;
        if (arguments.size() > 2) {
            emplaceAlg(arguments[1], arguments[2]);
        }
        else {
            emplaceAlg(arguments[1], arguments[1]);
        }
    }

    //Despues de crear cada cola asignamos cada algoritmo a su cola correspondiente
    assignProcesses();
}

//==Métodos privados==
std::string SCHEDULER::toUpper(const std::string& input) {
    std::string result = input;
    for (char& c : result) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    return result;
}

void SCHEDULER::emplaceAlg(std::string &alg, std::string &param) {
    alg = toUpper(alg);
    if (alg == "FCFS") {
        MLQ.emplace_back(false, false, 0, 0);
    }
    else if (alg == "SJF") {
        MLQ.emplace_back(false, false, 1, 0);
    }
    else if (alg == "PSJF") {
        MLQ.emplace_back(true, false, 2, 0);
    }
    else if (alg == "PRIORITY") {
        param = toUpper(param);
        if (param == "ASC") {
            MLQ.emplace_back(false, true, 3, 0);
        }
        else {
            MLQ.emplace_back(false, false, 3, 0);
        }
    }
    else if (alg == "P-PRIORITY") {
        param = toUpper(param);
        if (param == "ASC") {
            MLQ.emplace_back(true, true, 4, 0);
        }
        else {
            MLQ.emplace_back(true, false, 4, 0);
        }
    }
    else if (alg == "RR") {
        MLQ.emplace_back(true, false, 5, std::stoi(param));
    }
    else {
        throw std::invalid_argument("The algorithm '" + alg + "' is not supported by the simulator.");
    }
}

void SCHEDULER::assignProcesses() {
    if (multiQueueType == 1) {
        for (int i = 0; i < dataTable.getSize(); i++) {
            MLQ[dataTable.getQueue()[i] - 1].addProcess(i);
        }
    }
    else {
        for (int i = 0; i < dataTable.getSize(); i++) {
            MLQ[0].addProcess(i);
        }
    }
}

//==Getters==

std::vector<QUEUE>& SCHEDULER::getMLQ() {
    return MLQ;
}

TABLE& SCHEDULER::getTable() {
    return dataTable;
}