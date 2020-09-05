#pragma once
#include "xu_li.h"


//===================== doc file danh sach lop =======================
void doc_file_ds_lop(DS_LOP &ds_l)
{
	ifstream filein;
	filein.open("lop.txt", ios_base ::in);
	while (filein.eof() != true)
	{
		ds_l.ds[ds_l.sl] = new LOP;		
		getline(filein, ds_l.ds[ds_l.sl]->ma_lop, ',');
		getline(filein, ds_l.ds[ds_l.sl]->ten_lop, ',');
		getline(filein, ds_l.ds[ds_l.sl]->nien_khoa);
		ds_l.sl++;
	}
	filein.close();
}
void doc_file_ds_mon(DS_MON_HOC &ds_mon)
{
	ifstream filein;
	filein.open("mon.txt", ios_base::in);
	while (filein.eof() != true)
	{
		ds_mon.ds[ds_mon.sl] = new MON_HOC;
		getline(filein, ds_mon.ds[ds_mon.sl]->ma_mh, ',');
		getline(filein, ds_mon.ds[ds_mon.sl]->ten_mh);
		ds_mon.sl++;
	}
	filein.close();
}
void doc_file_ds_cau(DS_CAU_HOI_THI &ds_cau)
{
	ifstream filein;
	filein.open("cauhoi.txt", ios_base::in);
	while (filein.eof() != true)
	{
		cau_hoi_thi *x = khoi_tao_node_cau_hoi();
		filein >> x->id;
		filein.ignore();
		getline(filein, x->ma_mh);
		getline(filein, x->cau_hoi);
		getline(filein, x->A);
		getline(filein, x->B);
		getline(filein, x->C);
		getline(filein, x->D);
		filein >> x->dap_an;
		chuan_hoa_chu(x->ma_mh);
		chuan_hoa_chu(x->cau_hoi);
		chuan_hoa_chu(x->A);
		chuan_hoa_chu(x->B);
		chuan_hoa_chu(x->C);
		chuan_hoa_chu(x->D);
		up_case_char(x->dap_an);
		xu_li_dap_an(x);
		them_1_cau_hoi(ds_cau.TREE, x);
		filein.ignore();
		ds_cau.sl++;
	}
	filein.close();
}
void doc_file_ds_sv(DS_LOP &ds_l)
{
	ifstream filein;
	filein.open("sinhvien.txt", ios_base::in);
	for (int i = 0; i < ds_l.sl; i++)
	{
		filein >> ds_l.ds[i]->danh_sach_sv.sl;
		filein.ignore();
		for (int j=0;j< ds_l.ds[i]->danh_sach_sv.sl;j++)
		{
			SINH_VIEN *p = khoi_tao_node_sv();
			getline(filein, p->ma_sv, ',');
			getline(filein, p->ten, ',');
			getline(filein, p->ho, ',');
			getline(filein, p->phai, ',');
			getline(filein, p->password);
			chuan_hoa_chu(p->ma_sv);
			chuan_hoa_chu(p->ten);
			chuan_hoa_chu(p->ho);
			chuan_hoa_chu(p->phai);
			//chuan_hoa_chu(p->password);
			them_1_sinh_vien(ds_l.ds[i]->danh_sach_sv.p_head, p);
		}
	}
	filein.close();
}
void doc_file_diem__thi(DS_LOP &ds_l)
{
	ifstream filein;
	filein.open("diemthi.txt", ios_base::in);
	for (int i = 0; i < ds_l.sl; i++)
	{		
		for (int j = 0; j < ds_l.ds[i]->danh_sach_sv.sl; j++)
		{
			int n;
			filein >> n;
			cin.ignore();
			for (int m = 0; m < n; n++)
			{
				DIEM_THI *p = khoi_tao_node_diem();
				getline(filein, p->ma_mh, ':');
				filein >> p->diem;
				them_1_diem_thi(ds_l.ds[i]->danh_sach_sv.p_head->danh_sach_diem.p_head, p);
			}
		}
		
	}
	filein.close();
}
// =============== GHI FILE =======================
void ghi_file_lop(DS_LOP &ds_l)
{
	ofstream fileout;
	fileout.open("lop1.txt", ios_base::out);
	for (int i = 0; i < ds_l.sl; i++)
	{
		fileout << ds_l.ds[i]->ma_lop << ",";
		fileout << ds_l.ds[i]->ten_lop<< ",";
		fileout << ds_l.ds[i]->nien_khoa ;
		if (i != ds_l.sl - 1)
		{
			fileout << "\n";
		}		
	}
	fileout.close();
}
void ghi_file_mon(DS_MON_HOC &ds_mon)
{
	ofstream fileout;
	fileout.open("mon1.txt", ios_base::out);
	for (int i = 0; i < ds_mon.sl; i++)
	{
		fileout << ds_mon.ds[i]->ma_mh <<",";
		fileout << ds_mon.ds[i]->ten_mh;
		if (i != ds_mon.sl - 1)
		{
			fileout << "\n";
		}		
	}
	fileout.close();
}
void ghi_file_sv(DS_LOP &ds_l)
{
	ofstream fileout;
	fileout.open("sinhvien1.txt", ios_base::out);
	for (int i = 0; i < ds_l.sl; i++)
	{
		fileout << ds_l.ds[i]->danh_sach_sv.sl;
		fileout << "\n";
		for (SINH_VIEN *k = ds_l.ds[i]->danh_sach_sv.p_head; k!= NULL; k= k->p_next)
		{
			fileout << k->ma_sv << ",";
			fileout << k->ten << ",";
			fileout << k->ho << ",";
			fileout << k->phai << ",";
			fileout << k->password;
			if (k->p_next != NULL)
			{
				fileout << "\n";
			}
		}
		if (i != ds_l.sl - 1)
		{
			fileout << "\n";
		}
	}
	fileout.close();
}

void ghi_file_cau(cau_hoi_thi *ds[],int &nds)
{
	ofstream fileout;
	fileout.open("cauhoi1.txt", ios_base::out);
	for (int i = 0; i < nds; i++)
	{
		fileout << ds[i]->id<< endl;
		fileout << ds[i]->ma_mh << endl;
		fileout << ds[i]->cau_hoi << endl;
		fileout << ds[i]->A << endl;
		fileout << ds[i]->B << endl;
		fileout << ds[i]->C << endl;
		fileout << ds[i]->D << endl;
		fileout << ds[i]->cau_dap_an;
		if (i != nds)
		{
			fileout << "\n";
		}
	}
	fileout.close();
}
void ghi_file_diem(DS_LOP &ds_l)
{
	ofstream fileout;
	fileout.open("diemthi1.txt", ios_base::out);
	for (int i = 0; i < ds_l.sl; i++)
	{
		for (SINH_VIEN *k = ds_l.ds[i]->danh_sach_sv.p_head; k != NULL; k = k->p_next)
		{	
			fileout << k->ma_sv;
			fileout << "\n";
			fileout << k->danh_sach_diem.sl;
			fileout << "\n";
			for (DIEM_THI *p = k->danh_sach_diem.p_head; p != NULL; p = p->p_next)
			{

				fileout << p->ma_mh << ":";
				fileout << p->diem;
				if (p->p_next != NULL)
				{
					fileout << "\n";
				}
			}
			if (k->p_next != NULL)
			{
				fileout << "\n";
			}
		}
		if (i != ds_l.sl - 1)
		{
			fileout << "\n";
		}
	}
	fileout.close();
}