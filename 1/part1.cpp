#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main() {
    // read in input.txt
    std::vector<int> input_l1;
    std::vector<int> input_l2;

    std::ifstream input_file("input.txt");

    if (!input_file.is_open()) {
        std::cerr << "Could not open file." << std::endl;
        return 1;
    }

    std::string line;
    while  (std::getline(input_file, line)) {
        std::stringstream ss(line);
        int num1, num2;

        ss >> num1 >> num2;
        input_l1.push_back(num1);
        input_l2.push_back(num2);
    }

    input_file.close();
    
    // sort both inputs
    std::sort(input_l1.begin(), input_l1.end());
    std::sort(input_l2.begin(), input_l2.end());

    size_t sum = 0;
    for (int i = 0; i < input_l1.size(); i++) 
        sum += abs(input_l1[i] - input_l2[i]); 
    std::cout << sum << std::endl;

    return 0;
}