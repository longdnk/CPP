//
// Created by longdnk on 1/21/2023.
//
#include <bits/stdc++.h>
#include <ostream>

using namespace std;

class ThietBi {
protected:
    string ten;
    string maso;
    int vitri;
    bool trangthai;
public:
    void chinhTrangThai(bool t) {
        this->trangthai = t;
    }
};

class Den : public ThietBi {
protected:
    int doSang;
};

class DenChieuSang : public Den {
};

class DenNgu : public Den {
protected:
    string mauSang;
    int doSang;
public:
    DenNgu(const string &mauSang, int doSang) : mauSang(mauSang), doSang(doSang) {}

    DenNgu() {}

    void chonMausang(string mau) {
        this->mauSang = mau;
    }

    void chonDoSang(int ds) {
        this->doSang = ds;
    }
};

class DieuHoa : public ThietBi {
protected:
    int nhietDo;
    int mucDo;
    string cheDo;
public:
    DieuHoa(int nhietDo, int mucDo, const string &cheDo) : nhietDo(nhietDo), mucDo(mucDo), cheDo(cheDo) {}

    DieuHoa() {}

    void chinhNhietDo(int nhiet) {
        this->nhietDo = nhiet;
    }

    void chinhCheDo(string c) {
        this->cheDo = c;
    }

    void chinhMucDo(int m) {
        this->mucDo = m;
    }
};

class TiVi : public ThietBi {
protected:
    int amLuong, kenh;
public:
    void chinhAmLuong(int amluong) {
        this->amLuong = amluong;
    }

    void chinhKeng(int k) {
        this->kenh = k;
    }
};

int32_t main() {
    ThietBi *TB[10];
    TB[0] = new DenNgu("Xanh La", 20);
    TB[1] = new DieuHoa(15, 20, "Lanh Nhu Bac Cuc");
    for (int i = 0; i < 2; ++i) {
        TB[i]->chinhTrangThai(true);
    }
}