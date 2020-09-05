#pragma once
#include "ctdl.h"
void Normal();
void HighLight();
void color_khung();
void chuan_hoa_chu(string &a)
{
	/*int a = a.length();*/
	// |...tU...lAnh....|
	// |TU LANH|
	//xu li khoang trang dau
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	//xu li khoang trang cuoi
	if (a[a.length() > 1])
	{
		while (a[a.length() - 1] == ' ')
		{
			a.erase(a.begin() + a.length() - 1);
		}
	}
	//xu li khoang trang giua
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' '&& a[i + 1] == ' ')
		{
			a.erase(a.begin() + i + 1);
			i--;
		}
	}
	//in hoa cac ki tu
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] >= 97 && a[i] <= 122)
		{
			a[i] -= 32;
		}
	}
}
void up_case_char(char &a)
{
	if (a >= 97 && a <= 122)
	{
		a -= 32;
	}
}
// ============ x? l� c�u h?i ===================
cau_hoi_thi *khoi_tao_node_cau_hoi()
{
	cau_hoi_thi *p = new cau_hoi_thi;
	p->p_left = NULL;
	p->p_right = NULL;
	return p;
}
void xu_li_dap_an(cau_hoi_thi *p)
{
	if (p->dap_an == 'A')
	{
		p->cau_dap_an = p->A;
	}
	else if (p->dap_an == 'B')
	{
		p->cau_dap_an = p->B;
	}
	else if (p->dap_an == 'C')
	{
		p->cau_dap_an = p->C;
	}
	else if (p->dap_an == 'D')
	{
		p->cau_dap_an = p->D;
	}
}
void them_1_cau_hoi(tree &t, cau_hoi_thi *p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->id > t->id)
		{
			them_1_cau_hoi(t->p_right, p);
		}
		else if (p->id < t->id)
		{
			them_1_cau_hoi(t->p_left, p);
		}
	}
}
void them_1_sinh_vien(SINH_VIEN *&p_head, SINH_VIEN *p)
{
	if (p_head == NULL)
	{
		p_head = p;
	}
	else
	{
		for (SINH_VIEN *k = p_head; k != NULL; k = k->p_next)
		{
			if (k->p_next == NULL)
			{
				k->p_next = p;
				break;
			}
		}
	}
}
SINH_VIEN* khoi_tao_node_sv()
{
	SINH_VIEN *p = new SINH_VIEN;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat!";
		return NULL;
	}
	p->p_next = NULL;
	return p;
}
void print_clock(int minute, int second)
{
	char key;
	while (true)
	{
		gotoxy(110, 9);
		cout << minute << ":" << second ;

		if (second == 0)//&& minute !=0)
		{
			second = 59;
			minute--;
		}
		second--;
		if (second == 0 && minute == 0)break;
		if (_kbhit())
		{
			key = _getch();
			if (key == 27) break;
		}
		Sleep(1000);
	}
}
void color_khung()
{
	SetBGColor(11);
}
void Normal()
{
	SetColor(15);
	SetBGColor(0);
}
void HighLight()
{
	SetColor(11);
	SetBGColor(0);
}

