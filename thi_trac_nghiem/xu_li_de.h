﻿
#include "doc_ghi_file.h"


//=============================================================================
//============ Login ==========================
//void login();
/*if (user la : ma_sv; pass true)
{
	duoc thi;
	xem ket qua thi;
}
else if (user la GV, pass la GV)
{
	1. nhap lop (them, xoa. hieu chinh)
	2. Nhap sinh vien cua lop: nhap ma lop truoc, nhap sinh vien vao lop sau
	3. Nhap mon hoc: them, xoa, hieu chinh
	4. nhap cau hoi ( tu tao ra ID ngau nhien)
	5. Thi: mon thi -> so cau hoi -> time (phut) -> lay ngau nhien cau hoi
	6. In chi tiet cau hoi thi cua 1 sinh: nhap ma SV -> in ra cau hoi thi, diem
	7. In bang diem thi cua 1 lop: nhap ma lop -> in ra ds sinh vien da~ thi va chua thi
}*/
// ------------------------ LỚP -------------------------------------------
// ============================ them lop ==================================
void them_lop(DS_LOP &ds_l);

//============== ktra co trung lop hay chua =========================
int ktra_trung_lop(string a, DS_LOP ds_l);
//============= xoa lop =====================================
void xoa_lop(DS_LOP &dsl);
//============== In danh sach lop theo nien khoa ==========================
void in_ds_lop(DS_LOP ds_l);
//======================== ktra nien khoa co ton tai hay chua =================
int ktra_nien_khoa(string a, DS_LOP ds_l);
//================ hieu chinh lop ===================== 
void hieu_chinh_lop(DS_LOP &ds_l);
void giai_phong_bo_nho_lop(DS_LOP &ds_l);

//---------------------------------- SINH VIÊN ------------------------------------
//==================== SINH VIEN =========================
bool ktra_trung_ma_sv(SINH_VIEN *p_head, string ma);
SINH_VIEN* khoi_tao_node_sv();
void them_1_sinh_vien(SINH_VIEN *&p_head, SINH_VIEN *p);
void nhap_sinh_vien(DS_LOP &ds_l, DS_SINH_VIEN &ds_sv);
void giai_phong_ds_sv(DS_SINH_VIEN &ds_sv);
void in_ds_sv(DS_SINH_VIEN ds_sv);


// ----------------------------- MÔN ----------------------------------------------
// ======================== them mon hoc =====================
void them_mon(DS_MON_HOC &ds_mon);
void sap_xep_chen(DS_MON_HOC ds_mon);
// ====================== ktra mon hoc =======================
int ktra_trung_mon(string a, DS_MON_HOC ds_mon);
// =================== xoa mon hoc =====================
void xoa_mon(DS_MON_HOC &ds_mon);
// =================== hieu chinh mon hoc ================
void hieu_chinh_mon(DS_MON_HOC &ds_mon);
//==================== xuất môn hoc =========================
void xuat_mon(DS_MON_HOC ds_mon);
// =================== giải phóng bộ nhớ môn ====================
void giai_phong_bo_nho_mon(DS_MON_HOC &ds_mon);


//---------------------------- CÂU HỎI THI ------------------------------
//=========================== thêm câu hỏi ==============================
void nhap_cau_hoi(DS_CAU_HOI_THI &ds_cau);
cau_hoi_thi *khoi_tao_node_cau_hoi();
void xu_li_dap_an( cau_hoi_thi *p);
// ========================= ktra trung ma id ===========================
bool ktra_trung_id(tree t, int id_cau);
// ========================= tao ID câu hỏi ==============================
int tao_id_cau_hoi(tree t);
void them_1_cau_hoi(tree &t, cau_hoi_thi *p);
// ======================= chuyen cay sang mang ==========================
void chuyen_cay_sang_mang(tree t, cau_hoi_thi *ds[], int &nds);
//======================= in ds cau hoi ==================================
void in_ds_cau_hoi(cau_hoi_thi *ds[], int &nds);
//================= giai phong vung nho tree ===============
void giai_phong_ds_cau(cau_hoi_thi *ds[], int &nds);
// ================ hoán vị =======================
void hoan_vi_2_cau(cau_hoi_thi *a, cau_hoi_thi *b);
// ================ xoá 1 câu hỏi ====================
void xoa_cau(ds_cau_hoi_thi &ds_cau);
void xoa_1_cau(tree &t, int id_cau);
// ================ node thế mạng ====================
void node_the_mang(tree &t, cau_hoi_thi *x);
// =============== hiệu chỉnh 1 câu ===================
void hieu_chinh_1_cau(tree t, int id_cau, DS_MON_HOC &ds_mon);
//============= hieu chinh cau hoi ==========

void hieu_chinh_cau(DS_CAU_HOI_THI &ds_cau, DS_MON_HOC &ds_mon);
// ------------------------ THI ----------------------------
void shuffle_array(cau_hoi_thi *ds[], int nds); // xao tron bo cau hoi truoc khi phat de
void bo_de(cau_hoi_thi *ds[], int &nds,string a,int n, int minute, int second);




//=================================== Menu chinh =========================
//void menu_lop(DS_LOP &ds_l);
//void menu_sinh_vien(DS_LOP &ds_l, DS_SINH_VIEN &ds_sv);
//void menu_mon_hoc(DS_MON_HOC &ds_mon);
//void menu_de_thi(DS_CAU_HOI_THI &ds_cau, DS_MON_HOC &ds_mon);
//void menu_thi(DS_MON_HOC &ds_mon, cau_hoi_thi *ds[], int &nds);
//void menu_thi(cau_hoi_thi *ds[], int &nds, string a, int n);
//void menu_sv();
//void menu_gv();
//=================== Login ======================
//void menu_sv()
//{
//	// =============== khai bao bien =================
//	DS_SINH_VIEN ds_sv;
//	DS_CAU_HOI_THI ds_cau;
//	DS_MON_HOC ds_mon;
//	DS_LOP ds_l;
//	bool kt = true;
//	// ============ load file ==================
//	doc_file_ds_cau(ds_cau);	
//	//===============Login=========================
//	// ============= xu li menu =====================
//	while (kt = true)
//	{
//		int lua_chon;
//		system("cls");
//		cout << "1. Thi thu" << endl;
//		cout << "2. Ket qua thi thu" << endl;
//		cout << "3. In chi tiet bai lam cua 1 sinh vien." << endl;
//		cout << "0. Thoat." << endl;
//
//		cout << "Nhap lua chon: ";
//		cin >> lua_chon;
//
//		switch (lua_chon)
//		{
//		case 1:
//		{
//			system("cls");
//			menu_lop();
//			break;
//		}
//		case 2:
//		{
//			system("cls");
//			/*nhap_sinh_vien(ds_l, ds_sv);*/
//			system("pause");
//			break;
//		}
//		case 3:
//		{
//			system("cls");
//			menu_mon_hoc();
//		}
//		case 4:
//		{
//			system("cls");
//			menu_de_thi();
//			break;
//		}
//		case 0:
//		{
//			giai_phong_bo_nho_lop(ds_l);
//			giai_phong_bo_nho_mon(ds_mon);
//			kt = false;
//			break;
//		}
//		}
//	}
//}

