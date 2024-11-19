#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Ð?nh ngh?a class Diem
class Diem {
private:
    float diemToan;
    float diemLy;
    float diemHoa;

public:
    Diem() : diemToan(0.0), diemLy(0.0), diemHoa(0.0) {}

    Diem(float toan, float ly, float hoa)
        : diemToan(toan), diemLy(ly), diemHoa(hoa) {}

    float tinhDiemTrungBinh() const {
        return (diemToan + diemLy + diemHoa) / 3;
    }

    void hienThiDiem() const {
        cout << "Toan: " << diemToan << ", Ly: " << diemLy << ", Hoa: " << diemHoa;
        cout << ", Diem trung binh: " << tinhDiemTrungBinh() << endl;
    }

    void nhapDiem() {
        cout << "Nhap diem Toan: "; cin >> diemToan;
        cout << "Nhap diem Ly: "; cin >> diemLy;
        cout << "Nhap diem Hoa: "; cin >> diemHoa;
    }
};

// Ð?nh ngh?a class HocSinh
class HocSinh {
private:
    string hoTen;
    int tuoi;
    string maHocSinh;
    string queQuan;
    Diem diem;

public:
    HocSinh() : hoTen(""), tuoi(0), maHocSinh(""), queQuan("") {}

    void nhapThongTin() {
        cout << "Nhap ho ten: "; getline(cin >> ws, hoTen);
        cout << "Nhap tuoi: "; cin >> tuoi;
        cout << "Nhap ma hoc sinh: "; cin >> maHocSinh;
        cout << "Nhap que quan: "; getline(cin >> ws, queQuan);
        diem.nhapDiem();
    }

    void hienThiThongTin() const {
        cout << "Ma HS: " << maHocSinh << " - Ho ten: " << hoTen
             << " - Tuoi: " << tuoi << " - Que quan: " << queQuan << endl;
        diem.hienThiDiem();
    }

    string getMaHocSinh() const { return maHocSinh; }
    string getHoTen() const { return hoTen; }
    float getDiemTrungBinh() const { return diem.tinhDiemTrungBinh(); }
};

// Ð?nh ngh?a class QuanLyHocSinh
class QuanLyHocSinh {
private:
    vector<HocSinh> danhSachHS;
		
public:
    void hienThiMenu() {
    cout << "\n===== MENU QUAN LY HOC SINH =====\n";
    cout << "1. Them hoc sinh\n";
    cout << "2. Hien thi danh sach hoc sinh\n";
    cout << "3. Tim kiem hoc sinh theo ma sinh vien\n";
    cout << "4. Tim kiem hoc sinh theo ten\n";
    cout << "5. Sap xep danh sach hoc sinh theo ten\n";
    cout << "6. Sap xep danh sach hoc sinh theo diem trung binh (tu cao den thap)\n";
    cout << "7. Phan loai hoc sinh theo hoc luc (Gioi, Kha, Trung binh - Yeu)\n";
    cout << "8. Tim hoc sinh co diem trung binh cao nhat\n";  // Thêm vào ðây
    cout << "0. Thoat\n";
    cout << "Chon chuc nang: ";
	}


    void themHocSinh() {
        HocSinh hs;
        cout << "Nhap thong tin hoc sinh moi:\n";
        hs.nhapThongTin();
        danhSachHS.push_back(hs);
        cout << "Da them hoc sinh thanh cong!\n";
    }

    void hienThiDanhSachHocSinh() const {
        if (danhSachHS.empty()) {
            cout << "Danh sach hoc sinh trong!\n";
        } else {
            cout << "Danh sach hoc sinh:\n";
            for (const auto& hs : danhSachHS) {
                hs.hienThiThongTin();
                cout << "----------------------\n";
            }
        }
    }

