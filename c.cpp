#include <bits/stdc++.h>

using namespace std;

struct Bigint {
    string a;
    int sign;

    Bigint() {

    }

    auto operator=(string b) -> void {
        a = (b[0] == '-' ? b.substr(1) : b);
        reverse(a.begin(), a.end());
        (*this).Remove0(b[0] == '-' ? -1 : 1);
    }

    Bigint(string x) {
        (*this) = x;
    }

    Bigint(int64_t x) {
        (*this) = to_string(x);
    }

    auto operator=(int64_t x) -> void {
        *this = to_string(x);
    }

    auto operator[](int i) -> char {
        return a[i];
    }

    auto size() -> int {
        return a.size();
    }

    auto inverseSign() -> Bigint {
        sign *= -1;
        return (*this);
    }

    auto Remove0(int newSign) -> Bigint {
        sign = newSign;
        for (int i = a.size() - 1; i > 0 && a[i] == '0'; --i) {
            a.pop_back();
        }
        if (a.size() == 1 && a[0] == '0') {
            sign = 1;
        }
        return (*this);
    }

    auto operator==(Bigint x) -> bool {
        return sign == x.sign && a == x.a;
    }

    auto operator==(string x) -> bool {
        return *this == Bigint(x);
    }

    auto operator==(int64_t x) -> bool {
        return *this == Bigint(x);
    }

    auto operator!=(Bigint x) -> bool {
        return !(*this == x);
    }

    auto operator!=(string x) -> bool {
        return !(*this == x);
    }

    auto operator!=(int64_t x) -> bool {
        return !(*this == x);
    }

    auto operator<(Bigint b) -> bool {
        if (sign != b.sign) {
            return sign < b.sign;
        }
        if (a.size() != b.size()) {
            return a.size() * sign < b.size() * sign;
        }
        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
        return false;
    }

    auto operator<(string x) -> bool {
        return *this < Bigint(x);
    }

    auto operator<(int64_t x) -> bool {
        return *this < Bigint(x);
    }

    auto operator<=(Bigint b) -> bool {
        return *this == b || *this < b;
    }

    auto operator<=(string b) -> bool {
        return *this == b || *this < b;
    }

    auto operator<=(int64_t b) -> bool {
        return *this == b || *this < b;
    }

    auto operator>(Bigint b) -> bool {
        return !(*this == b || *this < b);
    }

    auto operator>(string x) -> bool {
        return !(*this == x || *this < x);
    }

    auto operator>(int64_t b) -> bool {
        return !(*this == b || *this < b);
    }

    auto operator>=(Bigint b) -> bool {
        return *this == b || *this > b;
    }

    auto operator>=(string b) -> bool {
        return *this == b || *this > b;
    }

    auto operator>=(int64_t b) -> bool {
        return *this == b || *this > b;
    }

    auto operator+(Bigint b) -> Bigint {
        if (sign != b.sign) return (*this) - b.inverseSign();
        Bigint sum;
        for (int i = 0, carry = 0; i < a.size() || i < b.size() || carry; i++) {
            if (i < a.size()) carry += a[i] - '0';
            if (i < b.size()) carry += b[i] - '0';
            sum.a += (carry % 10 + 48);
            carry /= 10;
        }
        return sum.Remove0(sign);
    }

    auto operator+(string x) -> Bigint {
        return *this + Bigint(x);
    }

    auto operator+(int64_t x) -> Bigint {
        return *this + Bigint(x);
    }

    auto operator++(int) -> Bigint {
        *this += 1;
        return *this - 1;
    }

    auto operator++() -> Bigint {
        *this += 1;
        return *this;
    }

    auto operator+=(Bigint x) -> void {
        *this = *this + x;
    }

    auto operator+=(string x) -> void {
        *this = *this + x;
    }

    auto operator+=(int64_t x) -> void {
        *this = *this + x;
    }


