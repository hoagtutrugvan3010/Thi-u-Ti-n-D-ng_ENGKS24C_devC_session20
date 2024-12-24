#include <stdio.h>
#include <string.h>

#define MAX_SACH 100

// Dinh nghia cau truc sach
typedef struct {
    int maSach;
    char tenSach[100];
    char tacGia[100];
    float giaTien;
    char theLoai[50];
} Sach;

Sach dsSach[MAX_SACH];
int soLuongSach = 0;

// Ham nhap thong tin sach
void nhapThongTinSach() {
    printf("Nhap so luong sach: ");
    scanf("%d", &soLuongSach);
    getchar();  // Doc ky tu du thua

    for (int i = 0; i < soLuongSach; i++) {
        printf("\nNhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%d", &dsSach[i].maSach);
        getchar(); // Doc ky tu du thua
        printf("Ten sach: ");
        fgets(dsSach[i].tenSach, sizeof(dsSach[i].tenSach), stdin);
        dsSach[i].tenSach[strcspn(dsSach[i].tenSach, "\n")] = '\0'; // Xoa ky tu newline
        printf("Tac gia: ");
        fgets(dsSach[i].tacGia, sizeof(dsSach[i].tacGia), stdin);
        dsSach[i].tacGia[strcspn(dsSach[i].tacGia, "\n")] = '\0'; // Xoa ky tu newline
        printf("Gia tien: ");
        scanf("%f", &dsSach[i].giaTien);
        getchar(); // Doc ky tu du thua
        printf("The loai: ");
        fgets(dsSach[i].theLoai, sizeof(dsSach[i].theLoai), stdin);
        dsSach[i].theLoai[strcspn(dsSach[i].theLoai, "\n")] = '\0'; // Xoa ky tu newline
    }
}

// Ham hien thi thong tin sach
void hienThiThongTinSach() {
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < soLuongSach; i++) {
        printf("Ma sach: %d\n", dsSach[i].maSach);
        printf("Ten sach: %s\n", dsSach[i].tenSach);
        printf("Tac gia: %s\n", dsSach[i].tacGia);
        printf("Gia tien: %.2f\n", dsSach[i].giaTien);
        printf("The loai: %s\n\n", dsSach[i].theLoai);
    }
}

// Ham them sach vao vi tri
void themSachVaoViTri() {
    int viTri;
    if (soLuongSach < MAX_SACH) {
        printf("Nhap vi tri muon them sach: ");
        scanf("%d", &viTri);
        if (viTri < 0 || viTri > soLuongSach) {
            printf("Vi tri khong hop le.\n");
            return;
        }

        for (int i = soLuongSach; i > viTri; i--) {
            dsSach[i] = dsSach[i - 1];
        }

        printf("\nNhap thong tin sach moi:\n");
        printf("Ma sach: ");
        scanf("%d", &dsSach[viTri].maSach);
        getchar();
        printf("Ten sach: ");
        fgets(dsSach[viTri].tenSach, sizeof(dsSach[viTri].tenSach), stdin);
        dsSach[viTri].tenSach[strcspn(dsSach[viTri].tenSach, "\n")] = '\0';
        printf("Tac gia: ");
        fgets(dsSach[viTri].tacGia, sizeof(dsSach[viTri].tacGia), stdin);
        dsSach[viTri].tacGia[strcspn(dsSach[viTri].tacGia, "\n")] = '\0';
        printf("Gia tien: ");
        scanf("%f", &dsSach[viTri].giaTien);
        getchar();
        printf("The loai: ");
        fgets(dsSach[viTri].theLoai, sizeof(dsSach[viTri].theLoai), stdin);
        dsSach[viTri].theLoai[strcspn(dsSach[viTri].theLoai, "\n")] = '\0';

        soLuongSach++;
    } else {
        printf("Danh sach sach da day.\n");
    }
}

// Ham xoa sach theo ma sach
void xoaSachTheoMa() {
    int maSach;
    printf("Nhap ma sach can xoa: ");
    scanf("%d", &maSach);

    for (int i = 0; i < soLuongSach; i++) {
        if (dsSach[i].maSach == maSach) {
            for (int j = i; j < soLuongSach - 1; j++) {
                dsSach[j] = dsSach[j + 1];
            }
            soLuongSach--;
            printf("Sach da duoc xoa.\n");
            return;
        }
    }

    printf("Khong tim thay sach voi ma sach %d.\n", maSach);
}