// ===================== MENU ========================
//void menu_gv()
//{
//	// =============== khai bao bien =================
//	DS_SINH_VIEN ds_sv;
//	DS_CAU_HOI_THI ds_cau;
//	DS_MON_HOC ds_mon;
//	DS_LOP ds_l;
//	cau_hoi_thi *ds[200];
//	int nds = 0;
//	bool kt = true;
//	// ============ load file ==================
//	doc_file_ds_cau(ds_cau);
//	doc_file_ds_lop(ds_l);
//	doc_file_ds_mon(ds_mon);
//	doc_file_ds_sv(ds_sv);
//	//===============Login=========================
//	// ============= xu li menu =====================
//	while (kt = true)
//	{
//		int lua_chon;
//		system("cls");
//		cout << "1. Lop hoc cua truong " << endl;
//		cout << "2. Sinh vien cua truong." << endl;
//		cout << "3. Mon hoc." << endl;
//		cout << "4. He thong cau hoi." << endl;
//		cout << "5. Thi thu" << endl;
//		cout << "6. Ket qua thi thu" << endl;
//		cout << "7. In chi tiet bai lam cua 1 sinh vien." << endl;
//		cout << "8. In bang diem cua lop." << endl;
//		cout << "0. Thoat." << endl;	
//		cout << "Nhap lua chon: ";
//		cin >> lua_chon;		
//		switch (lua_chon)
//		{
//			case 1:
//			{
//				system("cls");
//				menu_lop(ds_l);
//				break;
//			}
//			case 2:
//			{
//				system("cls");
//				menu_sinh_vien(ds_l, ds_sv);
//				/*system("pause");*/
//				break;
//			}
//			case 3:
//			{
//				system("cls");
//				menu_mon_hoc(ds_mon);
//				break;
//			}
//			case 4:
//			{
//				system("cls");
//				menu_de_thi(ds_cau, ds_mon);
//				break;
//			}
//			case 5:
//			{
//				system("cls");
//				chuyen_cay_sang_mang(ds_cau.TREE, ds, nds);
//				menu_thi(ds_mon, ds, nds);
//				system("pause");
//				break;
//			}
//			case 0:
//			{
//				kt = false;
//				
//				break;
//			}
//		}
//	}
//}
////=========================== Menu Lop ==============================
//void menu_lop(DS_LOP &ds_l)
//{	
//	// ======================= khai bao bien ====================
//	/*DS_LOP ds_l;
//	DS_SINH_VIEN ds_sv;*/
//	bool kt = true;
//	// ======================= load file ===================
//	/*doc_file_ds_lop(ds_l);*/
//	// ======================= xu li file =========================
//	while (kt == true)
//	{
//		int lua_chon;
//		system("cls");
//		cout << "1. Them lop." << endl;
//		cout << "2. Xoa lop." << endl;
//		cout << "3. Hieu chinh lop." << endl;
//		cout << "4. In danh sach lop theo khoa." << endl;
//		cout << "0. Thoat!" << endl;
//		cout << "Nhap lua chon: ";
//		cin >> lua_chon;
//		switch (lua_chon)
//		{
//			case 1:
//			{
//				if (ds_l.sl >= 500)
//				{
//					cout << "Them khong thanh cong vi vuot qua so lop cho phep!" << endl;
//					system("pause");
//				}
//				else
//				{
//					them_lop(ds_l);
//					cout << "Them thanh cong!" << endl;
//					system("pause");
//				}					
//				break;
//				}
//				case 2:
//				{
//					if (ds_l.sl == 0)
//					{
//						cout << "Chua co lop nao de xoa ca!" << endl;
//						system("pause");
//					}
//					else
//					{
//						xoa_lop(ds_l);
//					}
//					break;
//			}
//			case 3:
//			{
//				if (ds_l.sl == 0)
//				{
//					cout << "Data rong~ !" << endl;
//					system("pause");
//				}
//				else
//				{
//					hieu_chinh_lop(ds_l);
//					system("pause");
//				}
//				break;
//			}
//			case 4:
//			{
//				if (ds_l.sl == 0)
//				{
//					cout << "Khong co lop nao de in ca!" << endl;
//					system("pause");
//				}
//				else
//				{
//					in_ds_lop(ds_l);
//					system("pause");
//				}
//				break;
//			}
//			
//			case 0:
//			{
//				kt = false;
//				break;
//			}
//		}
//	}
//}
//void menu_sinh_vien(DS_LOP &ds_l, DS_SINH_VIEN &ds_sv)
//{
//	bool kt = true;
//	while (kt == true)
//	{
//		int lua_chon;
//		system("cls");
//		cout << "1. Them 1 sinh vien." << endl;
//		cout << "2. In danh sach sinh vien." << endl;
//		cout << "0. Thoat." << endl;
//		cout << "Nhap lua chon: ";
//		cin >> lua_chon;
//		switch (lua_chon)
//		{
//		case 1:
//		{
//			nhap_sinh_vien(ds_l, ds_sv);
//			break;
//		}
//		case 2:
//		{
//			in_ds_sv(ds_sv);
//			system("pause");
//			break;
//		}
//		case 0:
//		{
//			kt = false;
//			break;
//		}
//		}
//	}
//}
//void menu_mon_hoc(DS_MON_HOC &ds_mon)
//{
//	bool kt = true;
//	while (kt == true)
//	{
//		int lua_chon;
//		system("cls");
//		cout << "1. Them mon hoc. " << endl;
//		cout << "2. Xoa mon hoc." << endl;
//		cout << "3. Hieu chinh mon hoc." << endl;
//		cout << "4. Xuat danh sach mon hoc." << endl;
//		cout << "0. Thoat." << endl;
//		cout << "Nhap lua chon: ";
//		cin >> lua_chon;
//		switch (lua_chon)
//		{
//		case 1:
//		{
//			if (ds_mon.sl >= 300)
//			{
//				cout << "So luong mon hoc vuot qua so luong cko phep (300), hay xoa bot truoc khi them vao!";
//				system("pause");
//			}
//			else
//			{
//				system("cls");
//				them_mon(ds_mon);
//				sap_xep_chen(ds_mon); // sắp xếp mã môn học ngay sau khi nhập 
//				system("pause");
//			} 
//			break;
//		}
//		case 2:
//		{
//			system("cls");
//			xoa_mon(ds_mon);
//			system("pause");
//			break;
//		}
//		case 3:
//		{
//			system("cls");
//			hieu_chinh_mon(ds_mon);
//			system("pause");
//			break;
//		}
//		case 4:
//		{
//			system("cls");
//			xuat_mon(ds_mon);
//			system("pause");
//			break;
//		}
//		case 0:
//		{
//			kt = false;
//			break;
//		}
//		}
//	}
//}
//void menu_de_thi(DS_CAU_HOI_THI &ds_cau,DS_MON_HOC &ds_mon)
//{
//	cau_hoi_thi *ds[200];
//	int nds = 0;
//	
//	tree *t = NULL;
//	bool kt = true;
//	// ======================= load file ===================
//	//doc_file_ds_cau(ds_cau);
//	while (kt == true)
//	{
//		system("cls");
//		cout << "1. Them cau hoi thi" << endl;
//		cout << "2. In ds cau hoi thi" << endl;
//		cout << "3. Xoa cau hoi thi" << endl;
//		cout << "4. Chinh sua cau hoi thi" << endl;
//		cout << "0. Thoat!" << endl;
//		cout << "Nhap lua chon: ";
//		int luachon;
//		cin >> luachon;
//		switch (luachon)
//		{
//		case 1:
//		{
//			system("cls");
//			nhap_cau_hoi(ds_cau);
//			cout << "Them thanh cong!" << endl;
//			system("pause");
//			break;
//		}
//		case 2:
//		{
//			system("cls");	
//			chuyen_cay_sang_mang(ds_cau.TREE, ds, nds);
//			
//			in_ds_cau_hoi(ds, nds);
//			system("pause");
//			break;
//		}
//		case 3:
//		{
//			system("cls");
//			xoa_cau(ds_cau);
//			system("pause");
//			break;
//		}
//		case 4:
//		{
//			system("cls");
//			hieu_chinh_cau(ds_cau);
//			system("pause");
//			break;
//		}
//		case 0:
//		{
//			kt = false;
//			break;
//		}
//		}	
//	}	
//}


