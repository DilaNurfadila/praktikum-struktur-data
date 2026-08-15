#include <iostream>
using namespace std;
int square[5]; // deklarasi variable global untuk kuadrat
void GetData(int array[], int size)
{
    cout << "Input numbers" << endl;
    for (int n = 0; n < size; n++)
    {
        cin >> array[n]; // mengisi elemen
    }
}

void SquareOfData(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        square[i] = array[i] * array[i]; // menguadratkan elemen
    }
}

void DisplayData(int array[], int size)
{
    cout << "\n----- SQUARED DATA -----" << endl;
    for (int j = 0; j < size; j++)
    {
        cout << square[j] << endl; // menampilkan elemen yang sudah dikuadratkan
    }
}
int main()
{
    int arr[5];
    // passing argument
    GetData(arr, 5);
    SquareOfData(arr, 5);
    DisplayData(arr, 5);
}