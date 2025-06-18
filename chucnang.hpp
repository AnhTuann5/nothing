#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<stdexcept>
using namespace std;
const std::string RESET = "\033[0m";
const std::string RED = "\033[0;31m";
const std::string GREEN = "\033[0;32m";
const std::string BLUE = "\033[0;34m";
const std::string YELLOW = "\033[0;33m";
class item{
    private:
    std::string type,name,id,color,size,madein,brand,gioitinh,material;
    int number,yearmanu,yyyy,mm,dd;
    long long price;
    public:
    void nhap();
    void in();
    void ghifile();
    bool findid(std::string id)const;
    void change();
    int advancefind(std::string type,std::string color,std::string material,std::string size,std::string gioitinh,std::string madein);
    item():type(""),name(""),id(""),color(""),material(""),size(""),madein(""),brand(""),gioitinh(""),number(0),yearmanu(0),price(0),yyyy(0),mm(0),dd(0){};
    item(std::string type,std::string name,std::string id,std::string color,std::string material,std::string size,std::string madein,std::string brand,std::string gioitinh,int number,int yearproduct,long long price,int yyyy,int mm,int dd){
            this->type=type;
            this->name=name;
            this->id=id;
            this->color=color;
            this->material=material;
            this->size=size;
            this->madein=madein;
            this->brand=brand;
            this->gioitinh=gioitinh;
            this->number=number;
            this->yearmanu=yearproduct;
            this->price=price;
            this->yyyy=yyyy;
            this->mm=mm;
            this->dd=dd;
        }
    double getprice()const{return price;}
    int setnumber(int number){
        return this->number=this->number-number;
    }
    int getnumber(){
        return number;
    }
    int getday(){
        return dd;
    }
    int getmonth(){
        return mm;
    }
    int getyear(){
        return yyyy;
    }
    std::string getname(){
        return name;
    }
};
 void item::nhap(){
        std::cout<<"Loai: ";
        getline(std::cin,type);
        std::cout<<"Ten: ";
        getline(std::cin,name);
        std::cout<<"Ma: ";
        getline(std::cin,id);
        std::cout<<"Mau sac: ";
        getline(std::cin,color);
        std::cout<<"Chat lieu: ";
        getline(std::cin,material);
        std::cout<<"Kich thuoc: ";
        getline(std::cin,size);
        std::cout<<"Gioi tinh: ";
        getline(std::cin,gioitinh);
        std::cout<<"Nha san xuat: ";
        getline(std::cin,madein);
        std::cout<<"Xuat su: ";
        getline(std::cin,madein);
        std::cout<<"So luong: ";
        std::cin>>number;
        std::cout<<"Nam san xuat: ";
        std::cin>>yearmanu;
        std::cout<<"Gia: ";
        std::cin>>price;
        std::cout<<"Thoi gian nhap kho\n";
        std::cout<<"Ngay: ";
        std::cin>>dd;
        std::cout<<"Thang: ";
        std::cin>>mm;
        std::cout<<"Nam: ";
        std::cin>>yyyy;
    }
