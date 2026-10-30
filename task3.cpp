#include <iostream>
#include <random>

struct Track {
    int popularity;
    int stability;
    int id;
};


bool Less(const Track& a, const Track& b) {
    if (a.popularity != b.popularity) {
        return a.popularity < b.popularity;
    }
    if (a.stability != b.stability) {
        return a.stability < b.stability;
    }
    return a.id < b.id;
}

int Hoare(Track tracks[], int result[], int left, int right ) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(left, right);
    Track pivot = tracks[dis(gen)];
    int i = left;
    int j = right;
    while (true) {
        while (Less(tracks[i], pivot)) {
            i++;
        }
        while (Less(pivot, tracks[j])) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        std::swap(tracks[i], tracks[j]);
        std::swap(result[i], result[j]);
        i++;
        j--;
    }
}

void QuickSort(Track tracks[], int result[], int left, int right) {
    if (left >= right) {
        return;
    }
    int m = Hoare(tracks, result, left, right);
    QuickSort(tracks, result, left, m);
    QuickSort(tracks, result, m + 1, right);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int size;
    std::cin >> size;
    Track tracks[size];

    for (int i = 0; i < size; i++) {
        std::cin>> tracks[i].popularity >> tracks[i].stability;
        tracks[i].id = i + 1;
    }

    int result[size];
    for (int i = 0; i < size; i++) {
        result[i] = i + 1;
    }
    QuickSort(tracks, result, 0, size - 1);
    for (int i = 0; i < size - 1; i++) {
        if (tracks[i].popularity == tracks[i + 1].popularity) {
            if (tracks[i].stability > tracks[i + 1].stability) {
                std::swap(tracks[i], tracks[i + 1]);
                std::swap(result[i], result[i + 1]);
            }
        }
        if (tracks[i].popularity == tracks[i + 1].popularity &&
            tracks[i].stability == tracks[i + 1].stability) {
            continue;
            }
    }
    for (int i = 0; i < size; i++) {
        std::cout << result[i] << " ";
    }
}

