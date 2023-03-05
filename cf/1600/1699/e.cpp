#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;
const int M = 3 + 5e6;

// int p[N * 5], v[N * 5];

// void init(int n) {
//     for (int i = 2; i <= n; ++i) {
//         if (!v[i]) {
//             v[i] = i;
//             p[++p[0]] = i;
//         }
//         for (int j = 1; j <= p[0]; ++j) {
//             if (p[j] > v[i] || p[j] > n / i) break;
//             v[p[j] * i] = p[j];
//         }
//     }
// }

PII a[M];
int n, b[N], m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i < M; ++i) {
        a[i].first = 1;
        a[i].second = i;
    }
    int u, v;
    for (int i = 2; i < M; ++i) {
        for (int j = i + i; j < M; j += i) {
            u = i;
            v = j / i;
            if (u > v) swap(u, v);
            if (u > a[j].first) {
                a[j].first = u;
                a[j].second = v;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        set<int> s;
        for (int i = 1; i <= n; ++i) {
            s.insert(b[i]);
        }
        int ans = *s.rbegin() - *s.begin();
        for (; s.size();) {
            auto p = --s.end();
            if (a[*p].first == 1) break;
            s.insert(a[*p].first);
            s.insert(a[*p].second);
            s.erase(p);
            ans = min(ans, *s.rbegin() - *s.begin());
        }
        cout << ans << endl;
    }
    return 0;
}