#include <bits/stdc++.h>

using namespace std;

class Number {
protected:
    int value { 0 };
public:
    virtual auto check() -> bool = 0;

    auto input() -> void {
        int x;
        cin >> x;
        setValue(x);
    }

    [[nodiscard]] auto getValue() const -> int {
        return value;
    }

    auto setValue(int newValue) -> void {
        this->value = newValue;
    }

};

class PrimeNumber : public Number {
protected:
    bool flag = true;
public:
    PrimeNumber() = default;

    explicit PrimeNumber(int value) {
        this->value = value;
    }

    auto check() -> bool override {
        cout << "Value check: " << this->getValue() << " result: ";
        for (int i = 2; i * i <= this->getValue(); i = i + (i & 1) + 1) {
            if (!(this->getValue() % i)) {
                this->flag = false;
                break;
            }
        }
        return this->value > 1 && this->flag;
    }
};

class SquareNumber : public Number {
public:
    SquareNumber() = default;

    explicit SquareNumber(int value) {
        this->setValue(value);
    }

    auto check() -> bool override {
        cout << "Value check: " << this->getValue() << " result: ";
        return (int) sqrt(this->getValue()) * sqrt(this->getValue()) == this->getValue();
    }
};

class PerfectNumber : public Number {
protected:
    int64_t sum = 1;
public:
    PerfectNumber() = default;

    explicit PerfectNumber(int value) {
        this->setValue(value);
    }

    auto check() -> bool override {
        cout << "Value check: " << this->getValue() << " result: ";
        for (int i = 2; i * i < this->getValue(); ++i) {
            !(this->getValue() % i) ? this->sum += i * i != this->getValue() ? i + this->getValue() / i : i : 0;
        }
        return this->sum == this->getValue() && this->getValue() > 1;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<Number *> p = { new PrimeNumber, new SquareNumber, new PerfectNumber };
    for (Number *item: p) {
        item->input();
        cout << (item->check() ? "YES" : "NO") << '\n';
    }
}