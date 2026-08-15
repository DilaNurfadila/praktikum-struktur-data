#include <iostream> // header untuk mendefinisikan input dan output pada console
#include <fstream>  // header untuk mendefinisikan input dan output pada file
#include <cstring>
#include <iomanip>
// ====================
#include <termios.h> // header untuk mendefinisikan terminal I/O
#include <unistd.h>  // header untuk mendefinisikan konstanta dan tipe simbolik standar
// ====================

// Membuat variable global
#define aktif 1 // define aktif dengan 1
#define pasif 0 // define pasif dengan 0

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

/* Membuat tipe data baru dengan nama Nilai yang memiliki 2 elemen yaitu UTS dan UAS dengan tipe data int */
struct Nilai
{
    int UTS;
    int UAS;
};

/* Membuat tipe data baru dengan nama MTK (Matakuliah) yang memiliki 4 elemen yaitu STD, ALG, PBO, dan WEB dengan tipe data Nilai yang merupakan tipe data struct */
struct MTK
{
    Nilai STD;
    Nilai ALG;
    Nilai PBO;
    Nilai WEB;
};

/* Membuat tipe data baru dengan nama MHS yang memiliki 3 elemen yaitu NAMA, TAG, dan NilMTK.
Elemen NAMA tipe datanya string
Elemen TAG tipe datanya boolean
Elemen NilMTK tipe datanya MTK yang merupakan tipe data struct
 */
struct MHS
{
    char NAMA[30];
    bool TAG;
    MTK NilMTK;
} mahasiswa;

// List all Mahasiswa
// Menampilkan nama mahasiswa dengan TAG aktif atau pasif yang diterapkan pada parameter flag
void DspAllMhs(char *namafile, bool flag)
{
    cout << "Nama & Nilai Mahasiswa : " << endl
         << endl;

    ifstream myfile;
    myfile.open(namafile);
    if (!myfile.is_open())
    {
        cout << "Error File...!" << endl;
    }
    else
    {
        while (myfile.read((char *)&mahasiswa, sizeof(mahasiswa)) && !myfile.eof())
        {
            if (mahasiswa.TAG == flag)
            {
                cout << mahasiswa.NAMA << endl;
                cout << "MTK\tUjian\tNilai" << endl;
                cout << "=======================" << endl;
                cout << "STD\tUTS\t" << mahasiswa.NilMTK.STD.UTS << endl;
                cout << "STD\tUAS\t" << mahasiswa.NilMTK.STD.UAS << endl;
                cout << "ALG\tUTS\t" << mahasiswa.NilMTK.ALG.UTS << endl;
                cout << "ALG\tUAS\t" << mahasiswa.NilMTK.ALG.UAS << endl;
                cout << "PBO\tUTS\t" << mahasiswa.NilMTK.PBO.UTS << endl;
                cout << "PBO\tUAS\t" << mahasiswa.NilMTK.PBO.UAS << endl;
                cout << "WEB\tUTS\t" << mahasiswa.NilMTK.WEB.UTS << endl;
                cout << "WEB\tUAS\t" << mahasiswa.NilMTK.WEB.UAS << endl
                     << endl;
            }
        }
    }
    myfile.close();
}

// Append Mahasiswa
// Menambah mahasiswa
void AppendMhs(char *namafile)
{
    string inp; // deklarasi variable nama dengan tipe data string
    system("cls");

    cout << "Penambahan Mahasiswa" << endl; // display label untuk input nama
    cout << "====================" << endl;
    cout << "Nama : ";
    fflush(stdin);
    getline(cin, inp); // input nama, kemudian hasil inputnya di-assign ke variable nama
    strcpy(mahasiswa.NAMA, inp.c_str());
    // assign TAG dengan aktif / 1
    mahasiswa.TAG = aktif;

    // assign semua nilai menjadi 0
    mahasiswa.NilMTK.ALG.UTS = 0;
    mahasiswa.NilMTK.ALG.UAS = 0;
    mahasiswa.NilMTK.PBO.UTS = 0;
    mahasiswa.NilMTK.PBO.UAS = 0;
    mahasiswa.NilMTK.STD.UTS = 0;
    mahasiswa.NilMTK.STD.UAS = 0;
    mahasiswa.NilMTK.WEB.UTS = 0;
    mahasiswa.NilMTK.WEB.UAS = 0;

    fstream myfile;
    myfile.open(namafile, ios::app);
    if (!myfile.is_open())
    {
        cout << "Error File...!";
    }
    else
    {
        myfile.write((char *)&mahasiswa, sizeof(mahasiswa));
    }
    myfile.close();
}

