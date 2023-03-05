#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

struct Node {
    int x, y, z;
};

int n, a[N];
vector<Node> dp[34];
int d[213];
int dd[123][123];

int main() {
    int T;
    cin >> T;
    for (int i = 0; i <= 12; ++i) {
        for (int j = 0; j <= 12; ++j) {
            for (int k = 0; k <= 12; ++k) {
                int c = i * 1 + j * 2 + k * 3;
                if (c <= 5) dp[c].push_back({i, j, k});
            }
        }
    }
    memset(d, 0x3f, sizeof(d));
    *d = 0;
    for (int i = 1; i <= 123; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (i >= j) d[i] = min(d[i], d[i - j] + 1);
        }
    }

    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int ans = 1e9;
        for (int i = 0; i <= 12; ++i) {
            for (int j = 0; j <= 12; ++j) {
                for (int k = 0; k <= 12; ++k) {
                    int cnt = 0;
                    bool flag = true;
                    for (int q = 1; q <= n; ++q) {
                        auto &ve = dp[a[q] % 6];
                        bool ok = false;
                        int c = 1e9;
                        for (auto &w : ve) {
                            if (i >= w.x && j >= w.y && k >= w.z) {
                                ok = true;
                                int xx = i - w.x, yy = j - w.y, zz = k - w.z;
                                int cc = a[q] - a[q] % 6;
                                while (cc >= 6 && yy >= 3) {
                                    cc -= 6;
                                    yy -= 3;
                                }
                                while (cc >= 3 && min(xx, yy) >= 1) {
                                    cc -= 3;
                                    xx -= 1;
                                    yy -= 1;
                                }
                                while (cc >= 3 && zz >= 1) {
                                    cc -= 3;
                                    zz -= 1;
                                }
                                while (cc >= 3 && xx >= 3) {
                                    cc -= 3;
                                    xx -= 3;
                                }
                                c = min(cc / 3, c);
                            }
                        }
                        if (ok) {
                            cnt = max(cnt, c);
                        } else {
                            flag = false;
                        }
                    }
                    if (flag) {
                        ans = min(ans, cnt + i + j + k);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}