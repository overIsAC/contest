#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m, a[N];
int tr[N];

void add(int *tr, int p, int v) {
    for (; p <= n; p += p & -p) {
        tr[p] = min(tr[p], v);
    }
}

int ask(int *tr, int p) {
    int ans = 1e9 + 1;
    for (; p; p -= p & -p) {
        ans = min(ans, tr[p]);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            tr[i] = 1e9 + 1;
        }
        set<int> s;
        for (int i = 1; i <= n; ++i) {
            if (ask(tr, i - 1) > a[i]) {
                s.insert(i);
                add(tr, i, a[i]);
            }
        }
        while (m--) {
            int k, d;
            cin >> k >> d;
            a[k] -= d;
            int v = ask(tr, k - 1);
            if (v > a[k]) {
                add(tr, k, a[k]);
                s.insert(k);
                auto p = s.upper_bound(k);
                while (p != s.end() && a[*p] >= a[k]) {
                    p = s.erase(p);
                }
            }
            cout << s.size() << ' ';
        }
        cout << endl;
    }
    return 0;
}