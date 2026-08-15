#include <iostream>
#include <string>
using namespace std;

// Membuat struct
struct mahasiswa
{
    string nama;
    string jurusan;
    float ipk;
};

int main()
{
    mahasiswa mhs; // Membuat variable dengan tipe datanya struct mahasiswa

    mhs.nama = "Nurfadila";             // Mengubah nama
    mhs.jurusan = "Teknik Informatika"; // Mengubah jurusan
    mhs.ipk = 3.8;                      // Mengubah ipk

    // Menampilkan isi dari elemen struct
    cout << "DATA MAHASISWA" << endl;
    cout << "--------------" << endl;
    cout << "Nama \t: " << mhs.nama << endl;
    cout << "Jurusan : " << mhs.jurusan << endl;
    cout << "IPK \t: " << mhs.ipk << endl;
    cout << "--------------------------------" << endl;
}