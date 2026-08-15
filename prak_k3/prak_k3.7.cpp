#include <iostream>
using namespace std;
int main()
{
    int arr1[5];
    int arr2[5];
    int arr3[10];

    cout << "Enter Elements in 1st Array :" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr1[i]; // memasukan elemen ke array 1
    }

    cout << "Enter Elements in 2nd Array :" << endl;
    for (int i = 5; i < 10; i++)
    {
        cin >> arr2[i];    // memasukan elemen ke array 2
        arr1[i] = arr2[i]; // menyalin elemen array 2 ke array 1
    }

    cout << "\nElements of Array After Merge : " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr1[i] << endl;
    }
}