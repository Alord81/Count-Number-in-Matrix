#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int RandomeNumber(short From, short To)
{
    return rand() % (To - From + 1) + From;
}

void FullArrayWithOrderdNumber(short arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            arr[i][j] = RandomeNumber(0, 9);
        }
    }
}

void PrintArrayInMatrix(short arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%0*d\t", 2, arr[i][j]);
        }
        cout << endl;
    }
}

short CountInMatrix(short Matrix[3][3], short Row, short Col, short Number)
{
    short Count = 0;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (Matrix[i][j] == Number)
            {
                Count++;
            }
        }
    }

    return Count;
}
int main()
{

    srand((unsigned)time(NULL));
    short arr1[3][3];
    short cols = 3, rows = 3, UserNumber;

    FullArrayWithOrderdNumber(arr1, rows, cols);

    cout << "Matrix1:\n";
    PrintArrayInMatrix(arr1, rows, cols);

    cout << "Enter the number to count in matrix? ";
    cin >> UserNumber;

    short* ptr;
    ptr = new short;
    *ptr = CountInMatrix(arr1, rows, cols, UserNumber);
    printf("Number %d count in matrix is %d",UserNumber, *ptr);

    delete ptr;
    return 0;
}