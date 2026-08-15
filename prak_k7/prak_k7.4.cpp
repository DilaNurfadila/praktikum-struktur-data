#include <iostream>
// #include <conio.h>
#include <fstream>
#include <cstring>
#include <iomanip>

// ====================
#include <termios.h> // header untuk mendefinisikan terminal I/O
#include <unistd.h>  // header untuk mendefinisikan konstanta dan tipe simbolik standar
// ====================
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

struct {
		char kode[10];
		char nama[30];
		float harga;
		bool flag;
	} barang;
	
	void AppendData(char *namafile){
		string inp;
		system("clear");
		
		cout << "Penambahan Barang" << endl;
		cout << "=================" << endl;
		cout << "Kode  : "; getline(cin, inp); strcpy(barang.kode, inp.c_str());
		cout << "Nama  : "; getline(cin, inp); strcpy(barang.nama, inp.c_str());
		cout << "Harga : "; getline(cin, inp); barang.harga = atof(inp.c_str());
		barang.flag = 1;
		
		fstream myfile;
		myfile.open(namafile, ios::app);
		if(!myfile.is_open()) {
			cout << "Error File ...!";
			getch();
		} else {
			myfile.write((char*) &barang, sizeof(barang));
		}
		myfile.close();
	}
	
	void DspAllData(char *namafile){
		system("clear");
		cout << "Data Barang" << endl << endl;
		cout << "Kode\t  Nama\t\t\t\tHarga" << endl;
		cout << "=============================================" << endl;
		
		ifstream myfile;
		myfile.open(namafile);
		if(!myfile.is_open()){
			cout << "Error File ...!" << endl;
		} else {
			while(myfile.read((char*) &barang, sizeof(barang)) && !myfile.eof()){
				if (barang.flag){
					cout << setiosflags(ios::left) << setw(10) << barang.kode;
					cout << setiosflags(ios::left) << setw(30) << barang.nama;
					cout << setiosflags(ios::left) << setw(10) << barang.harga;
					cout << endl;
				}
			}
		}
		cout << endl << "Press any key to continue";
		getch();
		myfile.close();
	}
	
	void FilterData(char *namafile){
		string inp, brg;
		system("clear");
		cout << "Data Barang" << endl << endl;
		cout << "Kode\tNama\t\t\tHarga" << endl;
		cout << "=====================================" << endl;
		
		ifstream myfile;
		myfile.open(namafile);
		if(!myfile.is_open()){
			cout << "Error File ...!" << endl;
		} else {
			while(myfile.read((char*) &barang, sizeof(barang)) && !myfile.eof()){
				if (barang.flag && strstr(barang.nama, inp.c_str())){
					cout << setiosflags(ios::left) << setw(10) << barang.kode;
					cout << setiosflags(ios::left) << setw(30) << barang.nama;
					cout << setiosflags(ios::left) << setw(10) << barang.harga;
					cout << endl;
				}
			}
		}
		cout << endl << "Press any key to continue";
		getch();
		myfile.close();
	}
	
	void ModifyData(char *namafile){
		long pos;
		string inp;
		system("clear");
		
		cout << "Kode barang yang akan di edit : ";
		getline(cin, inp);
		
		fstream myfile;
		myfile.open(namafile);
		if(!myfile){
			cout << "File Error...";
		} else {
			while(myfile.read((char*) &barang, sizeof(barang)) && !myfile.eof() && strcmp(barang.kode, inp.c_str())){
				if(myfile.eof()){
					cout << "Data tidak ditemukan" << endl;
				} else if(!barang.flag){
					cout << "Data sudah dihapus" << endl;
				} else {
					system("cls");
					cout << "Data barang sebelumnya" << endl;
					cout << "======================" << endl;
					cout << "Kode  : "; getline(cin, inp); strcpy(barang.kode, inp.c_str());
					cout << "Nama  : "; getline(cin, inp); strcpy(barang.nama, inp.c_str());
					cout << "Harga : "; getline(cin, inp); barang.harga = atof(inp.c_str());
					
					pos = myfile.tellg();
					myfile.seekp(pos-sizeof(barang));
					myfile.write((char*) &barang, sizeof(barang));
					cout << endl << "Data sudah diubah" << endl;
				}
			}
		}
		cout << "Press any key...";
		getch();
		myfile.close();
	}
	
	void DeleteData(char *namafile){
		long pos;
		string inp;
		system("clear");
		
		cout << "Kode barang yang akan di delete : ";
		getline(cin, inp);
		
		fstream myfile;
		myfile.open(namafile);
		if(!myfile){
			cout << "File Error...";
		} else {
			while(myfile.read((char*) &barang, sizeof(barang)) && !myfile.eof() && strcmp(barang.kode, inp.c_str())){
				if(myfile.eof()){
					cout << "Data tidak ditemukan" << endl;
				} else if(!barang.flag) {
					cout << "Data sudah dihapus" << endl;
				} else {
					cout << "Data barang yang akan dihapus" << endl;
					cout << "=============================" << endl;
					cout << "Kode  : " << barang.kode << endl;
					cout << "Nama  : " << barang.nama << endl;
					cout << "Harga : " << barang.harga << endl;
					cout << endl;
					
					cout << "Tekan y untuk hapus...";
					if(getch() != 'y'){
						cout << endl << "Data tidak jadi dihapus..." << endl;
					} else {
						barang.flag = 0;
						pos = myfile.tellp();
						myfile.seekp(pos-sizeof(barang));
						myfile.write((char*) &barang, sizeof(barang));
						cout << endl << "Data sudah diubah" << endl;
					}
				}
			}
		}
		cout << "Press any key...";
		getch();
		myfile.close();
	}
	
	void DspDelData(char *namafile){
		system("clear");
		cout << "Data Barang" << endl << endl;
		cout << "Kode\tNama\t\t\tHarga" << endl;
		cout << "=====================================" << endl;
		
		ifstream myfile;
		myfile.open(namafile);
		if(!myfile.is_open()){
			cout << "Error File ...!" << endl;
		} else {
			while(myfile.read((char*) &barang, sizeof(barang)) && !myfile.eof()){
				if (!barang.flag){
					cout << setiosflags(ios::left) << setw(10) << barang.kode;
					cout << setiosflags(ios::left) << setw(30) << barang.nama;
					cout << setiosflags(ios::left) << setw(10) << barang.harga;
					cout << endl;
				}
			}
		}
		cout << endl << "Press any key to continue";
		getch();
		myfile.close();
	}
	
	void RecvryData(char *namafile){
		long pos;
		string inp;
		system("clear");
		
		cout << "Kode barang yang akan di delete : ";
		getline(cin, inp);
		
		fstream myfile;
		myfile.open(namafile);
		if(!myfile){
			cout << "File Error...";
		} else {
			while(myfile.read((char*) &barang, sizeof(barang)) && !myfile.eof() && strcmp(barang.kode, inp.c_str())){
				if(myfile.eof()){
					cout << "Data tidak ditemukan" << endl;
				} else if(!barang.flag) {
					cout << "Data sudah dihapus" << endl;
				} else {
					cout << "Data barang yang akan dihapus" << endl;
					cout << "=============================" << endl;
					cout << "Kode  : " << barang.kode << endl;
					cout << "Nama  : " << barang.nama << endl;
					cout << "Harga : " << barang.harga << endl;
					cout << endl;
					
					cout << "Tekan y untuk hapus...";
					if(getch() != 'y'){
						cout << endl << "Data tidak jadi dihapus..." << endl;
					} else {
						barang.flag = 1;
						pos = myfile.tellp();
						myfile.seekp(pos-sizeof(barang));
						myfile.write((char*) &barang, sizeof(barang));
						cout << endl << "Data sudah diubah" << endl;
					}
				}
			}
		}
		cout << "Press any key...";
		getch();
		myfile.close();
	}
	
	void PckingData(char *namafile, char *backfile){
		system("clear");
		cout << "Process..." << endl;
		rename(namafile, backfile);
		
		ifstream myback(backfile);
		ofstream myfile(namafile, ios::app);
		
		if(myfile && myback){
			while(myback.read((char*) &barang, sizeof(barang)) && !myback.eof()){
				if(barang.flag) {
					myfile.write((char*) &barang, sizeof(barang));
				} else {
					cout << "File Error..." << endl;
				}
			}
		}
		myfile.close();
		myback.close();
		cout << "Data Packed.. Press any key to continue...";
		getch();
	}

int main(){
	char *namafile = "binerfile.dat";
	char *backfile = "binerfile.bck";
	bool Exit = false;
	do {
		system("clear");
		cout << "1. Append Data" << endl;
		cout << "2. DspAll Data" << endl;
		cout << "3. Filter Data" << endl;
		cout << "4. Modify Data" << endl;
		cout << "5. Delete Data" << endl;
		cout << "6. DspDel Data" << endl;
		cout << "7. Recvry Data" << endl;
		cout << "8. Pcking Data" << endl;
		cout << "0. Exit" << endl;
		cout << "Pilihan : " << endl;
		
		switch(getch()) {
			case '1' :
				AppendData(namafile);
				break;
			case '2' :
				DspAllData(namafile);
				break;
			case '3' :
				FilterData(namafile);
				break;
			case '4' :
				ModifyData(namafile);
				break;
			case '5' :
				DeleteData(namafile);
				break;
			case '6' :
				DspDelData(namafile);
				break;
			case '7' :
				RecvryData(namafile);
				break;
			case '8' :
				PckingData(namafile, backfile);
				break;
			case '0' :
				Exit = true;
				break;
			default :
				cout << "Wrong choice...!";
				getch();
				break;
		}
	} while(!Exit);
}