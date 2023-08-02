#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <iomanip>
using namespace std;
struct name
{
    char holot[40];
    char ten[20];
};
struct date
{
    int day, month, year;
};
struct Car
{
    char sign[10];
    char namecar[20];
    date ngay;
    int price;
};
struct Customer
{
    char maso[11];
    name ten;
    date ngaysinh;
    char sdt[11];
    char cccd[13];
    int solanthue;
};
struct CustomerNode
{
    Customer data;
    CustomerNode *Next;
};
struct CarNode
{
    Car data;
    CarNode *Next;
};
struct ThueXe
{
    CustomerNode *khachhang;
    CarNode *xe;
    date thue;
    date tra;
    int songaythue;
    int giatien;
};
struct ThueNode
{
    ThueXe data;
    ThueNode *Next;
};
struct DanhSachXe
{
    CarNode *Head, *Tail;
    int size;
};
struct DanhSachKhachHang
{
    CustomerNode *Head, *Tail;
    int size;
};
struct DanhSachThueXe
{
    ThueNode *Head, *Tail;
    int size;
};
// Ham Menu
void Menu(DanhSachKhachHang &KhachHang, DanhSachXe &Xe, DanhSachThueXe &Thue);
void Menu1(DanhSachKhachHang &KhachHang, DanhSachXe &Xe, DanhSachThueXe &Thue);
void TimKhachHang(DanhSachKhachHang KhachHang, DanhSachXe Xe, DanhSachThueXe Thue);
void capNhat(DanhSachKhachHang &dsKH, DanhSachXe &dsXe, DanhSachThueXe &Thue);
// Ham KhoiTao
void init(DanhSachKhachHang &KhachHang);
void init(DanhSachXe &Xe);
void init(DanhSachThueXe &Thue);
CustomerNode *newNode(Customer KhachHang);
CarNode *newNode(Car Xe);
ThueNode *newNode(ThueXe Thue);
// Ham Xoa
void delete_1(DanhSachKhachHang &KH, CustomerNode *R);
void delete_1(DanhSachXe &Xe, CarNode *R);
void delete_1(DanhSachThueXe &Thue, ThueNode *R);
void ClearDS(DanhSachKhachHang &KhachHang);
void ClearDS(DanhSachXe &Xe);
void ClearDS(DanhSachThueXe &Thue);
// Ham Chen`
void insert(DanhSachKhachHang &KhachHang, CustomerNode *KhachHangMoi);
void insert(DanhSachXe &Xe, CarNode *XeMoi);
void insert(DanhSachThueXe &Thue, ThueNode *ThueMoi);
void Nhap_1(DanhSachKhachHang &KhachHang);
void Nhap_1(DanhSachXe &Xe);
void Nhap_1(DanhSachKhachHang KhachHang, DanhSachXe Xe, DanhSachThueXe &Thue);
// Ham Xuat
void XuatThueXe(ThueNode *i, DanhSachThueXe Thue);
void XuatKhachHang(CustomerNode *i, DanhSachKhachHang KhachHang);
void XuatXe(CarNode *i, DanhSachXe Xe);
void XuatDanhsachKhachHang(DanhSachKhachHang KhachHang);
void XuatDanhSachXe(DanhSachXe Xe);
void XuatDanhSachThueXe(DanhSachThueXe Thue);
// Ham KiemTra
int CheckXe(DanhSachThueXe Thue, char sign[]);
int timKhoangCachCuoi(char a[]);
int CheckcodeKH(DanhSachKhachHang &KhachHang, char maso[]);
void tachTen(char hovaten[], char ho[], char ten[]);
void xoakytu(char a[], int position);
void ktTenhople(char a[]);
int FindMin(DanhSachThueXe Thue);
int FindMax(DanhSachThueXe Thue);
int ChecksignXe(DanhSachXe &Xe, char sign[]);
int CheckCCCDKH(DanhSachKhachHang &KhachHang, char cccd[]);
int CheckSdtKH(DanhSachKhachHang &KhachHang, char sdt[]);
bool Checkdate(date a);
date PlusDate(date thue, int songaythue);
void resizeConsole(int width, int height);
void textcolor(int x);
void printNumberWithCommas(int num);
string ngay(date a);
void InHoaMaSo(char maso[]);
int countChars(char *str);
int countlongestkhachhang(DanhSachKhachHang KhachHang);
int countlongestxe(DanhSachXe Xe);
int countlongestthuexe(DanhSachThueXe Thue, int valuecheck);
// Ham Xu Ly File
void readfile(DanhSachKhachHang &KhachHang);
void Doc_1_Doi_Tuong(ifstream &KH, Customer &KhachHangMoi);
void readfile(DanhSachXe &Xe);
void Doc_1_Doi_Tuong(ifstream &X, Car &XeMoi);
void readfile(DanhSachKhachHang KhachHang, DanhSachXe Xe, DanhSachThueXe &Thue);
void Doc_1_Doi_Tuong(ifstream &TX, DanhSachKhachHang KH, DanhSachXe Xe, ThueXe &ThueMoi);
void Exportfile(DanhSachKhachHang KhachHang);
void Export_1_Doi_Tuong(ofstream &KH, Customer KhachHangMoi);
void Exportfile(DanhSachXe Xe);
void Export_1_Doi_Tuong(ofstream &X, Car XeMoi);
void Exportfile(DanhSachThueXe Thue);
void Export_1_Doi_Tuong(ofstream &TX, ThueXe ThueMoi);
// Ham Sap Xep
CustomerNode *FindMin(DanhSachKhachHang KhachHang);
CustomerNode *divideNode(DanhSachKhachHang &KhachHang, CustomerNode *min);
DanhSachKhachHang Sort(DanhSachKhachHang &KhachHang, int choice);
CustomerNode *FindMinNgaySinh(DanhSachKhachHang KhachHang);
DanhSachKhachHang SortNgaySinh(DanhSachKhachHang &KhachHang, int choice);
CarNode *FindMin(DanhSachXe Xe);
CarNode *divideNode(DanhSachXe &Xe, CarNode *min);
DanhSachXe Sort(DanhSachXe &Xe, int choice);
ThueNode *FindMinThue(DanhSachThueXe Thue);
ThueNode *divideNode(DanhSachThueXe &Thue, ThueNode *min);
DanhSachThueXe Sort(DanhSachThueXe &Thue, int choice);
// Ham Cap Nhat
void capNhatKhachHang(DanhSachKhachHang &dsKH, DanhSachThueXe &Thue, const char *maSo);
void capNhatXe(DanhSachXe &dsXe, const char *sign, DanhSachThueXe &Thue);
int main()
{
    resizeConsole(1200, 640);
    DanhSachKhachHang KhachHang;
    DanhSachThueXe Thue;
    DanhSachXe Xe;
    init(KhachHang);
    init(Xe);
    init(Thue);
    Menu(KhachHang, Xe, Thue);
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Ham Menu
void Menu(DanhSachKhachHang &KhachHang, DanhSachXe &Xe, DanhSachThueXe &Thue)
{
    int choice(1);
    while (choice != false)
    {
        int n(1), m(2);
        system("cls");
        textcolor(12);
        printf("\n\t\t\t\tMENU QUAN LY THUE XE\n");
        textcolor(7);
        printf("\t\t1.Them thong tin\n\t\t2.Tim kiem thong tin\n\t\t3.Xuat thong tin\n\t\t4.Sap xep\n\t\t5.Cap nhat\n\t\t6.Nhap thong tin bang File\n\t\t7.Xuat thanh file\n\t\t0.Thoat chuong trinh\n");
        textcolor(12);
        printf("\tSo Luong Khach Hang: %d\n", KhachHang.size);
        printf("\tSo Luong Xe: %d\n", Xe.size);
        printf("\tSo Luong Xe da duoc thue: %d\n", Thue.size);
        textcolor(7);
        printf("\tNhap lua chon cua ban: ");
        cin >> choice;
        switch (choice)
        {
        case 1:
            Menu1(KhachHang, Xe, Thue);
            break;
        case 2:
            TimKhachHang(KhachHang, Xe, Thue);
            break;
        case 3:
            while (n != false)
            {
                system("cls");
                textcolor(12);
                cout << "\n\t\t\t\tMENU QUAN LY THUE XE\n";
                textcolor(7);
                cout << "\t\t1.Xuat thong tin khach hang\n\t\t2.Xuat thong tin xe\n\t\t3.Xuat thong tin thue xe\n\t\t0.Quay lai\n\tNhap lua chon cua ban: ";
                cin >> n;
                switch (n)
                {
                case 1:
                    XuatDanhsachKhachHang(KhachHang);
                    break;
                case 2:
                    XuatDanhSachXe(Xe);
                    break;
                case 3:
                    XuatDanhSachThueXe(Thue);
                    break;
                default:
                    textcolor(12);
                    if (n == 0)
                        printf("Nhan phim bat ky de quay lai");
                    else
                        printf("Khong co lua chon nay, nhan phim bat ky de nhap lai");
                    textcolor(7);
                    getch();
                    break;
                }
            }
            break;
        case 4:
            while (n != false)
            {
                system("cls");
                textcolor(12);
                cout << "\n\t\t\t\tMENU QUAN LY THUE XE\n";
                textcolor(7);
                cout << "\t\t1.Sap Xep Khach Hang Theo Ngay Sinh\n\t\t2.Sap Xep Khach Hang Theo So Lan Thue\n\t\t3.Sap Xep Xe Theo Gia Thue\n\t\t4.Sap Xep Thue Xe Theo Tong Tien\n\t\t0.Quay lai\n\tNhap lua chon cua ban: ";
                cin >> n;
                switch (n)
                {
                case 1:
                    textcolor(12);
                    if (KhachHang.Head == NULL)
                    {
                        cout << "\tCHUA CO THONG TIN KHACH HANG!!";
                        getch();
                        continue;
                    }
                    cout << "\t\tSAP XEP TANG DAN HAY GIAM DAN\n";
                    textcolor(7);
                    cout << "\tTANG DAN - 1 / GIAM DAN - 0: ";
                    cin >> m;
                    while (m != 0 && m != 1)
                    {
                        cout << "\tTANG DAN - 1 / GIAM DAN - 0: ";
                        cin >> m;
                    }
                    if (m == 0)
                        KhachHang = SortNgaySinh(KhachHang, 0);
                    else
                        KhachHang = SortNgaySinh(KhachHang, 1);
                    XuatDanhsachKhachHang(KhachHang);
                    break;
                case 2:
                    textcolor(12);
                    if (KhachHang.Head == NULL)
                    {
                        cout << "\tCHUA CO THONG TIN KHACH HANG!!";
                        getch();
                        continue;
                    }
                    cout << "\t\tSAP XEP TANG DAN HAY GIAM DAN\n";
                    textcolor(7);
                    cout << "\tTANG DAN - 1 / GIAM DAN - 0: ";
                    cin >> m;
                    while (m != 0 && m != 1)
                    {
                        cout << "\tTANG DAN - 1 / GIAM DAN - 0: ";
                        cin >> m;
                    }
                    if (m == 0)
                        KhachHang = Sort(KhachHang, 0);
                    else
                        KhachHang = Sort(KhachHang, 1);
                    XuatDanhsachKhachHang(KhachHang);
                    break;
                case 3:
                    textcolor(12);
                    if (Xe.Head == NULL)
                    {
                        cout << "\tCHUA CO THONG TIN XE!!";
                        getch();
                        continue;
                    }
                    cout << "\t\tSAP XEP TANG DAN HAY GIAM DAN\n";
                    textcolor(7);
                    cout << "\tTANG DAN - 1 / GIAM DAN - 0: ";
                    cin >> m;
                    while (m != 0 && m != 1)
                    {
                        cout << "\tTANG DAN - 1 / GIAM DAN - 0: ";
                        cin >> m;
                    }
                    if (m == 0)
                        Xe = Sort(Xe, 0);
                    else
                        Xe = Sort(Xe, 1);
                    XuatDanhSachXe(Xe);
                    break;
                case 4:
                    textcolor(12);
                    if (Thue.Head == NULL)
                    {
                        cout << "\tCHUA CO THONG TIN XE THUE!!";
                        getch();
                        continue;
                    }
                    cout << "\t\tSAP XEP TANG DAN HAY GIAM DAN\n";
                    textcolor(7);
                    cout << "\tTANG DAN - 1 / GIAM DAN - 0: ";
                    cin >> m;
                    while (m != 0 && m != 1)
                    {
                        cout << "\tTANG DAN - 1 / GIAM DAN - 0: ";
                        cin >> m;
                    }
                    if (m == 0)
                        Thue = Sort(Thue, 0);
                    else
                        Thue = Sort(Thue, 1);
                    XuatDanhSachThueXe(Thue);
                    break;
                default:
                    textcolor(12);
                    if (n == 0)
                        printf("Nhan phim bat ky de quay lai");
                    else
                        printf("Khong co lua chon nay, nhan phim bat ky de nhap lai");
                    textcolor(7);
                    getch();
                    break;
                }
            }
            break;
        case 5:
            capNhat(KhachHang, Xe, Thue);
            break;
        case 6:
            while (n != false)
            {
                system("cls");
                textcolor(12);
                cout << "\n\t\t\t\tMENU QUAN LY THUE XE\n";
                textcolor(7);
                cout << "\t\t1.Nhap thong tin khach hang\n\t\t2.Nhap thong tin xe\n\t\t3.Nhap thong tin thue xe\n\t\t0.Quay lai\n\tNhap lua chon cua ban: ";
                cin >> n;
                switch (n)
                {
                case 1:
                    readfile(KhachHang);
                    break;
                case 2:
                    readfile(Xe);
                    break;
                case 3:
                    textcolor(12);
                    cout << "\t\tNHAP THONG TIN THUE XE THI BAN PHAI NHAP THONG TIN KHACH HANG VA XE!!\n";
                    textcolor(7);
                    cout << "\tYes - 1 / No - 0: ";
                    cin >> m;
                    while (m != 0 && m != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        cin >> m;
                    }
                    if (m == 0)
                        break;
                    readfile(KhachHang);
                    readfile(Xe);
                    readfile(KhachHang, Xe, Thue);
                    break;
                default:
                    textcolor(12);
                    if (n == 0)
                        printf("Nhan phim bat ky de quay lai");
                    else
                        printf("Khong co lua chon nay, nhan phim bat ky de nhap lai");
                    textcolor(7);
                    getch();
                    break;
                }
            }
            break;
        case 7:
            Exportfile(KhachHang);
            Exportfile(Xe);
            Exportfile(Thue);
            if (KhachHang.Head != NULL || Xe.Head != NULL || Thue.Head != NULL)
            {
                textcolor(12);
                cout << "\t\tDA XUAT THANH CONG!!";
                textcolor(7);
                getch();
            }
            break;
        default:
            textcolor(12);
            if (choice == 0)
                printf("Nhan phim bat ky de thoat khoi chuong trinh");
            else
                printf("Khong co lua chon nay, nhan phim bat ky de nhap lai");
            textcolor(7);
            getch();
            break;
        }
    };
}
void Menu1(DanhSachKhachHang &KhachHang, DanhSachXe &Xe, DanhSachThueXe &Thue)
{
    int choice(1);
    while (choice != false)
    {
        system("cls");
        textcolor(12);
        cout << "\n\t\t\t\tMENU QUAN LY THUE XE\n";
        textcolor(7);
        printf("\t\t1.Them thong tin khach hang\n\t\t2.Them thong tin xe\n\t\t3.Them thong tin thue xe\n\t\t0.Quay lai\n");
        printf("\tNhap lua chon cua ban: ");
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            Nhap_1(KhachHang);
            break;
        case 2:
            system("cls");
            Nhap_1(Xe);
            break;
        case 3:
            system("cls");
            Nhap_1(KhachHang, Xe, Thue);
            break;
        default:
            textcolor(12);
            if (choice == 0)
                printf("Nhan phim bat ky de quay lai");
            else
                printf("Khong co lua chon nay, nhan phim bat ky de nhap lai");
            textcolor(7);
            getch();
            break;
        }
    };
}
void TimKhachHang(DanhSachKhachHang KhachHang, DanhSachXe Xe, DanhSachThueXe Thue)
{
    Customer timkhachhang;
    CustomerNode *kiemkhachhang;
    Car timxe;
    CarNode *kiemxe;
    ThueNode *TimGiaTien;
    int t;
    int choice(1);
    while (choice != false)
    {
        int m(2), t(0);
        kiemkhachhang = KhachHang.Head;
        kiemxe = Xe.Head;
        DanhSachKhachHang KH;
        DanhSachXe X;
        DanhSachThueXe T;
        init(T);
        init(X);
        init(KH);
        ClearDS(KH);
        ClearDS(X);
        ClearDS(T);
        system("cls");
        textcolor(12);
        cout << "\n\t\t\t\tMENU QUAN LY THUE XE\n";
        textcolor(7);
        printf("\t\t1.Tim theo ma so khach hang\n\t\t2.Tim theo ten khach hang\n\t\t3.Tim theo ngay sinh khach hang\n\t\t4.Tim theo CCCD\n\t\t5.Tim theo bien so xe\n\t\t6.Tim theo gia thue xe\n\t\t0.Quay lai\n");
        printf("\tNhap lua chon cua ban: ");
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (KhachHang.Head == NULL)
            {
                textcolor(12);
                cout << "\tCHUA CO THONG TIN KHACH HANG!!";
                textcolor(7);
                getch();
                break;
            }
            system("cls");
            cin.ignore();
            printf("\t\tNhap ma so khach hang (10 ky tu): ");
            gets(timkhachhang.maso);
            fflush(stdin);
            InHoaMaSo(timkhachhang.maso);
            while (strlen(timkhachhang.maso) != 10)
            {
                if (strlen(timkhachhang.maso) != 10)
                    cout << "\tMa so khong hop le\n";
                printf("\t\tNhap ma so khach hang (10 ky tu): ");
                gets(timkhachhang.maso);
                fflush(stdin);
                InHoaMaSo(timkhachhang.maso);
            }
            while (kiemkhachhang != NULL)
            {
                if (strcmp(timkhachhang.maso, kiemkhachhang->data.maso) == 0)
                {
                    t++;
                    CustomerNode *p = newNode(kiemkhachhang->data);
                    insert(KH, p);
                }
                kiemkhachhang = kiemkhachhang->Next;
            }
            if (t == 0)
            {
                textcolor(12);
                printf("Khong tim thay thong tin khach hang");
                textcolor(7);
            }
            else
                XuatDanhsachKhachHang(KH);
            break;
        case 2:
            if (KhachHang.Head == NULL)
            {
                textcolor(12);
                cout << "\tCHUA CO THONG TIN KHACH HANG!!";
                textcolor(7);
                getch();
                break;
            }
            system("cls");
            printf("\t\tNhap ho va ten:\n");
            char hovaten[100];
            cin.ignore();
            gets(hovaten);
            fflush(stdin);
            while (strlen(hovaten) == 0)
            {
                cout << "\tTen khong hop le\n";
                printf("\t\tNhap ho va ten: ");
                gets(hovaten);
                fflush(stdin);
            }
            ktTenhople(hovaten);
            tachTen(hovaten, timkhachhang.ten.holot, timkhachhang.ten.ten);
            while (kiemkhachhang != NULL)
            {
                if (strcmp(timkhachhang.ten.holot, kiemkhachhang->data.ten.holot) == 0 && strcmp(timkhachhang.ten.ten, kiemkhachhang->data.ten.ten) == 0)
                {
                    t++;
                    CustomerNode *p = newNode(kiemkhachhang->data);
                    insert(KH, p);
                }
                kiemkhachhang = kiemkhachhang->Next;
            }
            if (t == 0)
            {
                textcolor(12);
                printf("Khong tim thay thong tin khach hang");
                textcolor(7);
                getch();
            }
            else
                XuatDanhsachKhachHang(KH);

            break;
        case 3:
            if (KhachHang.Head == NULL)
            {
                textcolor(12);
                cout << "\tCHUA CO THONG TIN KHACH HANG!!";
                textcolor(7);
                getch();
                break;
            }
            system("cls");
            printf("\t\tNhap ngay sinh khach hang DD MM YYYY: ");
            scanf("%d", &timkhachhang.ngaysinh.day);
            scanf("%d", &timkhachhang.ngaysinh.month);
            scanf("%d", &timkhachhang.ngaysinh.year);
            fflush(stdin);
            while (Checkdate(timkhachhang.ngaysinh) == false)
            {
                cout << "\tNgay sinh khong hop le\n";
                printf("\t\tNhap ngay sinh khach hang DD MM YYYY: ");
                scanf("%d", &timkhachhang.ngaysinh.day);
                scanf("%d", &timkhachhang.ngaysinh.month);
                scanf("%d", &timkhachhang.ngaysinh.year);
                fflush(stdin);
            }

            while (kiemkhachhang != NULL)
            {
                if (timkhachhang.ngaysinh.year == kiemkhachhang->data.ngaysinh.year && timkhachhang.ngaysinh.day == kiemkhachhang->data.ngaysinh.day && timkhachhang.ngaysinh.month == kiemkhachhang->data.ngaysinh.month)
                {
                    t++;
                    CustomerNode *p = newNode(kiemkhachhang->data);
                    insert(KH, p);
                }
                kiemkhachhang = kiemkhachhang->Next;
            }
            if (t == 0)
            {
                textcolor(12);
                printf("Khong tim thay thong tin khach hang");
                textcolor(7);
                getch();
            }
            else
                XuatDanhsachKhachHang(KH);
            break;
        case 4:
            if (KhachHang.Head == NULL)
            {
                textcolor(12);
                cout << "\tCHUA CO THONG TIN KHACH HANG!!";
                textcolor(7);
                getch();
                break;
            }
            system("cls");
            cin.ignore();
            printf("\t\tNhap CCCD khach hang (12 chu so): ");
            gets(timkhachhang.cccd);
            fflush(stdin);
            while (strlen(timkhachhang.cccd) != 12)
            {
                if (strlen(timkhachhang.cccd) != 12)
                    cout << "\tCCCD khong hop le\n";
                printf("\t\tNhap CCCD khach hang (12 chu so): ");
                gets(timkhachhang.cccd);
                fflush(stdin);
            }
            while (kiemkhachhang != NULL)
            {
                if (strcmp(timkhachhang.cccd, kiemkhachhang->data.cccd) == 0)
                {
                    t++;
                    CustomerNode *p = newNode(kiemkhachhang->data);
                    insert(KH, p);
                }
                kiemkhachhang = kiemkhachhang->Next;
            }
            if (t == 0)
            {
                textcolor(12);
                printf("Khong tim thay thong tin khach hang");
                textcolor(7);
                getch();
            }
            else
                XuatDanhsachKhachHang(KH);
            break;
        case 5:
            if (Xe.Head == NULL)
            {
                textcolor(12);
                cout << "\tCHUA CO THONG TIN XE!!";
                textcolor(7);
                getch();
                break;
            }
            system("cls");
            cin.ignore();
            printf("\t\tNhap bien so xe (9 ky tu): ");
            gets(timxe.sign);
            fflush(stdin);
            InHoaMaSo(timxe.sign);
            while (strlen(timxe.sign) != 9)
            {
                if (strlen(timxe.sign) != 9)
                    cout << "\tBien so xe khong hop le\n";
                printf("\t\tNhap bien so xe (9 ky tu): ");
                gets(timxe.sign);
                fflush(stdin);
                InHoaMaSo(timxe.sign);
            }
            while (kiemxe != NULL)
            {
                if (strcmp(timxe.sign, kiemxe->data.sign) == 0)
                {
                    t++;
                    CarNode *p = newNode(kiemxe->data);
                    insert(X, p);
                }
                kiemxe = kiemxe->Next;
            }
            if (t == 0)
            {
                textcolor(12);
                printf("Khong tim thay thong tin xe");
                textcolor(7);
                getch();
            }
            else
                XuatDanhSachXe(X);
            break;
        case 6:
            textcolor(12);
            if (Thue.Head == NULL)
            {
                textcolor(12);
                cout << "\tCHUA CO THONG TIN XE THUE!!";
                textcolor(7);
                getch();
                break;
            }
            system("cls");
            cout << "\t\tNhap Tim theo Gia Tri Lon Nhat hay Nho Nhat!!\n";
            textcolor(7);
            cout << "\tMax - 1 / Min - 0: ";
            cin >> m;
            while (m != 0 && m != 1)
            {
                cout << "\tMax - 1 / Min - 0: ";
                cin >> m;
            }
            if (m == 0)
                for (TimGiaTien = Thue.Head; TimGiaTien != NULL; TimGiaTien = TimGiaTien->Next)
                {
                    if (TimGiaTien->data.giatien == FindMin(Thue))
                    {
                        ThueNode *p = newNode(TimGiaTien->data);
                        insert(T, p);
                    }
                }
            else
                for (TimGiaTien = Thue.Head; TimGiaTien != NULL; TimGiaTien = TimGiaTien->Next)
                {
                    if (TimGiaTien->data.giatien == FindMax(Thue))
                    {
                        ThueNode *p = newNode(TimGiaTien->data);
                        insert(T, p);
                    }
                }
            XuatDanhSachThueXe(T);
            break;
        default:
            textcolor(12);
            if (choice == 0)
                printf("Nhan phim bat ky de quay lai");
            else
                printf("Khong co lua chon nay, nhan phim bat ky de nhap lai");
            textcolor(7);
            getch();
            break;
        }
    }
}
void capNhat(DanhSachKhachHang &dsKH, DanhSachXe &dsXe, DanhSachThueXe &Thue)
{
    Customer khachHang;
    Car xe;
    int choice(1);
    while (choice != false)
    {
        system("cls");
        textcolor(12);
        cout << "\n\t\t\t\tMENU QUAN LY THUE XE\n";
        textcolor(7);
        printf("\t\t1.Cap nhat thong tin khach hang\n\t\t2.Cap nhat thong tin xe\n\t\t0.Quay lai\n");
        printf("\tNhap lua chon cua ban: ");
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (dsKH.Head == NULL)
            {
                textcolor(12);
                cout << "\tCHUA CO THONG TIN KHACH HANG!!";
                textcolor(7);
                _getch();
                break;
            }
            system("cls");
            cin.ignore();
            printf("\t\tNhap ma so khach hang (10 ky tu): ");
            gets(khachHang.maso);
            fflush(stdin);

            while (strlen(khachHang.maso) != 10)
            {
                cout << "\tMa so khong hop le\n";
                printf("\t\tNhap ma so khach hang (10 ky tu): ");
                gets(khachHang.maso);
                fflush(stdin);
            }
            InHoaMaSo(khachHang.maso);
            capNhatKhachHang(dsKH, Thue, khachHang.maso);
            getch();
            break;
        case 2:
            if (dsXe.Head == NULL)
            {
                textcolor(12);
                cout << "\tCHUA CO THONG TIN XE!!";
                textcolor(7);
                _getch();
                break;
            }
            system("cls");
            cin.ignore();
            printf("\t\tNhap bien so xe (9 ky tu): ");
            gets(xe.sign);
            fflush(stdin);
            while (strlen(xe.sign) != 9)
            {
                cout << "\tBien so xe khong hop le\n";
                printf("\t\tNhap bien so xe (9 ky tu): ");
                gets(xe.sign);
                fflush(stdin);
            }
            InHoaMaSo(xe.sign);
            capNhatXe(dsXe, xe.sign, Thue);
            getch();
            break;
        default:
            textcolor(12);
            if (choice == 0)
                printf("Nhan phim bat ky de quay lai");
            else
                printf("Khong co lua chon nay, nhan phim bat ky de nhap lai");
            textcolor(7);
            getch();
            break;
        }
    }
}

