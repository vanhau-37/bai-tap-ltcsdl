#include <bits/stdc++.h>
using namespace std;

class baohiem{
	protected:
		string tennguoimua;
		int thoihan;
		double sotienphaidong;
	public:
		baohiem(string ten, int time, double tien):
		tennguoimua(ten), thoihan(time), sotienphaidong(tien){};
		baohiem(){}
		virtual void in() {
			cout << "Ten nguoi mua: " << tennguoimua << ", ";
	        cout << "Thoi han: " << thoihan << " thang, ";
	        cout << "So tien phai dong: " << sotienphaidong << " USD, \n";
		}
		virtual double hoahong(){}
		virtual double getsotienphaidong(){}
};

class baohiemnganhan : public baohiem{
	public:
		baohiemnganhan(string ten, int time, double tien):baohiem(ten, time, tien){};
		baohiemnganhan(){};
		void in() override {
			cout << "\nBao hiem ngan han: ";
	        baohiem::in();
		}
		double hoahong() override {
			return sotienphaidong*0.05;
		}
		double getsotienphaidong() override {
			return sotienphaidong;
		}
};

class baohiemdaihan : public baohiem{
	private:
		double sotiendongtheothang;
	public:
		baohiemdaihan(string ten, int time, double tien, double sotiendongtheothang):
		baohiem(ten, time, tien), sotiendongtheothang(sotiendongtheothang){};
		baohiemdaihan(){};
		void in() override {
			cout << "\nBao hiem dai han: ";
	        baohiem::in();
	        cout << "So tien theo hang thang: " << sotiendongtheothang << " USD" << endl;
		}
		double hoahong() override {
			return sotienphaidong*0.05;
		}
		double getsotienphaidong() override {
			return sotienphaidong;
		}
};

class nhanvien{
	private:
		string tennv;
		double hsl;
		vector<baohiem*> dsbh;
	public:
		nhanvien(string ten, double hsl): tennv(ten), hsl(hsl){};
		nhanvien(){}
		void thembaohiem(baohiem* bh){
			dsbh.push_back(bh);
		}
		double luong(){
			double luong=0;
			for(auto x:dsbh)
			{
				luong += x -> hoahong();
			}
			return 40*hsl + 0.01*luong;
		}
		bool thuong(){
			for(auto x:dsbh)
			{
				if(x -> getsotienphaidong() > 10000 ) 
				return 1;
			}
		}
		bool phat(){
			double doanhthu=0;
			for(auto x:dsbh) doanhthu += x -> getsotienphaidong();
	
			if(doanhthu < 10000 ) 
			return 1;
		}
		double tonghoahong(){
			double tonghoahong=0;
			for(auto x:dsbh) tonghoahong += x -> hoahong();
	
			return tonghoahong;
		}
		void innv(){
			cout << "***Thong tin nhan vien: ";
	        cout << "Ten: " << tennv << ", ";
	        cout << "Luong: " << luong() << " USD" << endl;
	
	        cout << "Cac bao hiem da ban duoc:" << endl;
			for(auto x:dsbh) x -> in();
		}
};

int main()
{
	vector<nhanvien*> nv; 
	vector<baohiem*> bh;
	bh.push_back(new baohiemnganhan("hau",11,1000));
	bh.push_back(new baohiemnganhan("anh",8,9000));
	
	bh.push_back(new baohiemdaihan("hau",26,100000,10));
	bh.push_back(new baohiemdaihan("hao",26,100000,10));
	bh.push_back(new baohiemdaihan("na",43,700,10));
	bh.push_back(new baohiemdaihan("xuan",19,200,10));
	
	cout<<"----------------------------Danh sach bao hiem duoc ban\n";
	for(auto x:bh){
		x->in();
		
	}
	
	nv.push_back(new nhanvien("a",3.2));
	nv.push_back(new nhanvien("b",5.5));
	nv.push_back(new nhanvien("c",1.2));
	
	nv[0] -> thembaohiem(bh[0]);
	nv[0] -> thembaohiem(bh[3]);
	
	nv[1] -> thembaohiem(bh[1]);
	nv[1] -> thembaohiem(bh[2]);
	
	nv[2] -> thembaohiem(bh[4]);
	nv[2] -> thembaohiem(bh[5]);
	cout<<"\n\n----------------------------Danh sach nhan vien\n\n";
	for(auto x:nv){
		x->innv();
		cout<<"\n\n";
	}
	
	cout<<"\n\n----------------------------Danh sach nhan vien co hoa hong >50 USD\n\n";
	for(auto x:nv){
		if(x -> tonghoahong() > 50 )
			x->innv();
		cout<<"\n\n";
	}
	
	cout<<"\n\n----------------------------Danh sach nhan vien bi phat";
	for(auto x:nv){
		if(x -> phat())
			x->innv();
		cout<<"\n\n";
	}
	
	cout<<"\n\n----------------------------Danh sach nhan vien duoc thuong";
	for(auto x:nv){
		if(x -> thuong())
			x->innv();
		cout<<"\n\n";
	}
}