void item::in(){
    std::string line =std::to_string(dd)+"/"+std::to_string(mm)+"/"+std::to_string(yyyy);
    for(int i=0;i<=30;i++){
        std::cout<<"_";
    }
    std::cout<<"\n";
    std::cout<<"|Loai: "<<std::setw(23)<<std::left<<type<<"|\n";
    std::cout<<"|Ten: "<<std::setw(24)<<name<<"|\n";
    std::cout<<"|Ma: "<<std::setw(25)<<id<<"|\n";
    std::cout<<"|Mau sac: "<<std::setw(20)<<color<<"|\n";
    std::cout<<"|Chat lieu: "<<std::setw(18)<<material<<"|\n";
    std::cout<<"|Kich thuoc: "<<std::setw(17)<<size<<"|\n";
    std::cout<<"|Gioi tinh: "<<std::setw(18)<<gioitinh<<"|\n";
    std::cout<<"|Xuat su: "<<std::setw(20)<<madein<<"|\n";
    std::cout<<"|So luong: "<<std::setw(19)<<number<<"|\n";
    std::cout<<"|Nam san xuat: "<<std::setw(15)<<yearmanu<<"|\n";
    std::cout<<"|Thoi gian nhap: "<<std::setw(13)<<line<<"|\n";
    std::cout<<"|Gia: "<<std::setw(24)<<price<<"|\n";
    std::cout<<"-------------------------------\n";
}
bool item::findid(std::string id)const{
    if(this->id==id){
        return true;
    }
        else{
            return false;
        }
}
void item::change(){
    std::cout<<"-Chon du lieu muon thay doi-\n";
    std::cout<<"___________________________\n";
    std::cout<<"|0 Mau sac                |\n";
    std::cout<<"|1 Kich thuoc             |\n";
    std::cout<<"|2 So luong               |\n";
    std::cout<<"|3 Gioi tinh              |\n";
    std::cout<<"|4 Nam san xuat           |\n";
    std::cout<<"|5 Chat lieu              |\n";
    std::cout<<"|_________________________|\n";
    int choice;
    std::cout<<"Nhap lua chon: "; 
    std::cin>>choice;
    std::cin.ignore();
    switch(choice){
        case 0: 
        std::cout<<"Mau: ";
        getline(std::cin,color);
        break;
        case 1:
        std::cout<<"Kich thuoc: ";
        getline(std::cin,size);
        break;
        case 2:
        std::cout<<"So luong: ";
        std::cin>>number;
        break;
        case 3:
        std::cout<<"Gioi tinh: ";
        getline(std::cin,gioitinh);
        break;
        case 4:
        std::cout<<"Nam san xuat: ";
        std::cin>>yearmanu;
        break;
        case 5:
        std::cout<<"Chat lieu: ";
        getline(std::cin,material);
        break;
        default:
        std::cout<<RED<<"-------Lua chon khong hop le-------\n"<<RESET;
    }
}
    int item::advancefind(std::string type,std::string color,std::string material,std::string size,std::string gioitinh,std::string madein){
        int x=0;
        if(this->type==type){x++;}
        if(this->color==color){x++;}
        if(this->material==material){x++;}
        if(this->size==size){x++;}
        if(this->gioitinh==gioitinh){x++;}
        if(this->madein==madein){x++;}
        return x;
    }
