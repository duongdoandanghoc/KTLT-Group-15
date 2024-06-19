#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

class Ticket {
public:
    char name[20];
    char email_id[45];
    long int p_number;
};

void Detail_reciver(Ticket &t, int a[], int n, ofstream &det) {
    cout << "\nVUI LONG DIEN DAY DU THONG TIN DUOI DAY";
    cout << "\nHo va ten:\t";
    cin >> t.name;
    cout << "\nSo dien thoai:\t";
    cin >> t.p_number;
    cout << "\nEmail:\t";
    cin >> t.email_id;

    det << "So ghe da co: ";
    for (int i = 0; i < n; i++) {
        det << a[i] << ", ";
    }
    det << "\n";

    det << t.name << "\n";
    det << t.email_id << "\n";
    det << t.p_number << "\n\n";
    det.close();
}

void admin() {
    char admin_id[20], det[25];
    char admin_pass[10], time[10];
    int choice;
    ofstream movdet;
    ifstream d1, d2, d3, d4, d5;
    string num;
    char ch;

    while (true) {
        cout << "Admin id:\t";
        cin >> admin_id;
        cout << "Admin password:\t";
        cin >> admin_pass;
        if (strcmp(admin_id, "admin") == 0 && strcmp(admin_pass, "admin") == 0) {
            while (true) {
                cout << "\n1]----->Thay doi ten va thoi gian phim";
                cout << "\n2]----->Lay thong tin chi tiet chuong trinh";
                cout << "\nNhap lua chon : ";
                cin >> choice;
                if (choice == 1) {
                    movdet.open("Movie_details.txt", ios::trunc);
                    for (int i = 0; i < 2; i++) {
                        num = to_string(i + 1);
                        char movie[100];
                        cout << "Nhap ten phim:\t";
                        cin >> movie;
                        cout << "Nhap thoi gian chieu:\t";
                        cin >> time;
                        if (strlen(movie) > 0 && strlen(time) > 0) {
                            movdet << num << "] " << movie << "\t" << time << "\n";
                        }
                    }
                    cout << "Luu thanh cong!!!\n\n";
                    movdet.close();
                } else if (choice == 2) {
                     ifstream movdet("Movie_details.txt"); // Change to ifstream for reading
                    int i = 0;
                    while (i < 5 && movdet.getline(det, 100)) {
                        cout << det << endl;
                        i++;
                    }
                    movdet.close();
                    cout << "\nNhap so phim cho chi tiet nguoi dung : ";
                    cin >> choice;
                    if (choice == 1) {
                        d1.open("tt1.txt");
                        while (d1.get(ch))
                            cout << ch;
                        cout << "\n\n\n";
                        d1.close();
                    } else if (choice == 2) {
                        d2.open("tt2.txt");
                        while (d2.get(ch))
                            cout << ch;
                        cout << "\n\n\n";
                        d2.close();
                    } else if (choice == 3) {
                        d3.open("tt3.txt");
                        while (d3.get(ch))
                            cout << ch;
                        cout << "\n\n\n";
                        d3.close();
                    } else if (choice == 4) {
                        d4.open("tt4.txt");
                        while (d4.get(ch))
                            cout << ch;
                        cout << "\n\n\n";
                        d4.close();
                    } else if (choice == 5) {
                        d5.open("tt5.txt");
                        while (d5.get(ch))
                            cout << ch;
                        cout << "\n\n\n";
                        d5.close();
                    } else {
                        cout << "\nDau vao nhap sai\n";
                    }
                } else {
                    cout << "Lua chon sai!!! Thu lai.";
                }
                cout << "\n\n----->1] Tiep tuc voi admin\n----->An nut bat ki de thoat\n\n";
                cin >> choice;
                if (choice != 1) break;
            }
        } else {
            cout << "\nTai khoan hoac mat khau khong chinh xac!\n";
        }
    }
}

void process_payment(float total_amount) {
    int payment_choice;
    cout << "\nTong thanh toan: " << total_amount << " VND";
    cout << "\nChon phuong thuc thanh toan:";
    cout << "\n1] QR code";
    cout << "\n2] So tai khoan ngan hang";
    cout << "\nLua chon: ";
    cin >> payment_choice;

    if (payment_choice == 1) {
        cout << "\nVui long quet ma QR sau de thanh toan:\n";
        cout << " ________ \n";
        cout << "|        |\n";
        cout << "|  QR    |\n";
        cout << "|  CODE  |\n";
        cout << "|________|\n";
    } else if (payment_choice == 2) {
        cout << "\nVui long chuyen khoan den so tai khoan sau:\n";
        cout << "So tai khoan: 08322229936688\n";
        cout << "Ten chu tai khoan: DOAN MINH DUONG\n";
        cout << "Ngan hang: MB BANK\n";
    } else {
        cout << "\nLua chon khong hop le!\n";
    }
    cout << "\nCHUC BAN CO MOT NGAY TOT LANH!!!\n\n\n";
}

