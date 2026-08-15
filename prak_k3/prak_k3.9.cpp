#include <iostream>
using namespace std;
int main()
{
    int arr[10], sum = 0, n, i;

    cout << "How many Elements you want to Enter : ";
    cin >> n; // mengisi jumlah elemen array

    cout << "Enter any " << n << " Elements in Array" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i]; // menjumlahkan elemen array
    }

    cout << "Sum of all Elements are : " << sum << endl;
}