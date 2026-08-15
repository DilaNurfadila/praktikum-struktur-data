#include <iostream>
using namespace std;
void input(int A[], int n)
{
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i]; // memasukan elemen array
    }
}

void search(int A[], int n, int data)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] == data) // mencari isi elemen sesuai data yang diberikan
        {
            // jika ditemukan, tampilkan pada indeks ke berapa data tersebut ditemukan
            cout << "Data Found at : " << i << endl;
            return;
        }
    }
    cout << "Data Not Found in the Array" << endl; // jika tidak ditemukan data yang dicari
}
int main()
{
    int arr[5];
    input(arr, 5);     // passing argumen
    search(arr, 5, 2); // passing argumen; datanya adalah 2
}