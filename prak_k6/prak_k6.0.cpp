#include <iostream> // header untuk mendefinisikan input dan output
// ====================
#include <termios.h> // header untuk mendefinisikan terminal I/O
#include <unistd.h>  // header untuk mendefinisikan konstanta dan tipe simbolik standar
// ====================

// Membuat variable global
#define JMHSMAX 30 // define JMHSMAX dengan 30
#define aktif 1    // define aktif dengan 1
#define pasif 0    // define pasif dengan 0

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
    string NAMA;
    bool TAG;
    MTK NilMTK;
};
int JmlActualMhs = 3; // Menyimpan 3 mahasiswa dalam memori
MHS Mhsw[JMHSMAX];    // Deklarasi array mahasiswa untuk menampung 30 data

// List all Mahasiswa
// Menampilkan nama mahasiswa dengan TAG aktif atau pasif yang diterapkan pada parameter flag
void LstMhs(bool flag)
{
    for (int i = 0; i < JmlActualMhs; i++) // Menelusuri data dalam Mhsw
    {
        if (Mhsw[i].TAG == flag) // Jika Mhsw ke i TAG nya sama dengan flag (berdasarkan argumen yang diisi)
        {
            cout << Mhsw[i].NAMA << endl; // Maka tampilkan namanya
        }
    }
}

// Append Mahasiswa
// Menambah mahasiswa
void AppMhs()
{
    string nama; // deklarasi variable nama dengan tipe data string
    cout << endl
         << "Tambah MHS.. Nama : "; // display label untuk input nama
    fflush(stdin);
    getline(cin, nama); // input nama, kemudian hasil inputnya di-assign ke variable nama
    // assign NAMA dengan nama yang sudah diinput
    // assign TAG dengan aktif / 1
    Mhsw[JmlActualMhs].NAMA = nama;
    Mhsw[JmlActualMhs].TAG = aktif;

    // assign semua nilai menjadi 0
    Mhsw[JmlActualMhs].NilMTK.ALG.UTS = 0;
    Mhsw[JmlActualMhs].NilMTK.ALG.UAS = 0;
    Mhsw[JmlActualMhs].NilMTK.PBO.UTS = 0;
    Mhsw[JmlActualMhs].NilMTK.PBO.UAS = 0;
    Mhsw[JmlActualMhs].NilMTK.STD.UTS = 0;
    Mhsw[JmlActualMhs].NilMTK.STD.UAS = 0;
    Mhsw[JmlActualMhs].NilMTK.WEB.UTS = 0;
    Mhsw[JmlActualMhs].NilMTK.WEB.UAS = 0;

    JmlActualMhs++; // Jumlah aktual mahasiswa bertambah 1
}

/* Fungsi searching (mencari) mahasiswa */
int SrcMhs(int JumMhs, bool flag)
{
    string Nma;
    cout << endl
         << "Nama : ";
    fflush(stdin);     // fflush
    getline(cin, Nma); // input nama yang ingin dicari

    while (JumMhs >= 0 && Mhsw[--JumMhs].NAMA != Nma)
        ;                         // Selama belum ditemukan
    if (Mhsw[JumMhs].TAG == flag) // jika TAG sama dengan flag (berdasarkan argumen yang diisi)
        return JumMhs;            // Decriment index
    else
        return -1; // jika tidak maka return -1 atau tidak menampilkan namanya
}

