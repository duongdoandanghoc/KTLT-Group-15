#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  // For Beep function

char movie[20];
float total = 100.0;  // Giá trị ví dụ cho hóa đơn
int discount = 10;
float payable = 90.0;
float free_gift = 5.0;

struct ticket {
    char name[20];
    char email_id[45];
    long int p_number;
};

// Hàm nhận thông tin chi tiết vé và lưu vào file
void Detail_reciver(struct ticket t, int a[], int n, FILE *det) {
    printf("\nVUI LONG DIEN DAY DU THONG TIN DUOI DAY");
    printf("\nHo va ten:\t");
    scanf("%s", t.name);
    printf("\nSo dien thoai:\t");
    scanf("%ld", &t.p_number);
    printf("\nEmail:\t");
    scanf("%s", t.email_id);
    fputs("So ghe da co: ", det);
    for (int i = 0; i < n; i++) {
        fprintf(det, "%d", a[i]);
        fputs(", ", det);
    }
    fputs("\n", det);

    fputs(t.name, det);
    fputs("\n", det);

    fputs(t.email_id, det);
    fputs("\n", det);

    fprintf(det, "%ld", t.p_number);
    fputs("\n", det);
    fputs("\n", det);

    fclose(det);
}

// Hàm quản lý chức năng của admin
void admin() {
    char admin_id[20], det[25];
    char admin_pass[10], time[10];
    int choice;
    FILE *movdet, *d1, *d2, *d3, *d4, *d5;
    char num[5], ch;
    L4: printf("Admin id:\t");
    scanf("%s", admin_id);
    printf("Admin password:\t");
    scanf("%s", admin_pass);
    if (strcmp(admin_id, "admin") == 0 && strcmp(admin_pass, "admin") == 0) {
        L8: printf("\n1]----->Thay doi ten va thoi gian phim");
        printf("\n2]----->Lay thong tin chi tiet chuong trinh");
        L5: printf("\nNhap lua chon : ");
        scanf("%d", &choice);
        if (choice == 1) {
            movdet = fopen("Movie_details.txt", "w+");
            for (int i = 0; i < 2; i++) {
                num[0] = (i + 1) + '0';
                printf("Nhap ten phim:\t");
                scanf("%s", movie);
                printf("Nhap thoi gian chieu:\t");
                scanf("%s", time);
                if (strlen(movie) > 0 && strlen(time) > 0) {
                    fputs(num, movdet);
                    fputs("] ", movdet);
                    fputs(movie, movdet);
                    fputs("\t", movdet);
                    fputs(time, movdet);
                    fputs("\n", movdet);
                }
            }
            printf("Luu thanh cong!!!\n\n");
            fclose(movdet);
        } else if (choice == 2) {
            movdet = fopen("Movie_details.txt", "a+");
            int i = 0;
            while (i < 5) {
                fgets(det, 100, movdet);
                printf("%s", det);
                i++;
            }
            fclose(movdet);
            L6: printf("\nNhap so phim cho chi tiet nguoi dung : ");
            scanf("%d", &choice);
            if (choice == 1) {
                d1 = fopen("tt1.txt", "r+");
                while ((ch = fgetc(d1)) != EOF)
                    printf("%c", ch);
                printf("\n\n\n");
                fclose(d1);

            } else if (choice == 2) {
                d2 = fopen("tt2.txt", "r+");
                while ((ch = fgetc(d2)) != EOF)
                    printf("%c", ch);
                printf("\n\n\n");
                fclose(d2);
            } else if (choice == 3) {
                d3 = fopen("tt3.txt", "r+");
                while ((ch = fgetc(d3)) != EOF)
                    printf("%c", ch);
                printf("\n\n\n");
                fclose(d3);
            } else if (choice == 4) {
                d4 = fopen("tt4.txt", "r+");
                while ((ch = fgetc(d4)) != EOF)
                    printf("%c", ch);
                printf("\n\n\n");
                fclose(d4);
            } else if (choice == 5) {
                d5 = fopen("tt5.txt", "r+");
                while ((ch = fgetc(d5)) != EOF)
                    printf("%c", ch);
                printf("\n\n\n");
                fclose(d5);
            } else {
                printf("\nDau vao nhap sai\n");
                goto L6;
            }
        } else {
            printf("Lua chon sai!!! Thu lai.");
            goto L5;
        }
    } else {
        printf("\nTai khoan hoac mat khau khong chinh xac!\n");
        goto L4;
    }
    printf("\n\n----->1] Tiep tuc voi admin\n----->An nut bat ki de thoat\n\n");
    scanf("%d", &choice);
    if (choice == 1)
        goto L8;
}

