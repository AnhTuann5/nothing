#include "chucnang.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
class chuongtrinh{
	private:
		Quanly manager;
		employee emp;
		vector<KhachHang> dsKH;
		GiaoDich Gd;
		void mainmenu(){
			cout<<"===CHUONG TRINH QUAN LY QUAN AO===\n";
			cout<<"|1. Dang nhap voi vai tro quan ly.	|\n";
			cout<<"|2. Dang nhap voi vai tro nhan vien.	|\n";
			cout<<"|3. Thoa							|\n";
			cout<<"=====================================\n";
			cout<<"Nhap lua chon: ";
		}
		void menuQL(){
			cout<<"===MENU QUAN LY===\n";
			cout<<"|1. Quan ly san pham.	|\n";
			cout<<"|2. Quan ly nhan vien.	|\n";
			cout<<"|3. Quan ly khach hang.	|\n";
			cout<<"========================="<<endl;
			cout<<"Nhap lua chon: ";
		}
		void menuNV() {
        cout<<"===MENU NHAN VIEN==="<< endl;
        cout<<"|1. Them san pham                 |" << endl;
        cout<<"|2. Xem san pham                  |" << endl;
        cout<<"|3. Xoa san pham                  |" << endl;
        cout<<"|4. Tim san pham theo ma          |" << endl;
        cout<<"|5. Tim san pham theo yeu cau     |" << endl;
        cout<<"|6. Lap hoa don                   |" << endl;
        cout<<"|7. Xem san pham nhap theo ngay   |" << endl;
        cout<<"|8. Thay doi so lieu san pham     |" << endl;
        cout<<"|0. Thoat chuong trinh            |" << endl;
        cout<<"|________________________________|" << endl;
        cout<<"Nhap lua chon: ";
    }
		void menuSP(){
			cout<<"===MENU QUAN LY SAN PHAM===\n";
			cout<<"|1. Them san pham.				|\n";
			cout<<"|2. Xem danh sach san pham.		|\n";
			cout<<"|3. Xoa san pham.				|\n";
			cout<<"|4. Tim san pham theo ma.		|\n";
			cout<<"|5. Tim theo yeu cau				|\n";
			cout<<"|6. Lap hoa don.					|\n";
			cout<<"|7. Xem san pham nhap theo ngay	|\n";
			cout<<"|8. Thay doi so lieu san pham	|\n";
			cout<<"|0. Thoat chuong trinh.			|\n";
			cout<<"================================="<<endl;
			cout<<"Nhap lua chon:";
		}
		void menuQLNV(){
			cout<<"===MENU NHAN VIEN===\n";
			cout<<"|1. Them nhan vien.				|\n";
			cout<<"|2. Xoa nhan vien.				|\n";
			cout<<"|3. Xem danh sach nhan vien.		|\n";
			cout<<"|4. Thay doi thong tin nhan vien.|\n";
			cout<<"|5. Tro ve.						|\n";
			cout<<"=================================\n";
			cout<<"Nhap lua chon: ";
		}
		void menuKH(){
			cout<<"===MENU KHACH HANG===\n";
			cout<<"|1. Them giao dich moi.	|\n";
			cout<<"|2. Xe, lich su mua hang.|\n";
			cout<<"|3. Xoa giao dich.		|\n";
			cout<<"|4. Xem hoa don.			|\n";
			cout<<"|5. Tro ve.				|\n";
			cout<<"========================="<<endl;
			cout<<"NHap lua chon: ";
		}
	public:
		void input(){
			emp.docfile_thanhvien("employees.csv");
			emp.docfile_item();
			KhachHang kh;kh.nhaptufile("khachhang.csv",dsKH);
		}
		void start(){
			int choice;
			do{
				mainmenu();
				cin>>choice;cin.ignore();
				switch(choice){
					case 1:{
						manager.login();
						QL();
						break;
					}
					case 2:{
						emp.login();
						employeeMenu();
						break;
					}
					case 3:{
						cout<<"Thoat chuong trinh!"<<endl;
						break;
					}
					default:
                    	cout<<RED<<"Lua chon khong hop le!"<<RESET<<endl;
				}
			}while(choice!=3);
		}
	private:
		void QL(){
			int choice;
			do{
				menuQL();
				cin>>choice;cin.ignore();
				switch(choice){
					case 1:{
						SP();
						break;
					}
					case 2:{
						NV();
						break;
					}
					case 3:{
						KH();
						break;
					}
					default:
                    	cout<<RED<<"Lua chon khong hop le!"<<RESET<<endl;
				}
			}while(choice!=4);
		}
		void SP(){
			int choice,none;
			do{
				menuSP();
				cin>>choice;cin.ignore();
				switch(choice){
					case 1:{
						emp.additem();
						break;
					}
					case 2:{
						emp.print_item();
						break;
					}
					case 3:{
						emp.xoa_hang();
						break;
					}
					case 4:{
						emp.tim_kim_theo_ma(none);
						break;
					}
					case 5:{
						emp.loc();
						break;
					}
					case 6:{
						emp.create_transaction();
						break;
					}
					case 7:{
						emp.xemgangmoinhap();
						break;
					}
					case 8:{
						emp.thay_doi();
						break;
					}
					default:
                    	cout<<RED<<"Lua chon khong hop le!"<<RESET<<endl;
				}
			}while(choice!=0);
		}
		void NV(){
			int choice;
			do{
				menuQLNV();
				cin>>choice;cin.ignore();
				switch(choice){
					case 1:{
						manager.themnv();
						break;
					}
					case 2:{
						manager.xoaNV();
						break;
					}
					case 3:{
						manager.xemDS();
						break;
					}
					case 4:{
						manager.thaydoithongtin();
						break;
					}
					default:
                    	cout<<RED<<"Lua chon khong hop le!"<<RESET<<endl;
				}
			}while(choice!=5);
		}
		void KH(){
			int choice;
			do{
				menuKH();
				cin>>choice;cin.ignore();
				switch(choice){
					case 1:{
						Gd.addGD(dsKH,emp.listitem);
						break;
					}
					case 2:{
						Gd.lichsumuahang(dsKH);
						break;
					}
					case 3:{
						Gd.xoaGD(dsKH);
						break;
					}
					case 4:{
						string ten;
	                    cout<<"Nhap ten khach hang: ";
	                    getline(cin, ten);
	                    KhachHang* kh=nullptr;
	                    if (Gd.findname(ten,kh,dsKH)) {
	                        kh->xuatHD();
	                    }
						break;
					}
					default:
                    	cout<<RED<<"Lua chon khong hop le!"<<RESET<<endl;
				}
			}while(choice!=5);
		}
		void employeeMenu() {
        int choice;
        do {
            menuNV();
            cin >> choice;cin.ignore();
            switch (choice) {
                case 1:
                    emp.additem();
                    break;
                case 2:
                    emp.print_item();
                    break;
                case 3:
                    emp.xoa_hang();
                    break;
                case 4:
                	int chiso;
                    emp.tim_kim_theo_ma(chiso);
                    break;
                case 5: {
                    emp.loc();
                    break;
                }
                case 6:
                    emp.create_transaction();
                    break;
                case 7:
                    emp.xemgangmoinhap();
                    break;
                case 8:
                    emp.thay_doi();
                    break;
                case 9:
                    cout<<GREEN<<"Dang xuat thanh cong!"<<RESET<<endl;
                    break;
                default:
                    cout<<RED<<"Lua chon khong hop le!"<<RESET<<endl;
            }
        }while(choice!=9);
    }
};

