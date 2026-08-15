#include <iostream>
using namespace std;
void Delete(int A[], int &N, int pos)
{
    if (pos < 0 || pos >= N)
    {
        cout << "Posisi tidak ditemukan\n";
        return;
    }

    int item = A[pos];
    for (int i = pos; i < N; i++)
    {
        A[i] = A[i + 1];
    }
    N--;
}
int main()
{
    const int N = 5;
    int arr[] = {10, 20, 30, 40, 50};
    int size = N;
    for (auto z : arr)
        cout << z << " ";
    cout << endl
         << endl;
    Delete(arr, size, 3);
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}