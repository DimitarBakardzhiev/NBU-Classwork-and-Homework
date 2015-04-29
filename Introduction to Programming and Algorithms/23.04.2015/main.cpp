#include <iostream>

using namespace std;

const int rows = 3;
const int cols = 4;

void gaussianMethod(double matrix[rows][cols])
{
    // the following code is used to every element on the main diagonal equal to 1
    // and every element under the main diagonal - equal to 0
    for (int i = 0; i < rows; i++)
    {
        // rowDivisor needed to remember the initial value of the first row element as it will be changed
        double rowDivisor = matrix[i][i];

        // divide the row by a constant to make the first element equal to 1
        for (int j = i; j < cols; j++)
        {
            matrix[i][j] /= rowDivisor;
        }

        // now let's make all the elements in the current column equal to 0
        // iterate over the lower rows
        for (int j = i; j < rows - 1; j++)
        {
            double multiplyRowBy = matrix[j + 1][i];

            // iterate over every element in the current row
            for (int k = i; k < cols; k++)
            {
                matrix[j + 1][k] -= matrix[i][k] * multiplyRowBy;
            }
        }
    }

    // TODO: calculate all roots
}

void printMatrix(double matrix[rows][cols])
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
    double matrix[rows][cols] =
    {
        { -3, -1, 2, -11 },
        { 2, 1, -1, 8 },
        { -2, 1, 2, -3 }
    };

    gaussianMethod(matrix);
    printMatrix(matrix);
    return 0;
}
