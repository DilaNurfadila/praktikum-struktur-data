#include <iostream>
// ====================
// Header untuk membuat fungsi getch
#include <termios.h>
#include <unistd.h>
// ====================

#define JMHS 30
#define JMTK 4
#define JNIL 2

#define NAMA 0
#define STTS 1

#define UTS 0
#define UAS 1

#define STD 0
#define ALG 1
#define PBO 2
#define WEB 3

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
/* reads from keypress, echoes */
// int getche(void)
// {
//     struct termios oldattr, newattr;
//     int ch;
//     tcgetattr(STDIN_FILENO, &oldattr);
//     newattr = oldattr;
//     newattr.c_lflag &= ~(ICANON);
//     tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
//     ch = getchar();
//     tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
//     return ch;
// }

// Membuat fungsi pause, karena di terminal linux tidak ada perintah pause
int pause(void)
{
    // Untuk pause menggunakan perintah read yang ada di terminal
    // -p digunakan untuk memberi suatu pesan yang akan tampil nantinya di terminal
    system("read -p 'Press any key to continue...' \e");
    return 0;
}
// ======================================================

int JmlMhs = 3;                                                            // Jumlah mahasiswa
string Mhs[JMHS][2] = {{"Rohman", "1"}, {"Renata", "1"}, {"Aditya", "1"}}; // Membuat array 2 dimensi dengan berisi elemen nama mahasiswa dan status
string NilMtkMhs[JMHS][JMTK][JNIL];                                        // Array 3 dimensi untuk nilai mata kuliah

// List all Mahasiswa
void LstMhs(string flag)
{
    for (int i = 0; i < JmlMhs; i++) // looping untuk menampilkan nama mahasiswa yang ada di array sebanyak jumlah mahasiswa
    {
        if (Mhs[i][STTS] == flag) // cek jika statusnya = 1, maka nama mahasiswa akan tampil
        {
            cout << Mhs[i][NAMA] << endl; // ListNilaiMhs(i)
        }
    }
}

// Append Mahasiswa
void AppMhs()
{
    string nama;
    cout << endl
         << "Tambah MHS.. Nama : ";
    fflush(stdin);
    getline(cin, nama);
    Mhs[JmlMhs][0] = nama; // Mengubah index nama menjadi nama yang telah diinput
    Mhs[JmlMhs][1] = "1";  // Mengubah statusnya menjadi 1 atau aktif

    // looping untuk mengubah nilai mata kuliah menjadi 0 semua
    for (int M = 0; M < JMTK; M++)
    {
        for (int N = 0; N < JNIL; N++)
        {
            NilMtkMhs[JmlMhs][M][N] = "0";
        }
    }
    JmlMhs++;
}

int SrcMhs(int JumMhs, string flag)
{
    string Nma;
    cout << endl
         << "Nama : ";
    fflush(stdin); // fflush
    getline(cin, Nma);

    while (JumMhs >= 0 && Mhs[--JumMhs][0] != Nma)
        ; // Selama belum ditemukan
    if (Mhs[JumMhs][STTS] == flag)
        return JumMhs; // Decriment index
    else
        return -1;
}

string NilAkhir(string akhir)
{
    // Fungsi stoi() digunakan untuk konversi string ke int
    if (stoi(akhir) >= 85 && stoi(akhir) <= 100)
    {
        return "A";
    }
    else if (stoi(akhir) >= 70 && stoi(akhir) < 85)
    {
        return "B";
    }
    else if (stoi(akhir) >= 55 && stoi(akhir) < 70)
    {
        return "C";
    }
    else if (stoi(akhir) >= 40 && stoi(akhir) < 55)
    {
        return "D";
    }
    else if (stoi(akhir) < 40)
    {
        return "E";
    }
}

