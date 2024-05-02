#include <bits/stdc++.h>
using namespace std;

class buupham{
	private:
		string diachinhan;
		string nguoinhan;
	public:
		buupham(string diachi, string nguoi) : diachinhan(diachi), nguoinhan(nguoi) {};
		buupham(){};
		string getnguoinhan(){
			return nguoinhan;
		}
		void in(){
			cout<<"Dia chi nhan: ";getline(cin,diachinhan);
			cout<<"Nguoi nhan: ";getline(cin,nguoinhan);
		};
		void out(){
			cout<<"Dia chi nhan: "<<diachinhan<<", "<<"Nguoi nhan: "<<nguoinhan<<endl;
		};
};


class thu : public buupham{
	protected:
		bool nhanh;
		string loaithu;
	public:
		thu(bool chuyennhanh, string diaChi, string nguoi) : 
		buupham(diaChi, nguoi), nhanh(chuyennhanh){};
		thu(){};
		void in(){
			cout<<"Loai buu pham: thu, Loai thu: nhanh(true or false)"; getline(cin,loaithu);
			nhanh = (loaithu=="true"? 1:0);
			buupham::in();
		};
		void out(){
			cout<<"Loai buu pham: thu, Loai thu: "<<(nhanh?"nhanh, ":"cham, ")
			<<"Phi van chuyen: "<<thu::phivanchuyen()<<", ";
			buupham::out();
		};
		void findbyname(string name){
			if(name == getnguoinhan()) thu::out();
		}
		int phivanchuyen(){
			return nhanh ? 3000 : 500;
		}
		bool getnhanh(){
			return nhanh;
		}
};

class hanghoa : public buupham{
	protected:
		double trongluong;
	public:
		hanghoa(double m, string diaChi, string nguoi) : trongluong(m), buupham(diaChi, nguoi){};
		hanghoa(){};
		void in(){
			cout<<"Loai buu pham: hang hoa, Trong luong: "; cin>>trongluong;
			cin.ignore();
			buupham::in();
		};
		void out(){
			cout<<"Loai buu pham: hang hoa, Trong luong: "<<trongluong
			<<", Phi van chuyen: "<<phivanchuyen()<<", ";
			buupham::out();
		}
		int phivanchuyen(){
			return trongluong*10000;
		}
};


int main()
{
	vector<thu> a;
	vector<hanghoa> b;
	int choice = -1;
	while(choice != 8)
	{
		cout << "0. Nhap thong tin buu pham" << endl;
		cout << "1. Xuat thong tin buu pham" << endl;
        cout << "2. Nhap tu dong" << endl;
        cout << "3. Dem tong so hang hoa" << endl;
        cout << "4. Xuat thong tin cac thu lien quan den nguoi nhan ten ..." << endl;
        cout << "5. Sap xep buu pham" << endl;
        cout << "6. Xoa thong tin thu thuong" << endl;
        cout << "7. Tinh tong phi van chuyen" << endl;
        cout << "8. Thoat" << endl;
        cout << "Chon chuc nang: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice){
        	case 0:{
        		thu newthu;
        		newthu.in();
    			a.push_back(newthu);
    			
    			hanghoa newhanghoa;
        		newhanghoa.in();
    			b.push_back(newhanghoa);
    			break;
			}
			case 1:{
				in:
				for(int i = 0;i<a.size();i++)
				{
					a[i].out();
					cout<<endl;
				}
				for(int i = 0;i<b.size();i++)
				{
					b[i].out();
					cout<<endl;
				}			
				break;
			}
			case 2:{
				a.push_back(thu(false, "ql1a", "anh"));
				a.push_back(thu(true, "ql1a", "hai"));
				b.push_back(hanghoa(33, "ql1a", "anh"));
				b.push_back(hanghoa(12.2, "ql1a", "hau"));
				goto in;
				break;
			}
			case 3:{
				cout<<"tong so hang hoa: "<<b.size()<<endl;
				break;
			}
			case 4:{
				string st;
				cout<<"nhap ten nguoi nhan: ";getline(cin,st);
				for(int i = 0;i<a.size();i++)
				{
					a[i].findbyname(st);
					cout<<endl;
				}	
				break;
			}
			case 5:{
				vector<buupham> allitems;
			    allitems.insert(allitems.end(), a.begin(), a.end());
			    allitems.insert(allitems.end(), b.begin(), b.end());
				sort(allitems.begin(), allitems.end(), [](buupham a,buupham b) {
				    return a.getnguoinhan() < b.getnguoinhan();
				});

				for(int i = 0;i<allitems.size();i++)
				{
					allitems[i].out();
					cout<<endl;
				}	
				break;
			}
			case 6:{
				a.erase(remove_if(a.begin(), a.end(), [](thu x){ return !x.getnhanh(); }), a.end());
				goto in;
				break;	
			}
			case 7:{
				int tongphivanchuyen = 0;
				for(int i = 0;i<a.size();i++)
				{
					tongphivanchuyen += a[i].phivanchuyen();
				}
				for(int i = 0;i<b.size();i++)
				{
					tongphivanchuyen += b[i].phivanchuyen();
				}	
				cout<<"Tong chi phi van chuyen: "<<tongphivanchuyen<<endl;
				break;
			}
			
			
		}
	}
	
}