void xoa_nen()
{
	int x = 42, y = 6;
	while (y < 36)
	{
		gotoxy(x, y);
		for (int i = 0; i < 81; i++) // 81 la so khoang trang de xoa nen ben canh
			cout << " ";
		y++;
	}
}
void khung_them_lop()
{
	HighLight();
	// ke thanh ngang
	
	int x1 = 60, y1 = 16;
	while (x1 < 110)
	{
		gotoxy(x1, y1);
		cout << "_";
		x1++;
	}
	int x3 = 60, y3 = 19;
	while (x3 < 110)
	{
		gotoxy(x3, y3);
		cout << "_";
		x3++;
	}
	int x2 = 60, y2 = 22;
	while (x2 < 110)
	{
		gotoxy(x2, y2);
		cout << "_";
		x2++;
	}
	int x6 = 60, y6 = 25;
	while (x6 < 110)
	{
		gotoxy(x6, y6);
		cout << "_";
		x6++;
	}
	// ke thanh doc
	color_khung();
	int x4 = 60, y4 = 17;
	while (y4 < 26)
	{
		gotoxy(x4, y4);
		cout << "|";
		y4++;
	}
	int x5 = 110, y5 = 17;
	while (y5 < 26)
	{
		gotoxy(x5, y5);
		cout << "|";
		y5++;
	}
}
void khung_them_sv()
{
	// ke thanh ngang
	HighLight();
	int x7 = 60, y7 = 13;
	while (x7 < 110)
	{
		gotoxy(x7, y7);
		cout << "_";
		x7++;
	}
	int x1 = 60, y1 = 16;
	while (x1 < 110)
	{
		gotoxy(x1, y1);
		cout << "_";
		x1++;
	}
	int x3 = 60, y3 = 19;
	while (x3 < 110)
	{
		gotoxy(x3, y3);
		cout << "_";
		x3++;
	}
	int x2 = 60, y2 = 22;
	while (x2 < 110)
	{
		gotoxy(x2, y2);
		cout << "_";
		x2++;
	}
	int x6 = 60, y6 = 25;
	while (x6 < 110)
	{
		gotoxy(x6, y6);
		cout << "_";
		x6++;
	}
	int x8 = 60, y8 = 28;
	while (x8 < 110)
	{
		gotoxy(x8, y8);
		cout << "_";
		x8++;
	}
	// ke thanh doc
	color_khung();
	int x4 = 60, y4 = 14;
	while (y4 < 29)
	{
		gotoxy(x4, y4);
		cout << "|";
		y4++;
	}
	int x5 = 110, y5 = 14;
	while (y5 < 29)
	{
		gotoxy(x5, y5);
		cout << "|";
		y5++;
	}
}
void khung_them_mon()
{
	HighLight();
	// ke thanh ngang

	int x1 = 60, y1 = 16;
	while (x1 < 110)
	{
		gotoxy(x1, y1);
		cout << "_";
		x1++;
	}
	int x2 = 60, y2 = 19;
	while (x2 < 110)
	{
		gotoxy(x2, y2);
		cout << "_";
		x2++;
	}
	int x3 = 60, y3 = 22;
	while (x3 < 110)
	{
		gotoxy(x3, y3);
		cout << "_";
		x3++;
	}
	// ke thanh doc
	color_khung();
	int x4 = 60, y4 = 17;
	while (y4 < 23)
	{
		gotoxy(x4, y4);
		cout << "|";
		y4++;
	}
	int x5 = 110, y5 = 17;
	while (y5 < 23)
	{
		gotoxy(x5, y5);
		cout << "|";
		y5++;
	}
}
void khung_cau_hoi()
{
	HighLight();
	//ke thanh ngang
	int x1 = 45, y1 = 11;
	while (x1 < 120)
	{
		gotoxy(x1, y1);
		cout << "_";
		x1++;
	}
	int x2 = 45, y2 = 16;
	while (x2 < 120)
	{
		gotoxy(x2, y2);
		cout << "_";
		x2++;
	}
	int x3 = 45, y3 = 20;
	while (x3 < 120)
	{
		gotoxy(x3, y3);
		cout << "_";
		x3++;
	}
	int x4 = 45, y4 = 24;
	while (x4 < 120)
	{
		gotoxy(x4, y4);
		cout << "_";
		x4++;
	}
	int x8 = 75, y8 = 28;
	while (x8 < 93)
	{
		gotoxy(x8, y8);
		cout << "_";
		x8++;
	}
	// ke thanh doc
	color_khung();
	int x5= 45, y5 = 12;
	while (y5 < 25)
	{
		gotoxy(x5, y5);
		cout << "|";
		y5++;
	}
	int x6 = 120, y6 = 12;
	while (y6 < 25)
	{
		gotoxy(x6, y6);
		cout << "|";
		y6++;
	}
	int x7 = 83, y7 = 17;
	while (y7 < 25)
	{
		gotoxy(x7, y7);
		cout << "|";
		y7++;
	}
	int x9 = 75, y9 = 26;
	while (y9 < 29)
	{
		gotoxy(x9, y9);
		cout << "|";
		y9++;
	}
}