// Menentukan nilai akhir
string NilAkhir(int akhir) // Fungsi untuk menentukan nilai akhir
{
    // Jika nilai akhir (nilai rata-rata) lebih dari sama dengan 85 dan kurang dari sama dengan 100
    if (akhir >= 85 && akhir <= 100)
    {
        return "A"; // Maka tampilkan nilai A
    }
    // Jika nilai akhir (nilai rata-rata) lebih dari sama dengan 70 dan kurang dari 85
    else if (akhir >= 70 && akhir < 85)
    {
        return "B"; // Maka tampilkan nilai B
    }
    // Jika nilai akhir (nilai rata-rata) lebih dari sama dengan 55 dan kurang dari 70
    else if (akhir >= 55 && akhir < 70)
    {
        return "C"; // Maka tampilkan nilai C
    }
    // Jika nilai akhir (nilai rata-rata) lebih dari sama dengan 40 dan kurang dari 55
    else if (akhir >= 40 && akhir < 55)
    {
        return "D"; // Maka tampilkan nilai D
    }
    // Jika nilai akhir (nilai rata-rata) kurang dari 40
    else if (akhir < 40)
    {
        return "E"; // Maka tampilkan nilai E
    }
}

// List nilai mahasiswa
void ListNilaiMhs(int i)
{
    // Akumulasi nilai rata-rata untuk menentukan nilai akhir
    int NilAkhirSTD = (Mhsw[i].NilMTK.STD.UTS + Mhsw[i].NilMTK.STD.UAS) / 2;
    int NilAkhirALG = (Mhsw[i].NilMTK.ALG.UTS + Mhsw[i].NilMTK.ALG.UAS) / 2;
    int NilAkhirPBO = (Mhsw[i].NilMTK.PBO.UTS + Mhsw[i].NilMTK.PBO.UAS) / 2;
    int NilAkhirWEB = (Mhsw[i].NilMTK.WEB.UTS + Mhsw[i].NilMTK.WEB.UAS) / 2;

    cout << endl
         << "STD, UTS : " << Mhsw[i].NilMTK.STD.UTS; // Menampilkan nilai STD, UTS
    cout << endl
         << "STD, UAS : " << Mhsw[i].NilMTK.STD.UAS << endl; // Manampilkan nilai STD, UAS
    cout << "STD, AKHIR : " << NilAkhir(NilAkhirSTD);        // Menghitung nilai akhir dari rata-rata UTS dan UAS
    cout << endl
         << endl
         << "ALG, UTS : " << Mhsw[i].NilMTK.ALG.UTS; // Menampilkan nilai ALG, UTS
    cout << endl
         << "ALG, UAS : " << Mhsw[i].NilMTK.ALG.UAS << endl; // Manampilkan nilai ALG, UAS
    cout << "ALG, AKHIR : " << NilAkhir(NilAkhirALG);        // Menghitung nilai akhir dari rata-rata UTS dan UAS
    cout << endl
         << endl
         << "PBO, UTS : " << Mhsw[i].NilMTK.PBO.UTS; // Menampilkan nilai PBO, UTS
    cout << endl
         << "PBO, UAS : " << Mhsw[i].NilMTK.PBO.UAS << endl; // Manampilkan nilai PBO, UAS
    cout << "PBO, AKHIR : " << NilAkhir(NilAkhirPBO);        // Menghitung nilai akhir dari rata-rata UTS dan UAS
    cout << endl
         << endl
         << "WEB, UTS : " << Mhsw[i].NilMTK.WEB.UTS; // Menampilkan nilai WEB, UTS
    cout << endl
         << "WEB, UAS : " << Mhsw[i].NilMTK.WEB.UAS << endl; // Manampilkan nilai WEB, UAS
    cout << "WEB, AKHIR : " << NilAkhir(NilAkhirWEB);        // Menghitung nilai akhir dari rata-rata UTS dan UAS
    cout << endl;
}

