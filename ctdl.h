#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <cstdlib> //rand, srand
#include <windows.h>
#include <thread>
#include <dos.h>
#include <iomanip>
#include "mylib.h"
#define MAX_LOP 500
#define MAX_MON 300
using namespace std;

//============== danh sach diem thi ====================
struct diem_thi
{
	string ma_mh;
	float diem;
	//pointer
	diem_thi *p_next;
};
typedef struct diem_thi DIEM_THI;
struct ds_diem_thi
{
	DIEM_THI *p_head = NULL;
	int sl = 0;
};
typedef ds_diem_thi DS_DIEM_THI;
//============= danh sach mon hoc ===================
struct mon_hoc
{
	string ma_mh;//max C15
	string ten_mh;//maxx c50
};
typedef struct mon_hoc MON_HOC;

struct ds_mon_hoc
{
	MON_HOC *ds[MAX_MON];
	int sl = 0;
};
typedef struct ds_mon_hoc DS_MON_HOC;
//============ danh sach sinh vien ====================
struct sinh_vien
{
	//data
	string ma_sv;
	string ho;
	string ten;
	string phai;
	string password;
	// *p toi danh sach diem thi
	DS_DIEM_THI danh_sach_diem;
	//pointer
	sinh_vien *p_next;
	sinh_vien *p_head;
	sinh_vien *p_tail;

};
typedef struct sinh_vien SINH_VIEN;
struct ds_sinh_vien
{
	SINH_VIEN *p_head = NULL;
	SINH_VIEN *p_tail = NULL;
	int sl = 0;
};
typedef ds_sinh_vien DS_SINH_VIEN;

// ============== danh sach cau hoi thi ===================
struct cau_hoi_thi
{
	//data
	int id;
	string ma_mh;
	string cau_hoi;
	string A;
	string B;
	string C;
	string D;
	char dap_an;
	string cau_dap_an;
	//pointer
	cau_hoi_thi *p_left;
	cau_hoi_thi *p_right;
};
typedef struct cau_hoi_thi *tree;
struct ds_cau_hoi_thi
{
	tree TREE = NULL;
	int sl = 0;
};
typedef ds_cau_hoi_thi DS_CAU_HOI_THI;
// ============= danh sach lop =======================
struct lop
{
	string ma_lop;
	string ten_lop;
	string nien_khoa;
	//*p toi ds sinh vien;
	DS_SINH_VIEN danh_sach_sv;
};
typedef struct lop LOP;
struct ds_lop
{
	LOP *ds[MAX_LOP];
	int sl = 0;
};
typedef struct ds_lop DS_LOP;


