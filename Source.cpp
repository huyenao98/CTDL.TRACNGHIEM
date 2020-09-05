#include "do_hoa.h"

int main()
{  
	SetConsoleTitle(TEXT("THI TRAC NGHIEM"));
	srand(time(NULL));
	setFontSize(20);
	resizeConsole(width, height);
	login();
	return 0;
}