// Ham KhoiTao
void init(DanhSachKhachHang &KhachHang)
{
    KhachHang.Head = KhachHang.Tail = NULL;
    KhachHang.size = 0;
}
void init(DanhSachXe &Xe)
{
    Xe.Head = Xe.Tail = NULL;
    Xe.size = 0;
}
void init(DanhSachThueXe &Thue)
{
    Thue.Head = Thue.Tail = NULL;
    Thue.size = 0;
}
CustomerNode *newNode(Customer KhachHang)
{
    CustomerNode *p = new CustomerNode();
    if (!p)
    {
        printf("\tTao that bai!\n");
        getch();
        return NULL;
    }
    p->data = KhachHang;
    p->Next = NULL;
    return p;
}
ThueNode *newNode(ThueXe Thue)
{
    ThueNode *p = new ThueNode();
    if (!p)
    {
        printf("\tTao that bai!\n");
        getch();
        return NULL;
    }
    p->data = Thue;
    p->Next = NULL;
    return p;
}
CarNode *newNode(Car Xe)
{
    CarNode *p = new CarNode();
    if (!p)
    {
        printf("\tTao that bai!\n");
        getch();
        return NULL;
    }
    p->data = Xe;
    p->Next = NULL;
    return p;
}
// Ham Xoa
void delete_1(DanhSachKhachHang &KH, CustomerNode *R)
{
    if (R == NULL)
    {
        textcolor(12);
        cout << "\t\t\tKhong tim thay khach hang !\n";
        textcolor(7);
        getch();
        return;
    }
    if (R == KH.Head)
    {
        KH.Head = KH.Head->Next;
        if (KH.Head == NULL)
            KH.Tail = NULL;
    }
    else
    {
        CustomerNode *pre = KH.Head;
        while (pre->Next != R)
            pre = pre->Next;
        pre->Next = R->Next;
        if (KH.Tail == R)
            KH.Tail = pre;
    }
    KH.size--;
    delete R;
}
void delete_1(DanhSachXe &Xe, CarNode *R)
{
    if (R == NULL)
    {
        textcolor(12);
        cout << "\t\t\tKhong tim thay xe !\n";
        textcolor(7);
        getch();
        return;
    }
    if (R == Xe.Head)
    {
        Xe.Head = Xe.Head->Next;
        if (Xe.Head == NULL)
            Xe.Tail = NULL;
    }
    else
    {
        CarNode *pre = Xe.Head;
        while (pre->Next != R)
            pre = pre->Next;
        pre->Next = R->Next;
        if (Xe.Tail == R)
            Xe.Tail = pre;
    }
    Xe.size--;
    delete R;
}
void delete_1(DanhSachThueXe &Thue, ThueNode *R)
{
    if (R == NULL)
    {
        textcolor(12);
        cout << "\t\t\tKhong tim thay thue xe !\n";
        textcolor(7);
        getch();
        return;
    }
    if (R == Thue.Head)
    {
        Thue.Head = Thue.Head->Next;
        if (Thue.Head == NULL)
            Thue.Tail = NULL;
    }
    else
    {
        ThueNode *pre = Thue.Head;
        while (pre->Next != R)
            pre = pre->Next;
        pre->Next = R->Next;
        if (Thue.Tail == R)
            Thue.Tail = pre;
    }
    Thue.size--;
    delete R;
}
void ClearDS(DanhSachKhachHang &KhachHang)
{
    if (KhachHang.Head == NULL)
        return;
    while (KhachHang.Head != NULL)
    {
        CustomerNode *p = KhachHang.Head;
        KhachHang.Head = KhachHang.Head->Next;
        delete p;
    }
    KhachHang.Tail = NULL;
}
void ClearDS(DanhSachXe &Xe)
{
    if (Xe.Head == NULL)
        return;
    while (Xe.Head != NULL)
    {
        CarNode *p = Xe.Head;
        Xe.Head = Xe.Head->Next;
        delete p;
    }
    Xe.Tail = NULL;
}
void ClearDS(DanhSachThueXe &Thue)
{
    if (Thue.Head == NULL)
        return;
    while (Thue.Head != NULL)
    {
        ThueNode *p = Thue.Head;
        Thue.Head = Thue.Head->Next;
        delete p;
    }
    Thue.Tail = NULL;
}
// Ham Chen`
void insert(DanhSachKhachHang &KhachHang, CustomerNode *KhachHangMoi)
{
    if (KhachHang.Head == NULL)
        KhachHang.Head = KhachHang.Tail = KhachHangMoi;
    else
    {
        KhachHang.Tail->Next = KhachHangMoi;
        KhachHang.Tail = KhachHangMoi;
    }
    KhachHang.size++;
}
void insert(DanhSachXe &Xe, CarNode *XeMoi)
{
    if (Xe.Head == NULL)
        Xe.Head = Xe.Tail = XeMoi;
    else
    {
        Xe.Tail->Next = XeMoi;
        Xe.Tail = XeMoi;
    }
    Xe.size++;
}
void insert(DanhSachThueXe &Thue, ThueNode *ThueMoi)
{
    if (Thue.Head == NULL)
        Thue.Head = Thue.Tail = ThueMoi;
    else
    {
        Thue.Tail->Next = ThueMoi;
        Thue.Tail = ThueMoi;
    }
    Thue.size++;
}
void Nhap_1(DanhSachKhachHang &KhachHang) // them khach hang
{
    Customer KhachHangMoi;
    textcolor(12);
    printf("\t\t\tNhap thong tin khach hang:\n");
    textcolor(7);
    cin.ignore();
    printf("\t\tNhap ma so khach hang (10 ky tu): ");
    gets(KhachHangMoi.maso);
    fflush(stdin);
    InHoaMaSo(KhachHangMoi.maso);
    while (CheckcodeKH(KhachHang, KhachHangMoi.maso) != 1 || strlen(KhachHangMoi.maso) != 10)
    {
        if (strlen(KhachHangMoi.maso) != 10)
            cout << "\tMa so khong hop le\n";
        if (CheckcodeKH(KhachHang, KhachHangMoi.maso) != 1)
            cout << "\tMa so da ton tai\n";
        printf("\t\tNhap ma so khach hang (10 ky tu): ");
        gets(KhachHangMoi.maso);
        fflush(stdin);
        InHoaMaSo(KhachHangMoi.maso);
    }
    printf("\t\tNhap ho va ten: ");
    char hovaten[100];
    gets(hovaten);
    fflush(stdin);
    while (strlen(hovaten) == 0)
    {
        cout << "\tTen khong hop le\n";
        printf("\t\tNhap ho va ten: ");
        gets(hovaten);
        fflush(stdin);
    }
    ktTenhople(hovaten);
    tachTen(hovaten, KhachHangMoi.ten.holot, KhachHangMoi.ten.ten);
    printf("\t\tNhap ngay sinh khach hang DD MM YYYY: ");
    scanf("%d", &KhachHangMoi.ngaysinh.day);
    scanf("%d", &KhachHangMoi.ngaysinh.month);
    scanf("%d", &KhachHangMoi.ngaysinh.year);
    fflush(stdin);
    while (Checkdate(KhachHangMoi.ngaysinh) != 1)
    {
        cout << "\tNgay sinh khong hop le\n";
        printf("\t\tNhap ngay sinh khach hang DD MM YYYY: ");
        scanf("%d", &KhachHangMoi.ngaysinh.day);
        scanf("%d", &KhachHangMoi.ngaysinh.month);
        scanf("%d", &KhachHangMoi.ngaysinh.year);
        fflush(stdin);
    }
    fflush(stdin);
    cin.ignore();
    printf("\t\tNhap SDT (10 chu so): ");
    gets(KhachHangMoi.sdt);
    fflush(stdin);
    while (CheckSdtKH(KhachHang, KhachHangMoi.sdt) == false || strlen(KhachHangMoi.sdt) != 10)
    {
        if (strlen(KhachHangMoi.sdt) != 10)
            cout << "\tSDT khong hop le\n";
        if (CheckSdtKH(KhachHang, KhachHangMoi.sdt) == false && strlen(KhachHangMoi.sdt) == 10)
            cout << "\tSDT da ton tai hoac chua ky tu khong hop le\n";
        printf("\t\tNhap SDT (10 chu so): ");
        gets(KhachHangMoi.sdt);
        fflush(stdin);
    }
    printf("\t\tNhap CCCD (12 chu so): ");
    gets(KhachHangMoi.cccd);
    fflush(stdin);
    while (CheckCCCDKH(KhachHang, KhachHangMoi.cccd) != 1 || strlen(KhachHangMoi.cccd) != 12)
    {
        if (strlen(KhachHangMoi.cccd) != 12)
            cout << "\tCCCD khong hop le\n";
        if (CheckCCCDKH(KhachHang, KhachHangMoi.cccd) != 1 && strlen(KhachHangMoi.cccd) == 12)
            cout << "\tCCCD da ton tai hay chua ky tu khong hop le\n";
        printf("\t\tNhap CCCD (12 chu so): ");
        gets(KhachHangMoi.cccd);
        fflush(stdin);
    }
    cout << "\t\tNhap so lan da thue xe: ";
    cin >> KhachHangMoi.solanthue;
    while (KhachHangMoi.solanthue < 0)
    {
        cout << "\tSo lan thue khong hop le\n";
        cout << "\t\tNhap so lan da thue xe: ";
        cin >> KhachHangMoi.solanthue;
    }

    CustomerNode *p = newNode(KhachHangMoi);
    insert(KhachHang, p);
}
void Nhap_1(DanhSachXe &Xe) // them xe
{
    Car XeMoi;
    textcolor(12);
    printf("\t\t\tNhap thong tin xe:\n");
    textcolor(7);
    cin.ignore();
    printf("\t\tNhap bien so xe (9 ky tu): ");
    gets(XeMoi.sign);
    fflush(stdin);
    InHoaMaSo(XeMoi.sign);
    while (ChecksignXe(Xe, XeMoi.sign) != 1 || strlen(XeMoi.sign) != 9)
    {
        if (strlen(XeMoi.sign) != 9)
            cout << "\tBien so xe khong hop le\n";
        if (ChecksignXe(Xe, XeMoi.sign) != 1)
            cout << "\tBien so xe da ton tai !!\n";
        printf("\t\tNhap bien so xe (9 ky tu): ");
        gets(XeMoi.sign);
        fflush(stdin);
        InHoaMaSo(XeMoi.sign);
    }
    printf("\t\tNhap ten xe: ");
    gets(XeMoi.namecar);
    fflush(stdin);
    while (strlen(XeMoi.namecar) == 0)
    {
        if (strlen(XeMoi.namecar) == 0)
            cout << "\tTen xe khong hop le\n";
        printf("\t\tNhap ten xe: ");
        gets(XeMoi.namecar);
        fflush(stdin);
    }
    ktTenhople(XeMoi.namecar);
    printf("\t\tNhap ngay dang kiem xe DD MM YYYY: ");
    scanf("%d", &XeMoi.ngay.day);
    scanf("%d", &XeMoi.ngay.month);
    scanf("%d", &XeMoi.ngay.year);
    while (Checkdate(XeMoi.ngay) != TRUE)
    {
        cout << "\tNgay dang kiem khong hop le\n";
        printf("\t\tNhap ngay dang kiem xe DD MM YYYY: ");
        scanf("%d", &XeMoi.ngay.day);
        scanf("%d", &XeMoi.ngay.month);
        scanf("%d", &XeMoi.ngay.year);
        fflush(stdin);
    }
    printf("\t\tNhap gia thue: ");
    scanf("%d", &XeMoi.price);
    while (XeMoi.price <= 0)
    {
        cout << "\tGia thue khong hop le\n";
        printf("\t\tNhap gia thue: ");
        scanf("%d", &XeMoi.price);
    }
    CarNode *p = newNode(XeMoi);
    insert(Xe, p);
}
void Nhap_1(DanhSachKhachHang KhachHang, DanhSachXe Xe, DanhSachThueXe &Thue) // them thue xe, goi ham` thue xe thi` khach hang` va` xe deu` dc goi
{
    if (KhachHang.size == 0)
    {
        textcolor(12);
        cout << "\tCHUA CO THONG TIN KHACH HANG!!";
        textcolor(7);
        getch();
        return;
    }
    if (Xe.size == 0)
    {
        textcolor(12);
        cout << "\tCHUA CO THONG TIN XE!!";
        textcolor(7);
        getch();
        return;
    }
    ThueXe ThueXeMoi;
    ThueXeMoi.khachhang = new CustomerNode();
    ThueXeMoi.xe = new CarNode();
    char maso[11], sign[10];
    textcolor(12);
    printf("\t\t\tNhap thong tin thue xe:\n");
    textcolor(7);
    cin.ignore();
    printf("\t\tNhap ma so khach hang (10 ky tu): ");
    gets(maso);
    fflush(stdin);
    InHoaMaSo(maso);
    while (CheckcodeKH(KhachHang, maso) != 0 || strlen(maso) != 10)
    {
        if (strlen(maso) != 10)
            cout << "\tMa so khong hop le\n";
        if (CheckcodeKH(KhachHang, maso) != 0 && strlen(maso) == 10)
            cout << "\tMa so khong ton tai !!\n";
        printf("\t\tNhap ma so khach hang (10 ky tu): ");
        gets(maso);
        fflush(stdin);
        InHoaMaSo(maso);
    }
    printf("\t\tNhap bien so xe (9 ky tu): ");
    gets(sign);
    fflush(stdin);
    InHoaMaSo(sign);
    while (CheckXe(Thue, sign) != 1 || ChecksignXe(Xe, sign) != 0 || strlen(sign) != 9)
    {
        if (strlen(sign) != 9)
            cout << "\tBien so xe khong hop le\n";
        if (CheckXe(Thue, sign) != 1)
            cout << "\tXe da duoc thue !!\n";
        if (ChecksignXe(Xe, sign) != 0 && strlen(sign) == 9)
            cout << "\tBien so xe khong ton tai !!\n";
        printf("\t\tNhap bien so xe (9 ky tu): ");
        gets(sign);
        fflush(stdin);
        InHoaMaSo(sign);
    }
    CustomerNode *p = KhachHang.Head;
    CarNode *q = Xe.Head;
    while (p != NULL)
    {
        if (strcmp(maso, p->data.maso) == 0)
            ThueXeMoi.khachhang = p;
        p = p->Next;
    }
    ThueXeMoi.khachhang->data.solanthue++;
    while (q != NULL)
    {
        if (strcmp(sign, q->data.sign) == 0)
            ThueXeMoi.xe = q;
        q = q->Next;
    }
    fflush(stdin);
    printf("\t\tNhap so ngay thue: ");
    cin >> ThueXeMoi.songaythue;
    while (ThueXeMoi.songaythue <= 0)
    {
        cout << "\tSo ngay thue khong hop le\n";
        printf("\t\tNhap so ngay thue: ");
        cin >> ThueXeMoi.songaythue;
    }
    printf("\t\tNhap ngay thue theo DD MM YYYY: ");
    cin >> ThueXeMoi.thue.day >> ThueXeMoi.thue.month >> ThueXeMoi.thue.year;
    while (Checkdate(ThueXeMoi.thue) == false)
    {
        printf("\tNgay thue khong hop le\n");
        printf("\t\tNhap ngay thue theo DD MM YYYY: ");
        scanf("%d", &ThueXeMoi.thue.day);
        scanf("%d", &ThueXeMoi.thue.month);
        scanf("%d", &ThueXeMoi.thue.year);
        fflush(stdin);
    };
    ThueXeMoi.tra = PlusDate(ThueXeMoi.thue, ThueXeMoi.songaythue);
    ThueXeMoi.giatien = ThueXeMoi.songaythue * ThueXeMoi.xe->data.price;
    ThueNode *Moi = newNode(ThueXeMoi);
    insert(Thue, Moi);
}
// Ham Xuat
void XuatKhachHang(CustomerNode *i, DanhSachKhachHang KhachHang)
{
    char Ho_Ten[40] = "\0";
    if (strcmp(i->data.ten.holot, "\0") != 0)
    {
        strcpy(Ho_Ten, i->data.ten.holot);
        strcat(Ho_Ten, " ");
    }
    strcat(Ho_Ten, i->data.ten.ten);
    int num = countlongestkhachhang(KhachHang);
    cout
        << left << setw(10) << i->data.maso << "  " << setw(num) << Ho_Ten << "  " << setw(10) << ngay(i->data.ngaysinh) << "  " << setw(10) << i->data.sdt << "  " << setw(12) << i->data.cccd << right << setw(13) << i->data.solanthue << endl;
}
void XuatXe(CarNode *i, DanhSachXe Xe)
{
    int num = countlongestxe(Xe);
    cout << left << setw(9) << i->data.sign
         << "   " << setw(num) << i->data.namecar
         << right << setw(16) << ngay(i->data.ngay)
         << setw(15);
    printNumberWithCommas(i->data.price);
}
void XuatThueXe(ThueNode *i, DanhSachThueXe Thue)
// ma so, ten ng, sign xe, so ngay thue, tong so tien
{
    char Ho_Ten[40] = "\0";
    int num1 = countlongestthuexe(Thue, 1);
    int num2 = countlongestthuexe(Thue, 2);
    if (strcmp(i->data.khachhang->data.ten.holot, "\0") != 0)
    {
        strcpy(Ho_Ten, i->data.khachhang->data.ten.holot);
        strcat(Ho_Ten, " ");
    }
    strcat(Ho_Ten, i->data.khachhang->data.ten.ten);
    cout << left << setw(10) << i->data.khachhang->data.maso << "  " << setw(num1) << Ho_Ten << "  " << setw(10) << i->data.xe->data.sign << "  " << setw(num2) << i->data.xe->data.namecar << "  " << setw(10) << ngay(i->data.thue) << "  " << setw(10) << ngay(i->data.tra) << right << setw(14) << i->data.songaythue << setw(15);
    printNumberWithCommas(i->data.giatien);
}
void XuatDanhsachKhachHang(DanhSachKhachHang KhachHang)
{
    CustomerNode *i;
    if (KhachHang.Head == NULL)
    {
        textcolor(12);
        cout << "\tCHUA CO THONG TIN KHACH HANG!!";
        textcolor(7);
        getch();
        return;
    }
    textcolor(12);
    int num = countlongestkhachhang(KhachHang);
    cout
        << left << setw(10) << "Ma so"
        << "  " << setw(num) << "Ho ten"
        << "  " << setw(10) << "Ngay sinh"
        << "  " << setw(10) << "SDT"
        << "  " << setw(12) << "CCCD"
        << "  " << setw(5) << "So lan thue" << right << endl;
    textcolor(7);
    for (i = KhachHang.Head; i != NULL; i = i->Next)
    {
        XuatKhachHang(i, KhachHang);
    }
    getch();
}
void XuatDanhSachXe(DanhSachXe Xe)
{
    CarNode *i;
    if (Xe.Head == NULL)
    {
        textcolor(12);
        cout << "\tCHUA CO THONG TIN XE!!";
        textcolor(7);
        getch();
        return;
    }
    textcolor(12);
    int num = countlongestxe(Xe);
    cout
        << left << setw(10) << "Bien so xe"
        << "  " << setw(num) << "Ten xe"
        << "  " << setw(10) << "Ngay dang kiem"
        << right << setw(15) << "Gia tien" << endl;
    textcolor(7);
    for (i = Xe.Head; i != NULL; i = i->Next)
    {
        XuatXe(i, Xe);
    }
    getch();
}
void XuatDanhSachThueXe(DanhSachThueXe Thue)
{
    ThueNode *i;
    if (Thue.Head == NULL)
    {
        textcolor(12);
        cout << "\tCHUA CO THONG TIN XE THUE!!";
        textcolor(7);
        getch();
        return;
    }
    textcolor(12);
    int num1 = countlongestthuexe(Thue, 1);
    int num2 = countlongestthuexe(Thue, 2);
    cout
        << left << setw(10) << "Ma so"
        << "  " << setw(num1) << "Ho ten"
        << "  " << setw(10) << "Bien so xe"
        << "  " << setw(num2) << "Ten xe"
        << "  " << setw(10) << "Ngay thue"
        << "  " << setw(10) << "Ngay tra"
        << "  " << setw(12) << "So ngay thue"
        << right << setw(15) << "Tong tien" << endl;
    textcolor(7);
    for (i = Thue.Head; i != NULL; i = i->Next)
    {
        XuatThueXe(i, Thue);
    }
    getch();
}
// Ham KiemTra
void xoakytu(char a[], int position)
{
    int i;
    int leng = strlen(a);
    for (i = position; i < leng - 1; i++)
    {
        a[i] = a[i + 1];
    }
    leng--;
    a[leng] = '\0'; // chuỗi
}
int timKhoangCachCuoi(char a[])
{
    int leng = strlen(a);
    int i, j(-1);
    for (i = 0; i < leng; i++)
        if (a[i] == 32)
            j = i;
    return j;
}
void tachTen(char hovaten[], char ho[], char ten[])
{
    int vitri = timKhoangCachCuoi(hovaten);
    if (vitri == -1)
    {
        for (int i = 0; i < strlen(hovaten); i++)
            ten[i] = hovaten[i];
        ten[strlen(hovaten)] = '\0';
        ho[0] = '\0';
        return;
    } // vị trí của khoảng cách cuối cùng
    int j = 0;
    for (int i = vitri + 1; i < strlen(hovaten); i++)
        ten[j++] = hovaten[i];
    ten[j] = '\0';
    j = 0;
    for (int i = 0; i < vitri; i++)
        ho[j++] = hovaten[i];
    ho[j] = '\0';
}
void ktTenhople(char a[])
{
    int i;
    int leng = strlen(a);
    for (i = 0; i < leng; i++)
    {
        if (a[0] == ' ')
            xoakytu(a, 0);
        if (a[i] == ' ' && a[i + 1] == ' ')
        {
            xoakytu(a, i);
            i--;
        }
        if (a[leng - 1] == ' ')
            xoakytu(a, leng - 1);
    }

    if (a[0] >= 'a' && a[0] <= 'z') // nếu a[0] là thường thì đổi sang IN
        a[0] -= 32;
    for (i = 1; i < leng; i++)
    {
        if (a[i - 1] == 32 && a[i] >= 'a' && a[i] <= 'z')
        {
            a[i] -= 32;
        }
        else if (a[i - 1] != 32 && a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 32;
    }
    a[strlen(a)] = '\0';
}
int CheckCCCDKH(DanhSachKhachHang &KhachHang, char cccd[]) // kiem tra cccd Khach Hang
{
    for (int i = 0; i < 12; i++)
    {
        if (!(cccd[i] >= 48 && cccd[i] <= 57))
            return 0;
    }
    if (KhachHang.Head == NULL)
        return 1;
    else
    {
        CustomerNode *p = KhachHang.Head;
        while (p != NULL)
        {
            if (strcmp(p->data.cccd, cccd) == 0)
                return 0;
            p = p->Next;
        }
        return 1;
    }
}
int CheckSdtKH(DanhSachKhachHang &KhachHang, char sdt[])
{
    for (int i = 0; i < 10; i++)
    {
        if (!(sdt[i] >= 48 && sdt[i] <= 57))
            return 0;
    }
    if (KhachHang.Head == NULL)
        return 1;
    else
    {
        CustomerNode *p = KhachHang.Head;
        while (p != NULL)
        {
            if (strcmp(p->data.sdt, sdt) == 0)
                return 0;
            p = p->Next;
        }
        return 1;
    }
}
int ChecksignXe(DanhSachXe &Xe, char sign[]) // kiem tra bien so Xe
{
    if (Xe.Head == NULL)
        return 1;
    else
    {
        CarNode *p = Xe.Head;
        while (p != NULL)
        {
            if (strcmp(p->data.sign, sign) == 0)
                return 0;
            p = p->Next;
        }
        return 1;
    }
}

bool Checkdate(date a)
{
    if (a.year <= 0)
        return false;
    switch (a.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (a.day >= 1 && a.day <= 31)
            return true;
        return false;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (a.day >= 1 && a.day <= 30)
            return true;
        return false;
        break;
    case 2:
        if (a.year % 4 == 0 && a.year % 100 != 0 || a.year % 400 == 0) // Kiểm tra năm nhuận
        {
            if (a.day >= 1 && a.day <= 29)
                return true;
            return false;
        }
        else
        {
            if (a.day >= 1 && a.day <= 28)
                return true;
            return false;
        }
        break;
    default:
        return false;
        break;
    }
}
date PlusDate(date thue, int songaythue)
{
    date tra = thue;
    tra.day = thue.day + songaythue;
    switch (tra.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (tra.day > 31)
        {
            tra.day -= 31;
            tra.month++;
            if (tra.month > 12)
            {
                tra.month = 1;
                tra.year++;
            }
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (tra.day > 30)
        {
            tra.day -= 30;
            tra.month++;
        }
        break;
    case 2:
        if (tra.year % 4 == 0 && tra.year % 100 != 0 || tra.year % 400 == 0) // Kiểm tra năm nhuận
        {
            if (tra.day > 29)
            {
                tra.day -= 29;
                tra.month++;
            }
        }
        else
        {
            if (tra.day > 28)
            {
                tra.day -= 28;
                tra.month++;
            }
        }
        break;
    default:
        break;
    }
    return tra;
}
int FindMin(DanhSachThueXe Thue)
{
    ThueNode *i = Thue.Head;
    int result = i->data.giatien;
    while (i != NULL)
    {
        result = result > i->data.giatien ? i->data.giatien : result;
        i = i->Next;
    }
    return result;
}
int FindMax(DanhSachThueXe Thue)
{
    ThueNode *i = Thue.Head;
    int result = i->data.giatien;
    while (i != NULL)
    {
        result = result > i->data.giatien ? result : i->data.giatien;
        i = i->Next;
    }
    return result;
}
int CheckXe(DanhSachThueXe Thue, char sign[]) // kiem tra xe da thue
{
    if (Thue.Head == NULL)
        return 1;
    else
    {
        ThueNode *p = Thue.Head;
        while (p != NULL)
        {
            if (strcmp(p->data.xe->data.sign, sign) == 0)
                return 0;
            p = p->Next;
        }
    }
    return 1;
}
int CheckcodeKH(DanhSachKhachHang &KhachHang, char maso[]) // kiem tra ma Khach Hang
{
    // 1 la` ko ton tai
    // 0 la` co ton tai
    if (KhachHang.Head == NULL)
        return 1;
    else
    {
        CustomerNode *p = KhachHang.Head;
        while (p != NULL)
        {
            if (strcmp(p->data.maso, maso) == 0)
                return 0;
            p = p->Next;
        }
        return 1;
    }
}
void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void textcolor(int x)
{
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}
void printNumberWithCommas(int num)
{
    string numString = to_string(num); // chuyển số nguyên thành chuỗi
    int length = numString.length();   // độ dài của chuỗi
    int commaIndex = length - 3;       // chỉ số vị trí dấu phẩy đầu tiên
    while (commaIndex > 0)
    {                                      // lặp qua chuỗi để chèn dấu phẩy
        numString.insert(commaIndex, ","); // chèn dấu phẩy vào vị trí commaIndex
        commaIndex -= 3;                   // di chuyển đến vị trí của dấu phẩy tiếp theo
    }
    cout << numString << std::endl; // xuất chuỗi đã định dạng ra màn hình
}
string ngay(date a)
{
    string day = to_string(a.day);
    string month = to_string(a.month);
    string year = to_string(a.year);
    if (day.length() == 1)
        day.insert(0, "0");
    if (month.length() == 1)
        month.insert(0, "0");
    int i = year.length();
    while (i != 4)
    {
        year.insert(0, "0");
        i++;
    }
    string R = day + "/" + month + "/" + year;
    return R;
}
void InHoaMaSo(char maso[])
{
    for (int i = 0; i < strlen(maso); i++)
        if (maso[i] >= 'a' && maso[i] <= 'z')
            maso[i] -= 32;
}
int countChars(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
int countlongestkhachhang(DanhSachKhachHang KhachHang)
{
    CustomerNode *i;
    char Ho_Ten_cur[40];
    char Ho_Ten_next[40];
    strcpy(Ho_Ten_cur, KhachHang.Head->data.ten.holot);
    strcat(Ho_Ten_cur, " ");
    strcat(Ho_Ten_cur, KhachHang.Head->data.ten.ten);
    char longest[40];
    strcpy(longest, Ho_Ten_cur);
    for (i = KhachHang.Head; i != NULL; i = i->Next)
    {
        strcpy(Ho_Ten_next, i->data.ten.holot);
        strcat(Ho_Ten_next, " ");
        strcat(Ho_Ten_next, i->data.ten.ten);
        if (strlen(longest) < strlen(Ho_Ten_next))
        {
            strcpy(longest, Ho_Ten_next);
        }
    }
    return countChars(longest);
}
int countlongestxe(DanhSachXe Xe)
{
    CarNode *i;
    char longest[20];
    strcpy(longest, Xe.Head->data.namecar);
    for (i = Xe.Head; i != NULL; i = i->Next)
    {
        if (strlen(longest) < strlen(i->data.namecar))
        {
            strcpy(longest, i->data.namecar);
        }
    }
    return countChars(longest);
}
int countlongestthuexe(DanhSachThueXe Thue, int valuecheck) // 1.Ten 2.ten xe
{
    ThueNode *i;
    char Ho_Ten_cur[40];
    char Ho_Ten_next[40];
    if (valuecheck == 1)
    {
        strcpy(Ho_Ten_cur, Thue.Head->data.khachhang->data.ten.holot);
        strcat(Ho_Ten_cur, " ");
        strcat(Ho_Ten_cur, Thue.Head->data.khachhang->data.ten.ten);
        char longest[40];
        strcpy(longest, Ho_Ten_cur);
        for (i = Thue.Head; i != NULL; i = i->Next)
        {
            strcpy(Ho_Ten_next, i->data.khachhang->data.ten.holot);
            strcat(Ho_Ten_next, " ");
            strcat(Ho_Ten_next, i->data.khachhang->data.ten.ten);
            if (strlen(longest) < strlen(Ho_Ten_next))
            {
                strcpy(longest, Ho_Ten_next);
            }
        }
        return countChars(longest);
    }
    else
    {
        char longest[40];
        strcpy(longest, Thue.Head->data.xe->data.namecar);
        for (i = Thue.Head; i != NULL; i = i->Next)
        {
            if (strlen(longest) < strlen(i->data.xe->data.namecar))
                strcpy(longest, i->data.xe->data.namecar);
        }
        return countChars(longest);
    }
}
// Ham Xu Ly File
void readfile(DanhSachKhachHang &KhachHang)
{
    ifstream KH;
    KH.open("khachhang.txt", ios_base::in);
    if (KH.fail())
    {
        textcolor(12);
        printf("\n\t\tFILE KHACH HANG KHONG TON TAI!!\n");
        textcolor(7);
        printf("Nhan Enter de tiep tuc!");
        getch();
        return;
    }
    while (!KH.eof())
    {
        Customer KhachHangMoi;
        Doc_1_Doi_Tuong(KH, KhachHangMoi);
        CustomerNode *p = newNode(KhachHangMoi);
        if (strcmp(p->data.cccd, "") == 0 || CheckCCCDKH(KhachHang, p->data.cccd) == 0)
            continue;
        insert(KhachHang, p);
    }
    KH.close();
}
void Doc_1_Doi_Tuong(ifstream &KH, Customer &KhachHangMoi)
{
    char hovaten[100] = "\0";
    KH.getline(KhachHangMoi.maso, 11, ',');
    KH.getline(hovaten, 100, ',');
    KH.getline(KhachHangMoi.sdt, 11, ',');
    KH.getline(KhachHangMoi.cccd, 13, ',');
    KH >> KhachHangMoi.solanthue;
    KH >> KhachHangMoi.ngaysinh.day;
    KH >> KhachHangMoi.ngaysinh.month;
    KH >> KhachHangMoi.ngaysinh.year;
    string tmp;
    getline(KH, tmp);
    ktTenhople(hovaten);
    tachTen(hovaten, KhachHangMoi.ten.holot, KhachHangMoi.ten.ten);
}
void readfile(DanhSachXe &Xe)
{
    ifstream X;
    X.open("danhmucxe.txt", ios_base::in);
    if (X.fail())
    {
        textcolor(12);
        printf("\n\t\tFILE Xe KHONG TON TAI!!\n");
        textcolor(7);
        printf("Nhan Enter de tiep tuc!");
        getch();
        return;
    }
    while (!X.eof())
    {
        Car XeMoi;
        Doc_1_Doi_Tuong(X, XeMoi);
        CarNode *p = newNode(XeMoi);
        if (strcmp(p->data.sign, "") == 0 || ChecksignXe(Xe, p->data.sign) == 0)
            continue;
        insert(Xe, p);
    }
    X.close();
}
void Doc_1_Doi_Tuong(ifstream &X, Car &XeMoi)
{
    X.getline(XeMoi.sign, 10, ',');
    X.getline(XeMoi.namecar, 20, ',');
    X >> XeMoi.ngay.day >> XeMoi.ngay.month >> XeMoi.ngay.year >> XeMoi.price;
    string tmp;
    getline(X, tmp);
    ktTenhople(XeMoi.namecar);
}
void readfile(DanhSachKhachHang KhachHang, DanhSachXe Xe, DanhSachThueXe &Thue)
{
    ifstream TX;
    TX.open("thuexe.txt", ios_base::in);
    if (TX.fail())
    {
        textcolor(12);
        printf("\n\t\tFILE Thue Xe KHONG TON TAI!!\n");
        textcolor(7);
        printf("Nhan Enter de tiep tuc!");
        getch();
        return;
    }
    while (!TX.eof())
    {
        ThueXe ThueMoi;
        Doc_1_Doi_Tuong(TX, KhachHang, Xe, ThueMoi);
        ThueNode *p = newNode(ThueMoi);
        if (strcmp(p->data.khachhang->data.maso, "") == 0 || CheckXe(Thue, p->data.xe->data.sign) == 0 || ChecksignXe(Xe, p->data.xe->data.sign) == 1)
            continue;
        else
        {
            p->data.giatien = p->data.songaythue * p->data.xe->data.price;
            p->data.tra = PlusDate(p->data.thue, p->data.songaythue);
        }
        insert(Thue, p);
    }
    TX.close();
}
void Doc_1_Doi_Tuong(ifstream &TX, DanhSachKhachHang KhachHang, DanhSachXe Xe, ThueXe &ThueMoi)
{
    char maso[11] = "\0", sign[10] = "\0";
    ThueMoi.khachhang = new CustomerNode();
    ThueMoi.xe = new CarNode();
    TX.getline(maso, 11, ',');
    TX.getline(sign, 10, ',');
    TX >> ThueMoi.thue.day >> ThueMoi.thue.month >> ThueMoi.thue.year >> ThueMoi.songaythue;
    string tmp;
    getline(TX, tmp);
    CustomerNode *p = KhachHang.Head;
    CarNode *q = Xe.Head;
    while (p != NULL)
    {
        if (strcmp(p->data.maso, maso) == 0)
            ThueMoi.khachhang = p;
        p = p->Next;
    }
    while (q != NULL)
    {
        if (strcmp(q->data.sign, sign) == 0)
            ThueMoi.xe = q;
        q = q->Next;
    }
}
void Exportfile(DanhSachKhachHang KhachHang)
{
    CustomerNode *p = KhachHang.Head;
    if (!p)
    {
        textcolor(12);
        cout << "\tKhong Co Thong Tin Khach Hang De Xuat\n";
        textcolor(7);
        getch();
        return;
    }
    ofstream KH;
    KH.open("khachhang.txt", ios_base::out);
    while (p != NULL)
    {
        Export_1_Doi_Tuong(KH, p->data);
        p = p->Next;
    }
    KH.close();
}
void Export_1_Doi_Tuong(ofstream &KH, Customer KhachHangMoi)
{
    if (strcmp(KhachHangMoi.ten.holot, "\0") == 0)
        KH << KhachHangMoi.maso << "," << KhachHangMoi.ten.ten << "," << KhachHangMoi.sdt << "," << KhachHangMoi.cccd << "," << KhachHangMoi.solanthue << " " << KhachHangMoi.ngaysinh.day << " " << KhachHangMoi.ngaysinh.month << " " << KhachHangMoi.ngaysinh.year << "\n";
    else
        KH << KhachHangMoi.maso << "," << KhachHangMoi.ten.holot << " " << KhachHangMoi.ten.ten << "," << KhachHangMoi.sdt << "," << KhachHangMoi.cccd << "," << KhachHangMoi.solanthue << " " << KhachHangMoi.ngaysinh.day << " " << KhachHangMoi.ngaysinh.month << " " << KhachHangMoi.ngaysinh.year << "\n";
}
void Exportfile(DanhSachXe Xe)
{
    CarNode *p = Xe.Head;
    if (!p)
    {
        textcolor(12);
        cout << "\tKhong Co Thong Tin Xe De Xuat\n";
        textcolor(7);
        getch();
        return;
    }
    ofstream X;
    X.open("danhmucxe.txt", ios_base::out);
    while (p != NULL)
    {
        Export_1_Doi_Tuong(X, p->data);
        p = p->Next;
    }
    X.close();
}
void Export_1_Doi_Tuong(ofstream &X, Car XeMoi)
{
    X << XeMoi.sign << "," << XeMoi.namecar << ", " << XeMoi.ngay.day << " " << XeMoi.ngay.month << " " << XeMoi.ngay.year << " " << XeMoi.price << "\n";
}
void Exportfile(DanhSachThueXe Thue)
{
    ThueNode *p = Thue.Head;
    if (!p)
    {
        textcolor(12);
        cout << "\tKhong Co Thong Tin Thue Xe De Xuat\n";
        textcolor(7);
        getch();
        return;
    }
    ofstream TX;
    TX.open("thuexe.txt", ios_base::out);
    while (p != NULL)
    {
        Export_1_Doi_Tuong(TX, p->data);
        p = p->Next;
    }
    TX.close();
}
void Export_1_Doi_Tuong(ofstream &TX, ThueXe ThueMoi)
{
    TX << ThueMoi.khachhang->data.maso << "," << ThueMoi.xe->data.sign << ", " << ThueMoi.thue.day << " " << ThueMoi.thue.month << " " << ThueMoi.thue.year << " " << ThueMoi.songaythue << "\n";
}
// Ham Sap Xep
CustomerNode *FindMin(DanhSachKhachHang KhachHang)
{
    CustomerNode *p = KhachHang.Head->Next;
    CustomerNode *Result = KhachHang.Head;
    while (p != NULL)
    {
        Result = Result->data.solanthue > p->data.solanthue ? p : Result;
        p = p->Next;
    }
    return Result;
}
CustomerNode *divideNode(DanhSachKhachHang &KhachHang, CustomerNode *min)
{
    if (KhachHang.Head == NULL)
        return NULL;
    CustomerNode *p = KhachHang.Head;
    while (p != NULL && p->Next != min)
        p = p->Next;
    if (min == KhachHang.Head)
    {
        KhachHang.Head = KhachHang.Head->Next;
        min->Next = NULL;
    }
    else if (min == KhachHang.Tail)
    {
        KhachHang.Tail = p;
        p->Next = NULL;
    }
    else
    {
        p->Next = min->Next;
        min->Next = NULL;
    }
    return min;
}
DanhSachKhachHang Sort(DanhSachKhachHang &KhachHang, int choice)
{
    DanhSachKhachHang R;
    init(R);
    CustomerNode *p = KhachHang.Head;
    if (p == NULL)
        return KhachHang;
    while (p != NULL)
    {
        p = KhachHang.Head;
        CustomerNode *q = KhachHang.Head;
        while (q != NULL)
        {
            CustomerNode *min = FindMin(KhachHang);
            if (q == min)
            {
                CustomerNode *Result = divideNode(KhachHang, min);
                if (choice == 1)
                    insert(R, Result);
                else
                {
                    if (R.Head == NULL)
                        R.Head = R.Tail = Result;
                    else
                    {
                        Result->Next = R.Head;
                        R.Head = Result;
                    }
                    R.size++;
                }
                break;
            }
            q = q->Next;
        }
    }

    return R;
}
CustomerNode *FindMinNgaySinh(DanhSachKhachHang KhachHang)
{
    CustomerNode *p = KhachHang.Head->Next;
    CustomerNode *Result = KhachHang.Head;
    while (p != NULL)
    {
        if (Result->data.ngaysinh.year > p->data.ngaysinh.year)
            Result = p;
        else if (Result->data.ngaysinh.year == p->data.ngaysinh.year)
        {
            if (Result->data.ngaysinh.month > p->data.ngaysinh.month)
                Result = p;
            else if (Result->data.ngaysinh.month == p->data.ngaysinh.month)
            {
                if (Result->data.ngaysinh.day > p->data.ngaysinh.day)
                    Result = p;
                else if (Result->data.ngaysinh.day == p->data.ngaysinh.day)
                    Result = p;
            }
        }
        p = p->Next;
    }
    return Result;
}
DanhSachKhachHang SortNgaySinh(DanhSachKhachHang &KhachHang, int choice)
{
    DanhSachKhachHang R;
    init(R);
    CustomerNode *p = KhachHang.Head;
    if (p == NULL)
        return KhachHang;
    while (p != NULL)
    {
        p = KhachHang.Head;
        CustomerNode *q = KhachHang.Head;
        while (q != NULL)
        {
            CustomerNode *min = FindMinNgaySinh(KhachHang);
            if (q == min)
            {
                CustomerNode *Result = divideNode(KhachHang, min);
                if (choice == 1)
                    insert(R, Result);
                else
                {
                    if (R.Head == NULL)
                        R.Head = R.Tail = Result;
                    else
                    {
                        Result->Next = R.Head;
                        R.Head = Result;
                    }
                    R.size++;
                }
                break;
            }
            q = q->Next;
        }
    }
    return R;
}
CarNode *FindMin(DanhSachXe Xe)
{
    CarNode *p = Xe.Head->Next;
    CarNode *Result = Xe.Head;
    while (p != NULL)
    {
        Result = Result->data.price > p->data.price ? p : Result;
        p = p->Next;
    }
    return Result;
}
CarNode *divideNode(DanhSachXe &Xe, CarNode *min)
{
    if (Xe.Head == NULL)
        return NULL;
    CarNode *p = Xe.Head;
    while (p != NULL && p->Next != min)
        p = p->Next;
    if (min == Xe.Head)
    {
        Xe.Head = Xe.Head->Next;
        min->Next = NULL;
    }
    else if (min == Xe.Tail)
    {
        Xe.Tail = p;
        p->Next = NULL;
    }
    else
    {
        p->Next = min->Next;
        min->Next = NULL;
    }
    return min;
}
DanhSachXe Sort(DanhSachXe &Xe, int choice)
{
    DanhSachXe R;
    init(R);
    CarNode *p = Xe.Head;
    if (p == NULL)
        return Xe;
    while (p != NULL)
    {
        p = Xe.Head;
        CarNode *q = Xe.Head;
        while (q != NULL)
        {
            CarNode *min = FindMin(Xe);
            if (q == min)
            {
                CarNode *Result = divideNode(Xe, min);
                if (choice == 1)
                    insert(R, Result);
                else
                {
                    if (R.Head == NULL)
                        R.Head = R.Tail = Result;
                    else
                    {
                        Result->Next = R.Head;
                        R.Head = Result;
                    }
                    R.size++;
                }
                break;
            }
            q = q->Next;
        }
    }
    return R;
}
ThueNode *FindMinThue(DanhSachThueXe Thue)
{
    ThueNode *p = Thue.Head->Next;
    ThueNode *R = Thue.Head;
    while (p != NULL)
    {
        R = R->data.giatien > p->data.giatien ? p : R;
        p = p->Next;
    }
    return R;
}
ThueNode *divideNode(DanhSachThueXe &Thue, ThueNode *min)
{
    if (Thue.Head == NULL)
        return NULL;
    ThueNode *p = Thue.Head;
    while (p != NULL && p->Next != min)
        p = p->Next;
    if (min == Thue.Head)
    {
        Thue.Head = Thue.Head->Next;
        min->Next = NULL;
    }
    else if (min == Thue.Tail)
    {
        Thue.Tail = p;
        p->Next = NULL;
    }
    else
    {
        p->Next = min->Next;
        min->Next = NULL;
    }
    return min;
}
DanhSachThueXe Sort(DanhSachThueXe &Thue, int choice)
{
    DanhSachThueXe R;
    init(R);
    ThueNode *p = Thue.Head;
    if (p == NULL)
        return Thue;
    while (p != NULL)
    {
        p = Thue.Head;
        ThueNode *q = Thue.Head;
        while (q != NULL)
        {
            ThueNode *min = FindMinThue(Thue);
            if (q == min)
            {
                ThueNode *Result = divideNode(Thue, min);
                if (choice == 1)
                    insert(R, Result);
                else
                {
                    if (R.Head == NULL)
                        R.Head = R.Tail = Result;
                    else
                    {
                        Result->Next = R.Head;
                        R.Head = Result;
                    }
                    R.size++;
                }
                break;
            }
            q = q->Next;
        }
    }
    return R;
}
// Ham Cap Nhat
void capNhatKhachHang(DanhSachKhachHang &dsKH, DanhSachThueXe &Thue, const char *maSo)
{
    CustomerNode *current = dsKH.Head;
    ThueNode *p = Thue.Head;
    while (current != nullptr)
    {
        if (strcmp(current->data.maso, maSo) == 0)
        { // tìm thấy khách hàng cần cập nhật
            // Chọn mục muốn cập nhật
            int temp = 0;
            bool del = false;
            bool del1 = false;
            bool ktthuexe = false;
            while (p != NULL)
            {
                ThueNode *q = p->Next;
                if (p->data.khachhang == current)
                {
                    del1 = false;
                    ktthuexe = true;
                    textcolor(12);
                    cout << "\t\tKhach da thue xe " << p->data.xe->data.sign << ".\n";
                    textcolor(7);
                    printf("\t\tBan muon huy Thue Xe khong!\n");
                    cout << "\tYes - 1 / No - 0: ";
                    scanf_s("%d", &temp);
                    fflush(stdin);
                    if (temp == 1)
                    {
                        del1 = true;
                    }
                    while (temp != 0 && temp != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        scanf_s("%d", &temp);
                        fflush(stdin);
                        if (temp == 1)
                        {
                            del1 = true;
                        }
                    }
                    if (del1 == true)
                        delete_1(Thue, p);
                }
                p = q;
            }
            p = Thue.Head;
            ktthuexe = false;
            del1 = false;
            while (p != NULL)
            {
                if (p->data.khachhang == current)
                {
                    ktthuexe = true;
                    del1 = false;
                    break;
                }
                p = p->Next;
            }
            bool hoTen = false;
            bool ngaySinh = false;
            bool soDienThoai = false;
            bool soCanCuoc = false;
            for (int i = 0; i < 5; i++)
            {
                if (i == 0)
                {
                    printf("\t\tBan muon xoa Khach Hang khong!\n");
                    cout << "\tYes - 1 / No - 0: ";
                    scanf_s("%d", &temp);
                    fflush(stdin);
                    if (temp == 1)
                    {
                        del = true;
                    }
                    while (temp != 0 && temp != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        scanf_s("%d", &temp);
                        fflush(stdin);
                        if (temp == 1)
                        {
                            del = true;
                        }
                    }
                    if (del == true)
                        break;
                }
                if (i == 1)
                {
                    printf("\t\tBan muon chinh sua Ho ten khong!\n");
                    cout << "\tYes - 1 / No - 0: ";
                    scanf_s("%d", &temp);
                    fflush(stdin);
                    if (temp == 1)
                    {
                        hoTen = true;
                    }
                    while (temp != 0 && temp != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        scanf_s("%d", &temp);
                        fflush(stdin);
                        if (temp == 1)
                        {
                            hoTen = true;
                        }
                    }
                }
                if (i == 2)
                {
                    printf("\t\tBan muon chinh sua Ngay sinh khong!\n");
                    cout << "\tYes - 1 / No - 0: ";
                    scanf_s("%d", &temp);
                    fflush(stdin);
                    if (temp == 1)
                    {
                        ngaySinh = true;
                    }
                    while (temp != 0 && temp != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        scanf_s("%d", &temp);
                        fflush(stdin);
                        if (temp == 1)
                        {
                            ngaySinh = true;
                        }
                    }
                }
                if (i == 3)
                {
                    printf("\t\tBan muon chinh sua So dien thoai khong!\n");
                    cout << "\tYes - 1 / No - 0: ";
                    scanf_s("%d", &temp);
                    fflush(stdin);
                    if (temp == 1)
                    {
                        soDienThoai = true;
                    }
                    while (temp != 0 && temp != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        scanf_s("%d", &temp);
                        fflush(stdin);
                        if (temp == 1)
                        {
                            soDienThoai = true;
                        }
                    }
                }
                if (i == 4)
                {
                    printf("\t\tBan muon chinh sua So can cuoc khong!\n");
                    cout << "\tYes - 1 / No - 0: ";
                    scanf_s("%d", &temp);
                    fflush(stdin);
                    if (temp == 1)
                    {
                        soCanCuoc = true;
                    }
                    while (temp != 0 && temp != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        scanf_s("%d", &temp);
                        fflush(stdin);
                        if (temp == 1)
                        {
                            soCanCuoc = true;
                        }
                    }
                }
            }

            textcolor(12);
            if (hoTen == 1 || ngaySinh == 1 || soDienThoai == 1 || soCanCuoc == 1)
            // cập nhật thông tin khách hàng
            {
                system("cls");
                printf("\t\tSua thong tin cho khach hang %s:\n", current->data.maso);
            }
            textcolor(7);
            if (del == true)
            {
                if (del1 == false && ktthuexe == true)
                {
                    bool del2 = false;
                    textcolor(12);
                    cout << "\t\tKhach da thue xe !!\n";
                    cout << "\t\tKhi xoa Khach Hang nay thi se xoa thong tin Thue Xe cua no !!\n";
                    textcolor(7);
                    cout << "\tYes - 1 / No - 0: ";
                    scanf_s("%d", &temp);
                    fflush(stdin);
                    if (temp == 1)
                    {
                        del2 = true;
                    }
                    while (temp != 0 && temp != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        scanf_s("%d", &temp);
                        fflush(stdin);
                        if (temp == 1)
                        {
                            del2 = true;
                        }
                    }
                    if (del2 == true)
                    {
                        p = Thue.Head;
                        while (p != NULL)
                        {
                            ThueNode *q = p->Next;
                            if (p->data.khachhang == current)
                                delete_1(Thue, p);
                            p = q;
                        }
                        delete_1(dsKH, current);
                    }
                }
                else if (ktthuexe == false)
                    delete_1(dsKH, current);
            }
            if (hoTen == true)
            {
                printf("\t\tNhap ho ten: ");
                char hoVaTen[100];
                cin.ignore();
                gets(hoVaTen);
                fflush(stdin);
                while (strlen(hoVaTen) == 0)
                {
                    cout << "\tTen khong hop le\n";
                    printf("\t\tNhap ho va ten: ");
                    gets(hoVaTen);
                    fflush(stdin);
                }
                ktTenhople(hoVaTen);
                tachTen(hoVaTen, current->data.ten.holot, current->data.ten.ten);
            }
            if (ngaySinh == true)
            {
                printf("\t\tNhap ngay sinh DD MM YYYY: ");
                scanf_s("%d", &current->data.ngaysinh.day);
                scanf_s("%d", &current->data.ngaysinh.month);
                scanf_s("%d", &current->data.ngaysinh.year);
                fflush(stdin);
                while (Checkdate(current->data.ngaysinh) != 1)
                {
                    cout << "\tNgay sinh khong hop le\n";
                    printf("\t\tNhap ngay sinh DD MM YYYY: ");
                    scanf_s("%d", &current->data.ngaysinh.day);
                    scanf_s("%d", &current->data.ngaysinh.month);
                    scanf_s("%d", &current->data.ngaysinh.year);
                    fflush(stdin);
                }
            }
            if (soDienThoai == true)
            {
                char sdt[11];
                cin.ignore();
                printf("\t\tNhap SDT (10 chu so): ");
                gets(sdt);
                fflush(stdin);
                while (strlen(sdt) != 10 || CheckSdtKH(dsKH, sdt) == 0)
                {
                    if (strlen(sdt) != 10)
                        cout << "\tSDT khong hop le\n";
                    if (CheckSdtKH(dsKH, sdt) == false && strlen(sdt) == 10)
                        cout << "\tSDT da ton tai hoac chua ky tu khong hop le\n";
                    printf("\t\tNhap SDT (10 chu so): ");
                    gets(sdt);
                    fflush(stdin);
                }
                strcpy(current->data.sdt, sdt);
            }
            if (soCanCuoc == true)
            {
                char cccd[13];
                printf("\t\tNhap CCCD (12 chu so): ");
                gets(cccd);
                fflush(stdin);
                while (strlen(cccd) != 12 || CheckCCCDKH(dsKH, cccd) != 1)
                {
                    if (strlen(cccd) != 12)
                        cout << "\tCCCD khong hop le\n";
                    if (CheckCCCDKH(dsKH, cccd) != 1 && strlen(cccd) == 12)
                        cout << "\tCCCD da ton tai hay chua ky tu khong hop le\n";
                    printf("\t\tNhap CCCD (12 chu so): ");
                    gets(cccd);
                    fflush(stdin);
                }
                strcpy(current->data.cccd, cccd);
            }
            textcolor(12);
            printf("Cap nhat thong tin khach hang thanh cong.\n");
            textcolor(7);
            return;
        }
        current = current->Next;
    }
    // không tìm thấy khách hàng có mã số cần cập nhật
    textcolor(12);
    printf("Khong tim thay khach hang co ma so %s.\n", maSo);
    textcolor(7);
}
void capNhatXe(DanhSachXe &dsXe, const char *sign, DanhSachThueXe &Thue)
{
    CarNode *current = dsXe.Head;
    ThueNode *p = Thue.Head;
    while (current != nullptr)
    {
        if (strcmp(current->data.sign, sign) == 0)
        { // tìm thấy xe cần cập nhật
            // Chọn mục muốn cập nhật
            int temp = 0;
            bool ktthuexe = false;
            bool del1 = false;
            while (p != NULL)
            {
                if (p->data.xe == current)
                {
                    ktthuexe = true;
                    textcolor(12);
                    cout << "\t\tXe da duoc thue boi " << p->data.khachhang->data.maso << ".\n";
                    textcolor(7);
                    printf("\t\tBan muon huy Thue Xe khong!\n");
                    cout << "\tYes - 1 / No - 0: ";
                    scanf_s("%d", &temp);
                    fflush(stdin);
                    if (temp == 1)
                    {
                        del1 = true;
                    }
                    while (temp != 0 && temp != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        scanf_s("%d", &temp);
                        fflush(stdin);
                        if (temp == 1)
                        {
                            del1 = true;
                        }
                    }
                    if (del1 == true)
                        delete_1(Thue, p);
                    break;
                }
                p = p->Next;
            }
            bool del = false;
            bool tenXe = false;
            bool ngayDangKiem = false;
            bool giaThue = false;
            for (int i = 0; i < 5; i++)
            {

                if (i == 0)
                {
                    printf("\t\tBan muon xoa Xe khong!\n");
                    cout << "\tYes - 1 / No - 0: ";
                    scanf_s("%d", &temp);
                    fflush(stdin);
                    if (temp == 1)
                    {
                        del = true;
                    }
                    while (temp != 0 && temp != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        scanf_s("%d", &temp);
                        fflush(stdin);
                        if (temp == 1)
                        {
                            del = true;
                        }
                    }
                    if (del == true)
                        break;
                }
                if (i == 1)
                {
                    printf("\t\tBan muon chinh sua Ten xe khong!\n");
                    cout << "\tYes - 1 / No - 0: ";
                    scanf_s("%d", &temp);
                    fflush(stdin);
                    if (temp == 1)
                    {
                        tenXe = true;
                    }
                    while (temp != 0 && temp != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        scanf_s("%d", &temp);
                        fflush(stdin);
                        if (temp == 1)
                        {
                            tenXe = true;
                        }
                    }
                }
                if (i == 2)
                {
                    printf("\t\tBan muon chinh sua Ngay dang kiem khong!\n");
                    cout << "\tYes - 1 / No - 0: ";
                    scanf_s("%d", &temp);
                    fflush(stdin);
                    if (temp == 1)
                    {
                        ngayDangKiem = true;
                    }
                    while (temp != 0 && temp != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        scanf_s("%d", &temp);
                        fflush(stdin);
                        if (temp == 1)
                        {
                            ngayDangKiem = true;
                        }
                    }
                }
                if (i == 3)
                {
                    printf("\t\tBan muon chinh sua Gia thue khong!\n");
                    cout << "\tYes - 1 / No - 0: ";
                    scanf_s("%d", &temp);
                    fflush(stdin);
                    if (temp == 1)
                    {
                        giaThue = true;
                    }
                    while (temp != 0 && temp != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        scanf_s("%d", &temp);
                        fflush(stdin);
                        if (temp == 1)
                        {
                            giaThue = true;
                        }
                    }
                }
            }

            textcolor(12);
            if (tenXe == 1 || ngayDangKiem == 1 || giaThue == 1)
            // cập nhật thông tin xe
            {
                system("cls");
                printf("\t\tSua thong tin cho xe co bien so %s:\n", current->data.sign);
            }
            textcolor(7);
            if (del == true)
            {
                if (del1 == false && ktthuexe == true)
                {
                    bool del2 = false;
                    textcolor(12);
                    cout << "\t\tXe da co nguoi thue !!\n";
                    cout << "\t\tKhi xoa Xe nay thi se xoa thong tin Thue Xe cua no !!\n";
                    textcolor(7);
                    cout << "\tYes - 1 / No - 0: ";
                    scanf_s("%d", &temp);
                    fflush(stdin);
                    if (temp == 1)
                    {
                        del2 = true;
                    }
                    while (temp != 0 && temp != 1)
                    {
                        cout << "\tYes - 1 / No - 0: ";
                        scanf_s("%d", &temp);
                        fflush(stdin);
                        if (temp == 1)
                        {
                            del2 = true;
                        }
                    }
                    if (del2 == true)
                    {
                        delete_1(Thue, p);
                        delete_1(dsXe, current);
                    }
                }
                else
                    delete_1(dsXe, current);
            }
            if (tenXe == true)
            {
                cin.ignore();
                printf("\t\tNhap ten xe: ");
                gets(current->data.namecar);
                fflush(stdin);
                ktTenhople(current->data.namecar);
                while (strlen(current->data.namecar) == 0)
                {
                    if (strlen(current->data.namecar) == 0)
                        cout << "\tTen xe khong hop le\n";
                    printf("\t\tNhap ten xe: ");
                    gets(current->data.namecar);
                    fflush(stdin);
                    ktTenhople(current->data.namecar);
                }
            }
            if (ngayDangKiem == true)
            {
                printf("\t\tNhap ngay dang kiem DD MM YYYY: ");
                scanf_s("%d", &current->data.ngay.day);
                scanf_s("%d", &current->data.ngay.month);
                scanf_s("%d", &current->data.ngay.year);
                fflush(stdin);
                while (Checkdate(current->data.ngay) != 1)
                {
                    cout << "\tNgay dang kiem khong hop le\n";
                    printf("\t\tNhap ngay dang kiem xe DD MM YYYY: ");
                    scanf_s("%d", &current->data.ngay.day);
                    scanf_s("%d", &current->data.ngay.month);
                    scanf_s("%d", &current->data.ngay.year);
                    fflush(stdin);
                }
            }
            if (giaThue == true)
            {
                printf("\t\tNhap gia thue: ");
                scanf_s("%d", &current->data.price);
                while (current->data.price <= 0)
                {
                    cout << "\tGia thue khong hop le\n";
                    printf("\t\tNhap gia thue: ");
                    scanf_s("%d", &current->data.price);
                }
                if (ktthuexe == true)
                    p->data.giatien = p->data.songaythue * p->data.xe->data.price;
            }
            textcolor(12);
            printf("Cap nhat thong tin xe thanh cong.\n");
            textcolor(7);
            return;
        }
        current = current->Next;
    }
    // không tìm thấy xe có biển số cần cập nhật
    textcolor(12);
    printf("Khong tim thay xe co bien so %s.\n", sign);
    textcolor(7);
}