#include <iostream>
using namespace std;
int main()
{
    int a[2][2], b[2][2], mult[2][2];

    cout << "Enter the 1st matrix elements row-wise : \n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "mat[" << i << "]"
                 << "[" << j << "]"
                 << " = ";
            cin >> a[i][j]; // mengisi elemen matriks 1
        }
    }

    cout << "Enter the 2nd matrix elements row-wise : \n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "mat[" << i << "]"
                 << "[" << j << "]"
                 << " = ";
            cin >> b[i][j]; // mengisi elemen matriks 2
        }
    }

    cout << "\nSum : \n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mult[i][j] = 0; // inisialisasi elemen matriks dengan 0
            for (int k = 0; k < 2; k++)
            {
                mult[i][j] += a[i][k] * b[k][j]; // mengalikan 2 matriks
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << mult[i][j] << "  ";
        }
        cout << "\n";
    }
}