﻿
#include "xu_li_de.h"
using namespace std;
#define width 1300
#define height 800
const int so_item = 22;
const int so_item_sv = 3;
const int dong = 9;
const int cot = 5;
const int Up = 72;
const int Down = 80;
const int ESC = 27;

int menu_tong(DS_LOP &ds_l, DS_SINH_VIEN &ds_sv, DS_CAU_HOI_THI &ds_cau, DS_MON_HOC &ds_mon);
int menu_tong_sv(DS_LOP &ds_l, DS_SINH_VIEN &ds_sv, DS_CAU_HOI_THI &ds_cau, DS_MON_HOC &ds_mon);
int menu_gv();
int menu_sv();
void ke_khung_doc_1();
void ke_khung_doc_2();
void ke_khung_doc_3();
void ke_khung_ngang_1();
void ke_khung_ngang_2();
void ke_khung_ngang_3();

void khung_menu();
void khung_login();
void khung_login_mini();

int login();



void ke_khung_doc_1()
{
	int x = 2, y = 2;
	while (y < 36)
	{
		gotoxy(x, y);
		cout << "  ";
		y++;
	}
}
void ke_khung_doc_2()
{
	int x = 40, y = 2;
	while (y < 36)
	{
		gotoxy(x, y);
		cout << "  ";
		y++;
	}
}
void ke_khung_doc_3()
{
	int x = 123, y = 2;
	while (y < 36)
	{
		gotoxy(x, y);
		cout << "  ";
		y++;
	}
}
void ke_khung_ngang_1()
{
	int x = 2, y = 1;
	while (x < 125)
	{
		gotoxy(x, y);
		cout << " ";
		x++;
	}
}
void ke_khung_ngang_2()
{
	int x = 2, y = 36;
	while (x < 125)
	{
		gotoxy(x, y);
		cout << " ";
		x++;
	}
}
void ke_khung_ngang_3()
{
	int x = 3, y = 7;
	while (x < 40)
	{
		gotoxy(x, y);
		cout << " ";
		x++;
	}
}
void ke_khung_ngang_4()
{
	int x = 42, y = 5;
	while (x < 125)
	{
		gotoxy(x, y);
		cout << "_";
		x++;
	}
}
void khung_login_mini()
{
	int x = 43, y = 22;
	while (x < 80)
	{
		gotoxy(x, y);
		cout << "_";
		x++;
	}

	int a = 43, b = 27;
	while (a < 80)
	{
		gotoxy(a, b);
		cout << "_";
		a++;
	}
	int e = 43, f = 25;
	while (e < 80)
	{
		gotoxy(e, f);
		cout << "-";
		e++;
	}
	color_khung();
	int c = 43, d = 23;
	while (d < 28)
	{

		gotoxy(c, d);
		cout << "|";
		d++;
	}
	int m = 80, n = 23;
	while (n < 28)
	{

		gotoxy(m, n);
		cout << "|";
		n++;
	}
}
void khung_menu()
{
	color_khung();
	ke_khung_doc_1();
	ke_khung_doc_2();
	ke_khung_doc_3();
	ke_khung_ngang_1();
	ke_khung_ngang_2();
	ke_khung_ngang_3();
	ke_khung_ngang_4();
}
void khung_login()
{
	color_khung();
	ke_khung_doc_1();
	ke_khung_doc_3();
	ke_khung_ngang_1();
	ke_khung_ngang_2();
	HighLight();
	khung_login_mini();
}


