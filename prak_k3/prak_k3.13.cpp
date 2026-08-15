#include <iostream>
using namespace std;
int main()
{
    int a[2][2], b[2][2], sum[2][2];

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
            sum[i][j] = a[i][j] + b[i][j]; // menjumlahkan 2 matriks
            cout << sum[i][j] << "  ";
        }
        cout << "\n";
    }
}