// Ubah nilai
void UpdNilaiMhs(int MhsKe)
{
    string nil; // Deklarasi variable nil dengan tipe data string

    cout << endl
         << "Just leave blank if no change.." << endl;
    cout << endl
         << "Ubah Nilai : " << endl;

    cout << "STD, UTS : " << Mhsw[MhsKe].NilMTK.STD.UTS << " menjadi : ";
    fflush(stdin);
    getline(cin, nil); // input nilai untuk STD, UTS
    // Jika nilai tidak kosong dan nilai lebih dari 0 dan nilai kurang dari sama dengan 100 maka nilai tetap yang sebelumnya
    if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
    {
        Mhsw[MhsKe].NilMTK.STD.UTS = stoi(nil);
    }

    cout << "STD, UAS : " << Mhsw[MhsKe].NilMTK.STD.UAS << " menjadi : ";
    fflush(stdin);
    getline(cin, nil); // input nilai untuk STD, UAS
    if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
    {
        Mhsw[MhsKe].NilMTK.STD.UAS = stoi(nil);
    }

    cout << "ALG, UTS : " << Mhsw[MhsKe].NilMTK.ALG.UTS << " menjadi : ";
    fflush(stdin);
    getline(cin, nil); // input nilai untuk ALG, UTS
    if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
    {
        Mhsw[MhsKe].NilMTK.ALG.UTS = stoi(nil);
    }

    cout << "ALG, UAS : " << Mhsw[MhsKe].NilMTK.ALG.UAS << " menjadi : ";
    fflush(stdin);
    getline(cin, nil); // input nilai untuk ALG, UAS
    if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
    {
        Mhsw[MhsKe].NilMTK.ALG.UAS = stoi(nil);
    }

    cout << "PBO, UTS : " << Mhsw[MhsKe].NilMTK.PBO.UTS << " menjadi : ";
    fflush(stdin);
    getline(cin, nil); // input nilai untuk PBO, UTS
    if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
    {
        Mhsw[MhsKe].NilMTK.PBO.UTS = stoi(nil);
    }

    cout << "PBO, UAS : " << Mhsw[MhsKe].NilMTK.PBO.UAS << " menjadi : ";
    fflush(stdin);
    getline(cin, nil); // input nilai untuk PBO, UAS
    if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
    {
        Mhsw[MhsKe].NilMTK.PBO.UAS = stoi(nil);
    }

    cout << "WEB, UTS : " << Mhsw[MhsKe].NilMTK.WEB.UTS << " menjadi : ";
    fflush(stdin);
    getline(cin, nil); // input nilai untuk WEB, UTS
    if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
    {
        Mhsw[MhsKe].NilMTK.WEB.UTS = stoi(nil);
    }

    cout << "WEB, UAS : " << Mhsw[MhsKe].NilMTK.WEB.UAS << " menjadi : ";
    fflush(stdin);
    getline(cin, nil); // input nilai untuk WEB, UAS
    if (!nil.empty() && stoi(nil) > 0 && stoi(nil) <= 100)
    {
        Mhsw[MhsKe].NilMTK.WEB.UAS = stoi(nil);
    }
}

