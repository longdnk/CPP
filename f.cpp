#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    auto checkPerfect = [&](int x) -> bool {
        int sum = 1;
        for (int i = 2; i * i <= x; ++i)
            !(x % i) ? sum += i * i != x ? i + x / i : 0 : 0;
        return sum == x && x > 1;
    };
    auto checkPrime = [&](int x) -> bool {
        bool flag = true;
        for (int i = 2; i * i <= x; i = i + (i & 1) + 1) {
            if (!(x % i)) {
                flag = false;
                break;
            }
        }
        return x > 1 && flag;
    };
    auto checkSquare = [&](int x) -> bool {
        return (1LL) * sqrt(x) * sqrt(x) == x;
    };
    int n;
    cin >> n;
    cout << (checkPrime(n) ? "YES" : "NO") << '\n';
    cout << (checkPerfect(n) ? "YES" : "NO") << '\n';
    cout << (checkSquare(n) ? "YES" : "NO") << '\n';
}