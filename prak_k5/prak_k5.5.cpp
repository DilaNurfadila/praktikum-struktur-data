#include <iostream>
// ====================
// Header untuk membuat fungsi getch
#include <termios.h>
#include <unistd.h>
// ====================
using namespace std;

// ======================================================
// Membuat fungsi getch karena header conio.h tidak support untuk linux
/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}
// ======================================================

// Membuat struct
struct Date
{
    int dd;
    int mm;
    int yyyy;
};

struct Time
{
    int h;
    int m;
    int s;
};

// Membuat nested struct (struct di dalam struct)
struct Login
{
    int ID;
    Date tglLogin;
    Time waktuLogin;
};

int main()
{
    int X;                                   // Digunakan untuk mencari ID
    bool data;                               // Digunakan untuk validasi
    Login user[3];                           // Membuat beberapa user dengan array
    int sz = sizeof(user) / sizeof(user[0]); // Untuk mengetahui ukuran dari array

    // Mengisi value dari struct sebanyak 3 user
    for (int i = 0; i < 3; i++)
    {
        cout << "USER ke-" << i + 1 << endl;
        cout << "ID : ";
        cin >> user[i].ID;
        cout << "Tanggal Login\n";
        cout << "Hari : ";
        cin >> user[i].tglLogin.dd;
        cout << "Bulan : ";
        cin >> user[i].tglLogin.mm;
        cout << "Tahun : ";
        cin >> user[i].tglLogin.yyyy;
        cout << "Waktu Login\n";
        cout << "Jam : ";
        cin >> user[i].waktuLogin.h;
        cout << "Menit : ";
        cin >> user[i].waktuLogin.m;
        cout << "Detik : ";
        cin >> user[i].waktuLogin.s;
        cout << "\nTerima kasih Atas Pengisiannya\n";
    }
    bool Loop = true;
    while (Loop)
    {
        cout << "Masukan nilai X : ";
        cin >> X;
        // Cek jika yang dimasukan adalah ID atau selain angka, jika ternyata bukan ID maka ubah Loop menjadi false dan program akan keluar
        if (!cin)
        {
            Loop = false;
        }
        // Jika ternyata merupakan ID, maka lanjut cek lagi
        else
        {
            for (int N = 0; N < sz; N++)
            {
                // Cek apakah ID ada dalam array, jika ada maka tampilkan datanya
                if (user[N].ID == X)
                {

                    cout << "Login ID : " << user[N].ID << endl;
                    cout << "Login Date : " << user[N].tglLogin.dd << " - " << user[N].tglLogin.mm << " - " << user[N].tglLogin.yyyy << endl;
                    cout << "Login Time : " << user[N].waktuLogin.h << ":" << user[N].waktuLogin.m << ":" << user[N].waktuLogin.s << endl
                         << endl;
                    data = true;
                    break;
                }
                // Jika ID tidak ada di dalam array maka ubah bool data menjadi false
                else if (user[N].ID != X)
                {
                    data = false;
                }
            }
            // Cek apakah bool data adalah false, jika iya maka tampilkan tulisan "tidak ada"
            if (data == false)
            {
                cout << "Tidak ada" << endl;
            }
        }
    }
    getch();
}