#include <iostream>
#include <cstdlib>
#include <string>
#include "permutations.hpp"

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int program = 0;
    bool shutdown = false;
    std::string buffer;
    
    do {
        clear_screen();
        std::cout << "Program list:" << std::endl;
        std::cout << "2. Permutations" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Which program would you like to run? : ";
        std::cin >> program;
        std::getline(std::cin, buffer);
        
        switch(program) {
            case 0:
                std::cout << "Goodbye!" << std::endl;
                shutdown = true;
                break;
            case 2:
                permutations_init();
                break;
            default:
                std::cout << "Wrong input!" << std::endl;
                break;
    };
    } while(!shutdown);

    return 0;
}