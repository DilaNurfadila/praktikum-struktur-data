#include <iostream>
using namespace std;
int main()
{
    int mat[5][5][5], a, b, c;

    cout << "Enter size of three dimensions : ";
    cin >> a >> b >> c; // mengisi ukuran dari matriks 3 dimensi

    cout << "Enter elements of array : \n";
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < c; k++)
            {
                cout << "mat[" << i << "]"
                     << "[" << j << "]"
                     << "[" << k << "]"
                     << " = ";
                cin >> mat[i][j][k]; // mengisi elemen matriks
            }
        }
    }

    cout << "\nDisplaying elements of array : " << endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < c; k++)
            {
                cout << "mat[" << i << "]"
                     << "[" << j << "]"
                     << "[" << k << "]"
                     << " = " << mat[i][j][k] << endl;
            }
        }
    }
}