/* Fungsi searching (mencari) mahasiswa */
long SearchMhs(char *namafile, bool flag)
{
    long pos = -1;
    string inp;
    cout << "Nama Mahasiswa : ";
    fflush(stdin);     // fflush
    getline(cin, inp); // input nama yang ingin dicari

    fstream myfile;
    myfile.open(namafile);
    if (!myfile.is_open())
    {
        cout << "File Error...!";
    }
    else
    {
        while (myfile.read((char *)&mahasiswa, sizeof(mahasiswa)) && !myfile.eof() && strcmp(mahasiswa.NAMA, inp.c_str()))
            ;
        if (!myfile.eof() && mahasiswa.TAG == flag)
        {
            pos = myfile.tellp();
        }
        else
        {
            cout << "Data tidak ditemukan" << endl;
        }
    }
    myfile.close();
    return pos;
}

void UbahTAGMhs(char *namafile, long pos, bool flag)
{
    fstream myfile;
    myfile.open(namafile);
    if (!myfile)
    {
        cout << "File Error...!";
    }
    else
    {
        mahasiswa.TAG = flag;
        myfile.seekp(pos - sizeof(mahasiswa));
        myfile.write((char *)&mahasiswa, sizeof(mahasiswa));
    }
    myfile.close();
}

void UpdNamaMhs(char *namafile, long pos)
{
    string inp;
    fstream myfile;
    myfile.open(namafile);
    if (!myfile)
    {
        cout << "File Error...!";
    }
    else
    {
        cout << "Nama Baru : ";
        fflush(stdin);
        getline(cin, inp);
        strcpy(mahasiswa.NAMA, inp.c_str());

        myfile.seekp(pos - sizeof(mahasiswa));
        myfile.write((char *)&mahasiswa, sizeof(mahasiswa));
        cout << endl
             << "Nama sudah diubah" << endl;
    }
    myfile.close();
}

// Ubah nilai
void UpdNilaiMhs(char *namafile, long pos)
{
    string inp;
    fstream myfile;
    myfile.open(namafile);
    if (!myfile)
    {
        cout << "File Error...!";
    }
    else
    {
        string nil;

        cout << endl
             << "Just leave blank if no change.." << endl;
        cout << endl
             << "Ubah Nilai : " << endl;

        cout << "STD, UTS : " << mahasiswa.NilMTK.STD.UTS << " menjadi : ";
        fflush(stdin);
        getline(cin, nil); // input nilai untuk STD, UTS
        // Jika nilai tidak kosong dan nilai lebih dari 0 dan nilai kurang dari sama dengan 100 maka nilai tetap yang sebelumnya
        if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
        {
            mahasiswa.NilMTK.STD.UTS = stoi(nil);
        }

        cout << "STD, UAS : " << mahasiswa.NilMTK.STD.UAS << " menjadi : ";
        fflush(stdin);
        getline(cin, nil); // input nilai untuk STD, UAS
        if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
        {
            mahasiswa.NilMTK.STD.UAS = stoi(nil);
        }

        cout << "ALG, UTS : " << mahasiswa.NilMTK.ALG.UTS << " menjadi : ";
        fflush(stdin);
        getline(cin, nil); // input nilai untuk ALG, UTS
        if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
        {
            mahasiswa.NilMTK.ALG.UTS = stoi(nil);
        }

        cout << "ALG, UAS : " << mahasiswa.NilMTK.ALG.UAS << " menjadi : ";
        fflush(stdin);
        getline(cin, nil); // input nilai untuk ALG, UAS
        if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
        {
            mahasiswa.NilMTK.ALG.UAS = stoi(nil);
        }

        cout << "PBO, UTS : " << mahasiswa.NilMTK.PBO.UTS << " menjadi : ";
        fflush(stdin);
        getline(cin, nil); // input nilai untuk PBO, UTS
        if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
        {
            mahasiswa.NilMTK.PBO.UTS = stoi(nil);
        }

        cout << "PBO, UAS : " << mahasiswa.NilMTK.PBO.UAS << " menjadi : ";
        fflush(stdin);
        getline(cin, nil); // input nilai untuk PBO, UAS
        if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
        {
            mahasiswa.NilMTK.PBO.UAS = stoi(nil);
        }

        cout << "WEB, UTS : " << mahasiswa.NilMTK.WEB.UTS << " menjadi : ";
        fflush(stdin);
        getline(cin, nil); // input nilai untuk WEB, UTS
        if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
        {
            mahasiswa.NilMTK.WEB.UTS = stoi(nil);
        }

        cout << "WEB, UAS : " << mahasiswa.NilMTK.WEB.UAS << " menjadi : ";
        fflush(stdin);
        getline(cin, nil); // input nilai untuk WEB, UAS
        if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
        {
            mahasiswa.NilMTK.WEB.UAS = stoi(nil);
        }

        myfile.seekp(pos - sizeof(mahasiswa));
        myfile.write((char *)&mahasiswa, sizeof(mahasiswa));
        cout << endl
             << "Nilai sudah diubah" << endl;
    }
}

