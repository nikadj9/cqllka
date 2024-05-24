#include <iostream>
#include <vector>

using namespace std;

void counting_sort(vector <int>& array, int m) {
    int min, max;
    max = min = array[0];
    for (size_t i = 1; i < m; i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }
    vector <int> counts(max - min + 1, 0);
    for (size_t i = 0; i < m; i++) {
        counts[array[i] - min]++;
    }
    size_t index = 0;
    for (size_t i = 0; i < counts.size(); i++) {
        for (size_t j = 0; j < counts[i]; j++) {
            array[index++] = i + min;
        }
    }
}

int main() {
    string n;
    getline(cin, n);
    vector <int> a;
    for (int i = 0; i < n.size(); i++) {
        if (n[i] >= '0' && n[i] <= '9') {
            a.push_back(int(n[i]) - 48);
        }
    }
    counting_sort(a, a.size());
    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i];
    }
}
