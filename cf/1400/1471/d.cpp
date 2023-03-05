#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n, a[N], m, q;
int p[N];
bool vis[N];

int main() {
    for (int i = 2; i < N; ++i) {
        if (!vis[i]) {
            p[++m] = i;
            for (int j = i + i; j < N; j += i) {
                vis[j] = true;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            int x = 1;
            for (int j = 1; j <= m && p[j] * p[j] <= a[i]; ++j) {
                int v = 0;
                while (a[i] % p[j] == 0) {
                    v ^= 1;
                    a[i] /= p[j];
                }
                if (v) x *= p[j];
            }
            if (a[i] > 1) x *= a[i];
            ++mp[x];
        }
        PII b = {0, 0};
        map<int, int> mp2;
        for (auto &i : mp) {
            if (b.second < i.second) b = i;
            if (i.second & 1) {
                mp2[i.first] += i.second;
            } else {
                mp2[1] += i.second;
            }
        }
        PII c = {0, 0};
        for (auto &i : mp2) {
            if (c.second < i.second) c = i;
        }
        cin >> q;
        while (q--) {
            LL x;
            cin >> x;
            if (x == 0) {
                cout << b.second << endl;
            } else {
                cout << c.second << endl;
            }
        }
    }
    return 0;
}