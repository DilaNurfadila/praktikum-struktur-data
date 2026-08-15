#include <iostream>
using namespace std;
// Menampilkan elemen array
void DspArr(string (&a)[5])
{
    // foreach untuk menampilkan data dari array
    for (auto x : a)
        cout << x << " ";
}
int main()
{
    string arr[] = {"ayah", "ibu", "Ani", "Andi", "Ana"};
    cout << endl;
    DspArr(arr);
}