void item::ghifile(){
    std::ofstream out("item.csv",std::ios::app);
    out<<type<<","<<name<<","<<id<<","<<color<<","<<size<<","<<madein<<","<<brand<<","<<gioitinh<<","<<material<<","<<number<<" "<<yearmanu<<" "<<price<<" "<<yyyy<<" "<<mm<<" "<<dd<<"\n";
}
class bill{
    private:
    int soluong;
    std::string mahang,tenhang;
    long long price;
    public:
    bill():mahang(""),tenhang(""),price(0){};
    bill(std::string mahang,std::string tenhang,long long price, int soluong){
        this->mahang=mahang;
        this->tenhang=tenhang;
        this->price=price;
        this->soluong=soluong;
    }
    double tinhtien(){
        return price*soluong;
    }
    // void create_bill(){
    //     std::ofstream out("bill.csv",std::ios::app);
    //     out<<"------------------------------\n";
    //     out<<"|Ma hang: "<<std::setw(19)<<std::left<<mahang<<"|\n";
    //     out<<"|Ten hang: "<<std::setw(18)<<tenhang<<"|\n";
    //     out<<"|So luong: "<<std::setw(18)<<std::left<<soluong<<"|\n";
    //     out<<"|Gia: "<<std::setw(23)<<price<<"|\n";
    // }
    void create_bill(std::ofstream& out) {
        out << "Ma hang: " << mahang << "\n";
        out << "Ten hang: " << tenhang << "\n";
        out << "Gia: " << price << "\n";
        out << "So luong: " << soluong << "\n";
        out << "Thanh tien: " << tinhtien() << "\n";
        out << "------------------------\n";
    }
};
class employee{
    protected:
    std::vector<std::string>name;
    std::vector<std::string>password;
    std::vector<item>listitem;
    std::vector<bill>listbill;
    double toltallprice;
    public:
    void additem();
    void print_item();
    void create_transaction();
    void docfile_item();
    void docfile_thanhvien(std::string tenfile);
    void login();
    void loc();
    void tim_kim_theo_ma(int &chiso);
    void xoa_hang();
    void thay_doi();
    void xemgangmoinhap();    
};
void employee::docfile_thanhvien(std::string tenfile){
std::ifstream inp(tenfile);
    std::string ten="",matkhau="",line="";
    while(getline(inp,line)){
        std::stringstream ss(line);
        getline(ss,ten,',');
        getline(ss,matkhau);
        name.push_back(ten);
        password.push_back(matkhau);
    }
}
void employee::login(){
    int ften=0,fmk=0;
    std::string ten,matkhau;
    do{
        ten="";matkhau="";
        std::cout<<"---Dang nhap---\n";
        std::cout<<"Ten: ";
        getline(std::cin,ten);
        std::cout<<"Mat khau: ";
        getline(std::cin,matkhau);
        for(int i=0;i<name.size();i++){
            if(ten==name[i]&&matkhau==password[i]){
                ften=1;fmk=1;
                break;
            }
        }
        if(fmk==0||ften==0){
            std::cout<<"Dang nhap khong thanh cong\n";
            std::cout<<"Ten hoac mat khau sai\n";
        }
    }while(fmk==0&&ften==0);
    std::cout<<"Danh nhap thanh cong\n";
    std::cout<<"Chao "<<ten<<"\n"; 
}
void employee::additem(){
   item itemtemp;
   itemtemp.nhap();
   itemtemp.ghifile();
   listitem.push_back(itemtemp);
}
void employee::print_item(){
    for(int i=0;i<listitem.size();i++){
        std::cout<<"_____________________________\n";
        listitem[i].in();
    }
}
void employee::docfile_item(){
    std::ifstream inp("item.csv");
    std::string line,ftype,fname,fid,fcolor,fsize,fmadein,fbrand,fgioitinh,fmaterial;
    int fnumber,fyearmanu,fyyyy,fmm,fdd;
    long long fprice;
    while(getline(inp,line)){
        std::stringstream ss(line);
        getline(ss,ftype,',');
        getline(ss,fname,',');
        getline(ss,fid,',');
        getline(ss,fcolor,',');
        getline(ss,fsize,',');
        getline(ss,fmadein,',');
        getline(ss,fbrand,',');
        getline(ss,fgioitinh,',');
        getline(ss,fmaterial,',');
        ss>>fnumber>>fyearmanu>>fprice>>fyyyy>>fmm>>fdd;
        item itemtemp(ftype,fname,fid,fcolor,fmaterial,fsize,fmadein,fbrand,fgioitinh,fnumber,fyearmanu,fprice,fyyyy,fmm,fdd);
        listitem.push_back(itemtemp);
    }
}
void employee::create_transaction() {
    std::string mahang, tenhang, tenkhach, choice;
    int soluong = 0, xflag = -10;
    long long thanhtien = 0, giaca = 0;
    listbill.clear();
    std::cout << "Ten khach hang: ";
    std::cin.ignore();
    getline(std::cin, tenkhach);
    do {
        std::cout << BLUE << "--- Nhap san pham ---\n" << RESET;
        std::cout << "Nhap ma hang: ";
        getline(std::cin, mahang);
        xflag = -10;
        for (int i = 0; i < listitem.size(); i++) {
            if (listitem[i].findid(mahang)) {
                xflag = i;
                break;
            }
        }
        if (xflag == -10) {
            std::cout << RED << "Khong tim thay hang\n" << RESET;
            continue;
        }
        tenhang = listitem[xflag].getname();
        do {
            std::cout << "Nhap so luong: ";
            std::cin >> soluong;
            if (soluong > listitem[xflag].getnumber() || soluong <= 0) {
                std::cout << RED << "So luong khong hop le\n" << RESET;
                soluong = 0;
            }
        } while (soluong == 0);
        std::cin.ignore();
        giaca = listitem[xflag].getprice();
        bill billtemp(mahang, tenhang, giaca, soluong);
        listbill.push_back(billtemp);
        std::cout << "Tiep tuc nhap san pham? [c/k]: ";
        getline(std::cin, choice);
    } while (choice == "c" || choice == "C");
    if (listbill.empty()) {
        std::cout << RED << "Khong co san pham nao duoc them!\n" << RESET;
        return;
    }
    int print_choice;
    std::cout << BLUE << "=== Lua chon sau khi nhap ===" << RESET << endl;
    std::cout << "| 1. In hoa don ra file    |\n";
    std::cout << "| 2. Thoat                 |\n";
    std::cout << "============================\n";
    std::cout << "Nhap lua chon: ";
    std::cin >> print_choice;
    std::cin.ignore();

    if (print_choice == 1) {
        std::ofstream out("bill.csv", std::ios::app);
        if (!out.is_open()) {
            std::cout << RED << "Khong the mo file bill.csv" << RESET << endl;
            return;
        }
        out << "===== HOA DON BAN HANG =====\n";
        out << "Ten khach hang: " << tenkhach << "\n";
        out << "----------------------------\n";
        for (int i = 0; i < listbill.size(); i++) {
            thanhtien += listbill[i].tinhtien();
            listbill[i].create_bill(out);
        }
        out << "Tong tien: " << thanhtien << "\n";
        out << "============================\n\n";
        out.close();
        std::cout << GREEN << "Hoa don da duoc luu vao bill.csv\n" << RESET;
    }
    else {
        std::cout << GREEN << "Giao dich da hoan tat, khong in hoa don.\n" << RESET;
    }
}
void employee::loc(){
     int dem,flagc;
    std::string choice="",ftype,fcolor,fsize,fmaterial,fbrand,fgioitinh,fmadein; 
    do{
        dem=0,flagc=0;
        std::cout<<"---------------------\n";
        std::cout<<"Nhan Enter neu khong chon\n";
        std::cout<<"Loai trang phuc: \n";
        getline(std::cin,ftype);
        std::cout<<"Chon mau: ";
        getline(std::cin,fcolor);
        std::cout<<"Chon kich thuoc: ";
        getline(std::cin,fsize);
        std::cout<<"Chon chat lieu: ";
        getline(std::cin,fmaterial);
        std::cout<<"Chon gioi tinh: ";
        getline(std::cin,fgioitinh);
        std::cout<<"Chon quoc gia: ";
        getline(std::cin,fmadein);
        if(!ftype.empty()){
            dem++;
        }
        if(!fcolor.empty()){
            dem++;
        }
        if(!fsize.empty()){
             dem++;   
        }
        if(!fmaterial.empty()){
            dem++;
        }
        if(!fgioitinh.empty()){
            dem++;
        }
        if(!fmadein.empty()){
            dem++;
        }
    for(int i=0;i<listitem.size();i++){
        if(listitem[i].advancefind(ftype,fcolor,fmaterial,fsize,fgioitinh,fmadein)==dem){
            listitem[i].in();
            flagc=1;
        }
    }
    if(flagc==0){
        std::cout<<"---Khong tim thay san pham---\n";
    }
    std::cout<<"Tim tiep ? [c/k]: ";
    getline(std::cin,choice);
}while(choice=="c"||choice=="C");
}
void employee::tim_kim_theo_ma(int &chiso){
    std::string choice="";
    chiso=-10;
    do{
        std::string id;
            std::cout<<"Nhap ma san pham: ";
            getline(std::cin,id);
            for(int i=0;i<listitem.size();i++){
                if(listitem[i].findid(id)){
                    listitem[i].in();
                    chiso=i;
                    break;
                    }
                }
            if(chiso==-10){
                std::cout<<"---Khong tim thay san pham---\n";
            }
        std::cout<<"Tim san pham khac ?[c/k]: ";
        getline(std::cin,choice);
    }while(choice=="c"||choice=="C");
}
void employee::thay_doi(){
    int chiso=-10,choice;
    std::cout<<"---Thay doi du lieu hang---\n";
    do{
        std::cout<<"----------------------------\n";
        std::cout<<"| 1 Tim san pham            |\n";
        std::cout<<"| 2 Luu thay doi            |\n";
        std::cout<<"| 3 Thoat                   |\n";
        std::cout<<"| Lua chon: ";
        std::cin>>choice;
        std::cin.ignore();
        if(choice==1){
                tim_kim_theo_ma(chiso);
                if(chiso!=-10){
                listitem[chiso].change();
            } 
        }
            else if(choice==2){
                std::ofstream out;
                out.open("item.csv",std::ios::out);
                for(int i=0;i<listitem.size();i++){
                    listitem[i].ghifile();
                }
            }          
    }while(choice!=3);
}
void employee::xoa_hang(){
    int choice,chiso=-10;
    std::cout<<"---Xoa san pham---\n";
    do{
        std::cout<<"| 1 Tim san pham \n";
        std::cout<<"| 2 Luu thay doi\n";
        std::cout<<"| 3 Thoat \n";
        std::cin>>choice;
        std::cin.ignore();
        if(choice==1){
            tim_kim_theo_ma(chiso);
                if(chiso!=-10){
                listitem.erase(listitem.begin()+chiso);
            } 
        }
            else if(choice==2){
                std::ofstream out;
                out.open("item.csv",std::ios::out);
                for(int i=0;i<listitem.size();i++){
                    listitem[i].ghifile();
                }
            }          
    }while(choice!=3);
}
void employee::xemgangmoinhap(){
    int songay,day,month,year;
    char dash;
    std::cout<<"Nhap so ngay: ";
    std::cin>>songay;
    std::cin.ignore();
    std::cout<<"Nhap ngay hien tai(dd-mm-yyyy): ";
    std::cin>>year>>dash>>month>>dash>>day;
    int startyear=year,startmonth=month,startday=day;
    startday-=songay;
    while(startday<=0){
        startmonth--;
        if(startmonth==0){
            startmonth=12;
            startyear--;
        }
        int Dayinmonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
        startday+=Dayinmonth[startmonth-1];
    }
    auto tinhngay=[](int y,int m, int d){
        return y*10000+m*100+d;
    };
    int ngayHienTai=tinhngay(year,month,day);
    int ngayBatDau=tinhngay(startyear,startmonth,startday);
    bool coHang=false;
    for(item sp:listitem){
        int itemyear=sp.getyear();
        int itemmonth=sp.getmonth();
        int itemday=sp.getday();
        int itemngay=tinhngay(itemyear,itemmonth,itemday);
        if(itemngay>=ngayBatDau && itemngay<=ngayHienTai){
            sp.in();
            coHang=true;
        }
    }
    if(!coHang) std::cout<<"Khong co mat hang nao duoc nhap trong "<<songay<<" ngay!\n";
}
class Quanly:public employee{
	private:
		string Aname,Apass;
	public:
		Quanly():Aname("admin"), Apass("password"){}
		void login(){
		    string ten,matkhau;
		    cout<<"---Dang nhap Quan Ly---\n";
		    cout<<"Ten: ";
		    getline(cin,ten);
		    cout<<"Mat khau: ";
		    getline(cin,matkhau);
		    if(ten==Aname&&matkhau==Apass){
		        cout<<GREEN<<"Dang nhap thanh cong voi vai tro Quan Ly\n"<<RESET;
		    }
		    else {
		        cout<<RED<<"Dang nhap that bai! Ten hoac mat khau sai.\n"<<RESET;
		        exit(0);
		    }
		}
		void themnv(){
			string ten,mk;
			cout<<"---Them nhan vien moi---\n ";
			cout<<"Ten nhan vien: ";getline(cin,ten);
			cout<<"Mat khau: ";getline(cin,mk);
			name.push_back(ten);
			password.push_back(mk);
			ofstream out("employees.csv",ios::app);
			out<<ten<<","<<mk<<endl;
			out.close();
			cout<<GREEN<<"Them nhan vien moi thanh cong!\n"<<RESET;
		}
		void xoaNV(){
			string ten;
			cout<<"Xoa nhan vien\n";
			cout<<"Nhap ten nhan vien can xoa";getline(cin,ten);
			bool found=false;
			for(int i=0;i<name.size();++i){
				if(name[i]==ten){
					name.erase(name.begin()+i);
					found=true;
					break;
				}
			}
			if(found){
				ofstream out("employees.csv",ios::out);
				for(int i=0;i<name.size();++i){
					out<<name[i]<<","<<password[i]<<endl;
				}
				out.close();
				cout<<GREEN<<"Xoa nhan vien thanh cong!\n"<<RESET;
			}
			else{
				cout<<RED<<"Khong tim thay nhan vien "<<ten<<" \n"<<RESET;
			}
		}
		void xemDS(){
			cout<<"Danh sach nhan vien\n";
			if(name.empty()){
				cout<<"Khong co nhan vien!\n";
				return;
			}
			for(int i=0;i<name.size();++i){
				cout<<"Nhan vien "<<i+1<<name[i]<<","<<password[i]<<endl;
			}
		}
		void thaydoithongtin(){
			string ten,newten,newmk;
			cout<<"---Thay doi thong tin nhan vien---\n";
			cout<<"Nhap ten nhan vien can thay doi: ";getline(cin,ten);
			bool found=false;
			for(int i=0;i<name.size();++i){
				if(name[i]==ten){
					found=true;
					cout<<"Nhap ten moi(Nhan ENTER de giu nguyen): ";getline(cin,newten);
					cout<<"Nhap mat khau moi(Nhan ENTER de giu nguyen): ";getline(cin,newmk);
					if(!newten.empty())	name[i]=newten;
					if(!newmk.empty())	password[i]=newmk;
					break;
				}
			}
			if(found){
				ofstream out("employees.csv",ios::out);
				for(int i=0;i<name.size();++i){
					out<<name[i]<<","<<password[i]<<endl;
				}
				out.close();
				cout<<GREEN<<"Thay doi thong tin thanh cong!\n"<<RESET;
			}
			else{
				cout<<RED<<"Khong tim thay nhan vien!\n"<<RESET;
			}
		}	
};
class KhachHang{
	protected:
		string name,sdt,diachi;
		vector<int> soluong;
		vector<string> maHang;
		vector<tm> ngaymua;
		vector<int> Tongtien;
	public:
         void nhap(){
                cout<<"---------------------------\n";
                cout<<"So dien thoai: \n";
                getline(cin,sdt);
                cout<<"Dia chi: \n";
                getline(cin,diachi);
            }
		void input(const vector<string>& row){
			name=row[0];sdt=row[1];diachi=row[2];
			if(!row[3].empty()&&!row[4].empty()&&!row[5].empty()){
				maHang.push_back(row[3]);soluong.push_back(stoi(row[4]));Tongtien.push_back(stoi(row[6]));
				stringstream ss(row[5]);
				int y,m,d;char dash;
				if(!(ss>>y>>dash>>m>>dash>>d)){
					throw runtime_error("du lieu ngay mua khong hop le!\n");
				}
				tm tgmua={};
				tgmua.tm_year=y-1900;
				tgmua.tm_mon=m-1;
				tgmua.tm_mday=d;
				ngaymua.push_back(tgmua);
			}
		}
		void nhaptufile(const string& tenfile,vector<KhachHang>& ds){
			ifstream fin(tenfile);
			string line;getline(fin,line);
			while(getline(fin,line)){
				stringstream ss(line);string temp;
				vector<string>row;
				while(getline(ss,temp,',')){
					row.push_back(temp);
				}
				if(row.size()<6)	continue;
				string sdt=row[1];
				bool daco=false;
				for(KhachHang& kh:ds){
					if(kh.getsdt()==sdt){
						int sl=stoi(row[4]),tongtien=stoi(row[6]);
						stringstream ssngay(row[5]);
						int y,m,d;char dash;
						if(!(ssngay>>y>>dash>>m>>dash>>d)){
							throw runtime_error("ngay khong hop le!\n");
						}
						kh.themGD(row[3],sl,y,m,d,tongtien);
						daco=true;
					}
				}
				if(!daco){
						KhachHang kh;
						kh.input(row);
						ds.push_back(kh);
					}
			}
			fin.close();
		}
		void themGD(string ma,int sl,int y,int m,int d,int tongtien){
			maHang.push_back(ma);
			soluong.push_back(sl);
			tm ngay={};
			ngay.tm_year=y-1900;ngay.tm_mon=m-1;ngay.tm_mday=d;
			ngaymua.push_back(ngay);
			Tongtien.push_back(tongtien);
		}
		void in(){
			cout<<"So dien thoai: "<<sdt<<endl;
			cout<<"Dia chi: "<<diachi<<endl;
			if(maHang.empty()){
				cout<<"Khong co lich su mua hang!\n";
			}
			else{
				cout<<"Lich su mua hang:\n";
				for(int i=0;i<maHang.size();++i){
					cout<<"Ma hang: "<<maHang[i]<<"	"<<"So luong: "<<soluong[i]<<"	"
					<<"Ngay mua: "<<ngaymua[i].tm_mday<<"-"<<ngaymua[i].tm_mon+1<<"-"<<ngaymua[i].tm_year+1900<<endl;
				}
			}
		}
		void xuatHD(){
			if(maHang.empty()){
				return;
			}
			else{
			cout<<"---HOA DON CUA BAN---\n";
			cout<<"Ho ten: "<<name<<endl;
			cout<<"---Chi tiet giao dich---\n ";
			int TongtienHD=0;
			for(int i=0;i<maHang.size();++i){
				cout<<"Ma hang: "<<maHang[i]<<endl;
				cout<<"Tong tien: "<<Tongtien[i]<<endl;
				cout<<"Ngay mua: "<<ngaymua[i].tm_mday<<"-"<<ngaymua[i].tm_mon+1<<"-"<<ngaymua[i].tm_year+1900<<endl;
				TongtienHD+=Tongtien[i];
			}
			cout<<"Tong tien hoa don: "<<TongtienHD<<endl;
			}
		}
		void themGdTuBanPhim(const vector<item>& dsHang){
			string ma;
			int sl,y,m,d;
			cout<<"Nhap ma hang: ";getline(cin,ma);
			cout<<"Nhap so luong: ";cin>>sl;cin.ignore();
			int price=-1;
			for(int i=0;i<dsHang.size();++i){
				if(dsHang[i].findid(ma)){
					price=dsHang[i].getprice();
				}
			}
			if(price==-1){
				cout<<"Khong tim thay mat hang!\n";
				return;
			}
			int tong=sl*price;
			cout<<"Nhap ngay mua(YYYY MM DD): ";cin>>y>>m>>d;cin.ignore();
			tm ngay={};
			ngay.tm_year=y-1900;
			ngay.tm_mon=m-1;
			ngay.tm_mday=d;
			maHang.push_back(ma);
			soluong.push_back(sl);
			Tongtien.push_back(tong);
			ngaymua.push_back(ngay);
			cout<<"Them GD thanh cong!\n";
		}
		void setThongTin(const string& t, const string& s, const string& d) {
		    name = t;
		    sdt = s;
		    diachi = d;
		}
		string getsdt()const{return sdt;}
		string getten()const{return name;}
		const vector<tm>& getNgayMua() const { return ngaymua; }
    	const vector<string>& getMaHang() const { return maHang; }
    	const vector<int>& getSoLuong() const { return soluong; }
};
class GiaoDich{
	private:
		string name,sdt,diachi;
	public:
		bool findname(string name,KhachHang*& found,vector<KhachHang>& ds){
			found=nullptr;
			for(int i=0;i<ds.size();++i){
				if(ds[i].getten()==name){
					ds[i].in();
					found=&ds[i];
					return true;
				}
			}
			cout<<"Khong tim thay khach hang phu hop!\n";
			return false;
		}
		void addGD(vector<KhachHang>& ds,const vector<item>& dsHang){
			string ten;cout<<"Nhap ten khach hang: ";getline(cin,ten);
			KhachHang* kh=nullptr;
			if(findname(ten,kh,ds)){
				cout<<"Khach hang da mua hang truoc do. Nhap GD moi: ";
				kh->themGdTuBanPhim(dsHang);
			}
			else{
				cout<<ten<<" la khach moi! Nhap thong tin khach hang: ";
				cout<<"Nhap so dien thoai: ";getline(cin,sdt);
				cout<<"Nhap dia chi: ";getline(cin,diachi);
                KhachHang khachmoi;
				khachmoi.setThongTin(ten,sdt,diachi);
				khachmoi.themGdTuBanPhim(dsHang);
				ds.push_back(khachmoi);
				cout<<"---Da them giao dich thanh cong---\n";
			}
		}
		void xoaGD(vector<KhachHang>& ds){
			string name;cout<<"Nhap ten can tim:";getline(cin,name);
			KhachHang* kh=nullptr;
			if(findname(name,kh,ds)){
				for(int i=0;i<ds.size();++i){
					if(&ds[i]==kh){
						ds.erase(ds.begin()+i);
						return;
					}
				}
			}
			else{
				cout<<"Khong tim thay khach hang phu hop!\n";
			}
		}
		void lichsumuahang(vector<KhachHang>& ds){
			int y1,m1,d1;int y2,m2,d2;char dash;
			cout<<"Nhap ngay bat dau(yyyy-mm-dd): ";cin>>y1>>dash>>m1>>dash>>d1;cin.ignore();
			cout<<"Nhap ngay ket thuc(yyyy-mm-dd): ";cin>>y2>>dash>>m2>>dash>>d2;cin.ignore();
			int ngayBD=y1*10000+m1*100+d1;
			int ngayKT=y2*10000+m2*100+d2;
			bool found=false;
			for(int i=0;i<ds.size();++i){
				vector<string> maHangs=ds[i].getMaHang();
				vector<tm> dates=ds[i].getNgayMua();
				vector<int> soluongs=ds[i].getSoLuong();
				for(int j=0;j<dates.size();++j){
					int ngayGD =(dates[j].tm_year+1900)*10000+(dates[j].tm_mon+1)*100+dates[j].tm_mday;
					if(ngayGD>=ngayBD && ngayGD<=ngayKT){
						cout<<"Khach hang: "<<ds[i].getten()<<" ";
						cout<<"Ma hang: "<<maHangs[j]<<" ";
						cout<<"So luong: "<<soluongs[j]<<" ";
						cout<<"Ngay mua: "<<dates[j].tm_mday<<"-"
                			<<dates[j].tm_mon+1<<"-"<<dates[j].tm_year+1900<<endl;
                		found=true;
					}
				}
			}
			if(!found)	cout<<"Khong tim thay lich su mua hang!\n";
		}
};
