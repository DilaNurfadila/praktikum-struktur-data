#include <iostream> // header untuk mendefinisikan input dan output pada console
#include <fstream>  // header untuk mendefinisikan input dan output pada file

// Baris ini digunakan supaya kita tidak perlu menuliskan berulang kata std di setiap perintah I/O
using namespace std;

int main()
{
    string str;          // Deklarasi variable str dengan tipe data string
    ifstream inpfile;    // Deklarasi inpfile sebagai file handler dari input file object
    int jumlah_kata = 0; // Deklarasi variable jumlah_kata dengan tipe data int dan assign value dengan 0

    inpfile.open("mahasiswa.txt"); // Membuka file "mahasiswa.txt"
    if (!inpfile)                  // Jika file tidak ditemukan
    {
        cout << "File tidak ditemukan"; // Maka tampilkan label tidak ditemukan
    }
    else // Jika file ditemukan
    {
        // Maka eksekusi perintah berikut
        cout << "=== Membaca file perkata ===" << endl; // Label
        while (!inpfile.eof())                          // Selama di dalam file masih ada karakter atau kalimat
        {
            inpfile >> str;      // Isi dari file di-assign ke variable str
            cout << str << endl; // Menampilkan value dari str
            jumlah_kata++;       // Setiap perulangan ditambah satu
        }
        cout << "Jumlah kata : " << jumlah_kata << endl; // Menampilkan jumlah kata
    }
    inpfile.close(); // Menutup file
}