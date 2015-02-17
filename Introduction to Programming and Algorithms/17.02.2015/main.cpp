#include <iostream>

using namespace std;

void findMinMax(int arr[], int length, int &min, int &max)
{
    min = max = arr[0];
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        else if (arr[i] > max)
        {
            max = arr[i];
        }
    }
}

int vectorScalarProduct(int vector1[], int vector2[], int length)
{
    int result = 0;
    for (int i = 0; i < length; i++)
    {
        result += vector1[i] * vector2[i];
    }

    return result;
}

int alternatingSum(int arr[], int length)
{
    int sum = 0;
    int sign = 1;
    for (int i = 0; i < length; i++)
    {
        sum += arr[i] * sign;
        sign *= -1;
    }

    return sum;
}

int* reverseVector(int arr[], int length)
{
    int* newVector = new int[length];
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
    {
        newVector[j] = arr[i];
    }

    return newVector;
}

int* vectorAddition(int vector1[], int vector2[], int length)
{
    int* newVector = new int[length];
    for (int i = 0; i < length; i++)
    {
        newVector[i] = vector1[i] + vector2[i];
    }

    return newVector;
}

int* vectorMerge(int vector1[], int vector2[], int length1, int length2)
{
    int length = length1 + length2;
    int* newVector = new int[length];
    for (int i = 0, j = 0; i < length; i++)
    {
        if (j < length1 && j < length2)
        {
            newVector[i] = i % 2 == 0 ? vector1[j] : vector2[j];
            if (i % 2 == 1)
            {
                j++;
            }
        }
        else
        {
            int* longerVector = j >= length1 ? vector2 : vector1;
            newVector[i] = longerVector[j];
            j++;
        }
    }

    return newVector;
}

int main()
{
    const int length1 = 7;
    const int length2 = 5;
    int a[length1] = { 1, 2, 3, 4, 5, 6, 7 };
    int b[length2] = { 0 };
    int* merged = vectorMerge(a, b, length1, length2);
    for (int i = 0; i < length1 + length2; i++)
    {
        cout << merged[i] << endl;
    }

//    cout << "Reversed" << endl;
//    int* reversed = reverseVector(merged, length1 + length2);
//    for (int i = 0; i < length1 + length2; i++)
//    {
//        cout << reversed[i] << endl;
//    }

    return 0;
}
