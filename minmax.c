#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Size must be a positive integer." << endl;
        return 1;
    }

    int* arr = new int[size];
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    if (size == 1) {
        cout << "Minimum: " << arr[0] << endl;
        cout << "Maximum: " << arr[0] << endl;
        delete[] arr;
        return 0;
    }

    int min = (arr[0] < arr[1]) ? arr[0] : arr[1];
    int max = (arr[0] < arr[1]) ? arr[1] : arr[0];

    for (int i = 2; i < size; i += 2) {
        // Get the current pair
        int a = arr[i];
        int b = (i + 1 < size) ? arr[i + 1] : a;

        // Determine min and max of the pair
        int pairMin = min(a, b);
        int pairMax = max(a, b);

        // Update global min and max
        if (pairMin < min) {
            min = pairMin;
        }
        if (pairMax > max) {
            max = pairMax;
        }
    }

    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;

    delete[] arr;
    return 0;
}
