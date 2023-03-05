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
const int N = 3 + 2e5;

int n, m;

int tr[N];
int cnt[N];
int temp;

int main() {
    cin >> n >> m;

    auto insert = [&](int u, int v) {
        if (u > v) {
            swap(u, v);
        }
        if (!cnt[u]++) {
            ++temp;
        }
    };
    auto remove = [&](int u, int v) {
        if (u > v) {
            swap(u, v);
        }
        if (!--cnt[u]) {
            --temp;
        }
    };

    while (m--) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
    }
    int q;
    cin >> q;
    while (q--) {
        int op, u, v;
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            insert(u, v);
        } else if (op == 2) {
            cin >> u >> v;
            remove(u, v);
        } else {
            cout << n - temp << endl;
        }
    }
    return 0;
}