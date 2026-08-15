#include <iostream> // header untuk mendefinisikan input dan output pada console
#include <fstream>  // header untuk mendefinisikan input dan output pada file

// Baris ini digunakan supaya kita tidak perlu menuliskan berulang kata std di setiap perintah I/O
using namespace std;

int main()
{
    char ch;          // Deklarasi variable str dengan tipe data string
    ifstream inpfile; // Deklarasi inpfile sebagai file handler dari input file object
    ofstream outfile;
    bool loop = true;

    inpfile.open("mahasiswa.txt"); // Membuka file "mahasiswa.txt"
    outfile.open("file_copy.txt");
    if (!inpfile) // Jika file tidak ditemukan
    {
        cout << "File tidak ditemukan"; // Maka tampilkan label tidak ditemukan
    }
    else // Jika file ditemukan
    {
        // Maka eksekusi perintah berikut
        // while (loop) // Selama di dalam file masih ada karakter atau kalimat
        // {
        //     inpfile.get(ch);
        //     if (inpfile.eof() == true)
        //     {
        //         loop = false;
        //     }
        //     else
        //     {
        //         outfile << ch;
        //     }
        // }
        while (inpfile.get(ch))
        {
            outfile << ch;
        }
        if (outfile)
        {
            cout << "Data successfully copied..!" << endl; // Menampilkan jumlah mahasiswa
        }
        else
        {
            cout << "Data unsuccessfully copied..!" << endl;
        }
    }
    inpfile.close(); // Menutup inpfile
    outfile.close(); // Menutup outfile
}