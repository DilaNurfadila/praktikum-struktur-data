#include <iostream>
#include <fstream>
using namespace std;
int main(){
	long begin, end;
	ifstream myfile("test.txt");
	begin = myfile.tellg();
	cout << "\nbeginning position from tellg() function is : " << begin << endl;
	
	myfile.seekg(0, ios::end);
	end = myfile.tellg();
	cout << "The ending position set using seekg() function is : " << end << endl;
	myfile.close();
	
	cout << "The total size of the file is using (end_begin) : " << (end-begin) << " bytes" << endl;
}