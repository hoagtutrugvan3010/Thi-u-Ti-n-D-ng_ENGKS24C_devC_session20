#include <stdio.h>
#include <string.h>

#define MAX_SANPHAM 100

// �?nh nghia c?u tr�c s?n ph?m
typedef struct {
    int maSanPham;
    char tenSanPham[100];
    float giaNhap;
    float giaBan;
    int soLuong;
} SanPham;

SanPham dsSanPham[MAX_SANPHAM];
int soLuongSanPham = 0;
float doanhThu = 0;

// H�m nh?p th�ng tin s?n ph?m
void nhapThongTinSanPham() {
    printf("Nhap so luong san pham: ");
    scanf("%d", &soLuongSanPham);
    getchar();  // �?c k� t? du th?a

    for (int i = 0; i < soLuongSanPham; i++) {
        printf("\nNhap thong tin san pham thu %d:\n", i + 1);
        printf("Ma san pham: ");
        scanf("%d", &dsSanPham[i].maSanPham);
        getchar(); // �?c k� t? du th?a
        printf("Ten san pham: ");
        fgets(dsSanPham[i].tenSanPham, sizeof(dsSanPham[i].tenSanPham), stdin);
        dsSanPham[i].tenSanPham[strcspn(dsSanPham[i].tenSanPham, "\n")] = '\0'; // X�a k� t? newline
        printf("Gia nhap: ");
        scanf("%f", &dsSanPham[i].giaNhap);
        printf("Gia ban: ");
        scanf("%f", &dsSanPham[i].giaBan);
        printf("So luong: ");
        scanf("%d", &dsSanPham[i].soLuong);
    }
}

// H�m hi?n th? danh s�ch s?n ph?m
void hienThiDanhSachSanPham() {
    printf("\nDanh sach san pham:\n");
    for (int i = 0; i < soLuongSanPham; i++) {
        printf("Ma san pham: %d\n", dsSanPham[i].maSanPham);
        printf("Ten san pham: %s\n", dsSanPham[i].tenSanPham);
        printf("Gia nhap: %.2f\n", dsSanPham[i].giaNhap);
        printf("Gia ban: %.2f\n", dsSanPham[i].giaBan);
        printf("So luong: %d\n\n", dsSanPham[i].soLuong);
    }
}

// H�m nh?p s?n ph?m (ki?m tra n?u s?n ph?m d� t?n t?i th� ch? tang s? lu?ng)
void nhapSanPham() {
    int maSanPham;
    printf("Nhap ma san pham can nhap: ");
    scanf("%d", &maSanPham);

    // T�m s?n ph?m trong danh s�ch
    for (int i = 0; i < soLuongSanPham; i++) {
        if (dsSanPham[i].maSanPham == maSanPham) {
            printf("San pham da ton tai, tong so luong hien tai: %d\n", dsSanPham[i].soLuong);
            printf("Nhap so luong can nhap them: ");
            int soLuongThem;
            scanf("%d", &soLuongThem);
            dsSanPham[i].soLuong += soLuongThem;
            doanhThu -= soLuongThem * dsSanPham[i].giaNhap;  // Gi?m doanh thu khi nh?p h�ng
            printf("Da nhap them %d san pham.\n", soLuongThem);
            return;
        }
    }

    // N?u s?n ph?m chua t?n t?i, th�m s?n ph?m m?i v�o m?ng
    if (soLuongSanPham < MAX_SANPHAM) {
        printf("San pham moi:\n");
        dsSanPham[soLuongSanPham].maSanPham = maSanPham;
        getchar(); // �?c k� t? du th?a
        printf("Ten san pham: ");
        fgets(dsSanPham[soLuongSanPham].tenSanPham, sizeof(dsSanPham[soLuongSanPham].tenSanPham), stdin);
        dsSanPham[soLuongSanPham].tenSanPham[strcspn(dsSanPham[soLuongSanPham].tenSanPham, "\n")] = '\0'; // X�a k� t? newline
        printf("Gia nhap: ");
        scanf("%f", &dsSanPham[soLuongSanPham].giaNhap);
        printf("Gia ban: ");
        scanf("%f", &dsSanPham[soLuongSanPham].giaBan);
        printf("So luong: ");
        scanf("%d", &dsSanPham[soLuongSanPham].soLuong);
        
        doanhThu -= dsSanPham[soLuongSanPham].soLuong * dsSanPham[soLuongSanPham].giaNhap; // Gi?m doanh thu khi nh?p h�ng
        soLuongSanPham++;
        printf("San pham moi da duoc them.\n");
    } else {
        printf("Danh sach san pham da day.\n");
    }
}

