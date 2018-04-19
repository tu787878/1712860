#include "ThuVien.h"

struct ThongTin
{
	wchar_t *MSSV, *Ten, *Khoa, *NienKhoa, *NgaySinh, *HinhAnh, *MoTa, *SoThich;
};

int KiemTraTongSoSinhVien(int Tong_SV)
{
	//Mở file csv và đọc file csv
	FILE* fileCSV = _wfopen(L"SinhVien.csv", L"r, ccs=UTF-8");
	if (!fileCSV) {
		wprintf(L"Không thể đọc file\n");
	}


	//Đếm số sinh viên trong dữ liệu
	int Count = 1; //Biến đếm số sinh viên
	while (!feof(fileCSV))
	{
		char ch = fgetwc(fileCSV);
		if (ch == '\n')
		{
			Count++;
		}
	}
	fclose(fileCSV);
	//Kiểm tra tổng sinh viên với số sinh viên người dùng nhập
	if (Tong_SV > Count)
	{
		return 0;
	}
	return 1;
}


void TachThongTin(wchar_t *SinhVien, ThongTin *&SV, int index, wchar_t *&SinhVien_CT, int SV_index, int *&ThuocTinh)
{	
	int dem = 1;
	wchar_t *buffer;

	wprintf(L"%s\n", SinhVien);
	wchar_t *token = wcstok_s(SinhVien, L"\"", &buffer);
	while (token) {
		//wprintf(L"%ls\n", token);
		if (wcsncmp(token, L",", 1) != 0){
			switch (dem)
			{
			case 1:
				SV[index].MSSV = token;
				dem++;
				break;
			case 2:
				SV[index].Ten = token;
				dem++;
				break;
			case 3:
				SV[index].Khoa = token;
				dem++;
				break;
			case 4:
				SV[index].NienKhoa = token;
				dem++;
				break;
			case 5:
				SV[index].NgaySinh = token;
				dem++;
				break;
			case 6:
				SV[index].HinhAnh = token;
				dem++;
				break;
			case 7:
				SV[index].MoTa = token;
				dem++;
				break;
			case 8:
				SV[index].SoThich = token;
				dem++;
				break;
			case 9:
				wcscat(SV[index].SoThich, L"\n");
				wcscat(SV[index].SoThich, token);


			}
			//wprintf(L"%ls\n", token);
		}
		token = wcstok_s(NULL, L"\"", &buffer);
	}


}



int GetInformation(ThongTin *&SV, int &Tong_SV, wchar_t *&SinhVien, wchar_t *&SinhVien_CT, int *&ThuocTinh, int &SV_index)
{
	//Nhập tổng số sinh viên
	wprintf(L"Nhập số sinh viên cần xuất: ");
	wscanf(L"%d", &Tong_SV);

	while (Tong_SV <= 0)
	{
		wprintf(L"\nSố sinh viên phải lớn hơn 0, Nhập lại: ");
		wscanf(L"%d", &Tong_SV);
	}
	int Test = KiemTraTongSoSinhVien(Tong_SV);
	if (Test == 0)
	{
		return 0;
	}
	SV = new ThongTin[Tong_SV];
	SV_index = 0;
	ThuocTinh = new int[Tong_SV];

	FILE* fileCSV = _wfopen(L"SinhVien.csv", L"r, ccs=UTF-8");
	if (!fileCSV) {
		wprintf(L"Không thể đọc file\n");
	}
	wchar_t buf[1000];


	//Lấy thông tin và đưa vào chuỗi thông tin các sinh viên
	for (int i = 0; i < Tong_SV; i++)
	{
		while (fgetws(buf, sizeof(buf), fileCSV) != NULL)
		{
			buf[wcslen(buf) - 1] = L'\0'; // eat the newline fgets() stores
			SinhVien = buf;
			//wprintf(L"%s\n", SinhVien);
			break;
		}
		//SinhVien[i] = buf;
		//getline(fileCSV, SinhVien[i]);
		//Tách từ chuỗi tổng đưa vào các thuộc tính các sinh viên
		TachThongTin(SinhVien, SV, i, SinhVien_CT, SV_index, ThuocTinh);
		//wprintf(L"%ls\n", SV[0].MSSV);
	}
	fclose(fileCSV);
	return 1;
}

void TaiThongTin(ThongTin *&SV, wchar_t *HTML, int index, int *ThuocTinh)
{
	//Mo file
	
	wchar_t *FileName = L"Profiles/";
	//wcscat(FileName, SV[0].MSSV);
	//wcscat(FileName, L".html");
	//wprintf(L"helo\n");
	//FileName = "Profiles/" + SV[index].MSSV + ".html";
}		