#include <iostream>

const int MAXN = 1000000;

long long val[MAXN], tmpVal[MAXN];
int idx[MAXN], tmpIdx[MAXN];
int ans[MAXN];
int n;

void ReadInput() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> val[i];
        idx[i] = i;
    }
}

void Merge(int l, int mid, int r) {
    int i = l, j = mid, k = l;
    while (i < mid || j < r) {
        if (j == r || (i < mid && val[i] <= val[j])) {
            tmpVal[k] = val[i];
            tmpIdx[k] = idx[i];
            i++;
        } else {
            ans[idx[j]] += i - l;
            tmpVal[k] = val[j];
            tmpIdx[k] = idx[j];
            j++;
        }
        k++;
    }
    for (int t = l; t < r; ++t) {
        val[t] = tmpVal[t];
        idx[t] = tmpIdx[t];
    }
}

void MergeSort(int l, int r) {
    if (r - l <= 1) {
        return;
    };
    int mid = (l + r) / 2;
    MergeSort(l, mid);
    MergeSort(mid, r);
    Merge(l, mid, r);
}

void PrintAnswers() {
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ReadInput();
    MergeSort(0, n);
    PrintAnswers();
    return 0;
}