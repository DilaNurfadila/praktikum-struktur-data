#include <iostream> // header untuk mendefinisikan input dan output pada console
#include <fstream>  // header untuk mendefinisikan input dan output pada file

// Baris ini digunakan supaya kita tidak perlu menuliskan berulang kata std di setiap perintah I/O
using namespace std;

int main()
{
    fstream outfile;
    outfile.open("app_text.txt", ios::out | ios::app);

    if (outfile.fail())
    {
        cout << "File gagal dibuka..!";
    }
    else
    {
        string str;
        cout << "Enter your name : ";
        getline(cin, str);
        outfile << str << endl;
    }
    outfile.close(); // Menutup outfile
}