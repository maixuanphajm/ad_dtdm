#include"Mang1C_SoNguyen.h"

void nhapSoNguyenDuong(int &x)
{
	do
	{
		scanf("%d", &x);
		if (x <= 0)
		{
			printf("Nhap sai. Vui long nhap lai so nguyen duong. \n");
		}
	} while (x<=0);
}
//===========================================================================
void nhapMang1C_SoNguyen(int *&a, int &n)
{
	printf("Ban hay cho biet so phan tu cua mang : ");
	nhapSoNguyenDuong(n);
	a = new int[n]; // Xin cấp phát n ô nhớ dể lưu trữ n só nguyên
	for (int  i = 0; i < n; i++)
	{
		int tmp;
		printf("Nhap a[%d] = ", i);
		scanf("%d", &tmp);
		a[i] = tmp;
	}
}
//===========================================================================
void taoMang1C_SoNguyen(int *&a, int &n)
{
	printf("Ban hay cho biet so phan tu cua mang : ");
	nhapSoNguyenDuong(n);
	a = new int[n]; // Xin cấp phát n ô nhớ dể lưu trữ n só nguyên
	srand((unsigned)time(NULL)); // tạo số ngẫu nhiên theo thời gian
	for (int i = 0; i < n; i++)
	{
		int tmp;
		tmp = rand() % 199 - 99; // Tạo 1 số nguyên thuộc [-99;99]
		a[i] = tmp;
	}
}
//===========================================================================
void docMang1C_SoNguyen(char *filename,int *&a, int &n)
{
	FILE *fi = fopen(filename, "rt");// read text
	if (!fi)
	{
		printf("Loi mo file: %s", filename);
		getch();
		return;
	}
	fscanf(fi, "%d\n", &n);
	a = new int[n]; // Xin cấp phát n ô nhớ dể lưu trữ n só nguyên
	 // tạo số ngẫu nhiên theo thời gian
	for (int i = 0; i < n; i++)
	{
		int tmp;
		fscanf(fi, "%d\n", &tmp);
		a[i] = tmp;
	}
}
//===========================================================================
void xuatMang1C_SoNguyen(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%4d", a[i]); 
	}
}
//===========================================================================
int tim_Kiem_TuyenTinh(ItemType *a, int n, ItemType x)
{
	for (int i = 0; i <n ; i++)
	{
		if (a[i] == x)
		{
			return i; // Tìm thấy giá trị x ở vị trí thứ i
		}
	}
	return -1; // Không tìm thấy giá trị x 
}
//===========================================================================
int tim_Kiem_NhiPhan(ItemType *a, int n, ItemType x)
{
	int left = 0, right = n - 1, mid;
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
		{
			return mid; // Tim thay gia tri x o vi tri thu mid
		}
		else if (a[mid] > x)
		{ // x co the nam nua trai cua day
			right = mid-1 ; // giam bien phai right xuong
		}
		else
		{ // x co the nam nua phaui cua day
			left = mid + 1; // tang bien phai left len
		}
	}
	return -1; // khong tim thay gia tri x 
}
//===========================================================================
void hoanVi(ItemType &x, ItemType &y)
{ 
	ItemType tmp;
	tmp = x;
	x = y;
	y = tmp;
}
//===========================================================================
void sapXep_DoiChoTrucTiep_TangDan(ItemType *&a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i]<a[j])
			{// Hoán vị a[i] với a[j]
				hoanVi(a[i], a[j]);
			}
		}
	}
}