//============================ Them lop =========================
void them_lop(DS_LOP &ds_l)
{
	LOP *p = new LOP;
	
	gotoxy(70, 13);
	HighLight();
	cout << "NHAP THONG TIN LOP VAO BANG";
	HighLight();
	khung_them_lop();
	Normal();
	gotoxy(62, 18);
	cout << "MA LOP     :";
	gotoxy(62, 21);
	cout << "TEN LOP    :";
	gotoxy(62, 24);
	cout << "NIEN KHOA  :";
	gotoxy(80, 18);
	getline(cin, p->ma_lop);
	chuan_hoa_chu(p->ma_lop);
	while (ktra_trung_lop(p->ma_lop, ds_l) >= 0)
	{
		gotoxy(70, 27);
		cout << "MA BI TRUNG, NHAP LAI MA MOI!";
		gotoxy(80, 18);
		cout << "                         ";	
		gotoxy(80, 18);
		getline(cin, p->ma_lop);
		chuan_hoa_chu(p->ma_lop);
		gotoxy(70, 27);
		cout << "                                       ";
	}	
	gotoxy(80, 21);
	getline(cin, p->ten_lop);
	chuan_hoa_chu(p->ten_lop);
	gotoxy(80, 24);
	getline(cin, p->nien_khoa);	
	chuan_hoa_chu(p->nien_khoa);
	gotoxy(75, 27);
	cout << "THEM THANH CONG!";
	ds_l.ds[ds_l.sl] = p;
	ds_l.sl++;	
	ghi_file_lop(ds_l);
}
//====== ktra co trung lop hay chua =========================
int ktra_trung_lop(string a, DS_LOP ds_l)
{
	for (int i = 0; i < ds_l.sl; i++)
	{
		if (ds_l.ds[i]->ma_lop == a)
		{
			return i;
		}
	}
	return -1;
}

