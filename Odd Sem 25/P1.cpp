#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// ---------- Linear Search ----------
int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// ---------- Binary Search ----------
int binarySearch(const vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// ---------- Main ----------
int main() {
    srand(time(0));

    vector<int> n_values = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    vector<double> linear_times, binary_times;
    vector<int> keys_used;

    int repetitions = 1000; // repeat to average out timing noise

    cout << "n\tKey\tLinear(us)\tBinary(us)\n";
    cout << "--------------------------------------------\n";

    for (int n : n_values) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = rand();
        sort(arr.begin(), arr.end());

        int key = arr[rand() % n]; // pick a random existing key
        keys_used.push_back(key);

        // Linear Search timing
        auto start1 = high_resolution_clock::now();
        for (int i = 0; i < repetitions; i++)
            linearSearch(arr, key);
        auto end1 = high_resolution_clock::now();
        double linear_time = duration_cast<microseconds>(end1 - start1).count() / (double)repetitions;

        // Binary Search timing
        auto start2 = high_resolution_clock::now();
        for (int i = 0; i < repetitions; i++)
            binarySearch(arr, key);
        auto end2 = high_resolution_clock::now();
        double binary_time = duration_cast<microseconds>(end2 - start2).count() / (double)repetitions;

        linear_times.push_back(linear_time);
        binary_times.push_back(binary_time);

        cout << n << "\t" << key << "\t" << linear_time << "\t\t" << binary_time << "\n";
    }

    // -------- Python-friendly lists --------
    cout << "\n# Copy these into Python directly\n";
    cout << "n = [";
    for (size_t i = 0; i < n_values.size(); i++) {
        cout << n_values[i];
        if (i != n_values.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "keys = [";
    for (size_t i = 0; i < keys_used.size(); i++) {
        cout << keys_used[i];
        if (i != keys_used.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "linear_time = [";
    for (size_t i = 0; i < linear_times.size(); i++) {
        cout << linear_times[i];
        if (i != linear_times.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "binary_time = [";
    for (size_t i = 0; i < binary_times.size(); i++) {
        cout << binary_times[i];
        if (i != binary_times.size() - 1) cout << ", ";
    }
    cout << "]\n";
}