void book(ofstream &poi, ofstream &ghe) {
    int a = 0, tick[80], no = 0, occupied;
    Ticket t1;
    cout << "\t\t\t\t\tMAN HINH\n\n";

    int occ[80] = {0}, i = 0;
    ifstream read_ghe("ghe1.txt", ios::in);
    while (read_ghe >> occupied) {
        occ[i] = occupied;
        i++;
    }
    read_ghe.close();

    for (int j = 0; j < 8; j++) {
        cout << "\t";
        for (int k = 0; k < 10; k++) {
            int flag = 0;
            a++;
            for (int r = 0; r < 80; r++) {
                if (occ[r] == a) {
                    if (a < 10)
                        cout << "0" << a << "-H\t";
                    else
                        cout << a << "-H\t";
                    flag = 0;
                    break;
                } else
                    flag = 1;
            }

            if (flag == 1) {
                if (a < 10)
                    cout << "0" << a << "-S\t";
                else
                    cout << a << "-S\t";
            }
        }
        cout << "\n";
    }
    cout << "\nGia";
    cout << "\nGhe [01 - 20]---> 60 000 VND--->Tiet kiem";
    cout << "\nGhe [21 - 60]---> 80 000 VND--->Cao cap";
    cout << "\nGhe [61 - 80]---> 100 000 VND--->Dac biet";

    while (true) {
        cout << "\n\nNhap so luong ghe : ";
        cin >> no;
        if (no > (80 - i)) {
            cout << "\nCon nhieu ghe khong co san\n";
        } else {
            break;
        }
    }

    cout << "\nVui long chon ghe: ";
    for (int i = 0; i < no; i++) {
        while (true) {
            cout << "\nGhe so:";
            cin >> tick[i];
            if (tick[i] > 80) {
                cout << "Oi hong!! Loi dau vao. Thu lai";
            } else {
                bool already_occupied = false;
                for (int k = 0; k < 80; k++) {
                    if (occ[k] == tick[i]) {
                        cout << "=((!! Ghe da duoc dat truoc. Vui long chon ghe khac";
                        already_occupied = true;
                        break;
                    }
                }
                if (already_occupied) continue;

                bool duplicate_entry = false;
                for (int s = 0; s < i; s++) {
                    if (tick[s] == tick[i]) {
                        cout << "\nDa nhap so ghe\n";
                        duplicate_entry = true;
                        break;
                    }
                }
                if (!duplicate_entry) break;
            }
        }
        ghe << tick[i] << " ";
    }
    ghe.close();

    Detail_reciver(t1, tick, no, poi);
    float sum = 0, tax = 0;
    for (int i = 0; i < no; i++) {
        if (tick[i] > 0 && tick[i] <= 20)
            sum += 60000;
        else if (tick[i] >= 21 && tick[i] <= 60)
            sum += 80000;
        else
            sum += 100000;
    }

    cout << "\nChuc mung ban da dat ghe thanh cong:";
    cout << "\nSo ghe da dat: " << no;
    cout << "\nCho ngoi da dat:";
    for (int r = 0; r < no; r++)
        cout << tick[r] << ", ";
    cout << "\nGia ve: " << sum << " VND";
    tax = (sum * 10) / 100;
    cout << "\nThue: " << tax << " VND";
    float total_amount = sum + tax;
    printf("\nTong thanh toan: %.0f VND", total_amount);
    process_payment(total_amount);

    poi.close();
}

int main() {
    ifstream Md;
    ofstream d1, d2, d3, d4, d5, s1, s2, s3, s4, s5;
    int choice;
    int ch = 0;
    char det[25];
    cout << "____________________________________________________________________\n";
    cout << "____________________________________________________________________\n";
    cout << "|            CHAO MUNG DEN VOI RAP CHIEU PHIM DQA                  |\n";
    cout << "|                          DAT VE NGAY                             |\n";
    cout << "____________________________________________________________________\n";
    cout << "____________________________________________________________________\n";

    while (true) {
        cout << "1]-----> Dat ve\n";
        cout << "2]-----> Admin\n";
        cout << "3]-----> Thoat\n";
        cin >> choice;

        if (choice == 1) {
            Md.open("Movie_details.txt");
            int i = 0;
            while (i < 5 && Md.getline(det, 100)) {
                cout << det << endl;
                i++;
            }
            Md.close();

            cout << "\nNHAP PHIM BAN CHON\n";
            cin >> ch;
            if (ch == 1) {
                d1.open("tt1.txt", ios::app);
                s1.open("ghe1.txt", ios::app);
                book(d1, s1);
            } else if (ch == 2) {
                d2.open("tt2.txt", ios::app);
                s2.open("ghe2.txt", ios::app);
                book(d2, s2);
            } else if (ch == 3) {
                d3.open("tt3.txt", ios::app);
                s3.open("ghe3.txt", ios::app);
                book(d3, s3);
            } else if (ch == 4) {
                d4.open("tt4.txt", ios::app);
                s4.open("ghe4.txt", ios::app);
                book(d4, s4);
            } else if (ch == 5) {
                d5.open("tt5.txt", ios::app);
                s5.open("ghe5.txt", ios::app);
                book(d5, s5);
            } else {
                cout << "\nLua chon khong hop le. Thu lai\n";
            }
        } else if (choice == 2) {
            admin();
        } else if (choice == 3) {
            cout << "\n\n\nCHUC BAN CO MOT NGAY TOT LANH!!!\n";
            break;
        } else {
            cout << "Lua chon khong hop le. Vui long nhap lai\n";
        }
    }
    return 0;
}
