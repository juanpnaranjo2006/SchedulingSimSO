#include <iostream>
#include <string>
#include "scheduler.h"

int main(int argc, char* argv[]) {
    //Recordar, argv[0] siempre es el nombre del ejecutable
    if (argc == 2) {
       std::string argument(argv[1]);
        if (argument == "-h" || argument == "--help") {
            std::cout << "Usage: SchedulingSim.exe <inputFile> <schedulingAlgorithm> [params]\n";
            std::cout << "Additional parameters may be required depending on the selected algorithm.\n";
            std::cout << "Available options for <schedulingAlgorithm>:\n";
            std::cout << "--------------------------------------------------------------\n";
            std::cout << "FCFS                                : First Come First Served\n";
            std::cout << "SJF                                 : Shortest Job First (Non-Preemptive)\n";
            std::cout << "PSJF                                : Preemptive Shortest Job First\n";
            std::cout << "PRIORITY [asc|des]                  : Priority (Non-Preemptive) with either ascending or descending order\n";
            std::cout << "P-PRIORITY [asc|des]                : Preemptive Priority with either ascending or descending order\n";
            std::cout << "RR [Q]                              : Round Robin with quantum Q\n";
            std::cout << "MLQ [N] [schAlg1] ... [schAlgN]     : Multi-Level Queue with N queues\n";
            std::cout << "MLFQ [N] [Q_1] ... [Q_N-1] [schAlg] : Multi-Level Feedback Queue with N queues\n";
            std::cout << "Notes:\n";
            std::cout << "  - For MLQ and MLFQ, specify the algorithms in order using same notation shown above, leaving at least a blank space between each queue algorithm.\n";
            std::cout << "  - For MLFQ, even if the last algorithm is Round Robin, it must also be specified so with the notation shown above.\n";
        }
        else {
            std::cout << "Try 'SchedulingSim.exe --help' for more information.\n";
        }

        return 1;
    }
    else if (argc < 3) {
        std::cout << "Error: missing required arguments.\n";
        std::cout << "Try 'SchedulingSim.exe --help' for more information.\n";
        return -1;
    }
    else {
        //Normal execution
        ;
    }
    return 0;
}