void ListNilaiMhs(int i)
{
    // Fungsi to_string() digunakan untuk konversi ke string
    // 1. Nilai UTS dan UAS dari setiap matkul dikonversi ke int terlebih dahulu untuk dihitung rata-ratanya
    // 2. Setelah dihitung rata-ratanya, hasilnya dikonversi lagi ke string
    // 3. Setelah dikonversi ke string, hasilnya dimasukan ke fungsi NilAkhir() untuk dihitung dari rata-rata tersebut apakah nilai akhirnya A, B, C, D, atau E
    string NilAkhirSTD = to_string((stoi(NilMtkMhs[i][STD][UTS]) + stoi(NilMtkMhs[i][STD][UAS])) / 2);
    string NilAkhirALG = to_string((stoi(NilMtkMhs[i][ALG][UTS]) + stoi(NilMtkMhs[i][ALG][UAS])) / 2);
    string NilAkhirPBO = to_string((stoi(NilMtkMhs[i][PBO][UTS]) + stoi(NilMtkMhs[i][PBO][UAS])) / 2);
    string NilAkhirWEB = to_string((stoi(NilMtkMhs[i][WEB][UTS]) + stoi(NilMtkMhs[i][WEB][UAS])) / 2);

    cout << endl
         << "STD, UTS : " << NilMtkMhs[i][STD][UTS];
    cout << endl
         << "STD, UAS : " << NilMtkMhs[i][STD][UAS] << endl;
    cout << "STD, AKHIR : " << NilAkhir(NilAkhirSTD); // Memanggil fungsi NilAkhir() dengan parameter yang sudah dihitung rata-ratanya begitu pun dengan matkul lain
    cout << endl
         << endl
         << "ALG, UTS : " << NilMtkMhs[i][ALG][UTS];
    cout << endl
         << "ALG, UAS : " << NilMtkMhs[i][ALG][UAS] << endl;
    cout << "ALG, AKHIR : " << NilAkhir(NilAkhirALG); // ini,
    cout << endl
         << endl
         << "PBO, UTS : " << NilMtkMhs[i][PBO][UTS];
    cout << endl
         << "PBO, UAS : " << NilMtkMhs[i][PBO][UAS] << endl;
    cout << "PBO, AKHIR : " << NilAkhir(NilAkhirPBO); // ini,
    cout << endl
         << endl
         << "WEB, UTS : " << NilMtkMhs[i][WEB][UTS];
    cout << endl
         << "WEB, UAS : " << NilMtkMhs[i][WEB][UAS] << endl;
    cout << "WEB, AKHIR : " << NilAkhir(NilAkhirWEB); // dan ini
    cout << endl;
}

void UpdNilaiMhs(int MhsKe)
{
    string mtk, uji, nil;

    cout << endl
         << "Just leave blank if no change.." << endl;

    // looping untuk set index matkul dan ujian
    for (int M = 0; M < JMTK; M++)
    {
        for (int N = 0; N < JNIL; N++)
        {
            if (M == 0)
                mtk = "STD";
            if (M == 1)
                mtk = "ALG";
            if (M == 2)
                mtk = "PBO";
            if (M == 3)
                mtk = "WEB";

            if (N == 0)
                uji = "UTS";
            if (N == 1)
                uji = "UAS";

            // Mengisi nilai berdasarkan index, index ini menentukan matkul dan ujian apa
            cout << "Ubah " << mtk << ", " << uji << " : " << NilMtkMhs[MhsKe][M][N] << " ..menjadi : ";
            fflush(stdin);
            getline(cin, nil);

            // Jika nilainya tidak ingin diubah maka nilai ujian dari matkul tersebut akan tetap dengan yang sebelumnya
            if (!nil.empty() && stoi(nil) > 0 && stoi(nil) < 100)
                NilMtkMhs[MhsKe][M][N] = nil;
        }
    }
}

