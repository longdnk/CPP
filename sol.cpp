#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int a[n + 1];
    auto isPrime = [&](int value) -> bool {
        auto isOdd = [&](int x) -> bool {
            return x & 1;
        };
        bool flag = value > 1;
        for (int i = 2; i * i <= value; i = i + (i & 1) + 1) {
            if (!(value % i) && isOdd(value)) {
                flag = false;
                break;
            }
        }
        return flag;
    };
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += isPrime(a[i]) ? a[i] : 0;
    }
}