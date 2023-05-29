#include<iostream>
using namespace std;
//Khai báo các lớp
class NhomMau//Lớp cha
{
protected:
	char Rh;
public:
	void Nhap();//Các lớp con không có thuộc tính riêng nên hàm Nhap() không cần là phương thức ảo
	virtual char LayMau() = 0;// Lấy nhóm máu của các lớp con(không xét Rh) để thực hiện các phương thức kiểm tra
	char LayRh();//Rh là thuộc tính của lớp cha, lớp con không cần ghi đè
	virtual bool KiemTra(NhomMau*, NhomMau*) = 0;//Kiểm tra xem nhóm máu cha mẹ có phù hợp với nhóm máu con hay không
	virtual bool TuongThich(NhomMau*) = 0;//Kiểm tra người nhận có nhận được nhóm máu từ người cho hay không
};

class DanhSach// Lớp DanhSach có quan hệ 1 - nhiều với lớp NhomMau
{
protected:
	int n;
	NhomMau* ds[100];/*Mảng ds được dùng để quản lí nhóm máu của từng người
					   Mỗi phần tử là con trỏ đối tượng kiểu NhomMau nên phiên bản
					   của phương thức thuần ảo được gọi sẽ phụ thuộc vào kiểu dữ liệu
					   của đối tượng mà mỗi phần tử đang giữ địa chỉ. */
public:
	void NhapDanhSach();//Nhập danh sách nhóm máu của từng người
	bool KetQua();//Kiểm tra bộ 3 nhóm máu của cha, mẹ, con trong danh sách
	void DanhSachCho(int);/*Xuất ra chỉ số của những người mà người nhận(có chỉ số đã biết)
						  có thể nhận máu*/
};

class A : public NhomMau
{
public:
	char LayMau();
	bool KiemTra(NhomMau*, NhomMau*);
	bool TuongThich(NhomMau*);
};

class B : public NhomMau
{
public:
	char LayMau();
	bool KiemTra(NhomMau*, NhomMau*);
	bool TuongThich(NhomMau*);
};

class O : public NhomMau
{
public:
	char LayMau();
	bool KiemTra(NhomMau*, NhomMau*);
	bool TuongThich(NhomMau*);
};

class AB : public NhomMau
{
public:
	char LayMau();
	bool KiemTra(NhomMau*, NhomMau*);
	bool TuongThich(NhomMau*);
};

int main()
{
	//Câu 1:
	DanhSach l;
	l.NhapDanhSach();
	//Câu 2:
	if (l.KetQua() == 1)
		cout << "Nhom mau phu hop" << endl;
	else
		cout << "Nhom mau khong phu hop" << endl;
	//Câu 3:
	int x;
	cout << "Nhap chi so nguoi nhan mau: ";
	cin >> x;
	cout << "Chi so nguoi cho mau: " << endl;
	l.DanhSachCho(x);
	return 0;
}

//Định nghĩa các phương thức cho câu 1
void NhomMau::Nhap()
{
	cout << "Nhap Rh: ";
	cin >> Rh;
}

void DanhSach::NhapDanhSach()
{
	cout << "Nhap so luong nguoi: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char loai;
		cout << "Nhap loai mau (Nhap C thay cho AB) thu ["<<i<<"]: ";
		cin >> loai;
		switch (loai)
		{
		case 'A':
			ds[i] = new A;
			break;
		case 'B':
			ds[i] = new B;
			break;
		case 'O':
			ds[i] = new O;
			break;
		case 'C':
			ds[i] = new AB;
		}
		ds[i]->Nhap();
	}
}

//Định nghĩa các phương thức cho câu 2
char A::LayMau()
{
	return 'A';
}

char B::LayMau()
{
	return 'B';
}

char O::LayMau()
{
	return 'O';
}

char AB::LayMau()
{
	return 'C';
}
char NhomMau::LayRh()
{
	return Rh;
}

bool A::KiemTra(NhomMau* cha, NhomMau* me)
{
	char mCha = cha->LayMau();
	char mMe = me->LayMau();
	//Nếu cha hoặc mẹ có nhóm máu A hoặc AB thì con có thể có nhóm máu A
	if (mCha == 'A' || mCha == 'C' || mMe == 'A' || mMe == 'C')
		return true;
	return false;
}

bool B::KiemTra(NhomMau* cha, NhomMau* me)
{
	char mCha = cha->LayMau();
	char mMe = me->LayMau();
	//Nếu cha hoặc mẹ có nhóm máu B hoặc AB thì con có thể có nhóm máu B
	if (mCha == 'B' || mCha == 'C' || mMe == 'B' || mMe == 'C')
		return true;
	return false;
}

bool O::KiemTra(NhomMau* cha, NhomMau* me)
{
	char mCha = cha->LayMau();
	char mMe = me->LayMau();
	//Nếu cha và mẹ có nhóm máu AB thì con không thể có nhóm máu O
	if (mCha == 'C' && mMe == 'C')
		return false;
	return true;
}

bool AB::KiemTra(NhomMau* cha, NhomMau* me)
{
	char mCha = cha->LayMau();
	char mMe = me->LayMau();
	/*Các trường hợp con không thể có nhóm máu AB:
	  - Cha và mẹ có nhóm máu giống nhau nhưng khác nhóm máu AB
	  - Cha hoặc mẹ có nhóm máu O*/
	if ((mCha == mMe && mMe != 'C') || mCha == 'O' || mMe == 'O')
		return false;
	return true;
}
bool DanhSach::KetQua()
{
	int cha, me, con;
	cout << "Nhap lan luot chi so cua cha, me, con: ";
	cin >> cha >> me >> con;
	bool check = ds[con]->KiemTra(ds[cha], ds[me]);
	if (check == 1)
		return true;
	return false;
}

//Định nghĩa các phương thức cho câu 3
void DanhSach::DanhSachCho(int x)
{
	for (int i = 0; i < n; i++)
	{
		if (i != x && ds[x]->TuongThich(ds[i]) == 1)
			cout << i << endl;
	}
}

bool A::TuongThich(NhomMau* nguoicho)
{
	//Người có nhóm máu A chỉ nhận được nhóm máu A và O(chưa xét Rh)
	if (nguoicho->LayMau() == 'A' || nguoicho->LayMau() == 'O')
		//Người có nhóm máu Rh+ có thể nhận người có nhóm máu Rh+ hoặc Rh-  
		//Người có nhóm máu Rh- có thể cho người có nhóm máu Rh+ hoặc Rh- 
		if (this->LayRh() == '+' || nguoicho->LayRh() == '-')
			return true;
	return false;
}

bool B::TuongThich(NhomMau* nguoicho)
{
	if (nguoicho->LayMau() == 'O' || nguoicho->LayMau() == 'B')
		if (this->LayRh() == '+' || nguoicho->LayRh() == '-')
			return true;
	return false;
}

bool O::TuongThich(NhomMau* nguoicho)
{
	if (nguoicho->LayMau() == 'O')
		if (this->LayRh() == '+' || nguoicho->LayRh() == '-')
			return true;
	return false;
}

bool AB::TuongThich(NhomMau* nguoicho)
{
	if (this->LayRh() == '+' || nguoicho->LayRh() == '-')
		return true;
	return false;
}
