#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 5e5;

int n, m, a[N], b[N], c[N];
LL t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> t;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        auto check = [&](int l, int r, int mid) {
            for (int i = mid + 1; i <= r; ++i) {
                b[i] = a[i];
            }
            sort(b + mid + 1, b + r + 1);
            {
                int u = l, v = mid + 1, w = l;
                while (u <= mid && v <= r) {
                    if (b[u] < b[v]) {
                        c[w++] = b[u++];
                    } else {
                        c[w++] = b[v++];
                    }
                }
                while (u <= mid) {
                    c[w++] = b[u++];
                }
                while (v <= r) {
                    c[w++] = b[v++];
                }
            }
            LL cnt = 0;
            for (int i = l, j = r, k = m; k && i < j; ++i, --j, --k) {
                cnt += (LL)(c[j] - c[i]) * (c[j] - c[i]);
                if (cnt > t) {
                    return false;
                }
            }

            for (int i = l; i <= r; ++i) {
                b[i] = c[i];
            }
            return true;
        };

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int p = 1, j = i;
            b[i] = a[i];
            while (p) {
                if (j + p <= n && check(i, j + p, j)) {
                    j += p;
                    p *= 2;
                } else {
                    p /= 2;
                }
            }
            ans += 1;
            i = j;
        }
        cout << ans << endl;
    }

    return 0;
}