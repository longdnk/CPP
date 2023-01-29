//
// Created by longdnk on 1/15/2023.
//
#include <bits/stdc++.h>

using namespace std;

struct compare {
    auto operator()(const string a, const string b) -> bool {
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
    for (int i = 1; i <= n; cin >> s[i], ++i);
    sort(s + 1, s + 1 + n, compare());
    for (int i = 1; i <= n; cout << s[i], ++i);
}