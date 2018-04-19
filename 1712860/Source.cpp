#include "ThuVien.h"
#include "Xuli.h"
#include "Template.h"

int wmain(int argc, wchar_t* argv[])
{
	_setmode(_fileno(stdout), _O_U16TEXT); //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input
	//Khai báo các biến sử dụng
	ThongTin *SV = NULL; //Con trỏ cấu trúc thông tin sinh vien
	int Tong_SV; //Biến chứa tổng số sinh viên
	wchar_t *SinhVien = NULL; //Con trỏ chứa thông tin của sinh viên
	wchar_t *SinhVien_CT = NULL; //Con trỏ chứa thuộc tính của sinh viên
	int SV_index; //Chỉ mục các thuộc tính các sinh viên
	int *ThuocTinh = NULL; //Con trỏ chứa số thuộc tính của các sinh viên
	wchar_t* HTML = L""; //Chuỗi chứa cấu trúc file HTML

	
	GetTemplate(HTML);
	//Lấy thông tin sinh viên
	int Test = GetInformation(SV, Tong_SV, SinhVien, SinhVien_CT, ThuocTinh, SV_index);
	if (Test == 0)
	{
		wprintf(L"Looix");
		system("pause");
		return 0;
	}
	
	//Lấy template từ file html
	
	//wprintf(L"%ls\n", HTML);



	//Đưa thông tin trong struct vào file html
	for (int i = 0; i < Tong_SV; i++)
	{
		TaiThongTin(SV, HTML, i, ThuocTinh);
	}
	//Thông báo hoàn tất

	//Giải phóng vùng nhớ

	wprintf(L"Đã xuất thành công, bạn hãy kiểm tra trong file Profiles\n");
	system("pause");
	return 0;
}