//======================== ktra nien khoa co ton tai hay chua =================
int ktra_nien_khoa(string a, DS_LOP ds_l)
{
	for (int i = 0; i < ds_l.sl; i++)
	{
		if (ds_l.ds[i]->nien_khoa == a)
		{
			return i;
		}
	}
	return -1;
}
//============= xoa lop =====================================
void xoa_lop(DS_LOP &ds_l)
{
	string a;
	Normal();
	gotoxy(50, 8);
	cout << "NHAP MA LOP BAN MUON XOA: ";
	getline(cin, a);
	chuan_hoa_chu(a);
	//================= ktra lop da co ton tai hay chua ============
	int ktra_a = ktra_trung_lop(a, ds_l);
	if (ktra_a < 0)
	{
		HighLight();
		gotoxy(60, 10);
		cout << "MA LOP KHONG TON TAI!";
	}
	else
	{
		int n;
		gotoxy(60, 10);
		cout << "                     ";
		
		for (int i = ktra_a; i < ds_l.sl - 1; i++)
		{
			ds_l.ds[i]->ma_lop = ds_l.ds[i + 1]->ma_lop;
			ds_l.ds[i]->ten_lop = ds_l.ds[i + 1]->ten_lop;
			ds_l.ds[i]->nien_khoa = ds_l.ds[i + 1]->nien_khoa;
		}
		LOP *tam = ds_l.ds[ds_l.sl - 1];
		ds_l.sl--;
		gotoxy(60, 10);
		cout << "XOA THANH CONG!";
		
	}
}
//================ hieu chinh lop =====================
void hieu_chinh_lop(DS_LOP &ds_l)
{
	string a;
	Normal();
	gotoxy(50, 8);
	cout << "NHAP MA LOP BAN CAN HIEU CHINH: ";
	getline(cin, a);
	chuan_hoa_chu(a);
	int ktra = ktra_trung_lop(a, ds_l);
	if (ktra < 0)
	{
		HighLight();
		gotoxy(65, 10);
		cout << "MA LOP KHONG TON TAI";
	}
	else
	{
		//============= hieu chinh ==========
		Normal();
		gotoxy(60, 10);
		cout << "Nhap ten lop      : ";
		gotoxy(60, 11);
		cout << "Nhap nien khoa    : ";
		HighLight();
		gotoxy(80, 10);
		getline(cin, ds_l.ds[ktra]->ten_lop);
		gotoxy(80, 11);
		getline(cin, ds_l.ds[ktra]->nien_khoa);
		chuan_hoa_chu(ds_l.ds[ktra]->ten_lop);
		chuan_hoa_chu(ds_l.ds[ktra]->nien_khoa);
		gotoxy(65, 13);
		cout << "DA~ THAY DOI THONG TIN LOP!";
	}
}
//============== In danh sach lop theo nien khoa ==========================
void in_ds_lop(DS_LOP ds_l)
{
	string a;
	Normal();
	gotoxy(50, 8);
	cout << "NHAP NIEN KHOA CUA LOP BAN MUON IN: ";
	getline(cin, a);
	chuan_hoa_chu(a);
	int ktra_a = ktra_nien_khoa(a, ds_l);
	if (ktra_a < 0)
	{
		HighLight();
		gotoxy(60, 10);
		cout << "KHONG TON TAI NIEN KHOA " << a << " DE IN!";
	}
	else
	{
		HighLight();
		gotoxy(51, 10);
		cout << "DANH SACH LOP CO NIEN KHOA " << a;
		gotoxy(50, 11);
		cout << "=======================================";
		for (int i = 0; i < ds_l.sl; i++)
		{
			if (ds_l.ds[i]->nien_khoa == a)
			{
				gotoxy(50, 12 + 3 * i); cout << "|";
				gotoxy(88, 12 + 3 * i); cout << "|";
				gotoxy(51, 12 + 3 * i);
				cout << " MA LOP    :   " << ds_l.ds[i]->ma_lop;
				gotoxy(50, 13 + 3 * i); cout << "|";
				gotoxy(88, 13 + 3 * i); cout << "|";
				gotoxy(51, 13 + 3 * i);
				cout << " TEN LOP   :   " << ds_l.ds[i]->ten_lop;
				gotoxy(50, 14 + 3 * i);
				cout << "---------------------------------------";
			}
		}
	}

}
void giai_phong_bo_nho_lop(DS_LOP &ds_l)
{
	for (int i = 0; i < ds_l.sl; i++)
	{
		delete ds_l.ds[i];
	}
}
//=============== lập ds sinh viên =====================
void nhap_sinh_vien(DS_LOP &ds_l, DS_SINH_VIEN &ds_sv)
{
	string a;
	gotoxy(55, 11);
	cout << "                     ";
	gotoxy(55, 12);
	cout << "                     ";
	gotoxy(55, 13);
	cout << "                     ";
	gotoxy(55, 14);
	cout << "                     ";
	
	gotoxy(87, 8);
	cout << "                     ";
	gotoxy(50, 10);
	cout << "                                                                ";
	gotoxy(50, 8);
	cout << "NHAP MA LOP BAN MUON THEM SINH VIEN: ";
	
	getline(cin, a);
	chuan_hoa_chu(a);

	if (ktra_trung_lop(a, ds_l) < 0)
	{
		gotoxy(50, 10);
		cout << "MA LOP KHONG TON TAI, YEU CAU NHAP LAI HOAC TAO MA MOI! ";
		Sleep(1000);
		int ktra = true;
		while (ktra)
		{
			int chon;
			xoa_nen();
			gotoxy(55, 11);
			cout << "1. Nhap lai ma lop." ;
			gotoxy(55, 12);
			cout << "2. Tao ma lop moi.";
			gotoxy(55, 13);
			cout << "0. Thoat!";
			gotoxy(55, 14);
			cout << "Ban chon: ";
			cin >> chon;
			gotoxy(55, 15);
			cout << "                    ";
			switch (chon)
			{
			case 1:
			{
				cin.ignore();
				nhap_sinh_vien(ds_l, ds_sv);
				break;
			}
			case 2:
			{
				xoa_nen();
				cin.ignore();
				them_lop(ds_l);
				break;
			}
			case 0:
			{
				ktra = false;
				break;
			}
			}
		}

	}
	else
	{
		gotoxy(55, 11);
		cout << "                  ";
		gotoxy(55, 12);
		cout << "                  ";
		gotoxy(55, 13);
		cout << "                  ";
		gotoxy(55, 14);
		cout << "                  ";
		SINH_VIEN *p = khoi_tao_node_sv();
		them_1_sinh_vien(ds_sv.p_head, p);
		// =============== them sinh vien vao ds sinh vien ====================
		p->ma_lop = a;
		khung_them_sv();
		HighLight();
		gotoxy(50, 10);
		cout << "***Luu y: Ma sinh vien la duy nhat va cung la id de dang nhap.";
		Normal();
		gotoxy(62, 15);
		cout << "MA SV      :";
		gotoxy(62, 18);
		cout << "HO SV      :";
		gotoxy(62, 21);
		cout << "TEN SV     :";
		gotoxy(62, 24);
		cout << "PHAI       :";
		gotoxy(62, 27);
		cout << "PASSWORD   :";
		string ma_sv;
		gotoxy(80, 15);
		getline(cin, ma_sv);
		chuan_hoa_chu(ma_sv);
		while (ktra_trung_ma_sv(ds_sv.p_head, ma_sv) == true)
		{
			HighLight();
			gotoxy(70, 30);
			cout << "MA BI TRUNG, NHAP LAI MA MOI!";
			gotoxy(80, 15);
			cout << "                         ";
			gotoxy(80, 15);
			getline(cin, p->ma_lop);
			chuan_hoa_chu(p->ma_lop);
			gotoxy(70, 29);
			cout << "                                       ";
		}
		p->ma_sv = ma_sv;
		gotoxy(80, 18);
		getline(cin, p->ho);
		gotoxy(80, 21);
		getline(cin, p->ten);
		gotoxy(80, 24);
		getline(cin, p->phai);
		gotoxy(80,27);
		getline(cin, p->password);
		chuan_hoa_chu(p->ho);
		chuan_hoa_chu(p->ten);
		chuan_hoa_chu(p->phai);
		chuan_hoa_chu(p->password);
		/*cout << "Nhap sinh vien thanh cong!" << endl;
		cout << "Name: " << p->ten << " " << p->ho << ", " << p->phai << endl;
		cout << "MSSV: " << p->ma_sv << endl;
		cout << "PASS: " << p->password << endl;*/
		/*ghi_file_1_sv(ds_sv);*/
		ds_sv.sl++;
		ghi_file_sv(ds_sv);
		/*giai_phong_ds_sv(ds_sv);*/
	}
}
void in_ds_sv(DS_SINH_VIEN ds_sv)
{
	gotoxy(60, 8);
	cout << "============ DANH SACH SINH VIEN =============";
	gotoxy(45, 9); cout << "----------------------------------------------------------------------------";
	gotoxy(45, 10); cout << "|   MA LOP";
	gotoxy(60, 10); cout << "|     MSSV";
	gotoxy(75, 10); cout << "|           NAME";
	gotoxy(100, 10); cout << "| PHAI";
	gotoxy(108, 10); cout << "|   PASS";
	gotoxy(120, 10); cout << "| ";
	gotoxy(45, 11); cout << "----------------------------------------------------------------------------";
	int i = 0;
	for (SINH_VIEN *k = ds_sv.p_head; k != NULL; k = k->p_next)
	{
		gotoxy(45, 12 + 1 * i); cout << "| " << k->ma_lop;
		gotoxy(60,12 + 1 * i); cout << "| " << k->ma_sv;
		gotoxy(75, 12 + 1 * i); cout << "| " << k->ho << " " << k->ten;
		gotoxy(100, 12 + 1 * i); cout << "| " << k->phai;
		gotoxy(108, 12 + 1 * i); cout << "| " << k->password;
		gotoxy(120, 12 + 1 * i); cout << "| ";
		i++;
	}
	/*gotoxy(45, 11 + 1 * i); cout << "----------------------------------------------------------------------------";*/
}
void giai_phong_ds_sv(DS_SINH_VIEN &ds_sv)
{
	for (SINH_VIEN *k = ds_sv.p_head; k != NULL; k = k->p_next)
	{
		delete k;
	}
}
bool ktra_trung_ma_sv(SINH_VIEN *p_head, string ma)
{
	for (SINH_VIEN *k = p_head; k != NULL; k = k->p_next)
	{
		if (k->ma_sv == ma)
		{
			return true;
		}
	}
	return false;
}

