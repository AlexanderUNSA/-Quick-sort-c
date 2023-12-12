#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);

        int pivotIndex = i + 1;

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    srand(time(0));

    std::vector<int> sizes = { 100, 1000, 2000, 3000, 4000, 5000 };

    for (int size : sizes) {
        // Generate a random list
        std::vector<int> vec(size);
        for (int i = 0; i < size; i++) {
            vec[i] = rand() % 1000;
        }

        // Measure the time taken to sort
        clock_t start = clock();
        quickSort(vec, 0, size - 1);
        clock_t end = clock();

        double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "Size: " << size << ", Time: " << elapsed_time << " seconds\n";
    }

    return 0;
}