// H�m c?p nh?t th�ng tin s?n ph?m
void capNhatThongTinSanPham() {
    int maSanPham;
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%d", &maSanPham);

    for (int i = 0; i < soLuongSanPham; i++) {
        if (dsSanPham[i].maSanPham == maSanPham) {
            printf("Cap nhat thong tin san pham ma %d:\n", maSanPham);
            getchar(); // �?c k� t? du th?a
            printf("Ten san pham: ");
            fgets(dsSanPham[i].tenSanPham, sizeof(dsSanPham[i].tenSanPham), stdin);
            dsSanPham[i].tenSanPham[strcspn(dsSanPham[i].tenSanPham, "\n")] = '\0'; // X�a k� t? newline
            printf("Gia nhap: ");
            scanf("%f", &dsSanPham[i].giaNhap);
            printf("Gia ban: ");
            scanf("%f", &dsSanPham[i].giaBan);
            printf("So luong: ");
            scanf("%d", &dsSanPham[i].soLuong);
            return;
        }
    }

    printf("Khong tim thay san pham voi ma %d.\n", maSanPham);
}

// H�m s?p x?p s?n ph?m theo gi� (tang ho?c gi?m)
void sapXepSanPhamTheoGia(int tang) {
    for (int i = 0; i < soLuongSanPham - 1; i++) {
        for (int j = i + 1; j < soLuongSanPham; j++) {
            if ((tang && dsSanPham[i].giaBan > dsSanPham[j].giaBan) || 
                (!tang && dsSanPham[i].giaBan < dsSanPham[j].giaBan)) {
                SanPham temp = dsSanPham[i];
                dsSanPham[i] = dsSanPham[j];
                dsSanPham[j] = temp;
            }
        }
    }
    printf("Sap xep san pham theo gia thanh cong.\n");
}

// H�m t�m ki?m s?n ph?m
void timKiemSanPham() {
    char tenSanPham[100];
    printf("Nhap ten san pham can tim: ");
    getchar(); // �?c k� t? du th?a
    fgets(tenSanPham, sizeof(tenSanPham), stdin);
    tenSanPham[strcspn(tenSanPham, "\n")] = '\0';

    printf("\nDanh sach san pham tim duoc:\n");
    int found = 0;
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strstr(dsSanPham[i].tenSanPham, tenSanPham) != NULL) {
            printf("Ma san pham: %d\n", dsSanPham[i].maSanPham);
            printf("Ten san pham: %s\n", dsSanPham[i].tenSanPham);
            printf("Gia nhap: %.2f\n", dsSanPham[i].giaNhap);
            printf("Gia ban: %.2f\n", dsSanPham[i].giaBan);
            printf("So luong: %d\n\n", dsSanPham[i].soLuong);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay san pham voi ten \"%s\".\n", tenSanPham);
    }
}

// H�m b�n s?n ph?m
void banSanPham() {
    int maSanPham, soLuongBan;
    printf("Nhap ma san pham can ban: ");
    scanf("%d", &maSanPham);

    for (int i = 0; i < soLuongSanPham; i++) {
        if (dsSanPham[i].maSanPham == maSanPham) {
            printf("Nhap so luong can ban: ");
            scanf("%d", &soLuongBan);

            if (soLuongBan > dsSanPham[i].soLuong) {
                printf("Khong con du hang.\n");
            } else if (dsSanPham[i].soLuong == 0) {
                printf("San pham het hang.\n");
            } else {
                dsSanPham[i].soLuong -= soLuongBan;
                doanhThu += soLuongBan * dsSanPham[i].giaBan;
                printf("Ban %d san pham thanh cong.\n", soLuongBan);
                return;
            }
        }
    }

    printf("Khong tim thay san pham voi ma %d.\n", maSanPham);
}

// H�m hi?n th? doanh thu hi?n t?i
void hienThiDoanhThu() {
    printf("Doanh thu hien tai: %.2f\n", doanhThu);
}

// H�m hi?n th? menu
void hienThiMenu() {
    printf("\nMENU\n");
    printf("1. Nhap so luong va thong tin san pham\n");
    printf("2. Hien thi danh sach san pham\n");
    printf("3. Nhap san pham\n");
    printf("4. Cap nhat thong tin san pham\n");
    printf("5. Sap xep san pham theo gia (tang/giam)\n");
    printf("6. Tim kiem san pham\n");
    printf("7. Ban san pham\n");
    printf("8. Doanh thu hien tai\n");
    printf("9. Thoat\n");
    printf("Lua chon cua ban: ");
}

// H�m di?u khi?n chuong tr�nh
int main() {
    int luaChon;
    do {
        hienThiMenu();
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapThongTinSanPham();
                break;
            case 2:
                hienThiDanhSachSanPham();
                break;
            case 3:
                nhapSanPham();
                break;
            case 4:
                capNhatThongTinSanPham();
                break;
            case 5:
                printf("Chon 1 - Tang dan, 0 - Giam dan: ");
                int tang;
                scanf("%d", &tang);
                sapXepSanPhamTheoGia(tang);
                break;
            case 6:
                timKiemSanPham();
                break;
            case 7:
                banSanPham();
                break;
            case 8:
                hienThiDoanhThu();
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 9);

    return 0;
}

