#include <iostream>
using namespace std;
int main()
{
    int n, arr[10], temp, i, j;

    cout << "How many Elements you want to Enter : ";
    cin >> n; // mengisi jumlah elemen array

    cout << "Enter any " << n << " Elements in Array" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i]; // mengisi elemen array
    }

    for (i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        // membalikkan urutan dengan saling memindahkan terlebih dahulu
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    cout << "\nReverse of Array : " << endl;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}