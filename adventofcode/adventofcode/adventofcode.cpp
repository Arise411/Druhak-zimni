#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>


//prosim o ignoraci obcasnych komentaru, kde si neco vysvetluji pro budouci pouziti :)



int main() {
    std::ifstream inputFile("adventofcode.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    // txt do vektoru
    std::vector<int> numbers;
    std::string line;
    while (std::getline(inputFile, line)) {
        int number = std::atoi(line.c_str()); //atoi == "ASCII to Integer," převod stringu do int
        numbers.push_back(number);
    }

    // 2 cisla == 2020
    int n = numbers.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (numbers[i] + numbers[j] == 2020) {
                std::cout << "Cisla: " << numbers[i] << " a " << numbers[j] << std::endl;
                int nasob = numbers[i] * numbers[j];
                std::cout << "Vysledek: " << nasob << std::endl;

            }
        }
    }
    
	// 3 cisla == 2020
    int m = numbers.size();
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                if (numbers[i] + numbers[j] + numbers[k] == 2020) {
                    std::cout << "Cisla: " << numbers[i] << ", " << numbers[j] << " a " << numbers[k] << std::endl;
                    int nasob = numbers[i] * numbers[j] * numbers[k];
                    std::cout << "Vysledek: " << nasob << std::endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
