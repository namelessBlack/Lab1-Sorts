#include <iostream>
#include <random>



int Hoare(int a[], int left, int right) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(left, right);
    int pivot = a[dis(gen)];
    int i = right;
    int j = left;
    while (true) {
        while (a[i] > pivot) {
            i--;
        }
        while (a[j] < pivot) {
            j++;
        }
        if (i <= j) {
            return i;
        }
        std::swap(a[i], a[j]);
        i--;
        j++;
    }
}

void QuickSort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }
    int m = Hoare(a, left, right);
    QuickSort(a, left, m);
    QuickSort(a, m + 1, right);
}



int main() {
    int size;
    std::cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    QuickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