//============================ Them mon =========================
void them_mon(DS_MON_HOC &ds_mon)
{
	MON_HOC *p = new MON_HOC;
	gotoxy(45, 8);
	cout << "** NOTE: MA MH TOI DA 15 KTU, TEN MH TOI DA 50 KTU";
	khung_them_mon();
	gotoxy(73, 14);	
	HighLight();
	cout << "NHAP THONG TIN MON HOC";
	string ma_mh;
	gotoxy(62, 18);
	cout << "MA MON     :";
	gotoxy(62, 21);
	cout << "TEN MON    :";
	do
	{
		gotoxy(80, 18);
		getline(cin, p->ma_mh);
		chuan_hoa_chu(p->ma_mh);
		gotoxy(68, 24);
		cout << "                                   ";
		if (p->ma_mh.length() > 15)
		{
			gotoxy(68, 24);
			cout << "Do dai vuot qua 15 ki tu, nhap lai!";
			
			gotoxy(80, 18);
			cout << "                              ";
		}
		while (ktra_trung_mon(p->ma_mh, ds_mon) >= 0)
		{
			gotoxy(68, 24);
			cout << "                                   ";
			gotoxy(68, 24);
			cout << "Ma mon bi trung, yeu cau ma moi ";
			gotoxy(80, 18);
			cout << "                              ";
			gotoxy(80, 18);
			getline(cin,p->ma_mh);
		}
	} while (p->ma_mh.length() > 15);
	//p->ma_mh = ma_mh;
	do
	{	
		gotoxy(80, 21);
		getline(cin, p->ten_mh);
		chuan_hoa_chu(p->ten_mh);
		if (p->ten_mh.length() > 50)
		{
			gotoxy(68, 24);
			cout << "                                        ";
			gotoxy(50, 24);
			cout << "Do dai vuot qua 50 ki tu, nhap lai!";
			gotoxy(80, 21);
			cout << "                              ";
		}
	} while (p->ten_mh.length() > 50);
	gotoxy(68, 24);
	cout << "                                   ";
	gotoxy(75, 24);
	cout << "NHAP THANH CONG!";
	
	ds_mon.ds[ds_mon.sl] = p;
	ds_mon.sl++;
}
//============= săp xếp chèn môn học ===================
void sap_xep_chen(DS_MON_HOC ds_mon) // insertionSort();
{
	int index;
	string value_ma, value_ten;
	for (int i = 1; i < ds_mon.sl; i++)
	{
		index = i;
		value_ma = ds_mon.ds[i]->ma_mh;
		value_ten = ds_mon.ds[i]->ten_mh;
		while (index > 0 && ds_mon.ds[index - 1]->ma_mh > value_ma)
		{
			ds_mon.ds[index]->ma_mh = ds_mon.ds[index - 1]->ma_mh;
			ds_mon.ds[index]->ten_mh = ds_mon.ds[index - 1]->ten_mh;
			index--;
		}
		ds_mon.ds[index]->ma_mh = value_ma;
		ds_mon.ds[index]->ten_mh = value_ten;
	}
}
//========================= ktra mon da duoc lap hay chua ===============
int ktra_trung_mon(string a, DS_MON_HOC ds_mon)
{
	for (int i = 0; i < ds_mon.sl; i++)
	{
		if (ds_mon.ds[i]->ma_mh == a)
		{
			return i;
		}
	}
	return -1;
}
//========================== Xoa mon hoc ==================
void xoa_mon(DS_MON_HOC &ds_mon)
{
	string a;
	Normal();
	gotoxy(50, 8);
	cout << "NHAP MA MON HOC BAN MUON XOA: ";
	getline(cin, a);
	chuan_hoa_chu(a);
	//===========ktra mon hoc da ton tai hay chua ================
	int ktra_a = ktra_trung_mon(a, ds_mon);
	if (ktra_a < 0)
	{
		HighLight();
		gotoxy(60, 10);
		cout << "Ma mon khong ton tai";
	}
	else
	{
		gotoxy(60, 10);
		cout << "                     ";
		for (int i = ktra_a; i < ds_mon.sl - 1; i++)
		{
			ds_mon.ds[i]->ma_mh = ds_mon.ds[i + 1]->ma_mh;
			ds_mon.ds[i]->ten_mh = ds_mon.ds[i + 1]->ten_mh;
		}
		MON_HOC *tam = ds_mon.ds[ds_mon.sl - 1];
		ds_mon.sl--;
		ghi_file_mon(ds_mon);
		gotoxy(60, 10);
		cout << "XOA THANH CONG!";
	}
}
//========================= Hieu chinh mon hoc ===================
void hieu_chinh_mon(DS_MON_HOC &ds_mon)
{
	string a;
	Normal();
	gotoxy(50, 8);
	cout << "NHAP MA MON BAN CAN HIEU CHINH: ";
	getline(cin, a);
	chuan_hoa_chu(a);
	int ktra = ktra_trung_mon(a, ds_mon);
	if (ktra < 0)
	{
		HighLight();
		gotoxy(60, 10);
		cout << "MA MON KHONG TON TAI!"<< endl;

	}
	else
	{
		
		// ============== hieu chinh =================
		Normal();
		gotoxy(60, 10);
		cout << "NHAP TEN MON: "; 
		gotoxy(80, 10);
		getline(cin, ds_mon.ds[ktra]->ten_mh);
		chuan_hoa_chu(ds_mon.ds[ktra]->ma_mh);
		chuan_hoa_chu(ds_mon.ds[ktra]->ten_mh);
		gotoxy(65, 13); HighLight();
		cout << "DA~ THAY DOI THONG TIN MON HOC.";
		sap_xep_chen(ds_mon);
		ghi_file_mon(ds_mon);
	}
}
//========================== xuat ds lop =========================
void xuat_mon(DS_MON_HOC ds_mon)
{
	HighLight();
	gotoxy(60, 10);
	cout << "DANH SACH MON HOC";
	gotoxy(50, 11);
	cout << "=======================================";
	for (int i = 0; i < ds_mon.sl; i++)
	{
		gotoxy(50, 12 + 3 * i); cout << "|";
		gotoxy(88, 12 + 3 * i); cout << "|";
		gotoxy(51, 12 + 3 * i);
		cout << " MA MON   :   " << ds_mon.ds[i]->ma_mh;
		gotoxy(50, 13 + 3 * i); cout << "|";
		gotoxy(88, 13 + 3 * i); cout << "|";
		gotoxy(51, 13 + 3 * i);
		cout << " TEN MON  :   " << ds_mon.ds[i]->ten_mh;
		gotoxy(50, 14 + 3 * i);
		cout << "---------------------------------------";
	}
}
//========================= giai phong bo nho mon ================
void giai_phong_bo_nho_mon(DS_MON_HOC &ds_mon)
{
	for (int i = 0; i < ds_mon.sl; i++)
	{
		delete ds_mon.ds[i];
	}
}

// ================= nhập câu hỏi =====================

