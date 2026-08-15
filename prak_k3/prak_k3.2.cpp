#include <iostream>
using namespace std;
int main()
{
    int arr[5], sum = 0, i;
    cout << "Enter 5 numbers" << endl;
    for (i = 0; i < 5; i++)
    {
        cin >> arr[i];
        sum = sum + arr[i]; // Menjumlahkan isi array
    }
    cout << "Sum = " << sum << endl;
}