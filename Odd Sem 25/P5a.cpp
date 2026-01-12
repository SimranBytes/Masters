#include <iostream>
using namespace std;

void maxSubarraySum(int arr[], int n) {
    int max_sum = arr[0];
    int current_sum = arr[0];
    int start = 0, end = 0, temp_start = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > current_sum + arr[i]) {
            current_sum = arr[i];
            temp_start = i;
        } else {
            current_sum += arr[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }

    cout << "\nMaximum Subarray Sum = " << max_sum << endl;
    cout << "Subarray elements: ";
    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    maxSubarraySum(arr, n);
    return 0;
}