void nhap_cau_hoi(DS_CAU_HOI_THI &ds_cau, DS_MON_HOC &ds_mon)
{
	cau_hoi_thi *p = khoi_tao_node_cau_hoi();
	p->id = tao_id_cau_hoi(ds_cau.TREE);
	string ma_mh;
	
	khung_cau_hoi();
	HighLight();
	gotoxy(70, 8);
	cout << "====== NHAP CAU HOI ======";
	gotoxy(50, 10);
	cout << "ID: " << p->id;
	gotoxy(80, 10);
	cout << "MA MH: "; getline(cin, ma_mh);
	chuan_hoa_chu(ma_mh);
	while (ktra_trung_mon(ma_mh, ds_mon) < 0)
	{
		gotoxy(68, 13);
		cout << "                                   ";
		gotoxy(68, 13);
		cout << "MA MON KHONG TON TAI! ";
		
		gotoxy(87, 10);
		cout << "                              ";
		gotoxy(87, 10);
		getline(cin, ma_mh);
		chuan_hoa_chu(ma_mh);
	}
	p->ma_mh = ma_mh;
	do
	{
		gotoxy(47, 13);
		cout << "CAU HOI: ";
		gotoxy(68, 13);
		cout << "                                   ";
		gotoxy(50, 18);
		cout << "                                 ";
		gotoxy(88, 18);
		cout << "                                ";
		gotoxy(50, 22);
		cout << "                                 ";
		gotoxy(88, 22);
		cout << "                                ";
		gotoxy(47, 18);
		cout << "A.";
		gotoxy(85, 18);
		cout << "B.";
		gotoxy(47, 22);
		cout << "C.";
		gotoxy(85, 22);
		cout << "D.";
		gotoxy(77, 27);
		cout << "DAP AN: ";
		gotoxy(56, 13);
		getline(cin, p->cau_hoi);
		gotoxy(50, 18);
		getline(cin, p->A);	
		gotoxy(88, 18);
		getline(cin, p->B);
		gotoxy(50, 22);
		getline(cin, p->C);
		gotoxy(88, 22);
		getline(cin, p->D);
		chuan_hoa_chu(p->cau_hoi);
		chuan_hoa_chu(p->A);
		chuan_hoa_chu(p->B);
		chuan_hoa_chu(p->C);
		chuan_hoa_chu(p->D);
		do
		{
			gotoxy(85, 27);
			cout << "    ";
			gotoxy(85, 27);
			cin >> p->dap_an;
			up_case_char(p->dap_an);
			if (p->dap_an != 'A' && p->dap_an != 'B' && p->dap_an != 'C' && p->dap_an != 'D')
			{
				gotoxy(65, 30);
				cout << "NHAP DAP AN KHONG HOP LE, YEU CAU NHAP LAI!";
			}
			if (p->A == p->B || p->A == p->C || p->A == p->D || p->B == p->C || p->B == p->D || p->C == p->D)
			{
				gotoxy(65, 30);
				cout << "                                           ";
				gotoxy(65, 30);
				cout << "CAC CAU DAP AN KHONG DUOC TRUNG NHAU";
			}
		} while (p->dap_an != 'A' && p->dap_an != 'B' && p->dap_an != 'C' && p->dap_an != 'D');
	} while (p->A == p->B || p->A == p->C || p->A == p->D || p->B == p->C || p->B == p->D || p->C == p->D );
	
	gotoxy(65, 30);
	cout << "                                           ";
	gotoxy(77, 30);
	cout << "NHAP THANH CONG!";
	xu_li_dap_an(p);
	them_1_cau_hoi(ds_cau.TREE, p);
	ds_cau.sl++;
}
int tao_id_cau_hoi(tree t)
{
	int id_cau;// 000->999;
	do
	{
		id_cau = rand() % (999 - 0 + 1) + 000;
	} while (ktra_trung_id(t, id_cau)==true);
	return id_cau;
}
bool ktra_trung_id(tree t, int id_cau)
{
	if (t == NULL)
	{
		return false;
	}
	else
	{
		if (t->id == id_cau)
		{
			return true;
		}
		else if (t->id < id_cau)
		{
			ktra_trung_id(t->p_right, id_cau);
		}
		else
		{
			ktra_trung_id(t->p_left, id_cau);
		}
	}
}
//============== chuyển cây sang mảng =====================
void chuyen_cay_sang_mang(tree t, cau_hoi_thi *ds[], int &nds)
{	
	if (t != NULL)
	{		
		ds[nds] = new cau_hoi_thi;
		ds[nds]->id = t->id;
		ds[nds]->ma_mh = t->ma_mh;
		ds[nds]->cau_hoi = t->cau_hoi;
		ds[nds]->A = t->A;
		ds[nds]->B = t->B;
		ds[nds]->C = t->C;
		ds[nds]->D = t->D;
		ds[nds]->dap_an = t->dap_an;
		ds[nds]->cau_dap_an = t->cau_dap_an;
		nds++;
		chuyen_cay_sang_mang(t->p_left, ds, nds);
		chuyen_cay_sang_mang(t->p_right, ds, nds);
	}
	/*delete[]ds;*/
}
//============== xuat TREE ================================

