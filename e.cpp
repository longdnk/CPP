#include "bits/stdc++.h"

using namespace std;
const int maxn = 1e6 + 9;
int n, m;
pair<int, int> a[maxn], b[109];

inline auto operator-(const pair<int, int> &a, const pair<int, int> &b) -> pair<int, int> {
    return pair<int, int>(b.first - a.first, b.second - a.second);
}

inline auto operator*(const pair<int, int> &u, const pair<int, int> &v) -> int64_t {
    return (int64_t) u.first * v.first + (int64_t) u.second * v.second;
}

inline auto operator^(const pair<int, int> &u, const pair<int, int> &v) -> int64_t {
    return (int64_t) u.first * v.second - (int64_t) v.first * u.second;
}

inline auto pointOnSegment(const pair<int, int> &a, const pair<int, int> &b, const pair<int, int> &c) -> bool {
    pair<int, int> ab = b - a, ac = c - a;
    return (ab ^ ac) == 0 && (ab * ac) <= 0;
}

inline auto pointOnRay(const pair<int, int> &a, const pair<int, int> &x, const pair<int, int> &b) -> bool {
    pair<int, int> ax = x - a, ab = b - a;
    return (ax ^ ab) == 0 && (ax * ab) >= 0;
}

inline auto rayCutSegment(const pair<int, int> &a, const pair<int, int> &x, const pair<int, int> &b, const pair<int, int> &c) -> bool {
    pair<int, int> ax = x - a, xb = b - x, xc = c - x;
    int64_t axb = ax ^ xb, axc = ax ^ xc;
    if ((axb <= 0 && axc <= 0) || (axb >= 0 && axc >= 0)) {
        return 0;
    }
    int64_t S1 = (b - a) ^ (c - a), S2 = xb ^ xc;
    if ((S1 <= 0 && S2 <= 0) || (S1 >= 0 && S2 >= 0)) {
        return abs(S2) < abs(S1);
    }
    return 1;
}

inline auto check(const pair<int, int> &x) -> bool {
    for (int i = 1; i <= n; ++i) {
        if (pointOnSegment(x, a[i - 1], a[i])) {
            return 1;
        }
    }
    pair<int, int> y = pair<int, int>(x.first, 1e9 + 1);
    while (1) {
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            if (pointOnRay(x, y, a[i])) {
                ok = false;
                break;
            }
        }
        if (ok) {
            break;
        }
        y = pair<int, int>(rand() % int(1e8), rand() % int(1e8));
    }
    int cnt = {};
    for (int i = 1; i <= n; ++i) {
        cnt += rayCutSegment(x, y, a[i - 1], a[i]);
    }
    return cnt & 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(time(nullptr));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    a[0] = a[n];
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].first >> b[i].second;
        cout << (check(b[i]) ? "YES" : "NO") << '\n';
    }
}