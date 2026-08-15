#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    // assign vector
    vector<int> vec;

    // menambahkan angka 12 sebanyak 7 kali ke vec
    vec.assign(7, 12);

    // menampilkan vector setelah ditambahkan
    cout << "The vector elements are : ";
    for (int i = 0; i < 7; i++)
    {
        // output => 12 12 12 12 12 12 12
        cout << vec[i] << " ";
    }

    // menambahkan angka 24 di belakang
    vec.push_back(24);
    int s = vec.size(); // assign ukuran vector ke variable s
    // menampilkan element vector terakhir
    // output => 24
    cout << "\nThe last element is : " << vec[s - 1];

    // menampilkan vector setelah ditambahkan
    cout << "\nThe vector elements after push_back are : ";
    for (int i = 0; i < vec.size(); i++)
    {
        // output => 12 12 12 12 12 12 12 24
        cout << vec[i] << " ";
    }

    // mengambil atau menghapus element terakhir
    vec.pop_back();

    // menampilkan vector setelah dihapus
    cout << "\nThe vector elements after pop_back are : ";
    for (int i = 0; i < vec.size(); i++)
    {
        // output => 12 12 12 12 12 12 12
        cout << vec[i] << " ";
    }

    // menambahkan angka 10 diawal
    vec.insert(vec.begin(), 10);

    // menampilkan element vector pertama
    // output => 10
    cout << "\nThe first element after insert command is : " << vec[0];

    // menghapus angka 10
    vec.erase(vec.begin());

    // menampilkan element vector pertama
    // output => 12
    cout << "\nThe first element after erase command is : " << vec[0];

    // menambahkan angka 5 diawal
    vec.emplace(vec.begin(), 5);
    // output => 5
    cout << "\nThe first element emplace is : " << vec[0];

    // menambahkan angka 20 dibelakang
    vec.emplace_back(20);
    s = vec.size(); // assign ukuran vector ke variable s
    // output => 20
    cout << "\nThe last element after emplace_back is : " << vec[s - 1];

    // menghapus seluruh element
    vec.clear();
    // output => 0
    cout << "\nVector size after clear() : " << vec.size();

    vector<int> obj1, obj2;
    // menambahkan element ke obj1 dan obj2 ke belakang
    obj1.push_back(2);
    obj1.push_back(4);
    obj2.push_back(6);
    obj2.push_back(8);

    // menampilkan element vector
    cout << "\nVector 1 : ";
    for (int i = 0; i < obj1.size(); i++)
    {
        // output => 2 4
        cout << obj1[i] << " ";
    }

    cout << "\nVector 2 : ";
    for (int i = 0; i < obj2.size(); i++)
    {
        // output => 6 8
        cout << obj2[i] << " ";
    }

    // menukarkan element obj1 dan obj2
    obj1.swap(obj2);

    // menampilkan element vector setelah di swap
    cout << "\nAfter swap\nVector 1 : ";
    for (int i = 0; i < obj1.size(); i++)
    {
        // output => 6 8
        cout << obj1[i] << " ";
    }

    cout << "\nVector 2 : ";
    for (int i = 0; i < obj2.size(); i++)
    {
        // output => 2 4
        cout << obj2[i] << " ";
    }
}