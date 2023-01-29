#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int dp[n + 1][5];
    memset(dp, 0x0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            dp[i][j] += dp[i - 1][j];
        }
    }
    for (int i = 1, l, r; i <= n; ++i) {
        cin >> l >> r;
        for (int j = 1; j <= 3; ++j) {
            cout << dp[r - 1][j] - dp[l - 1][j] << (j == 3 ? '\n' : ' ');
        }
    }
}