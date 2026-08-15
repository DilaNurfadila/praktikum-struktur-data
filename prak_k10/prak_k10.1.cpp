#include <iostream> // header untuk mendefinisikan input dan output dalam console
// ====================
#include <termios.h> // header untuk mendefinisikan terminal I/O
#include <unistd.h>  // header untuk mendefinisikan konstanta dan tipe simbolik standar
// ====================

// Baris ini digunakan supaya kita tidak perlu menuliskan berulang kata std di setiap perintah I/O
using namespace std;

// ======================================================
/* reads from keypress, doesn't echo */
// Karena di linux tidak ada header <conio.h>, maka diganti dengan baris perintah berikut untuk menggunakan fungsi _getch() pada header <conio.h>
// Fungsi getch digunakan untuk membaca input satu karakter tanpa menekan tombol enter
int getch(void)
{
    struct termios oldattr, newattr;   // deklarasi 2 variable dengan tipe termios
    int ch;                            // deklarasi untuk membaca karakter
    tcgetattr(STDIN_FILENO, &oldattr); // mengambil atribut dari terminal yang kemudian disimpan ke address oldattr
    newattr = oldattr;                 // pengaturan terminal yang lama disalin ke variable newattr

    newattr.c_lflag &= ~(ICANON | ECHO); // mematikan mode canonical dan mode echo
    /* ICANON merupakan parameter yang menentukan apakah inputan dari user harus disimpan dalam buffer atau tidak.

    ECHO merupakan parameter yang menentukan apakah inputan dari user akan ditampilkan di layar atau tidak */

    tcsetattr(STDIN_FILENO, TCSANOW, &newattr); // menerapkan perubahan pengaturan terminal
    ch = getchar();                             // membaca inputan satu karakter yang kemudian disimpan dalam variable ch
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); // mengembalikan terminal ke pengaturan awal
    return ch;                                  // return nilai ch ke fungsi getch
}

// Karena di linux tidak ada perintah pause, maka digantikan dengan perintah read pada bash scripting
int pause(void)
{
    /* Perintah read digunakan untuk membaca sebuah FD (File Descriptor)
    Parameter -p digunakan untuk menampilkan pesan yang diikuti isi pesan yang ingin ditampilkan
    Perintah \e digunakan untuk escape */
    system("read -p 'Press any key to continue...' \e");
    return 0;
}
// ======================================================

// Fungsi untuk menghitung faktorial dengan loop
int factorial(int n)
{
    int out = n;
    for (int i = n - 1; i > 0; i--)
    {
        out = out * i;
    }
    return out;
}

// Fungsi untuk menghitung faktorial dengan rekursif
int factorialRec(int n)
{
    if (n == 1)
        return 1;
    else
        return (n * factorialRec(n - 1));
}

// Fungsi untuk mencari FPB dengan loop
int fpb(int x, int y)
{
    int z = x % y;
    while (z != 0)
    {
        x = y;
        y = z;
        z = x % y;
    }
    return y;
}

// Fungsi untuk mencari FPB dengan rekursif
int fpbRec(int x, int y)
{
    if (y == 0)
        return (x);
    else
        return fpbRec(y, x % y);
}

// Fungsi untuk menghitung fibbonaci dengan loop
int fib(int n)
{
    int a = 1, b = 1, c = 0;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Fungsi untuk menghitung fibbonaci dengan rekursif
int fibRec(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return (fibRec(n - 1) + fibRec(n - 2));
}

// Fungsi untuk menghitung pangkat dengan loop
int nPower(int x, int y)
{
    int total = 1;
    for (int i = 1; i <= y; i++)
    {
        total *= x;
    }
    return total;
}

// Fungsi untuk menghitung pangkat dengan rekursif
int nPowerRec(int x, int y)
{
    if (y == 1)
    {
        return (x);
    }
    else
    {
        return (x * nPowerRec(x, y - 1));
    }
}

// Fungsi untuk menghitung jumlah dengan loop
int sum(int n)
{
    int out = n;
    for (int i = n - 1; i > 0; i--)
    {
        out = out + i;
    }
    return out;
}

// Fungsi untuk menghitung jumlah dengan rekursif
int sumRec(int n)
{
    if (n == 0)
        return 0;
    else
        return n + sumRec(n - 1);
}

int main()
{
    // deklarasi
    int inp, x, y;
    bool loop = true;

    // show menu
    do
    {
        system("clear");
        cout << endl;
        cout << "1. FactRec" << endl;
        cout << "2. FactLoop" << endl;
        cout << "3. FPBRec" << endl;
        cout << "4. FPBLoop" << endl;
        cout << "5. FiboRec" << endl;
        cout << "6. FiboLoop" << endl;
        cout << "7. PowerLoop" << endl;
        cout << "8. PowerRec" << endl;
        cout << "9. SumRec" << endl;
        cout << "0. SumLoop" << endl;
        cout << "esc. Exit" << endl
             << endl;
        cout << "Pilihan : " << endl;

        // Percabangan
        switch (getch())
        {
        case 27:
        {
            loop = false;
            cout << "next..by";
            break;
        }
        case '1':
        {
            cout << "FactLoop(n)" << endl;
            cout << "n = ";
            cin >> inp;
            cout << factorial(inp);
            break;
        }
        case '2':
        {
            cout << "FactRec(n)" << endl;
            cout << "n = ";
            cin >> inp;
            cout << factorialRec(inp);
            break;
        }
        case '3':
        {
            cout << "FPBRec(x, y)" << endl;
            cout << "x = ";
            cin >> x;
            cout << "y = ";
            cin >> y;
            cout << fpbRec(x, y);
            break;
        }
        case '4':
        {
            cout << "FPBLoop(x, y)" << endl;
            cout << "x = ";
            cin >> x;
            cout << "y = ";
            cin >> y;
            cout << fpb(x, y);
            break;
        }
        case '5':
        {
            cout << "FiboRec(n)" << endl;
            cout << "n = ";
            cin >> inp;
            cout << fibRec(inp);
            break;
        }
        case '6':
        {
            cout << "FiboLoop(n)" << endl;
            cout << "n = ";
            cin >> inp;
            cout << fib(inp);
            break;
        }
        case '7':
        {
            cout << "nPKLoop(x, y)" << endl;
            cout << "x = ";
            cin >> x;
            cout << "y = ";
            cin >> y;
            cout << nPower(x, y);
            break;
        }
        case '8':
        {
            cout << "nPKRec(x, y)" << endl;
            cout << "x = ";
            cin >> x;
            cout << "y = ";
            cin >> y;
            cout << nPowerRec(x, y);
            break;
        }
        case '9':
        {
            cout << "SumRec(n)" << endl;
            cout << "n = ";
            cin >> inp;
            cout << sumRec(inp);
            break;
        }
        case '0':
        {
            cout << "SumLoop(n)" << endl;
            cout << "n = ";
            cin >> inp;
            cout << sum(inp);
        }
        break;
        }
        cout << endl;
        pause();
    } while (loop);
}