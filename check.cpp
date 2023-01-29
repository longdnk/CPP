#include <bits/stdc++.h>
using namespace std;

struct compare {
    auto operator()(auto a, auto b) -> bool {
        return a + b > b + a;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    sort(s + 1, s + 1 + n, compare());
    for (int i = 1; i <= n; ++i) {
        cout << s[i];
    }
}