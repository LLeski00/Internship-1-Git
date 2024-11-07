#include <iostream>
#include "diamond_generator.hpp"

void print_spaces(int line_width, int position)
{
    for (int i = 0; i < line_width / 2 - position; i++) {
        std::cout << " ";
    }
}

void display_diamond(int rows, int line_width)
{
    for (int i = 0; i < line_width/2; i++) {
        print_spaces(line_width, i);

        for (int j = 0; j < i*2 + 1; j++) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    if (rows%2 == 0) {
        for (int i = 0; i < line_width; i++) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    for (int i = line_width/2; i >= 0 ; i--) {
        print_spaces(line_width, i);

        for (int j = 0; j < i*2 + 1; j++) {
                std::cout << "*";
        }

        std::cout << std::endl;
    }
}

void diamond_generator_init()
{
    int rows;
    int line_width;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    line_width = rows % 2 == 0 ? rows - 1 : rows;

    display_diamond(rows, line_width);

    return;
}