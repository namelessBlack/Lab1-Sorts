#include <iostream>
#include <random>
using namespace std;

uint32_t cur = 0;
mt19937 gen(12345);
uint32_t nextRand24(uint32_t a, uint32_t b) {
    cur = cur * a + b;
    return cur >> 8;
}

uint32_t nextRand32(uint32_t a, uint32_t b) {
    uint32_t x = nextRand24(a, b);
    uint32_t y = nextRand24(a, b);
    return (x << 8) ^ y;
}

uint32_t partitionLomuto(uint32_t nums[], uint32_t low, uint32_t high) {
    uint32_t pivot = nums[high];
    uint32_t i = low;
    for (int j = low; j < high; ++j) {
        if (nums[j] <= pivot) {
            std::swap(nums[i], nums[j]);
            i++;
        }
    }
    std::swap(nums[i], nums[high]);
    return i;
}

uint32_t quickSelect(uint32_t nums[], uint32_t low, uint32_t high, uint32_t k) {
    if (low == high) {
        return nums[low];
    }
    std::random_device rd;
    std::uniform_int_distribution<> dis(low, high);
    uint32_t pivotIndex = dis(gen);

    std::swap(nums[pivotIndex], nums[high]);

    uint32_t p = partitionLomuto(nums, low, high);
    
    if (p == k) {
        return nums[p];
    } else if (p > k) {
        return quickSelect(nums, low, p - 1, k);
    } else {
        return quickSelect(nums, p + 1, high, k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint32_t n, k, a, b;
    cin >> n >> k >> a >> b;

    uint32_t arr[n];

    for (uint32_t i = 0; i < n; i++) {
        arr[i] = nextRand32(a, b);
    }

    uint32_t res = quickSelect(arr, 0, n - 1, k - 1);
    std::cout << res;
    return 0;
}