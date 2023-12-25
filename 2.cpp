#include <iostream>

double* allocateArray(int size);
void fillArray(double* arr, int size);
void displayArray(const double* arr, int size);
void deallocateArray(double* arr);

int main() {
    double* dynamicArray = nullptr;
    int size;

    while (true) {
        std::cout << "Enter the size of the array (0 to exit): ";
        std::cin >> size;

        if (size == 0) {
            break;
        }

        dynamicArray = allocateArray(size);
        fillArray(dynamicArray, size);
        displayArray(dynamicArray, size);
        deallocateArray(dynamicArray);
    }

    return 0;
}

double* allocateArray(int size) {
    return new double[size];
}

void fillArray(double* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }
}

void displayArray(const double* arr, int size) {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void deallocateArray(double* arr) {
    delete[] arr;
}