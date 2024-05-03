#include<iostream>
#include <cmath>
#include<fstream>
using namespace std;
#define max 50
struct Stack{
	int top;
	int nut[max];
};
void Init(Stack &s){
	s.top = -1;
	return;
}
int IsEmpty(Stack s){
	if(s.top == -1){
		return 1;
	}else return 0;
}
int IsFull(Stack s){
	if(s.top == max - 1){
		return 1;
	}else return 0;
}
void Push(Stack &s, int x){
	if(IsFull(s)){
		cout<<"danh sach day.";
	}else{
		s.top ++;
		s.nut[s.top]=x;
	}
}
int Pop(Stack &s){
	if(IsEmpty(s)){
		cout<<"danh sach rong.";
	}else return s.nut[s.top--];
}
int Top(Stack s){
	if(IsEmpty(s)){
		cout<<"danh sach rong.";
	}else return s.nut[s.top];
}

void chuyendoicoso(Stack &s, int socandoi, int coso){
	while(socandoi>0){
		int n = socandoi%coso;
		socandoi = socandoi/coso;
		Push(s, n);
	}
}
void Hienthi(Stack &s){
	while(!IsEmpty(s)){
		int x = Pop(s);
		if(x<10){
			cout<<x;
		}else{
			cout<<(char)('A'+x-10);
		}
	}
}
int KiemTraSoNguyenTo(int x) {
    if (x < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}
int TinhTongChuSo(int x) {
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int TinhBinhPhuong(int x) {
    return x * x;
}
int main(){
	Stack s;
	Init(s);
	int x;
	int chon;
	while(true){
		cout<<endl;
		cout<<"   ===============CHUYEN DOI CO SO==================\n";
		cout<<"1.|Nhap so can chuyen doi.                          |\n";
		cout<<"2.|Chuyen thanh he nhi phan.                        |\n";
		cout<<"3.|Chuyen thanh he bat phan.                        |\n";
		cout<<"4.|Chuyen thanh he thap luc phan.                   |\n";
		cout<<"5.|Ghi du lieu vao tep.                             |\n";
        cout<<"6.|Doc du lieu tu tep.                              |\n";                                                
        cout<<"7.|Kiem tra so can chuyen la chan or le.            |\n";                              
        cout<<"8.|Kiem tra so can chuyen co phai so nguyen to.     |\n";                    
        cout<<"9.|Tong hai chu so cua so can chuyen.               |\n";                                
        cout<<"10|Tinh binh phuong cua so can chuyen               |\n";   
		cout<<"0.|Dung chuong trinh.                               |\n";
		cout<<"=====================END============================|\n";
		cout<<"Moi ban chon: "; cin>>chon;
		switch(chon){
			case 1:{
				cout<<"So can chuyen: ";
				cin >> x;
				break;
				}
			case 2:{
				cout<<"He nhi phan cua "<<x<<" la: "; chuyendoicoso(s, x, 2); Hienthi(s);
				break;
			}
			case 3:{
				cout<<"He bat phan cua "<<x<<" la: "; chuyendoicoso(s, x, 8); Hienthi(s);
				break;
			}
			case 4:{
				cout<<"He thap luc phan cua "<<x<<" la: "; chuyendoicoso(s, x, 16); Hienthi(s);
				break;
			}
			 case 5:{
                // Ghi du lieu vào tep
                ofstream fileOut("Input.dat"); // Mo tep da ghi du lieu vào
                if(fileOut.is_open()){
                    fileOut << x; // Ghi giá tri x vào tep
                    fileOut.close(); // Ðóng tep sau khi ghi xong
                    cout << "Ghi du lieu thanh cong." << endl;
                } else {
                    cout << "Khong the mo tep de ghi du lieu." << endl;
                }
                break;
            }
            case 6:{
                // Ðoc du lieu tu tep
                ifstream fileIn("Input.dat"); // Mo tep de doc du lieu
                if(fileIn.is_open()){
                    fileIn >> x; // Ðoc giá tri tu tep vào bien x
                    fileIn.close(); // Ðóng tep sau khi doc xong
                    cout << "Du lieu doc tu tep: " << x << endl;
                } else {
                    cout << "Khong the mo tep de doc du lieu." << endl;
                }
                break;
            }
            case 7: {
            if (x % 2 == 0) {
            cout << x << " la so chan." << endl;
            } else {
            cout << x << " la so le." << endl;
            }
            break;
            }
            
            case 8:{
            if (KiemTraSoNguyenTo(x)) {
                cout << x << " la so nguyen to.";
            }
            else {
                cout << x << " khong phai la so nguyen to.";
            }
            }
            break;
            case 9:{
            cout << "Tong cac chu so cua " << x << " la: " << TinhTongChuSo(x);
            break;}
            case 10: {
            cout << "Binh phuong cua " << x << " la: " << TinhBinhPhuong(x) << endl;
            break;
        }
		case 0: 
		return 0;
		}
	}
}
