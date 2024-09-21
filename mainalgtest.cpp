#include <iostream>
#include <vector>
#include <cstdlib>  // for rng
#include <chrono>   // for time measurement

// Function to generate an array of random int
std::vector<int> generateArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;  // Random numbers between 0 and 9999
    }
    return arr;
}

// Function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Array sizes for tests
    std::vector<int> sizes = {1000, 5000, 10000, 50000, 100000};
    
    for (int size : sizes) {
        std::vector<int> arr = generateArray(size);

        std::cout << "Sorting array of size: " << size << std::endl;
        
        // Measure start time
        auto start = std::chrono::high_resolution_clock::now();

        // Call merge sort
        mergeSort(arr, 0, arr.size() - 1);

        // Measure end time
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        // Output the time taken to sort the array
        std::cout << "Time taken: " << duration.count() << " seconds\n" << std::endl;
    }

    return 0;
}
