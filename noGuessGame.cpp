#include <iostream>
#include <random>

int main() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist100(1, 100);
    int target = dist100(rng);
    
    while(true) {
        std::cout << "Guess the number (between 1 and 100): ";
        int input;
        std::cin >> input;

        if (input == target) {
            std::cout << "Correct!" << std::endl;
            break;
        } else if (input > target) {
            std::cout << "Wrong!, the number is less than " << input << std::endl;
        } else {
            std::cout << "Wrong!, the number is greater than " << input << std::endl;
        }
    }   
    
    return 0;
}