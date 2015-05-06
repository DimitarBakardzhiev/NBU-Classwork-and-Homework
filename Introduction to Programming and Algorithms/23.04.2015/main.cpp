#include <iostream>

using namespace std;

const int rows = 3;
const int cols = 4;

double* gaussianMethod(double matrix[rows][cols])
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

    // calculate all roots
    double *roots = new double[rows];
    for (int i = rows - 1; i >= 0; i--)
    {
        // sum the left side -> ex.: 5 - 7 + 3x = 21 -> sum the known numbers from the left side
        // the following code would sum 5 + (-7) in this example
        double sum = 0;
        // the following if statement prevents an error that could occur on the first iteration
        // of the outer for loop
        if (i == rows - 1)
		{
			roots[i] = matrix[i][cols - 1] / matrix[i][i];
		}
		else
		{
			for (int j = cols - 2; j > i; j--)
			{
				sum += matrix[i][j] * roots[j];
			}

			// to get the root we need to move the sum to the right side with the opposite sign
			double rightSide = matrix[i][cols - 1] + (-sum);
			roots[i] = rightSide / matrix[i][i];
		}
	}

	return roots;
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

    double *roots = gaussianMethod(matrix);
    printMatrix(matrix);
    for (int i = 0; i < cols - 1; i++)
    {
        cout << "x" << i + 1 << " = " << roots[i] << endl;
    }

    return 0;
}
