#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>

int main() {
    std::vector<int> input_l1;
    std::unordered_map<int, int> l2_freqs;

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
        l2_freqs[num2]++;   // default value is 0
    }


    size_t similarity_score = 0;
    int cur_num;
    for (int i = 0; i < input_l1.size(); cur_num = input_l1[i++]) {
        similarity_score += cur_num * l2_freqs[cur_num];
    }

    std::cout << similarity_score << std::endl;
    return 0;
}