    void timKiemHocSinhTheoMa() const {
        string maHS;
        cout << "Nhap ma hoc sinh can tim: ";
        cin >> maHS;
        bool found = false;
        for (const auto& hs : danhSachHS) {
            if (hs.getMaHocSinh() == maHS) {
                hs.hienThiThongTin();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Khong tim thay hoc sinh voi ma: " << maHS << endl;
        }
    }

    void timKiemHocSinhTheoTen() const {
        string ten;
        cout << "Nhap ten hoc sinh can tim: ";
        getline(cin >> ws, ten);
        bool found = false;
        for (const auto& hs : danhSachHS) {
            if (hs.getHoTen() == ten) {
                hs.hienThiThongTin();
                found = true;
            }
        }
        if (!found) {
            cout << "Khong tim thay hoc sinh voi ten: " << ten << endl;
        }
    }

    void sapXepTheoTen() {
        sort(danhSachHS.begin(), danhSachHS.end(), [](const HocSinh& a, const HocSinh& b) {
            return a.getHoTen() < b.getHoTen();
        });
        cout << "Danh sach sau khi sap xep theo ten:\n";
        hienThiDanhSachHocSinh();
    }

    void sapXepTheoDiemTrungBinh() {
        sort(danhSachHS.begin(), danhSachHS.end(), [](const HocSinh& a, const HocSinh& b) {
            return a.getDiemTrungBinh() > b.getDiemTrungBinh();
        });
        cout << "Danh sach sau khi sap xep theo diem trung binh (tu cao den thap):\n";
        hienThiDanhSachHocSinh();
    }

    void phanLoaiHocSinh() const {
        cout << "\nHoc sinh gioi:\n";
        for (const auto& hs : danhSachHS) {
            if (hs.getDiemTrungBinh() >= 8.0) {
                hs.hienThiThongTin();
                cout << "----------------------\n";
            }
        }

        cout << "\nHoc sinh kha:\n";
        for (const auto& hs : danhSachHS) {
            if (hs.getDiemTrungBinh() >= 6.5 && hs.getDiemTrungBinh() < 8.0) {
                hs.hienThiThongTin();
                cout << "----------------------\n";
            }
        }

        cout << "\nHoc sinh trung binh - yeu:\n";
        for (const auto& hs : danhSachHS) {
            if (hs.getDiemTrungBinh() < 6.5) {
                hs.hienThiThongTin();
                cout << "----------------------\n";
            }
        }
    }
    
    void timHocSinhDiemCaoNhat() const {
    if (danhSachHS.empty()) {
        cout << "Danh sach hoc sinh trong!\n";
        return;
    }

    float diemCaoNhat = danhSachHS[0].getDiemTrungBinh();
    for (const auto& hs : danhSachHS) {
        if (hs.getDiemTrungBinh() > diemCaoNhat) {
            diemCaoNhat = hs.getDiemTrungBinh();
        }
    }

    cout << "\nHoc sinh co diem trung binh cao nhat (Diem = " << diemCaoNhat << "):\n";
    bool found = false;
    for (const auto& hs : danhSachHS) {
        if (hs.getDiemTrungBinh() == diemCaoNhat) {
            hs.hienThiThongTin();
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay hoc sinh co diem trung binh cao nhat.\n";
    }
}

};

// Hàm main ð? ði?u khi?n menu
int main() {
    QuanLyHocSinh quanLy;
    int luaChon;

    do {
        quanLy.hienThiMenu();
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                quanLy.themHocSinh();
                break;
            case 2:
                quanLy.hienThiDanhSachHocSinh();
                break;
            case 3:
                quanLy.timKiemHocSinhTheoMa();
                break;
            case 4:
                quanLy.timKiemHocSinhTheoTen();
                break;
            case 5:
                quanLy.sapXepTheoTen();
                break;
            case 6:
                quanLy.sapXepTheoDiemTrungBinh();
                break;
            case 7:
                quanLy.phanLoaiHocSinh();
                break;
            case 8:
                quanLy.timHocSinhDiemCaoNhat();  // Thêm trý?ng h?p này
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (luaChon != 0);

    return 0;
}

