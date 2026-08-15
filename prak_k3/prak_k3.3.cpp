#include <iostream>
using namespace std;
int main()
{
    int arr[5], square[5], i, j;
    cout << "Enter 5 numbers" << endl;
    for (i = 0; i < 5; i++)
    {
        cin >> arr[i];
        square[i] = arr[i] * arr[i]; // menguadratkan elemen array
    }
    for (j = 0; j < 5; j++)
    {
        cout << "Square " << j + 1 << " = " << square[j] << endl;
    }
}