// Hàm hiển thị hóa đơn sau khi thanh toán
void viewReceipt(float sum, float tax, float total_amount) {
    char choice1[2];

    printf("\n\n\n\n\n\t\t\t\t\t\n");

    do {
        printf("\t        1. Xuat hoa don \n");
        printf("\t        2. Thoat \n");
        printf("\t        Your choice : ");
        scanf("%s", choice1);

        if (strcmp(choice1, "1") == 0) {
            printf("HOA DON\n");

            printf("\n\n\n\n\n\n\n\t\t           ====================\n");
            printf("\t\t           |      HOA DON     |\n");
            printf("\t\t           ====================\n");
            printf("\t      ___________________________________________________\n");
            printf("\t      |                                                 |\n");
            printf("\t                           HOA DON                      \n");
            printf("\t      |                   DQA CINEMA                    |\n");
            printf("\t                          GIO MO CUA:                  \n");
            printf("\t      |            MOI NGAY : 10 a.m. - 1 a.m.          |\n");
            printf("\t         _____________________________________________   \n");
            printf("\t      |                                                 |\n");
            printf("\t            Total Price.......................%.2fVND\n", sum);
            printf("\t      |                                                 |\n");
            printf("\t            TAX (10).........................%.0fVND\n", tax);
            printf("\t      |                                                 |\n");
            printf("\t            Payable After Discount............%.2fVND\n", payable);
            printf("\t      |                                                 |\n");
            printf("\t            Discount..........................%d %%\n", discount);
            printf("\t      |                                                 |\n");
            printf("\t            Final Total.......................%.2fVND\n", total_amount);
            printf("\t      |                                                 | \n");
            printf("\t         _____________________________________________    \n");
            printf("\t      |                                                 | \n");
            printf("\t                                                          \n");
            printf("\t      |                                                 | \n");
            printf("\t            Cam on ban da chon dich vu cua chung toi.           \n");
            printf("\t      |        Rat han hanh duoc phuc vu quy khach      | \n");
            printf("\t                      DQA CINEMA XIN CAM ON                 \n");
            printf("\t      |                                                 | \n");
            printf("\t                                                          \n");
            printf("\t      |_________________________________________________|\n");

        } else if (strcmp(choice1, "2") == 0) {
            // Thoát khỏi hàm
            return;
        } else {
            printf("\n\t        Loi dau vao.\n");
            Beep(300, 500);
            printf("\t        Vui long chon (1 hoac 2): \n\n");
        }
    } while (strcmp(choice1, "1") != 0 && strcmp(choice1, "2") != 0);
}

// Hàm xử lý thanh toán và hiển thị hóa đơn sau khi thanh toán thành công
void process_payment(float total_amount, float sum, float tax) {
    int payment_choice;
    printf("\nTong thanh toan: %.0f VND", total_amount);
    printf("\nChon phuong thuc thanh toan:");
    printf("\n1] QR code");
    printf("\n2] So tai khoan ngan hang");
    printf("\nLua chon: ");
    scanf("%d", &payment_choice);

    if (payment_choice == 1) {
        printf("\nVui long quet ma QR sau de thanh toan:\n");
        printf(" ________ \n");
        printf("|        |\n");
        printf("|  QR    |\n");
        printf("|  CODE  |\n");
        printf("|________|\n");
    } else if (payment_choice == 2) {
        printf("\nVui long chuyen khoan den so tai khoan sau:\n");
        printf("So tai khoan: 08322229936688\n");
        printf("Ten chu tai khoan: DOAN MINH DUONG\n");
        printf("Ngan hang: MB BANK\n");
    } else {
        printf("\nLua chon khong hop le!\n");
    }
    printf("\nCHUC BAN CO MOT NGAY TOT LANH!!!\n\n\n");
    Sleep(2000);
    system("cls");
    printf("\nCHUC MUNG BAN DA THANH TOAN THANH CONG\n");
    viewReceipt(sum, tax, total_amount);
}

