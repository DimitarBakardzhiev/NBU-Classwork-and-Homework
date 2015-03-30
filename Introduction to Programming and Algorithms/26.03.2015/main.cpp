#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = size - 1; j >= i; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int value = arr[i];
        int index = i;
        while (index > 0 && arr[index - 1] > value)
        {
            arr[index] = arr[index - 1];
            index--;
        }

        arr[index] = value;
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << arr[size - 1] << "." << endl;
}

int main()
{
    const int size = 7;
    int a[size] = { 5, 1234, 5, -1, 0, 123, 0 };
    print(a, size);
    insertionSort(a, size);
    print(a, size);

    return 0;
}
