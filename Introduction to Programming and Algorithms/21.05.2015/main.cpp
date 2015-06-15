#include <iostream>

using namespace std;

int binarySearch(int* arr, int left, int right, int x) {
    if (left > right) {
        return -1;
    }

    int middle = (left + right) / 2;
    if (arr[middle] == x) {
        return middle;
    } else if (x < arr[middle]) {
        return binarySearch(arr, left, middle - 1, x);
    } else {
        return binarySearch(arr, middle + 1, right, x);
    }
}

int main() {

    int arr[6] = { -2, 32, 66, 77, 123, 1000 };
    cout << endl << binarySearch(arr, 0, 5, 77) << endl;
    
    return 0;
}