int main()
{
    char Pilih;       // Deklarasi variable Pilih dengan tipe data char
    bool loop = true; // Deklarasi variable loop dengan tipe data boolen dan memiliki value true

    // Nilai dari setiap matkul mahasiswa
    Mhsw[0].NAMA = "Nurfadila";
    Mhsw[0].NilMTK.STD.UTS = 50;
    Mhsw[0].NilMTK.STD.UAS = 69;
    Mhsw[0].NilMTK.ALG.UTS = 30;
    Mhsw[0].NilMTK.ALG.UAS = 67;
    Mhsw[0].NilMTK.PBO.UTS = 76;
    Mhsw[0].NilMTK.PBO.UAS = 67;
    Mhsw[0].NilMTK.WEB.UTS = 90;
    Mhsw[0].NilMTK.WEB.UAS = 45;
    // Bisa menggunakan true atau aktif, karena keduanya memiliki nilai yang sama yaitu 1
    // Mhsw[0].TAG = true;
    Mhsw[0].TAG = aktif;

    Mhsw[1].NAMA = "Indiyani Lestari";
    Mhsw[1].NilMTK.STD.UTS = 67;
    Mhsw[1].NilMTK.STD.UAS = 59;
    Mhsw[1].NilMTK.ALG.UTS = 30;
    Mhsw[1].NilMTK.ALG.UAS = 70;
    Mhsw[1].NilMTK.PBO.UTS = 55;
    Mhsw[1].NilMTK.PBO.UAS = 75;
    Mhsw[1].NilMTK.WEB.UTS = 66;
    Mhsw[1].NilMTK.WEB.UAS = 80;
    Mhsw[1].TAG = aktif;

    Mhsw[2].NAMA = "Bintang Rizqia";
    Mhsw[2].NilMTK.STD.UTS = 65;
    Mhsw[2].NilMTK.STD.UAS = 70;
    Mhsw[2].NilMTK.ALG.UTS = 40;
    Mhsw[2].NilMTK.ALG.UAS = 50;
    Mhsw[2].NilMTK.PBO.UTS = 80;
    Mhsw[2].NilMTK.PBO.UAS = 80;
    Mhsw[2].NilMTK.WEB.UTS = 70;
    Mhsw[2].NilMTK.WEB.UAS = 70;
    Mhsw[2].TAG = aktif;

    do
    {                    // display menu
        system("clear"); // Membersihkan atau menghapus tampilan dari terminal
        cout << endl;
        cout << "   Menu" << endl;
        cout << "   ====" << endl;
        cout << "0. Exit" << endl;
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
        cout << "7. Lihat Nilai MHS" << endl;
        cout << "8. Ubah Nilai MHS" << endl;
        cout << "Pilih : ";
        Pilih = getch(); // input tanpa buffer, artinya kita tidak perlu menekan enter setelah memilih menu
        system("clear"); // Membersihkan atau menghapus tampilan dari terminal

        switch (Pilih) // Percabangan yang diambil dari variable Pilih
        {
        case '0': // Jika user memilih karakter 0
        {
            loop = false; // Maka ubah value loop menjadi false dan program akan keluar
            break;        // Keluar dari case
        }

        case '1': // Jika user memilih karakter 1
        {
            // Maka tampilkan daftar mahasiswa
            cout << "Daftar MHS" << endl;
            cout << "==========" << endl;
            LstMhs(aktif); // Menampilkan mahasiswa dengan TAG aktif atau 1
            pause();       // Jeda sebelum kembali ke menu awal
            break;         // Keluar dari case
        }

        case '2':
        {
            AppMhs();                                                  // Memanggil fungsi untuk menambahkan mahasiswa
            cout << Mhsw[JmlActualMhs - 1].NAMA << ".. Added" << endl; // Label yang menunjukan mahasiswa telah ditambahkan
            pause();                                                   // Jeda sebelum kembali ke menu awal
            break;                                                     // Keluar dari case
        }

        case '3':
        {
            int X = SrcMhs(JmlActualMhs, aktif); // Memanggil fungsi searching mahasiswa yang memiliki TAG aktif di-assign ke variable X dengan tipe data int
            if (X >= 0)                          // Jika X lebih dari sama dengan 0
            {
                cout << "Ubah Nama : " << Mhsw[X].NAMA << " ..menjadi : "; // Maka ubah nama mahasiswa yang sebelumnya
                fflush(stdin);
                getline(cin, Mhsw[X].NAMA); // Input nama baru mahasiswa
                cout << endl
                     << "Nama Updated.." << endl;
            }
            else                               // Jika X kurang dari 0
                cout << " Tdk Ada.. " << endl; // Maka tampilkan tulisan "Tdk Ada"
            pause();                           // Jeda sebelum kembali ke menu awal
            break;                             // Keluar dari case
        }

        case '4':
        {
            cout << "Delete MHS" << endl;        // Label hapus mahasiswa
            int X = SrcMhs(JmlActualMhs, aktif); // Memanggil fungsi searching mahasiswa yang memiliki TAG aktif di-assign ke variable X dengan tipe data int
            if (X == -1)                         // Jika X sama dengan -1
                cout << " Tdk Ada.. " << endl;   // Maka tampilkan tulisan "Tdk Ada"
            else                                 // Jika tidak
            {
                cout << "Delete Nama : " << Mhsw[X].NAMA << " y/n : "; // Maka isi nama mahasiswa yang ingin dihapus
                // Konfirmasi apakah yakin nama mahasiswa tersebut ingin dihapus
                if (getch() == 'y') // Jika user menekan tombol 'y'
                {
                    Mhsw[X].TAG = pasif; // Maka ubah TAG mahasiswa dengan pasif atau 0
                    cout << endl
                         << Mhsw[X].NAMA << " ..Deleted.." << endl; // Nama mahasiswa telah dihapus
                }
            }
            pause(); // Jeda sebelum kembali ke menu awal
            break;   // Keluar dari case
        }

        case '5':
        {
            cout << "Deleted" << endl; // Label
            cout << "==========" << endl;
            LstMhs(pasif); // Memanggil fungsi daftar mahasiswa dengan TAG pasif atau 0
            pause();       // Jeda sebelum kembali ke menu awal
            break;         // Keluar dari case
        }

        case '6':
        {
            cout << "UnDelete MHS" << endl;      // Label
            int X = SrcMhs(JmlActualMhs, pasif); // Memanggil fungsi searching mahasiswa yang memiliki TAG pasif di-assign ke variable X dengan tipe data int
            if (X == -1)                         // Jika X sama dengan -1
                cout << " Tdk Ada.. " << endl;   // Maka tampilkan tulisan "Tdk Ada"
            else                                 // Jika tidak
            {
                cout << "UnDelete Nama : " << Mhsw[X].NAMA << " y/n : "; // Maka user mengisikan nama mahasiswa yang ingin di-Undelete
                if (getch() == 'y')                                      // Jika user menekan tombol 'y'
                {
                    Mhsw[X].TAG = aktif; // Maka ubah TAG mahasiswa dengan aktif atau 1
                    cout << endl
                         << Mhsw[X].NAMA << " ..UnDeleted.." << endl; // Nama mahasiswa telah di-Undelete
                }
            }
            pause(); // Jeda sebelum kembali ke menu awal
            break;   // Keluar dari case
        }

        case '7':
        {
            cout << "Lihat Nilai MHS" << endl;   // Label
            int X = SrcMhs(JmlActualMhs, aktif); // Memanggil fungsi searching mahasiswa yang memiliki TAG aktif di-assign ke variable X dengan tipe data int
            if (X >= 0)                          // Jika X lebih dari sama dengan 0
            {
                // Maka tampilkan nama dan nilai mahasiswa
                cout << "Nilai MTK : " << Mhsw[X].NAMA;
                ListNilaiMhs(X); // Memanggil fungsi untuk menampilkan nilai ujian mahasiswa
            }
            else                               // Jika tidak
                cout << " Tdk Ada.. " << endl; // Maka tampilkan tulisan "Tdk Ada"
            pause();                           // Jeda sebelum kembali ke menu awal
            break;                             // Keluar dari case
        }

        case '8':
        {
            cout << "Ubah Nilai MHS" << endl;    // Label
            int X = SrcMhs(JmlActualMhs, aktif); // Memanggil fungsi searching mahasiswa yang memiliki TAG aktif di-assign ke variable X dengan tipe data int
            if (X == -1)                         // Jika X sama dengan -1
                cout << " Tdk Ada.. " << endl;   // Maka tampilkan tulisan "Tdk Ada"
            else                                 // Jika tidak
                UpdNilaiMhs(X);                  // Maka panggil fungsi ini untuk ubah nilai ujian mahasiswa
            pause();
            break;
        }

        default:   // Jika user memilih yang tidak ada case di atas
            break; // Maka keluar dari case
        }
        cout << endl;
    } while (loop); // Ulangi selama loop = true
}