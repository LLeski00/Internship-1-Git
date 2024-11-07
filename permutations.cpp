#include <iostream>
#include <vector>
#include <sstream>
#include "permutations.hpp"

void print_permutation(const std::vector<int>& nums) {
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void generate_permutations(std::vector<int>& nums, int start) {
    if (start == nums.size() - 1) {
        print_permutation(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        std::swap(nums[start], nums[i]);
        generate_permutations(nums, start + 1);
        std::swap(nums[start], nums[i]);
    }
}

void permutations_init()
{
    std::string input;
    std::cout << "Enter numbers: ";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::vector<int> nums;
    int num;

    while (iss >> num) {
        nums.push_back(num);
    }

    std::cout << "All possible permutations:\n";
    generate_permutations(nums, 0);

    return;
}