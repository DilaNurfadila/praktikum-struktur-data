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

// Membuat struct dengan nama Node
struct Node
{
    int data;    // deklarasi variable data dengan tipe data int
    Node *left;  // deklarasi variable pointer left dengan tipe data Node
    Node *right; // deklarasi variable pointer right dengan tipe data Node
};

int order = 1; // deklarasi variable order dengan tipe data int dan isi value 1

// Recursive
void add(Node **NewNode, Node **Parent)
{
    if (*Parent == NULL) // jika tidak ada parent
    {
        *Parent = *NewNode; // assign node baru menjadi parent
    }
    else if ((*NewNode)->data < (*Parent)->data) // jika node baru lebih kecil dari parent
    {
        add(&(*NewNode), &(*Parent)->left); // tambahkan node baru di sebelah kiri parent
    }
    else if ((*NewNode)->data > (*Parent)->data) // jika node baru lebih besar dari parent
    {
        add(&(*NewNode), &(*Parent)->right); // tambahkan node baru di sebelah kanan parent
    }
    else if ((*NewNode)->data == (*Parent)->data) // jika node baru sama dengan parent
    {
        cout << "Data sudah ada"; // tampilkan label
    }
}

// Looping
// void add(Node **NewNode, Node **Parent){
//     if(*Parent == NULL) {
//         *Parent = *NewNode;
//     } else {
//         Node *p, *q;
//         p = q = *Parent;
//         while ((q != NULL) && ((*NewNode)->data != p->data)) {
//             p = q;
//             if((*NewNode)->data < p->data) {
//                 q = p->left;
//             } else {
//                 q = p->right;
//             }

//             if((*NewNode)->data == p->data) {
//                 cout << "Data duplikasi";
//             } else if((*NewNode)->data < p->data) {
//                 p->left = *NewNode;
//             } else {
//                 p->right = *NewNode;
//             }
//         }
//     }
// }

// fungsi untuk menampilkan data dari parent
void preOrder(Node *root, int order)
{
    if (root != NULL)
    {
        cout << "No: " << order << ", Data : " << root->data << endl;
        preOrder(root->left, order * 10 + 1);
        preOrder(root->right, order * 10 + 2);
    }
}

// fungsi untuk menampilkan data dari daun sebelah kiri parent
void inOrder(Node *root, int order)
{
    if (root != NULL)
    {
        inOrder(root->left, order * 10 + 1);
        cout << "No: " << order << ", Data : " << root->data << endl;
        inOrder(root->right, order * 10 + 2);
    }
}

// fungsi untuk menampilkan data dari daun sebelah kiri parent dan setelah cetak lanjut
// ke daun sebelah kanan parent
void postOrder(Node *root, int order)
{
    if (root != NULL)
    {
        postOrder(root->left, order * 10 + 1);
        postOrder(root->right, order * 10 + 2);
        cout << "No: " << order << ", Data : " << root->data << endl;
    }
}

// fungsi untuk menghitung jumlah node secara keseluruhan
int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// fungsi untuk mencari nilai paling kecil dari node
int findMinimumValue(Node *root)
{
    if (root == NULL)
    {
        cout << "Pohon biner kosong." << endl;
    }
    if (root->left == NULL)
    {
        return root->data; // Jika tidak ada subtree kiri, maka nilai root adalah nilai minimum
    }
    return findMinimumValue(root->left); // Rekursif mencari nilai minimum pada subtree kiri
}

// fungsi untuk mencetak data yang ada di daun
void printLeaf(Node *root)
{
    if (root != NULL)
    {
        printLeaf(root->left);
        printLeaf(root->right);
        if (root->left == NULL && root->right == NULL)
            cout << root->data << endl;
    }
}

int main()
{
    // deklarasi
    Node *tree = NULL;
    Node *NewNode;
    bool loop = true;

    do
    {
        // show menu
        system("clear");
        cout << endl;
        cout << "Program tree" << endl;
        cout << "1. Add node" << endl;
        cout << "2. Show post, pre, in order" << endl;
        cout << "3. Show total node" << endl;
        cout << "4. Show minimum value" << endl;
        cout << "5. Show leaf Tree" << endl;
        cout << "6. Exit" << endl
             << endl;
        cout << "Masukan Pilihan : " << endl;

        switch (getch())
        {
        case '1':
        {
            system("clear");
            NewNode = new Node;
            NewNode->left = NULL;
            NewNode->right = NULL;
            cout << "Masukan data : ";
            cin >> NewNode->data;
            add(&NewNode, &tree);
            cout << endl;
            pause();
            break;
        }

        case '2':
        {
            system("clear");
            if (tree != NULL)
            {
                cout << "postOrder : " << endl;
                postOrder(tree, order);
                cout << "\npreOrder : " << endl;
                preOrder(tree, order);
                cout << "\ninOrder : " << endl;
                inOrder(tree, order);
            }
            cout << endl;
            pause();
            break;
        }

        case '3':
        {
            system("clear");
            cout << "Jumlah node : ";
            cout << countNodes(tree);
            cout << endl;
            pause();
            break;
        }

        case '4':
        {
            system("clear");
            cout << "Nilai terkecil dari node : ";
            cout << findMinimumValue(tree);
            cout << endl;
            pause();
            break;
        }

        case '5':
        {
            system("clear");
            cout << "Cetak daun" << endl;
            printLeaf(tree);
            pause();
            break;
        }

        case '6':
        {
            loop = false;
            break;
        }
        }

    } while (loop);
}