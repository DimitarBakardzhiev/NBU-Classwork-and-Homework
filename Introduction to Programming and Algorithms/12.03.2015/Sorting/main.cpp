#include <iostream>

using namespace std;

void selectionSort(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int min = arr[i];
        int minIndex = i;

        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    const int length = 5;
    int arr[length] = { 1, 2, 2, 2, 1 };
    selectionSort(arr, length);

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