//================= giai phong vung nho tree ===============
void giai_phong_ds_cau(cau_hoi_thi *ds[], int &nds)
{
	for (int i = 0; i < nds; i++)
	{
		delete ds[i];
	}
	nds = 0;
}
// =============== xoa cau hoi =======================
void xoa_cau(ds_cau_hoi_thi &ds_cau)
{
	int a;
	gotoxy(50, 9);
	cout << "Nhap id cau hoi: ";
	cin >> a;
	bool kt = ktra_trung_id(ds_cau.TREE, a);
	if (kt == true)
	{
		gotoxy(50, 11);
		cout << "                         ";
		xoa_1_cau(ds_cau.TREE, a);
		ds_cau.sl--;
		gotoxy(50, 11);
		cout << "Xoa thanh cong!" ;
	}
	else
	{
		gotoxy(50, 11);
		cout << "Id cau hoi khong ton tai!";
	}
}
void xoa_1_cau(tree &t, int id_cau)
{
	if (t != NULL)
	{
		if (t->id == id_cau)
		{
			cau_hoi_thi *x = t; // x se luu node can giai phong
			if (t->p_left == NULL)
			{
				t = t->p_right;
			}
			else if (t->p_right == NULL)
			{
				t = t->p_left;
			}
			else if (t->p_left != NULL && t->p_right != NULL)
			{
				node_the_mang(t->p_right,x);
			}
			delete x;
		}
		else if (t->id < id_cau)
		{
			xoa_1_cau(t->p_right, id_cau);
		}
		else if (t->id > id_cau)
		{
			xoa_1_cau(t->p_left, id_cau);
		}
	}
}
void hoan_vi_2_cau(cau_hoi_thi *a, cau_hoi_thi *b)
{
	cau_hoi_thi *tam = new cau_hoi_thi;
	tam->id = a->id;
	tam->cau_hoi = a->cau_hoi;
	tam->A = a->A;
	tam->B = a->B;
	tam->C = a->C;
	tam->D = a->D;
	tam->dap_an = a->dap_an;
	tam->cau_dap_an = a->cau_dap_an;
	//---------------
	a->id = b->id;
	a->cau_hoi = b->cau_hoi;
	a->A = b->A;
	a->B = b->B;
	a->C = b->C;
	a->D = b->D;
	a->dap_an = b->dap_an;
	a->cau_dap_an = b->cau_dap_an;
	//---------------------
	b->id = tam->id;
	b->cau_hoi = tam->cau_hoi;
	b->A = tam->A;
	b->B = tam->B;
	b->C = tam->C;
	b->D = tam->D;
	b->dap_an = tam->dap_an;
	b->cau_dap_an = tam->cau_dap_an;
	delete tam;
}
void node_the_mang(tree &t, cau_hoi_thi *x)
{
	if (t->p_left != NULL)
	{
		node_the_mang(t->p_left,x);
	}
	else // trai cung
	{
		hoan_vi_2_cau(t, x);
		x = t; // x luu vi tri node nay de giai phong
		t = t->p_right;
	}
}
//============= hieu chinh cau hoi ==========
void hieu_chinh_cau(DS_CAU_HOI_THI &ds_cau,DS_MON_HOC &ds_mon)
{
	int a;
	gotoxy(50, 9);
	cout << "Nhap ID cau hoi can hieu chinh: "; cin >> a;
	bool kt = ktra_trung_id(ds_cau.TREE, a);
	if (kt == true)
	{
		gotoxy(50, 11);
		cout << "                 ";
		cin.ignore();
		hieu_chinh_1_cau(ds_cau.TREE, a,ds_mon);
	}
	else
	{
		gotoxy(50, 11);
		cout << "ID KHONG TON TAI!" ;
	}
	
}
void hieu_chinh_1_cau(tree t, int id_cau, DS_MON_HOC &ds_mon)
{
	if (t != NULL)
	{
		if (t->id == id_cau)
		{
			string ma_mh;
			khung_cau_hoi();
			HighLight();
			gotoxy(70, 8);
			cout << "==== CHINH SUA CAU HOI ====";
			gotoxy(50, 10);
			cout << "ID DUOC CHINH: " << t->id;
			gotoxy(80, 10);
			cout << "MA MH: "; getline(cin, ma_mh);
			chuan_hoa_chu(ma_mh);
			gotoxy(90, 10); cout << ma_mh;
			while (ktra_trung_mon(ma_mh, ds_mon) < 0)
			{
				gotoxy(68, 13);
				cout << "                                   ";
				gotoxy(68, 13);
				cout << "MA MON KHONG TON TAI! ";
				gotoxy(87, 10);
				cout << "                              ";
				gotoxy(87, 10);
				getline(cin, ma_mh);
				chuan_hoa_chu(ma_mh);
			}
			t->ma_mh = ma_mh;
			do
			{
				gotoxy(47, 13);
				cout << "CAU HOI: ";
				gotoxy(68, 13);
				cout << "                                   ";
				gotoxy(50, 18);
				cout << "                                 ";
				gotoxy(88, 18);
				cout << "                                ";
				gotoxy(50, 22);
				cout << "                                 ";
				gotoxy(88, 22);
				cout << "                                ";
				gotoxy(47, 18);
				cout << "A.";
				gotoxy(85, 18);
				cout << "B.";
				gotoxy(47, 22);
				cout << "C.";
				gotoxy(85, 22);
				cout << "D.";
				gotoxy(77, 27);
				cout << "DAP AN: ";
				gotoxy(56, 13);
				getline(cin, t->cau_hoi);
				gotoxy(50, 18);
				getline(cin, t->A);
				gotoxy(88, 18);
				getline(cin, t->B);
				gotoxy(50, 22);
				getline(cin, t->C);
				gotoxy(88, 22);
				getline(cin, t->D);
				chuan_hoa_chu(t->cau_hoi);
				chuan_hoa_chu(t->A);
				chuan_hoa_chu(t->B);
				chuan_hoa_chu(t->C);
				chuan_hoa_chu(t->D);
				do
				{
					gotoxy(85, 27);
					cout << "    ";
					gotoxy(85, 27);
					cin >> t->dap_an;
					up_case_char(t->dap_an);
					if (t->dap_an != 'A' && t->dap_an != 'B' && t->dap_an != 'C' && t->dap_an != 'D')
					{
						gotoxy(65, 30);
						cout << "NHAP DAP AN KHONG HOP LE, YEU CAU NHAP LAI!";
					}
					if (t->A == t->B || t->A == t->C || t->A == t->D || t->B == t->C || t->B == t->D || t->C == t->D)
					{
						gotoxy(65, 30);
						cout << "                                           ";
						gotoxy(65, 30);
						cout << "CAC CAU DAP AN KHONG DUOC TRUNG NHAU";
					}
				} while (t->dap_an != 'A' && t->dap_an != 'B' && t->dap_an != 'C' && t->dap_an != 'D');
			} while (t->A == t->B || t->A == t->C || t->A == t->D || t->B == t->C || t->B == t->D || t->C == t->D);			
			gotoxy(65, 30);
			cout << "                                           ";
			gotoxy(77, 30);			
			cout << "SUA? THANH CONG!";
			xu_li_dap_an(t);
		}
		else if (t->id > id_cau)
		{
			hieu_chinh_1_cau(t->p_left, id_cau,ds_mon);
		}
		else if (t->id < id_cau)
		{
			hieu_chinh_1_cau(t->p_left, id_cau,ds_mon);
		}
	}
}
void in_ds_cau_hoi( cau_hoi_thi *ds[], int &nds)
{
	int a = nds /3;	
	int b;
	if (nds % 3 == 0) b = a;
	else b = a + 1;
	
	while (true)
	{
		
		for (int j = 0; j < a;)
		{
			xoa_nen();
			char key;
			
			int m = 0;
			if (m == 2) m = 0;
			for (int i = 3 * j; i < 3 * j + 3; i++)
			{
				gotoxy(105, 35);
				cout << "Page " << j + 1 << "/" << b;
				gotoxy(50, 7 + 9 * m);
				cout << "======== Cau " << i + 1 << "==========";
				gotoxy(50, 8 + 9 * m);
				cout << "ID: " << ds[i]->id;
				gotoxy(50, 9 + 9 * m);
				cout << "Ma: " << ds[i]->ma_mh;
				gotoxy(50, 10 + 9 * m);
				cout << "Cau hoi: " << ds[i]->cau_hoi;
				gotoxy(50, 11 + 9 * m);
				cout << "Cau A: " << ds[i]->A;
				gotoxy(50, 12 + 9 * m);
				cout << "Cau B: " << ds[i]->B;
				gotoxy(50, 13 + 9 * m);
				cout << "Cau C: " << ds[i]->C;
				gotoxy(50, 14 + 9 * m);
				cout << "Cau D: " << ds[i]->D;
				gotoxy(50, 15 + 9 * m);
				cout << "Dap an la: " << ds[i]->dap_an << ". " << ds[i]->cau_dap_an;
				m++;
			}	
			key = _getch();
			if (key == 77)
			{
				if (j < a) j++;
				else if (j == a) goto page_last;
			}
			if (key == 75 && j > 0) j--;
			if (key == 27) break;
		}
		page_last:
		xoa_nen();
		int n = 0;
		for (int i = 3 * a; i < 3 * a + (nds % 3); i++)
		{
			gotoxy(105, 35);
			cout << "Page " << a + 1 << "/" << b;
			gotoxy(50, 7 + 9 * n);
			cout << "======== Cau " << i + 1 << "==========";
			gotoxy(50, 8 + 9 * n);
			cout << "ID: " << ds[i]->id;
			gotoxy(50, 9 + 9 * n);
			cout << "Ma: " << ds[i]->ma_mh;
			gotoxy(50, 10 + 9 * n);
			cout << "Cau hoi: " << ds[i]->cau_hoi;
			gotoxy(50, 11 + 9 * n);
			cout << "Cau A: " << ds[i]->A;
			gotoxy(50, 12 + 9 * n);
			cout << "Cau B: " << ds[i]->B;
			gotoxy(50, 13 + 9 * n);
			cout << "Cau C: " << ds[i]->C;
			gotoxy(50, 14 + 9 * n);
			cout << "Cau D: " << ds[i]->D;
			gotoxy(50, 15 + 9 * n);
			cout << "Dap an la: " << ds[i]->dap_an << ". " << ds[i]->cau_dap_an;
			n++;
		}
		
		break;
		gotoxy(60, 35);
		system("pause");

	}
}
void menu_thi(ds_mon_hoc &ds_mon, cau_hoi_thi *ds[], int &nds)
{
check_mon:
	string a;
	gotoxy(50, 10);
	cout << "                      ";
	gotoxy(77, 8);
	cout << "                      ";
	gotoxy(50, 8);
	cout << "NHAP MA MON BAN MUON THI: ";
	getline(cin, a);
	chuan_hoa_chu(a);
	if (ktra_trung_mon(a, ds_mon) < 0)
	{
		gotoxy(50, 10);
		cout << "MON HOC KHONG TON TAI!";
		goto check_mon;
	}
	int chon;

	bool kt = true;
	while (kt == true)
	{
		gotoxy(50, 10);
		cout << "CHON SO LUONG CAU HOI. ";
		gotoxy(50, 11);
		cout << "1. 20 CAU, 10 PHUT.";
		gotoxy(50, 12);
		cout << "2. 40 CAU, 20 PHUT.";
		gotoxy(50, 13);
		cout << "3. 60 CAU, 30 PHUT.";
		gotoxy(50, 14);
		cout << "0. RETURN. ";
		gotoxy(50, 15);
		cout << "CHON: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			gotoxy(55, 16);
			cout << "BAN CHON 20 CAU, TIME 10P";
			gotoxy(60, 35);
			system("pause");
			bo_de(ds, nds, a, 20, 10, 0);
			break;
		}
		case 2:
		{
			gotoxy(55, 16);
			cout << "BAN CHON 40 CAU, TIME 20P";
			gotoxy(60, 35);
			system("pause");
			bo_de(ds, nds, a, 40, 20, 0);
			break;
		}
		case 3:
		{
			gotoxy(55, 16);
			cout << "BAN CHON 60 CAU, TIME 30P";
			gotoxy(60, 35);
			system("pause");
			bo_de(ds, nds, a, 60, 30, 0);
			break;
		}
		case 0:
			cin.ignore();
			kt = false;
			break;
		}
	}
}

