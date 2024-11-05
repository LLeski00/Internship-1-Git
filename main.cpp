#include <iostream>
#include <cstdlib>

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
    
    do {
        clear_screen();
        std::cout << "Program list:" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Which program would you like to run? : ";
        std::cin >> program;
        
        switch(program) {
            case 0:
                std::cout << "Goodbye!" << std::endl;
                shutdown = true;
                break;
            default:
                std::cout << "Wrong input!" << std::endl;
                break;
    };
    } while(!shutdown);

    return 0;
}