    auto operator-(Bigint b) -> Bigint {
        if (sign != b.sign) {
            return (*this) + b.inverseSign();
        }
        if (*this < b) {
            return (b - *this).inverseSign();
        }
        Bigint sub;
        for (int i = 0, borrow = 0; i < a.size(); ++i) {
            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : '0');
            sub.a += borrow >= 0 ? borrow + '0' : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }
        return sub.Remove0(sign);
    }

    auto operator-(string x) -> Bigint {
        return *this - Bigint(x);
    }

    auto operator-(int64_t x) -> Bigint {
        return *this - Bigint(x);
    }

    auto operator--(int) -> Bigint {
        *this -= 1;
        return *this + 1;
    }

    auto operator--() -> Bigint {
        *this -= 1;
        return *this;
    }

    auto operator-=(Bigint x) -> void {
        *this = *this - x;
    }

    auto operator-=(string x) -> void {
        *this = *this - x;
    }

    auto operator-=(int64_t x) -> void {
        *this = *this - x;
    }

    auto operator*(Bigint b) -> Bigint {
        Bigint mult("0");
        for (int i = 0, k = a[i]; i < a.size(); ++i, k = a[i]) {
            while (k-- - '0') {
                mult += b;
            }
            b.a.insert(b.a.begin(), '0');
        }
        return mult.Remove0(sign * b.sign);
    }

    auto operator*(string x) -> Bigint {
        return *this * Bigint(x);
    }

    auto operator*(int64_t x) -> Bigint {
        return *this * Bigint(x);
    }

    auto operator*=(Bigint x) -> void {
        *this = *this * x;
    }

    auto operator*=(string x) -> void {
        *this = *this * x;
    }

    auto operator*=(int64_t x) -> void {
        *this = *this * x;
    }

    auto operator/(Bigint b) -> Bigint {
        if (b.size() == 1 && b[0] == '0') {
            b.a[0] /= (b[0] - '0');
        }
        Bigint c("0"), d;
        for (int j = 0; j < a.size(); ++j) {
            d.a += "0";
        }
        int dSign = sign * b.sign;
        b.sign = 1;
        for (int i = a.size() - 1; i >= 0; --i) {
            c.a.insert(c.a.begin(), '0');
            c = c + a.substr(i, 1);
            while (!(c < b)) {
                c = c - b, ++d.a[i];
            }
        }
        return d.Remove0(dSign);
    }

    auto operator/(string x) -> Bigint {
        return *this / Bigint(x);
    }

    auto operator/(int64_t x) -> Bigint {
        return *this / Bigint(x);
    }

    auto operator/=(Bigint x) -> void {
        *this = *this / x;
    }

    auto operator/=(string x) -> void {
        *this = *this / x;
    }

    auto operator/=(int64_t x) -> void {
        *this = *this / x;
    }

    auto operator%(Bigint b) -> Bigint {
        if (b.size() == 1 && b[0] == '0') {
            b.a[0] /= (b[0] - '0');
        }
        Bigint c("0");
        int cSign = sign * b.sign;
        b.sign = 1;
        for (int i = a.size() - 1; i >= 0; --i) {
            c.a.insert(c.a.begin(), '0');
            c = c + a.substr(i, 1);
            while (!(c < b)) {
                c -= b;
            }
        }
        return c.Remove0(cSign);
    }

    auto operator%(string x) -> Bigint {
        return *this % Bigint(x);
    }

    auto operator%(int64_t x) -> Bigint {
        return *this % Bigint(x);
    }

    auto operator%=(Bigint x) -> void {
        *this = *this % x;
    }

    auto operator%=(string x) -> void {
        *this = *this % x;
    }

    auto operator%=(int64_t x) -> void {
        *this = *this % x;
    }

    auto print() -> void {
        if (sign == -1) {
            putchar('-');
        }
        for (int i = a.size() - 1; i >= 0; --i) {
            putchar(a[i]);
        }
    }

    friend auto operator>>(istream &in, Bigint &x) -> istream & {
        string s;
        in >> s;
        x = s;
        return in;
    }

    friend auto operator<<(ostream &out, Bigint &x) -> ostream & {
        if (x.sign == -1) putchar('-');
        for (int i = x.size() - 1; i >= 0; --i) {
            putchar(x[i]);
        }
        putchar(' ');
        putchar('\n');
        return out;
    }

    friend auto pow(Bigint base, Bigint pw) -> Bigint {
        Bigint ans = 1;
        while (pw != 0) {
            if (pw % 2 != 0) {
                ans *= base;
            }
            base *= base, pw /= 2;
        }
        return ans;
    }

    friend auto pow(Bigint a, Bigint b, Bigint mod) -> Bigint {
        if (b == 0) {
            return Bigint(1);
        }
        Bigint tmp = pow(a, b / 2, mod);
        if (b % 2 == 0) {
            return (tmp * tmp) % mod;
        }
        else {
            return (((tmp * tmp) % mod) * a) % mod;
        }
    }

    friend auto sqrt(Bigint x) -> Bigint {
        Bigint ans = x, tmp = (x + 1) / 2;
        while (tmp < ans) ans = tmp, tmp = (tmp + x / tmp) / 2;
        return ans;
    }

    friend auto gcd(Bigint a, Bigint b) -> Bigint {
        return a % b == 0 ? b : gcd(b, a % b);
    }

    friend auto lcm(Bigint a, Bigint b) -> Bigint {
        return a / gcd(a, b);
    }
};

Bigint f[2009], a, b;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("out", "w", stdout);
    f[0] = 0, f[1] = 1;
    for (int i = 2; i <= 2000; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[2000];
    // cin >> a >> b;
    // for (int i = 0; i <= 1000; ++i) {
        // if (f[i] >= a && f[i] <= b) {
        //     cout << f[i];
        // }
    // }
    // cout << 1;
    // for (int i = 1; i <= 200; ++i) {
    //     cout << 0;
    // }
}