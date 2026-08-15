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

/*
Membuat tipe data baru dengan nama Simpul yang memiliki 2 elemen yaitu Info dengan tipe data int
dan pointer Next dengan tipe data struct Simpul itu sendiri
 */
struct Simpul
{
    int Info;
    Simpul *Next;
};

// Fungsi untuk menambahkan 1 elemen di depan
void InsertFirst(Simpul **firstcell)
{
    int data;                                   // deklarasi variable data dengan tipe data int
    system("clear");                            // untuk menghilangkan atau membersihkan tampilan terminal
    cout << "Input data yang akan disimpan : "; // label
    cin >> data;                                // input data console ke variable data;

    Simpul *newcell;                            // deklarasi pointer newcell yang digunakan untuk menyimpan elemen baru
    newcell = (Simpul *)malloc(sizeof(Simpul)); // Mengalokasikan memori ke variable newcell dengan mengambil ukuran memori yang dibutuhkan untuk menyimpan 1 elemen Simpul
    newcell->Info = data;                       // assign value data ke atribut Info dalam newcell
    newcell->Next = NULL;                       // assign NULL ke atribut Next dalam newcell

    if (*firstcell != NULL) // cek apakah pointer firstcell tidak sama dengan NULL
    {
        newcell->Next = *firstcell; // jika true, maka assign pointer firstcell ke atribut Next dalam newcell
    }
    *firstcell = newcell; // mengubah pointer firstcell menunjuk ke newcell, sehingga newcell menjadi elemen pertama dalam linked list
}

// Fungsi untuk menampilkan isi dari linked list
void DisplayList(Simpul **Head)
{
    system("clear");
    if (*Head == NULL) // cek apakah pointer Head sama dengan NULL
    {
        cout << "List masih kosong..."; // jika true, maka tampilkan label
    }
    else // jika false
    {
        // looping untuk display
        for (Simpul *p = *Head; p != NULL; p = p->Next)
        {
            cout << to_string(p->Info) << " "; // display linked list
        }
    }
}

// Fungsi untuk menghapus elemen pertama pada linked list
void DeleteFirst(Simpul **firstcell)
{
    system("clear");
    if (firstcell == NULL) // cek apakah firstcell sama dengan NULL
    {
        cout << "Kosong"; // label
    }
    else
    {
        Simpul *delCell;                 // deklarasi pointer delCell yang digunakan untuk menghapus elemen pertama
        delCell = *firstcell;            // delCell menunjuk ke pointer firstcell
        *firstcell = (*firstcell)->Next; // pointer firstcell menunjuk ke list selanjutnya
        delete delCell;                  // hapus elemen
    }
}

// Fungsi untuk menambahkan elemen di akhir list
void InsertLast(Simpul **Head)
{
    int data; // deklarasi variable data dengan tipe data int
    system("clear");
    cout << "Input data yang akan disimpan : "; // label
    cin >> data;                                // input data console ke variable data

    Simpul *Newcell;                            // deklarasi pointer newcell yang digunakan untuk menyimpan elemen baru
    Newcell = (Simpul *)malloc(sizeof(Simpul)); // Mengalokasikan memori ke variable Newcell dengan mengambil ukuran memori yang dibutuhkan untuk menyimpan 1 elemen Simpul

    Newcell->Info = data; // assign value data ke atribut Info dalam Newcell
    Newcell->Next = NULL; // assign NULL ke atribut Next dalam Newcell

    if (*Head == NULL) // cek apakah pointer Head sama dengan NULL
    {
        *Head = Newcell; // Jika true, maka set pointer Head dengan Newcell
    }
    else // jika false
    {
        Simpul *p;                                    // deklarasi pointer p
        for (p = *Head; p->Next != NULL; p = p->Next) // penelusuran
            ;
        p->Next = Newcell; // set p->Next dengan Newcell
    }
}

void InsertAfter(Simpul **Head)
{
    system("clear");
    if (Head == NULL)
    {
        cout << "List masih kosong";
    }
    else
    {
        int FindData;
        cout << "Input data yang dicari : ";
        cin >> FindData;

        Simpul *p;
        for (p = *Head; p != NULL && p->Info != FindData; p = p->Next)
            ;

        if (p == NULL)
        {
            cout << "Tidak bisa insert, yang dicari tidak ada";
        }
        else
        {
            int InsertData;
            cout << "Input data yang akan di insert : ";
            cin >> InsertData;

            Simpul *Newcell;
            Newcell = (Simpul *)malloc(sizeof(Simpul));

            Newcell->Info = InsertData;
            Newcell->Next = NULL;

            Newcell->Next = p->Next;
            p->Next = Newcell;
        }
    }
}

void DeleteAfter(Simpul **Head)
{
    system("clear");
    if (*Head == NULL)
    {
        cout << "List masih kosong";
    }
    else
    {
        int FindData;
        cout << "Input data yang dicari : ";
        cin >> FindData;

        Simpul *p;
        for (p = *Head; p != NULL && p->Info != FindData; p = p->Next)
        {
            if (p != NULL && p->Next != NULL)
            {
                Simpul *DellCell;
                DellCell = p->Next;
                p->Next = p->Next->Next;
                delete DellCell;
            }
            else
            {
                cout << "Data tidak ada atau sudah di ujung";
            }
        }
    }
}

Simpul *SearchData(Simpul **Head)
{
    int FindData;
    system("clear");
    cout << "Input data yang akan dicari : ";
    cin >> FindData;

    Simpul *p;
    for (p = *Head; p != NULL && p->Info != FindData; p = p->Next)
        ;
    return p;
}

void EditData(Simpul **Head)
{
    Simpul *p = SearchData(&(*Head));
    system("clear");
    if (p != NULL)
    {
        int NewData;
        cout << "Input data baru : ";
        cin >> NewData;
        p->Info = NewData;
        cout << "Data sudah diubah";
    }
}

int main()
{
    Simpul *AwalList = NULL;
    bool loop = true;

    do
    {
        system("clear");
        cout << endl;
        cout << "Praktikum List" << endl;
        cout << "==============" << endl;
        cout << "esc. Exit" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Insert After" << endl;
        cout << "4. Display List" << endl;
        cout << "5. Search Data" << endl;
        cout << "6. Delete First" << endl;
        cout << "7. Delete After" << endl;
        cout << "8. Edit Data" << endl;
        cout << endl;
        cout << "Masukan Pilihan : ";

        switch (getch())
        {
        case 27:
            loop = false;
            system("clear");
            cout << "Exit...bye";
            break;
        case '1':
            InsertFirst(&AwalList);
            break;
        case '2':
            InsertLast(&AwalList);
            break;
        case '3':
            InsertAfter(&AwalList);
            break;
        case '4':
            DisplayList(&AwalList);
            break;
        case '5':
            if (SearchData(&AwalList) == NULL)
            {
                cout << "Data tidak ada";
            }
            else
            {
                cout << "Data ditemukan";
            }
            break;
        case '6':
            DeleteFirst(&AwalList);
            break;
        case '7':
            DeleteAfter(&AwalList);
            break;
        case '8':
            EditData(&AwalList);
            break;
        default:
            break;
        }
        cout << endl;
        pause();
    } while (loop);
}