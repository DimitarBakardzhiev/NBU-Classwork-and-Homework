#include <iostream>

using namespace std;

double** multiplySquareMatices(double** left, double** right, int dimentions)
{
    double** result = new double*[dimentions];
    for (int i = 0; i < dimentions; i++)
    {
        result[i] = new double[dimentions];
    }

    for (int i = 0; i < dimentions; i++)
    {
        for (int j = 0; j < dimentions; j++)
        {
            for (int k = 0; k < dimentions; k++)
            {
                result[i][j] += left[i][k] * right[k][j];
            }
        }
    }

    return result;
}

void releaseMemory(double** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

bool areVectorsAlmostEqual(double* a, double* b, int length)
{
    if (a == NULL || b == NULL)
    {
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        double greater = max(a[i], b[i]);
        double lower = min(a[i], b[i]);
        if (greater - lower >= 0.001)
        {
            return false;
        }
    }

    return true;
}

double* getEigenVector(double** matrix, int dimentions)
{
    double* currentEigenVector = NULL;
    double* lastEigenVector = NULL;

    do
    {
        double** oldMatrix = matrix;
        matrix = multiplySquareMatices(matrix, matrix, dimentions);
        releaseMemory(oldMatrix, dimentions, dimentions);

        if (lastEigenVector != NULL)
        {
            delete[] lastEigenVector;
        }

        lastEigenVector = currentEigenVector;
        currentEigenVector = new double[dimentions];
        for (int i = 0; i < dimentions; i++)
        {
            for (int j = 0; j < dimentions; j++)
            {
                currentEigenVector[i] += matrix[i][j];
            }
        }

        double totalSum = 0;
        for (int i = 0; i < dimentions; i++)
        {
            totalSum += currentEigenVector[i];
        }

        for (int i = 0; i < dimentions; i++)
        {
            currentEigenVector[i] /=  totalSum;
        }
    }
    while (lastEigenVector == NULL || areVectorsAlmostEqual(currentEigenVector, lastEigenVector, dimentions));

    delete[] lastEigenVector;
    return currentEigenVector;
}

void printMatrix(double** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << '\t';
        }

        cout << endl;
    }
}

int main()
{
//    double** left = new double*[3]
//    {
//        new double[3] { 1, 0.5, 3 },
//        new double[3] { 2, 1, 4 },
//        new double[3] { 0.33, 0.25, 1 }
//    };
//    double** right = new double*[2]
//    {
//        new double[2] { 0, 1 },
//        new double[2] { 0, 0 }
//    };
//
//    double** result = multiplySquareMatices(left, left, 3);
//    printMatrix(result, 3, 3);

    double** matrix = new double*[3]
    {
        new double[3] { 1, 0.5, 3 },
        new double[3] { 2, 1, 4 },
        new double[3] { 0.33, 0.25, 1 }
    };

    double* eigenVector = getEigenVector(matrix, 3);
    for (int i = 0; i < 3; i++)
    {
        cout << eigenVector[i] << '\t';
    }

    return 0;
}
