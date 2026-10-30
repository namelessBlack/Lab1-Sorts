#include <iostream>

const int MAXN = 1'000'000;

uint32_t arr[MAXN];
uint32_t leftHalf[MAXN / 2 + 1];
uint32_t rightHalf[MAXN / 2 + 1];

uint32_t cur = 0;

uint32_t nextRand24(uint32_t a, uint32_t b) {
    cur = cur * a + b;
    return cur >> 8;
}

long long Merge(uint32_t left[], uint32_t leftSize, uint32_t right[], uint32_t rightSize, uint32_t result[]) {
    uint32_t i = 0, j = 0, k = 0;
    long long inversions = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            result[k] = left[i];
            i++;
        }
        else {
            inversions += leftSize - i;
            result[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        result[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        result[k] = right[j];
        j++;
        k++;
    }

    return inversions;
}

long long MergeSort(uint32_t nums[], uint32_t size) {
    if (size <= 1) {
        return 0;
    }

    uint32_t middle = size / 2;
    long long inversions = 0;

    inversions += MergeSort(nums, middle);
    inversions += MergeSort(nums + middle, size - middle);

    for (uint32_t i = 0; i < middle; i++) {
        leftHalf[i] = nums[i];
    }
    for (uint32_t i = middle; i < size; i++) {
        rightHalf[i - middle] = nums[i];
    }

    inversions += Merge(leftHalf, middle, rightHalf, size - middle, nums);
    return inversions;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t n, m, a, b;
    std::cin >> n >> m >> a >> b;

    for (uint32_t i = 0; i < n; i++) {
        uint32_t x = nextRand24(a, b) % m;
        arr[i] = x;
    }

    long long inversions =  MergeSort(arr,n);
    std::cout << inversions << std::endl;
}