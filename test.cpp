//
// Created by longdnk on 1/15/2023.
//

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int w[n + 1], v[m + 1], dp[n + 1][m + 1];
    memset(dp, 0x0, sizeof(dp));
    for (int i = 1; i <= n; cin >> w[i] >> v[i], ++i);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = j < w[i] ? dp[i - 1][j] : max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[n][m] << '\n';
}