int main()
{
    char Pilih;

    // Nilai dari setiap mahasiswa
    NilMtkMhs[0][STD][UTS] = "50";
    NilMtkMhs[0][STD][UAS] = "69";
    NilMtkMhs[0][ALG][UTS] = "30";
    NilMtkMhs[0][ALG][UAS] = "67";
    NilMtkMhs[0][PBO][UTS] = "76";
    NilMtkMhs[0][PBO][UAS] = "67";
    NilMtkMhs[0][WEB][UTS] = "90";
    NilMtkMhs[0][WEB][UAS] = "45";

    NilMtkMhs[1][STD][UTS] = "67";
    NilMtkMhs[1][STD][UAS] = "59";
    NilMtkMhs[1][ALG][UTS] = "30";
    NilMtkMhs[1][ALG][UAS] = "70";
    NilMtkMhs[1][PBO][UTS] = "55";
    NilMtkMhs[1][PBO][UAS] = "75";
    NilMtkMhs[1][WEB][UTS] = "66";
    NilMtkMhs[1][WEB][UAS] = "80";

    NilMtkMhs[2][STD][UTS] = "65";
    NilMtkMhs[2][STD][UAS] = "70";
    NilMtkMhs[2][ALG][UTS] = "40";
    NilMtkMhs[2][ALG][UAS] = "50";
    NilMtkMhs[2][PBO][UTS] = "80";
    NilMtkMhs[2][PBO][UAS] = "80";
    NilMtkMhs[2][WEB][UTS] = "70";
    NilMtkMhs[2][WEB][UAS] = "70";

    bool loop = true;

    do
    {                    // display menu
        system("clear"); // Menghapus/membersihkan tulisan dari layar terminal
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
        Pilih = getch();
        system("clear");

        switch (Pilih)
        {
        case '0':
        {
            loop = false;
            break;
        }

        case '1':
        {
            cout << "Daftar MHS" << endl;
            cout << "==========" << endl;
            LstMhs("1"); // Memanggil fungsi LstMhs dengan parameter "1", artinya menampilkan nama mahasiswa yang hanya memiliki status 1
            pause();     // Memanggil fungsi pause supaya programnya berhenti sementara
            break;
        }

        case '2':
        {
            AppMhs(); // Memanggil fungsi AppMhs untuk menambahkan mahasiswa
            cout << Mhs[JmlMhs - 1][NAMA] << ".. Added" << endl;
            pause();
            break;
        }

        case '3':
        {
            int X = SrcMhs(JmlMhs, "1"); // Memanggil fungsi SrcMhs dan dimasukan ke dalam variable X
            // Cek apakah X atau mahasiswa ada dalam list, jika ada maka ubah namanya, jika tidak ada maka tampilkan tulisan "tidak ada"
            if (X >= 0)
            {
                cout << "Ubah Nama : " << Mhs[X][NAMA] << " ..menjadi : ";
                fflush(stdin);
                getline(cin, Mhs[X][NAMA]);
                cout << endl
                     << "Nama Updated.." << endl;
            }
            else
                cout << " Tdk Ada.. " << endl;
            pause();
            break;
        }

        case '4':
        {
            cout << "Delete MHS" << endl;
            int X = SrcMhs(JmlMhs, "1");
            // Cek apakah ada mahasiswa yang memiliki status 1, jika statusnya -1 maka tampilkan tulisan "tidak ada", jika tidak maka ketik nama mahasiswa yang ingin dihapus lalu pilih y/n
            if (X == -1)
                cout << " Tdk Ada.. " << endl;
            else
            {
                cout << "Delete Nama : " << Mhs[X][NAMA] << " y/n : ";
                // Jika pilih 'y', maka status mahasiswa akan diubah ke 0
                if (getch() == 'y')
                {
                    Mhs[X][STTS] = "0";
                    cout << endl
                         << Mhs[X][NAMA] << " ..Deleted.." << endl;
                }
            }
            pause();
            break;
        }

        case '5':
        {
            cout << "Deleted" << endl;
            cout << "==========" << endl;
            LstMhs("0"); // Memanggil fungsi LstMhs dengan parameter "0", artinya menampilkan nama mahasiswa yang hanya memiliki status 0
            pause();
            break;
        }

        case '6':
        {
            cout << "UnDelete MHS" << endl;
            int X = SrcMhs(JmlMhs, "0");
            if (X == -1)
                cout << " Tdk Ada.. " << endl;
            else
            {
                cout << "UnDelete Nama : " << Mhs[X][NAMA] << " y/n : ";
                // Jika pilih 'y', maka status mahasiswa akan diubah ke 1
                if (getch() == 'y')
                {
                    Mhs[X][STTS] = "1";
                    cout << endl
                         << Mhs[X][NAMA] << " ..UnDeleted.." << endl;
                }
            }
            pause();
            break;
        }

        case '7':
        {
            cout << "Lihat Nilai MHS" << endl;
            int X = SrcMhs(JmlMhs, "1");
            if (X >= 0)
            {
                cout << "Nilai MTK : " << Mhs[X][NAMA];
                ListNilaiMhs(X); // Memanggil fungsi ListNilaiMhs untuk menampilkan daftar nilai mahasiswa
            }
            else
                cout << " Tdk Ada.. " << endl;
            pause();
            break;
        }

        case '8':
        {
            cout << "Ubah Nilai MHS" << endl;
            int X = SrcMhs(JmlMhs, "1");
            if (X == -1)
                cout << " Tdk Ada.. " << endl;
            else
                UpdNilaiMhs(X); // Memanggil fungsi UpdNilaiMhs untuk mengubah nilai mahasiswa
            pause();
            break;
        }

        default:
            break;
        }
        cout << endl;
    } while (loop); // looping selama loop = true
}