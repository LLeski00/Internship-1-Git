#include <iostream>
#include <cstdlib>
#include <string>
#include "permutations.hpp"
#include "tic_tac_toe.hpp"
#include "center_text.hpp"
#include "diamond_generator.hpp"

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
        std::cout << "1. Tic Tac Toe" << std::endl;
        std::cout << "2. Permutations" << std::endl;
        std::cout << "3. Center text" << std::endl;
        std::cout << "4. Diamond generator" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Which program would you like to run? : ";
        std::cin >> program;
        std::getline(std::cin, buffer);
        
        switch(program) {
            case 0:
                std::cout << "Goodbye!" << std::endl;
                shutdown = true;
                break;
            case 1:
                tic_tac_toe_init();
                break;
            case 2:
                permutations_init();
                break;
            case 3:
                center_text_init();
                break;
            case 4:
                diamond_generator_init();
                break;
            default:
                std::cout << "Wrong input!" << std::endl;
                break;
    };
    } while(!shutdown);

    return 0;
}