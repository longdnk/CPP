//
// Created by longdnk on 12/20/2022.
//
#include <bits/stdc++.h>

using namespace std;

string s1, s2, res;

auto findSum(string str1, string str2) -> string {
    string result;
    int carry = 0, sum, n1 = (int) str1.size(), n2 = (int) str2.size();
    if (n1 > n2) {
        swap(str1, str2);
    }
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    for (int i = 0; i < n1; ++i) {
        sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = n1; i < n2; ++i) {
        sum = ((str2[i] - '0') + carry);
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry) {
        result.push_back(carry + '0');
    }

    reverse(result.begin(), result.end());

    return result;
}

inline auto operator+(string s1, string s2) -> string {
    return findSum(s1, s2);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s1 >> s2;
    res = s1 + s2;
    cout << res << '\n';
}