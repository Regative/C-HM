#include <iostream>
#include <cstdlib> 
#include <ctime>   

void fillRandomNumbers(int** arr, int rows, int cols) {
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = std::rand() % 41 + 10; 
        }
    }
}

void displayArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows, cols;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    int** dynamicArray = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        dynamicArray[i] = new int[cols];
    }

    fillRandomNumbers(dynamicArray, rows, cols);

    std::cout << "Randomly generated array:\n";
    displayArray(dynamicArray, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] dynamicArray[i];
    }
    delete[] dynamicArray;

    return 0;
}