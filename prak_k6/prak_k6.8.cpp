#include <iostream> // header untuk mendefinisikan input dan output pada console
#include <fstream>  // header untuk mendefinisikan input dan output pada file

// Baris ini digunakan supaya kita tidak perlu menuliskan berulang kata std di setiap perintah I/O
using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("out_text.txt");

    outfile << "This is a first line.." << endl;
    outfile << "This is another line.." << endl;

    cout << "Line is written to file" << endl;

    outfile.close(); // Menutup outfile
}