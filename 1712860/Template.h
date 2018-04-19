#include "ThuVien.h"

//Hàm Get Template
//Input: chuỗi HTML
//Output: dữ liệu html template chứa vào chuỗi HTML
void GetTemplate(wchar_t *&HTML)
{
	//Mở file html
	FILE* f = _wfopen(L"Personal.txt", L"r, ccs=UTF-8");
	if (!f) {
		wprintf(L"Không thể đọc file\n");
	}
	wchar_t h[300];
	//wchar_t h[200]; //Chuỗi tạm
	while (fgetws(h, 300, f) != NULL)
	{
		h[wcslen(h) - 1] = L'\0'; 
		HTML = h;
		wcscat(HTML, L"\n");
		//wcscat(HTML, h);
		wprintf(L"%ls", HTML);
		//break;
	}
	wprintf(L"%ls", HTML);
	//Đóng file
	fclose(f);
}

