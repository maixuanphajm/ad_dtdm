#include"Mang1C_SinhVien.h"

void nhapSinhVien(int &x)
{
	do
	{
		scanf("%d", &x);
		if (x <= 0)
		{
			printf("Nhap sai. Vui long nhap lai so nguyen duong. \n");
		}
	} while (x <= 0);
}
//===========================================================================
void nhapMang1C_SinhVien(int *&a, int &n)
{
	printf("Ban hay cho biet so phan tu cua mang : ");
	nhapSinhVien(n);
	a = new int[n]; // Xin cấp phát n ô nhớ dể lưu trữ n só nguyên
	for (int i = 0; i < n; i++)
	{
		int tmp;
		printf("Nhap a[%d] = ", i);
		scanf("%d", &tmp);
		a[i] = tmp;
	}
}
//===========================================================================
void docMang1C_SinhVien(char *filename, int *&a, int &n)
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
void xuatMang1C_SinhVien(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
}
//===========================================================================
