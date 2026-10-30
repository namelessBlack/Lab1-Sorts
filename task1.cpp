#include <iostream>

int InsertionSort(int arr[], int size) {
    int count = 0;
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            count++;
            if (arr[j] <= key) {
                break;
            }
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return count;
}

int main() {
    int size;
    std::cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        std::cin>>arr[i];
    }
    int result = InsertionSort(arr, size);
    std::cout << result << std::endl;
    return 0;
}