int main()
{
    char *namafile = "data_biner_mhs.dat";
    char Pilih;       // Deklarasi variable Pilih dengan tipe data char
    bool loop = true; // Deklarasi variable loop dengan tipe data boolen dan memiliki value true

    do
    {                    // display menu
        system("clear"); // Membersihkan atau menghapus tampilan dari terminal
        cout << endl;
        cout << "   Menu" << endl;
        cout << "   ====" << endl;
        cout << "esc. Exit" << endl;
        cout << "   Data MHS" << endl;
        cout << "   ====" << endl;
        cout << "1. Lst MHS" << endl;
        cout << "2. Add MHS" << endl;
        cout << "3. Upd MHS" << endl;
        cout << "4. Del MHS" << endl;
        cout << "5. Show Deleted" << endl;
        cout << "6. Undelete" << endl;
        cout << "   Data Nilai MTK MHS" << endl;
        cout << "   ==================" << endl;
        cout << "7. Ubah Nilai MHS" << endl;
        cout << "Pilih : ";
        Pilih = getch(); // input tanpa buffer, artinya kita tidak perlu menekan enter setelah memilih menu
        system("clear"); // Membersihkan atau menghapus tampilan dari terminal

        switch (Pilih) // Percabangan yang diambil dari variable Pilih
        {
        case 27: // Jika user memilih escape
        {
            loop = false; // Maka ubah value loop menjadi false dan program akan keluar
            break;        // Keluar dari case
        }

        case '1': // Jika user memilih karakter 1
        {
            // Maka tampilkan daftar mahasiswa
            DspAllMhs(namafile, aktif); // Menampilkan mahasiswa dengan TAG aktif atau 1
            pause();                    // Jeda sebelum kembali ke menu awal
            break;                      // Keluar dari case
        }

        case '2':
        {
            AppendMhs(namafile);                          // Memanggil fungsi untuk menambahkan mahasiswa
            cout << mahasiswa.NAMA << ".. Added" << endl; // Label yang menunjukan mahasiswa telah ditambahkan
            pause();                                      // Jeda sebelum kembali ke menu awal
            break;                                        // Keluar dari case
        }

        case '3':
        {
            long X = SearchMhs(namafile, aktif); // Memanggil fungsi searching mahasiswa yang memiliki TAG aktif di-assign ke variable X dengan tipe data int
            if (X >= 0)                          // Jika X lebih dari sama dengan 0
            {
                UpdNamaMhs(namafile, X);
            }
            pause(); // Jeda sebelum kembali ke menu awal
            break;   // Keluar dari case
        }

        case '4':
        {
            cout << "Delete MHS" << endl;        // Label hapus mahasiswa
            long X = SearchMhs(namafile, aktif); // Memanggil fungsi searching mahasiswa yang memiliki TAG aktif di-assign ke variable X dengan tipe data int
            if (X >= 0)
            { // Jika X sama dengan -1
                cout << "Delete y/n : ";
                if (getch() == 'y')
                {
                    UbahTAGMhs(namafile, X, pasif);
                    cout << endl
                         << mahasiswa.NAMA << "..Deleted..";
                }
            }
            pause(); // Jeda sebelum kembali ke menu awal
            break;   // Keluar dari case
        }

        case '5':
        {
            cout << "Deleted" << endl; // Label
            cout << "==========" << endl;
            DspAllMhs(namafile, pasif); // Memanggil fungsi daftar mahasiswa dengan TAG pasif atau 0
            pause();                    // Jeda sebelum kembali ke menu awal
            break;                      // Keluar dari case
        }

        case '6':
        {
            cout << "UnDelete MHS" << endl;      // Label
            long X = SearchMhs(namafile, pasif); // Memanggil fungsi searching mahasiswa yang memiliki TAG pasif di-assign ke variable X dengan tipe data int
            if (X >= 0)
            { // Jika X sama dengan -1
                cout << "UnDelete y/n : ";
                if (getch() == 'y')
                {
                    UbahTAGMhs(namafile, X, aktif);
                    cout << endl
                         << mahasiswa.NAMA << "..Recovered..";
                }
            }
            pause(); // Jeda sebelum kembali ke menu awal
            break;   // Keluar dari case
        }

        case '7':
        {
            cout << "Ubah Nilai MHS" << endl;    // Label
            long X = SearchMhs(namafile, aktif); // Memanggil fungsi searching mahasiswa yang memiliki TAG aktif di-assign ke variable X dengan tipe data int
            if (X >= 0)                          // Jika X lebih dari sama dengan 0
            {
                UpdNilaiMhs(namafile, X); // Memanggil fungsi untuk menampilkan nilai ujian mahasiswa
            }
            pause(); // Jeda sebelum kembali ke menu awal
            break;   // Keluar dari case
        }

        default:   // Jika user memilih yang tidak ada case di atas
            break; // Maka keluar dari case
        }
        cout << endl;
    } while (loop); // Ulangi selama loop = true
}