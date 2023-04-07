#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hoc_sinh {
public:
	void Nhap();
	void Xuat();
private:
	int MSSV;
	string ho_ten;
	double toan;
	double van;
	double diemtb;
};

void Hoc_sinh::Nhap() {
	cin >> MSSV;
	getline(cin, ho_ten);
	cin >> toan;
	cin >> van; 
	diemtb = (toan + van) / 2;
}

void Hoc_sinh::Xuat() {
	cout << MSSV << endl << ho_ten << endl << toan << endl << van << endl << diemtb << endl;
}

