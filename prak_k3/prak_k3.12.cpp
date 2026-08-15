#include <iostream>
using namespace std;
int main()
{
    int mat[2][3];

    cout << "Enter the matrix elements row-wise : \n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "mat[" << i << "]"
                 << "[" << j << "]"
                 << " = ";
            cin >> mat[i][j]; // mengisi elemen array 2 dimensi atau matriks
        }
    }

    cout << "You have entered the matrix : \n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << "  ";
        }
        cout << "\n";
    }
}