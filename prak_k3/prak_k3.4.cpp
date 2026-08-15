#include <iostream>
using namespace std;
int main()
{
    int firstArray[5];
    int secondArray[5];

    cout << "Enter 5 numbers" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> firstArray[i];
        secondArray[i] = firstArray[i]; // Menyalin isi dari array 1 ke array 2
    }

    // Array 1 dan array 2 akan memiliki isi yang sama
    cout << "\nElements of first array" << endl;
    for (int j = 0; j < 5; j++)
    {
        cout << firstArray[j] << endl;
    }

    cout << "\nElements of second array" << endl;
    for (int k = 0; k < 5; k++)
    {
        cout << secondArray[k] << endl;
    }
}