void bo_de(cau_hoi_thi *ds[], int &nds, string a, int n, int minute, int second)
{
	xoa_nen();
	khung_cau_hoi();
	cin.ignore();
	cau_hoi_thi *ds_luu[1000];
	//char *tl = new char;
	char tl[1000];
	int point = 0;
	//thread clock;
	
	shuffle_array(ds, nds);
	
	khung_cau_hoi();
	HighLight();
	//clock = thread(print_clock, minute, second);
	gotoxy(70, 8);
	cout << "====== NHAP CAU HOI ======";

	for (int i = 0; i < n; i++)
	{
		if (ds[i]->ma_mh == a)
		{
			gotoxy(47, 13);
			cout << "                                                                         ";
			gotoxy(68, 13);
			cout << "                                   ";
			gotoxy(50, 18);
			cout << "                                 ";
			gotoxy(88, 18);
			cout << "                                ";
			gotoxy(50, 22);
			cout << "                                 ";
			gotoxy(88, 22);
			cout << "                                ";
			/*gotoxy(80, 10);
			cout << "                     ";
			gotoxy(80, 10);
			cout << "ID: " << ds[i]->id;*/
			gotoxy(50, 10);
			cout << "Cau so " << i + 1;
			gotoxy(47, 13);
			cout << "Cau hoi: " << ds[i]->cau_hoi;
			gotoxy(47, 18);
			cout << "A. " << ds[i]->A;
			gotoxy(85, 18);
			cout << "B. " << ds[i]->B;
			gotoxy(47, 22);
			cout << "C. " << ds[i]->C;
			gotoxy(85, 22);
			cout << "D. " << ds[i]->D;
		check_tl:
			gotoxy(77, 27);
			cout << "DAP AN: ";
			gotoxy(85, 27);
			cout << "    ";
			gotoxy(85, 27);
			cin >> tl[i];
			up_case_char(tl[i]);
			string cau_tl;
			if (tl[i] == 'A')
			{
				cau_tl = ds[i]->A;
			}
			else if (tl[i] == 'B')
			{
				cau_tl = ds[i]->A;
			}
			else if (tl[i] == 'C')
			{
				cau_tl = ds[i]->A;
			}
			else if (tl[i] == 'D')
			{
				cau_tl = ds[i]->D;
			}
			else
			{
				gotoxy(65, 30);
				cout << "NHAP DAP AN KHONG HOP LE, YEU CAU NHAP LAI!";
				goto check_tl;
			}
			ds_luu[i] = new cau_hoi_thi;
			ds_luu[i]->id = ds[i]->id;
			ds_luu[i]->cau_hoi = ds[i]->cau_hoi;
			ds_luu[i]->A = ds[i]->A;
			ds_luu[i]->B = ds[i]->B;
			ds_luu[i]->C = ds[i]->C;
			ds_luu[i]->D = ds[i]->D;
			ds_luu[i]->dap_an = ds[i]->dap_an;
			ds_luu[i]->cau_dap_an = ds[i]->cau_dap_an;

			if (cau_tl == ds[i]->cau_dap_an)
			{
				point++;
			}
		}
	}
	//clock.join();
	xoa_nen();
	gotoxy(50, 9);
	cout << "SO DIEM BAN DAT DUOC LA: " << point << "/" << n << ".";
	bool kt = true;
	while (kt == true)
	{
		xoa_nen();
		gotoxy(50, 10);
		cout << "BAN CO MUON IN RA KET QUA KHONG?";
		gotoxy(50, 11);
		cout << "1. Co.";
		gotoxy(50, 12);
		cout << "0. Khong.";
		gotoxy(50, 13);
		cout << "Ban chon: ";
		int xem_kq;
		cin >> xem_kq;
		switch (xem_kq)
		{
		case 1:
		{
			xoa_nen();
			gotoxy(50, 8);
			cout << "==================================================================";
			gotoxy(50, 9);
			cout << "|CAU| ID |         DAP AN DUNG                         |BAN CHON |";
			gotoxy(50, 10);
			cout << "==================================================================";
			int i = 0;
			for (i = 0; i < n; i++)
			{
				gotoxy(50, 11 + i); cout << "| " << i + 1;
				gotoxy(54, 11 + i); cout << "| " << ds_luu[i]->id ;
				gotoxy(59, 11 + i); cout << "|";
				gotoxy(61, 11 + i); cout << ds_luu[i]->dap_an << ". " << ds_luu[i]->cau_dap_an;
				gotoxy(105, 11 + i); cout << "|";
				gotoxy(110, 11 + i); cout << tl[i];
				gotoxy(115, 11 + i); cout << "|";	
			}
			gotoxy(50, 11 + i);
			cout << "------------------------------------------------------------------";
			cin.ignore();
			gotoxy(60, 35);
			system("pause");
			/*delete tl;
			delete []ds_luu;*/
			
			break;
			
			
		}
		case 0:
		{
			kt = false;
			break;
		}
		}
	}
}
void shuffle_array(cau_hoi_thi *ds[], int nds)
{
	/*srand(time(NULL));*/
	int min_position;
	int max_position = nds - 1;
	int swap_position;
	int i = 0;
	while (i < nds - 1)
	{
		min_position = i + 1;
		swap_position = rand() % (max_position - min_position + 1) + min_position;
		hoan_vi_2_cau(ds[i], ds[swap_position]);
		i++;
	}
}