// Ham cap nhat thong tin sach theo ma sach
void capNhatSachTheoMa() {
    int maSach;
    printf("Nhap ma sach can cap nhat: ");
    scanf("%d", &maSach);

    for (int i = 0; i < soLuongSach; i++) {
        if (dsSach[i].maSach == maSach) {
            printf("\nNhap thong tin moi cho sach ma %d:\n", maSach);
            printf("Ten sach: ");
            getchar(); // Doc ky tu du thua
            fgets(dsSach[i].tenSach, sizeof(dsSach[i].tenSach), stdin);
            dsSach[i].tenSach[strcspn(dsSach[i].tenSach, "\n")] = '\0';
            printf("Tac gia: ");
            fgets(dsSach[i].tacGia, sizeof(dsSach[i].tacGia), stdin);
            dsSach[i].tacGia[strcspn(dsSach[i].tacGia, "\n")] = '\0';
            printf("Gia tien: ");
            scanf("%f", &dsSach[i].giaTien);
            getchar();
            printf("The loai: ");
            fgets(dsSach[i].theLoai, sizeof(dsSach[i].theLoai), stdin);
            dsSach[i].theLoai[strcspn(dsSach[i].theLoai, "\n")] = '\0';

            printf("Cap nhat thanh cong.\n");
            return;
        }
    }

    printf("Khong tim thay sach voi ma sach %d.\n", maSach);
}

// Ham sap xep sach theo gia tien (tang dan hoac giam dan)
void sapXepSachTheoGia(int tang) {
    for (int i = 0; i < soLuongSach - 1; i++) {
        for (int j = i + 1; j < soLuongSach; j++) {
            if ((tang && dsSach[i].giaTien > dsSach[j].giaTien) || (!tang && dsSach[i].giaTien < dsSach[j].giaTien)) {
                Sach temp = dsSach[i];
                dsSach[i] = dsSach[j];
                dsSach[j] = temp;
            }
        }
    }

    printf("Sap xep sach theo gia thanh cong.\n");
}

// Ham tim kiem sach theo ten
void timKiemSachTheoTen() {
    char tenSach[100];
    printf("Nhap ten sach can tim: ");
    getchar(); // Doc ky tu du thua
    fgets(tenSach, sizeof(tenSach), stdin);
    tenSach[strcspn(tenSach, "\n")] = '\0';

    printf("\nDanh sach sach tim duoc:\n");
    int found = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (strstr(dsSach[i].tenSach, tenSach) != NULL) {
            printf("Ma sach: %d\n", dsSach[i].maSach);
            printf("Ten sach: %s\n", dsSach[i].tenSach);
            printf("Tac gia: %s\n", dsSach[i].tacGia);
            printf("Gia tien: %.2f\n", dsSach[i].giaTien);
            printf("The loai: %s\n\n", dsSach[i].theLoai);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ten \"%s\".\n", tenSach);
    }
}

// Ham hien thi menu
void hienThiMenu() {
    printf("\nMENU\n");
    printf("1. Nhap so luong va thong tin sach\n");
    printf("2. Hien thi thong tin sach\n");
    printf("3. Them sach vao vi tri\n");
    printf("4. Xoa sach theo ma sach\n");
    printf("5. Cap nhat thong tin sach theo ma sach\n");
    printf("6. Sap xep sach theo gia (tang/giam)\n");
    printf("7. Tim kiem sach theo ten\n");
    printf("8. Thoat\n");
    printf("Lua chon cua ban: ");
}

// Ham dieu khien chuong trinh
int main() {
    int luaChon;
    do {
        hienThiMenu();
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapThongTinSach();
                break;
            case 2:
                hienThiThongTinSach();
                break;
            case 3:
                themSachVaoViTri();
                break;
            case 4:
                xoaSachTheoMa();
                break;
            case 5:
                capNhatSachTheoMa();
                break;
            case 6:
                printf("Chon: 1 - Tang dan, 0 - Giam dan: ");
                int tang;
                scanf("%d", &tang);
                sapXepSachTheoGia(tang);
                break;
            case 7:
                timKiemSachTheoTen();
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 8);

    return 0;
}

