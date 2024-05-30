#include <iostream>
#include <string>
using namespace std;

void merge(int* arr, int s, int mid, int e) {
    int left_size = mid - s + 1;
    int right_size = e - mid;

    // Iterate from the end of the left array to the beginning
    for (int i = left_size - 1; i >= 0; i--) {
        arr[s + i + right_size] = arr[s + i];
    }

    int i = right_size; // Index for the copied left array
    int j = 0;          // Index for the right array
    int k = s;          // Index for the original array

    while (i < left_size + right_size && j < right_size) {
        if (arr[s + i] <= arr[mid + 1 + j]) {
            arr[k] = arr[s + i];
            i++;
        } else {
            arr[k] = arr[mid + 1 + j];
            j++;
        }
        k++;
    }
}

void merge_sort(int* arr, int s, int e) {
    if (s < e) {
        int mid = s + (e - s) / 2;
        merge_sort(arr, s, mid);
        merge_sort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }
}

int main() {
    int n = 6;
    int arr[n] = {5, 4, 3, 2, 1, 0};
    int s = 0;
    int e = n - 1;

    merge_sort(arr, s, e);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
