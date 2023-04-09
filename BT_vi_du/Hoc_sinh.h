#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hoc_sinh {
private:
	int MSSV;
	string ho_ten;
	double toan;
	double van;
	double diemtb;
	void Xuly();
protected:
public:
	double get_toan();
	void set_toan(double);
	void Nhap();
	void Xuat();
};

void Hoc_sinh::Xuly() {
	diemtb = (toan + van) / 2;
}

void Hoc_sinh::Nhap() {
	cin >> MSSV;
	getline(cin, ho_ten);
	cin >> toan;
	cin >> van; 
}

void Hoc_sinh::Xuat() {
	cout << MSSV << endl << ho_ten << endl << toan << endl << van << endl << diemtb;
}

double Hoc_sinh::get_toan() {
	return toan;
}
void Hoc_sinh::set_toan(double toan) {
	if (toan > 10 || toan < 0) {
		cout << "ERROR: điểm toán không được lớn hơn 10 hoặc bé hơn 0" << endl;
		return;
	}
	this->toan = toan;
	this->Xuly(); // tính lại điểm trung bình
}

