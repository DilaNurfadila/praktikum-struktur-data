#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream outfile;
	outfile.open("Example.txt");
	outfile << "My name is Nurfadila";
	long pos = outfile.tellp();
	outfile.seekp(pos+6);
	outfile << "My name is Nurfadila, again.....";
	outfile.close();
	cout << "Data Written Successfully";
}