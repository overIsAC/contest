#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int p[N];
PII a[N];
int n, q;

void mySwap(int i, int j) {
    swap(p[a[i].second], p[a[j].second]);
    swap(a[i], a[j]);
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
        p[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j >= 2; --j) {
            if (a[j] < a[j - 1]) {
                mySwap(j - 1, j);
            }
        }
    }
    while (q--) {
        // for (int i = 1; i <= n; ++i) {
        //     cout << a[i].first << ' ' << a[i].second << endl;
        // }

        int op, x, v;
        cin >> op >> x;
        if (op == 1) {
            cin >> v;
            a[p[x]].first = v;
            while (p[x] + 1 <= n && a[p[x]] >a[p[x] + 1]) {
                mySwap(p[x], p[x] + 1);
            }
            while (p[x] - 1 >= 1 && a[p[x]] < a[p[x] - 1]) {
                mySwap(p[x], p[x] - 1);
            }
        } else {
            cout << p[x] << endl;
        }
    }

    return 0;
}