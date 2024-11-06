#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "center_text.hpp"

std::string center_line(const std::string& line, int line_width) {
    int padding = (line_width - line.size()) / 2;
    std::string centered_line(padding, ' ');
    centered_line += line;
    return centered_line;
}

void center_text_init() {
    int max_chars, line_width;
    std::string input_line;
    std::vector<std::string> lines;

    std::cout << "Enter the maximum number of characters per line (m): ";
    std::cin >> max_chars;
    std::cout << "Enter the line width (n): ";
    std::cin >> line_width;

    if (line_width < max_chars) {
        std::cerr << "Line width (n) must be greater than or equal to max characters (m)." << std::endl;
        return;
    }

    std::cin.ignore();
    std::cout << "Enter text (end input with an empty line): " << std::endl;

    while (std::getline(std::cin, input_line)) {
        if (input_line.empty()) break;

        std::istringstream word_stream(input_line);
        std::string word, current_line;
        
        while (word_stream >> word) {
            if (word.size() > max_chars) {
                std::cerr << "Word exceeds max characters (" << max_chars << "): " << word << std::endl;
                continue;
            }

            if (current_line.size() + word.size() + 1 <= max_chars) {
                if (!current_line.empty()) {
                    current_line += ' ';
                }
                current_line += word;
            } else {
                lines.push_back(current_line);
                current_line = word;
            }
        }
        
        if (!current_line.empty()) {
            lines.push_back(current_line);
        }
    }

    std::cout << "\nCentered text:\n";
    for (const std::string& line : lines) {
        std::cout << center_line(line, line_width) << std::endl;
    }
}
