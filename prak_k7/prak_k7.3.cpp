#include <iostream>
#include <fstream>
using namespace std;
int main(){
	fstream fp;
	char buf[100];
	int pos;
	fp.open("random.txt", ios::out | ios::ate);
	cout << "\nWritting to a file ..." << endl;
	
	fp << "This is a line" << endl;
	fp << "This is another line" << endl;
	pos = fp.tellp();
	cout << "Current position of put pointer : " << pos << endl;
	fp.seekp(-7, ios::cur);
	fp << endl << "Writting at a random location";
	fp.seekp(7, ios::beg);
	fp << " Hello World ";
	fp.close();
	cout << "Writting Complete ..." << endl;
	
	fp.open("random.txt", ios::in | ios::ate);
	cout << "\nReading from the file ..." << endl;
	fp.seekg(0);
	while(!fp.eof()){
		fp.getline(buf, 100);
		cout << buf << endl;
	}
	
	pos = fp.tellg();
	cout << "\nCurrent Position of get pointer : " << pos << endl;
}