// Hàm đặt vé và lưu thông tin vào file
void book(FILE *poi, FILE *ghe) {
    int a = 0, tick[80], no = 0, occupied;
    struct ticket t1;
    printf("\t\t\t\t\tMAN HINH\n\n");

    int occ[80] = {0}, i = 0;
    while ((occupied = getw(ghe)) != EOF) {
        occ[i] = occupied;
        i++;
    }
    for (int j = 0; j < 8; j++) {
        printf("\t");
        for (int k = 0; k < 10; k++) {
            int flag = 0;
            a++;
            for (int r = 0; r < 80; r++) {
                if (occ[r] == a) {
                    if (a < 10)
                        printf("0%d-H\t", a);
                    else
                        printf("%d-H\t", a);
                    flag = 0;
                    break;
                } else
                    flag = 1;
            }

            if (flag == 1) {
                if (a < 10)
                    printf("0%d-S\t", a);
                else
                    printf("%d-S\t", a);
            }
        }
        printf("\n");
    }
    printf("\nGia");
    printf("\nGhe [01 - 20]---> 60 000 VND--->Tiet kiem");
    printf("\nGhe [21 - 60]---> 80 000 VND--->Cao cap");
    printf("\nGhe [61 - 80]---> 100 000 VND--->Dac biet");
    L3: printf("\n\nNhap so luong ghe : ");
    scanf("%d", &no);
    Sleep(100);
    printf("----------");
    if (no > (80 - i)) {
        printf("\nCon nhieu ghe khong co san\n");
        goto L3;
    }
    printf("\nVui long chon vi tri ghe: ");
    for (int i = 0; i < no; i++) {
        L7: printf("\nGhe so:");
        scanf("%d", &tick[i]);
        if (tick[i] > 80) {
            printf("Loi dau vao. Thu lai");
            goto L7;
        } else {
            for (int k = 0; k < 80; k++) {
                if (occ[k] == tick[i]) {
                    printf("=((!! Ghe da duoc dat truoc. Vui long chon ghe khac");
                    goto L7;
                }
            }
        }
        for (int s = 0; s < i; s++) {
            if (tick[s] == tick[i]) {
                printf("\nDa nhap so ghe\n");
                goto L7;
            }
        }
        putw(tick[i], ghe);
    }
    fclose(ghe);
    a = 0;
    Detail_reciver(t1, tick, no, poi);
    float sum = 0, tax = 0;
    for (int i = 0; i < no; i++) {
        if (tick[i] > 0 && tick[i] <= 20)
            sum = sum + 60000;
        else if (tick[i] >= 21 && tick[i] <= 60)
            sum = sum + 80000;
        else
            sum = sum + 100000;
    }

    printf("\nChuc mung ban da dat ghe thanh cong:");
    printf("\nSo ghe da dat: %d", no);
    printf("\nCho ngoi da dat:");
    for (int r = 0; r < no; r++)
        printf("%d, ", tick[r]);
    printf("\nGia ve: %.0f VND", sum);
    tax = (sum * 10) / 100;
    printf("\nThue  : %.0f VND", tax);
    float total_amount = sum + tax;
    printf("\nTong thanh toan: %.0f VND", total_amount);
    
    process_payment(total_amount, sum, tax);

    fclose(poi);
}

// Hàm chính của chương trình
int main() {
    FILE *Md, *d1, *d2, *d3, *d4, *d5, *s1, *s2, *s3, *s4, *s5;
    int choice;
    int ch = 0;
    char det[25];
    printf("____________________________________________________________________\n");
    printf("____________________________________________________________________\n");
    printf("|            CHAO MUNG DEN VOI RAP CHIEU PHIM DQA                  |\n");
    printf("|                          DAT VE NGAY                             |\n");
    printf("____________________________________________________________________\n");
    printf("____________________________________________________________________\n");
    l1: printf("1]-----> Dat ve\n");
    printf("2]-----> Admin\n");
    printf("3]-----> Thoat\n");
    scanf("%d", &choice);
    Sleep(100);
    printf("----------");
    Sleep(1000);
    system("cls");

    if (choice == 1) {
        Md = fopen("Movie_details.txt", "a+");
        int i = 0;
        while (i < 5) {
            fgets(det, 100, Md);
            printf("%s", det);
            i++;
        }
        fclose(Md);
        L2: printf("\nNHAP PHIM BAN CHON\n");
        scanf("%d", &ch);
        Sleep(100);
        printf("----------");
        Sleep(1000);
        system("cls");

        if (ch == 1) {
            d1 = fopen("tt1.txt", "a+");
            s1 = fopen("ghe1.txt", "a+");
            book(d1, s1);
            fclose(d1);
            fclose(s1);
            goto l1;
        } else if (ch == 2) {
            d2 = fopen("tt2.txt", "a+");
            s2 = fopen("ghe2.txt", "a+");
            book(d2, s2);
            fclose(d2);
            fclose(s2);
            goto l1;
        } else if (ch == 3) {
            d3 = fopen("tt3.txt", "a+");
            s3 = fopen("ghe3.txt", "a+");
            book(d3, s3);
            fclose(d3);
            fclose(s3);
            goto l1;
        } else if (ch == 4) {
            d4 = fopen("tt4.txt", "a+");
            s4 = fopen("ghe4.txt", "a+");
            book(d4, s4);
            fclose(d4);
            fclose(s4);
            goto l1;
        } else if (ch == 5) {
            d5 = fopen("tt5.txt", "a+");
            s5 = fopen("ghe5.txt", "a+");
            book(d5, s5);
            fclose(d5);
            fclose(s5);
            goto l1;
        } else {
            printf("\nLua chon khong hop le. Thu lai");
            printf("\n");
            goto L2;
        }
    } else if (choice == 2) {
        admin();
        goto l1;
    } else if (choice == 3) {
        printf("\n\n\nCHUC BAN CO MOT NGAY TOT LANH!!!\n");
    } else {
        printf("Lua chon khong hop le. Vui long nhap lai\n");
        goto l1;
    }
}


// Detail_reciver: Chức năng nhận thông tin chi tiết về vé và lưu vào file.
// admin: Chức năng quản trị viên quản lý phim và truy xuất thông tin chi tiết chương trình.
// viewReceipt: Chức năng hiển thị biên lai sau khi thanh toán.
// process_ Payment: Chức năng xử lý thanh toán và gọi viewReceipt sau khi thanh toán thành công.
// book: Chức năng đặt vé và lưu thông tin vào file.
// main: Chức năng chính để hiển thị menu và xử lý các lựa chọn của người dùng.
