#include <iostream>
using namespace std;
int main()
{
    int a[2][2], transpose[2][2];

    cout << "Enter the matrix elements row-wise : \n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "mat[" << i << "]"
                 << "[" << j << "]"
                 << " = ";
            cin >> a[i][j]; // mengisi elemen matriks
        }
    }

    cout << "\nSum : \n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            transpose[j][i] = a[i][j]; // transpose matriks
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << transpose[i][j] << "  ";
        }
        cout << "\n";
    }
}