int menu_tong(DS_LOP &ds_l, DS_SINH_VIEN &ds_sv, DS_CAU_HOI_THI &ds_cau, DS_MON_HOC &ds_mon)
{

	system("cls");
	cau_hoi_thi *ds[100];
	int nds = 0;
	int chon;
	
	while (true)
	{
		chon = menu_gv();
		switch (chon)
		{
		case 2: // them lop
		{
			if (ds_l.sl >= 500)
			{
				gotoxy(60, 8);
				cout << "Them khong thanh cong vi vuot qua so lop cho phep!";
			}
			else
			{
				khung_them_lop();
				them_lop(ds_l);
				ghi_file_lop(ds_l);
			}
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 3:	// xoa lop
		{
			if (ds_l.sl == 0)
			{
				gotoxy(50, 8);
				cout << "Chua co lop nao de xoa ca!";
			}
			else
			{
				xoa_lop(ds_l);
				ghi_file_lop(ds_l);
			}
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 4:// chinh lop
		{
			if (ds_l.sl == 0)
			{
				gotoxy(50, 8);
				cout << "DATA RONG~~";
			}
			else
			{
				hieu_chinh_lop(ds_l);
				ghi_file_lop(ds_l);
			}
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 5: // in ds lop theo nien khoa
		{
			if (ds_l.sl == 0)
			{
				gotoxy(50, 8);
				cout << "KHONG CO LOP NAO DE IN CA";
				gotoxy(60, 35);
				system("pause");
			}
			else
			{
				in_ds_lop(ds_l);
				gotoxy(60, 35);
				system("pause");
			}

			break;
		}
		case 7:
		{
			nhap_sinh_vien(ds_l, ds_sv);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 8:
		{
			in_ds_sv(ds_sv);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 10:
		{
			if (ds_mon.sl >= 300)
			{
				gotoxy(50, 8);
				cout << "SO LUONG MON HOC VUOT QUA 300, XOA TRC KHI THEM";
				gotoxy(60, 35);
				system("pause");
			}
			else
			{				
				them_mon(ds_mon);
				sap_xep_chen(ds_mon);
				ghi_file_mon(ds_mon);
				gotoxy(60, 35);
				system("pause");
			} 
			break;
		}
		case 11:
		{
			xoa_mon(ds_mon);
			ghi_file_mon(ds_mon);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 12:
		{
			hieu_chinh_mon(ds_mon);
			ghi_file_mon(ds_mon);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 13:
		{
			xuat_mon(ds_mon);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 15:
		{
			nhap_cau_hoi(ds_cau,ds_mon);
			chuyen_cay_sang_mang(ds_cau.TREE, ds, nds);
			ghi_file_cau(ds, nds);
			giai_phong_ds_cau(ds, nds);
			Normal();
			gotoxy(60, 35);
			system("pause");
			//Sleep(2000);
			break;
		}
		case 16:
		{
			xoa_cau(ds_cau);
			chuyen_cay_sang_mang(ds_cau.TREE, ds, nds);
			ghi_file_cau(ds, nds);
			giai_phong_ds_cau(ds, nds);
			gotoxy(60, 35);
			system("pause");
			break;	
		}
		case 17:
		{
			hieu_chinh_cau(ds_cau, ds_mon);
			chuyen_cay_sang_mang(ds_cau.TREE, ds, nds);
			ghi_file_cau(ds, nds);
			giai_phong_ds_cau(ds, nds);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 18:
		{
			chuyen_cay_sang_mang(ds_cau.TREE, ds, nds);
			in_ds_cau_hoi(ds, nds);
			giai_phong_ds_cau(ds, nds);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 19:
		{			
			chuyen_cay_sang_mang(ds_cau.TREE, ds, nds);
			menu_thi(ds_mon, ds, nds);
			giai_phong_ds_cau(ds, nds);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 20:
		{
			// chưa kịp làm, sẽ bổ sung
			break;
		}
		case 21:
		{
			// chưa kịp làm, sẽ bổ sung
			break;
		}
		case so_item:
			HighLight();
			gotoxy(60, 20);
			cout << "DANG TAT CHUONG TRINH! ";
			gotoxy(60, 21);
			system("pause");
			return 0;
		case 27:
			HighLight();
			gotoxy(60, 20);
			cout << "DANG TAT CHUONG TRINH! ";
			gotoxy(60, 21);
			system("pause");
			return 0;
		}
		
	}
}
int menu_tong_sv(DS_LOP &ds_l, DS_SINH_VIEN &ds_sv, DS_CAU_HOI_THI &ds_cau, DS_MON_HOC &ds_mon)
{
	system("cls");
	cau_hoi_thi *ds[100];
	int nds = 0;
	int chon;
	while (true)
	{
		chon = menu_sv();
		switch (chon)
		{
		case 1: 
		{
			chuyen_cay_sang_mang(ds_cau.TREE, ds, nds);
			menu_thi(ds_mon, ds, nds);
			giai_phong_ds_cau(ds, nds);
			gotoxy(60, 35);
			system("pause");
			break;
		}
		case 2:	
		{
			break;
		}
		case so_item:
			return 0;
		case 27:
			return 0;
		}
	}
}
int menu_sv()
{
	while (true)
	{
		khung_menu();
		HighLight();
		gotoxy(5, 3);
		cout << "HUONG DAN:";
		gotoxy(5, 4);
		cout << "SU DUNG PHIM LEN XUONG DE MOVE";
		gotoxy(5, 5);
		cout << "ESC: THOAT";
		gotoxy(25, 5);
		cout << "ENTER: CHON";
		int chon = 0;

		Normal();
		char thucdon[so_item_sv][35] = {" + THI THU                        ",
										" + XEM LAI BAI LAM                ",
										" + EXIT                           " };
		for (int i = 0; i < so_item_sv; i++)
		{
			gotoxy(cot, dong + i);
			cout << thucdon[i];
		}
		HighLight();
		gotoxy(cot, dong + chon);
		cout << thucdon[chon];
		char kytu;
		xoa_nen();

		do
		{
			kytu = _getch();
			if (kytu == -32) kytu = _getch();
			if (kytu == 8) kytu != _getch();
			switch (kytu)
			{
			case Up:
			{
				if (chon > 0)
				{
					Normal();
					gotoxy(cot, dong + chon); cout << thucdon[chon];
					chon--;
					HighLight();
					gotoxy(cot, dong + chon); 	cout << thucdon[chon];
				}
				break;
			}
			case Down:
			{
				if (chon + 1 < so_item_sv)
				{
					Normal();
					gotoxy(cot, dong + chon);	cout << thucdon[chon];
					chon++;
					HighLight();
					gotoxy(cot, dong + chon); 	cout << thucdon[chon];
				}
				break;
			}
			case ESC:
			{
				return so_item_sv;
			}
			case 13:
			{
				return chon + 1;
			}
			}
		} while (true);
	}
}
int menu_gv()
{
	while (true)
	{		
		khung_menu();
		HighLight();
		gotoxy(5, 3);
		cout << "HUONG DAN:";
		gotoxy(5, 4);
		cout << "SU DUNG PHIM LEN XUONG DE MOVE";
		gotoxy(5, 5);
		cout << "ESC: THOAT";
		gotoxy(25, 5);
		cout << "ENTER: CHON";
		gotoxy(43, 3);
		cout << "                                                                               ";
		gotoxy(50, 3);
		cout << "ID: GIAO VIEN";

		int chon = 0;
		Normal();
		char thucdon[so_item][35] = { " + LOP                            ",
										"   - THEM LOP                     ",
										"   - XOA LOP                      ",
										"   - HIEU CHINH LOP               ",
										"   - IN DANH SACH LOP             ",
										" + SINH VIEN                      ",
										"   - THEM SINH VIEN               ",
										"   - IN DANH SACH SINH VIEN       ",
										" + MON HOC                        ",
										"   - THEM MON HOC                 ",
										"   - XOA MON HOC                  ",
										"   - HIEU CHINH MON               ",
										"   - IN DANH SACH MON             ",
										" + CAU HOI THI                    ",
										"   - THEM CAU HOI                 ",
										"   - XOA CAU HOI                  ",
										"   - HIEU CHINH CAU HOI           ",
										"   - IN DANH SACH CAU HOI         ",
										" + THI THU                        ",
										" + IN BAI THI CUA SINH VIEN       ",
										" + IN KET QUA THI CUA 1 LOP       ",
										" + EXIT                           " };
		for (int i = 0; i < so_item; i++)
		{
			gotoxy(cot, dong + i);
			cout << thucdon[i];
		}
		HighLight();
		gotoxy(cot, dong + chon);
		cout << thucdon[chon];
		char kytu;
		xoa_nen();
		do
		{
			kytu = _getch();
			if (kytu == -32) kytu = _getch();
			if (kytu == 8) kytu != _getch();
			switch (kytu)
			{
			case Up:
			{
				if (chon > 0)
				{
					Normal();
					gotoxy(cot, dong + chon); cout << thucdon[chon];
					chon--;
					HighLight();
					gotoxy(cot, dong + chon); 	cout << thucdon[chon];
				}
				break;
			}
			case Down:
			{
				if (chon + 1 < so_item)
				{
					Normal();
					gotoxy(cot, dong + chon);	cout << thucdon[chon];
					chon++;
					HighLight();
					gotoxy(cot, dong + chon); 	cout << thucdon[chon];
				}
				break;
			}
			case ESC:
			{
				return so_item;
			}
			case 13:
			{
				return chon + 1;
			}
			}
		} while (true);
		
	}	
}

int login()
{
	// =============== khai bao bien =================
	DS_SINH_VIEN ds_sv;
	DS_CAU_HOI_THI ds_cau;
	DS_MON_HOC ds_mon;
	DS_LOP ds_l;
	cau_hoi_thi *ds[1000];
	int nds = 0;
	// ============ load file ==================
	doc_file_ds_cau(ds_cau);
	doc_file_ds_lop(ds_l);
	doc_file_ds_mon(ds_mon);
	doc_file_ds_sv(ds_sv);
	
	system("cls");
	khung_login();
	string id;
	int count = 0, ch;
	string pass = "";
	HighLight();
	gotoxy(42, 6);
	cout << "  ___  _   _         _   _   _     ___     ";
	gotoxy(42, 7);
	cout << " / _ \\| | | |  /\\   | \\ | | | |   | o |   ";
	gotoxy(42, 8);
	cout << "| | | | | | | /  \\  |  \\| | | |    | |    ";
	gotoxy(42, 9);
	cout << "| | | | | | |/ /\\ \\ | . ' | | |    | |    ";
	gotoxy(42, 10);
	cout << "| |_| | |_| / ____ \\| |\\  | | |___ | |    ";
	gotoxy(42, 11);
	cout << " \\__\\_\\\\___/_/    \\_\\_| \\_| |_____|___|   ";
	gotoxy(18, 13);
	cout << "  _______ _   _ ___    _______ _____           ___     _   _  ___  _   _ ___ _____  __    __   ";
	gotoxy(18, 14);
	cout << " |__   __| | | | o |  |__   __/  _  |   /\\    / _ \\   | \\ | |/ __\\| | | | o |  ___||  \\  /  |  ";
	gotoxy(18, 15);
	cout << "    | |  | |_| || |      | |  | | | |  /  \\  | / \\_\\  |  \\| | / __| |_| || || |___ | . \\/ . |  ";
	gotoxy(18, 16);
	cout << "    | |  |  _  || |      | |  | |/ /  / /\\ \\ | |  __  | . ' | |[_ ]  _  || ||  ___|| |\\  /| |  ";
	gotoxy(18, 17);
	cout << "    | |  | | | || |      | |  | | \\ \\/ ____ \\| \\_/ /  | |\\  | \\_/ / | | || || |___ | | \\/ | |  ";
	gotoxy(18, 18);
	cout << "    |_|  |_| |_|___|     |_|  |_|  \\/_/    \\_\\\\___/   |_| \\_|\\___/|_| |_|___|_____|___|  |___| ";
wrong:
	HighLight();

	

	gotoxy(45, 24);
	cout << "NHAP ID	:";
	gotoxy(45, 26);
	cout << "NHAP PASS	:";
	gotoxy(60, 24);
	getline(cin, id);
	chuan_hoa_chu(id);
	gotoxy(60, 26);
	while (ch = _getch())
	{
		bool kt_break = false;

		if (ch == 80 || ch == 72 || ch == 77 || ch == 75) ch = _getch();
		else if(ch == 27) break;
		else
		{
			if (ch == 13)
			{
				int i = 0;
				for (SINH_VIEN *k = ds_sv.p_head; k != NULL; k = k->p_next)
				{
					if ((id == k->ma_sv) && (pass == k->password))
					{
						gotoxy(52, 30);
						cout << "LOGIN  SUCCESSFUL!";
						gotoxy(48, 35);
						system("pause");
						gotoxy(43, 3);
						cout << "                                                                                 ";
						gotoxy(55, 3);
						cout << "ID: " << k->ma_sv << "                   NAME: " << k->ho << " " << k->ten;
						menu_tong_sv(ds_l, ds_sv, ds_cau, ds_mon);
						break;
					} i++;
				}
				if ((pass == "GV") && (id == "GV"))
				{
					gotoxy(52, 30);
					cout << "LOGIN SUCCESSFUL!";
					gotoxy(48, 35);
					system("pause");
					menu_tong(ds_l, ds_sv, ds_cau, ds_mon);
					kt_break = true;
					break;
				}
				gotoxy(55, 30);
				cout << "LOGIN FALSE!";
				pass = "";
				count++;
				if (count == 3)
				{
					cout << "YOU ENTER WRONG 3 TIMES, SYSTEM SUT DOWN AFTER 3 SECONDS!";
					return 0;
				}				
				gotoxy(60, 24);
				cout << "                    ";
				gotoxy(60, 26);
				cout << "                    ";
				goto wrong;
			}
			else if (ch == 8)
			{
				if (pass.length() > 0)
				{
					cout << "\b \b";
					pass.erase(pass.length() - 1);
				}
			}
			else
			{
				cout << "*";
				pass += ch;
				chuan_hoa_chu(pass);
			}
		}
		if (kt_break == true)
		{
			break;
		}
	}

}

//int Menu(char td[8][80]) {
//
//	system("cls");
//	int chon = 0;
//	int i;
//	for (i = 0; i < 8; i++)
//	{
//		gotoxy(cot, dong + i);
//		cout << td[i];
//	}
//Nhaplai:
//	gotoxy(cot, dong + so_item);
//	cout << "Ban chon 1 so (1..10) :    ";
//	gotoxy(wherex() - 4, wherey());
//	cin >> chon;
//	if (chon <1 || chon >8) goto Nhaplai;
//	return chon;
//}

