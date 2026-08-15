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

void display(int A[], int n)
{
    cout << "The ELements of the array are : \n";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}

void BSort(int A[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1 - i); j++)
        {
            if (A[j] > A[j + 1])
            {
                // mengurutan dengan saling memindahkan terlebih dahulu
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int arr[5];
    input(arr, 5);     // passing argumen
    search(arr, 5, 2); // passing argumen; datanya adalah 2
    BSort(arr, 5);
    display(arr, 5);
}