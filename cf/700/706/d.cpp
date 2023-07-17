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

int n, tr[N * 30][2], cnt[N * 30], id;
int q;

void insert(int x, int v) {
    int rt = 0;
    for (int i = 29; i >= 0; --i) {
        int &p = tr[rt][x >> i & 1];
        if (!p) {
            p = ++id;
        }
        cnt[p] += v;
        rt = p;
    }
}

int query(int x) {
    int ans = 0, rt = 0;
    for (int i = 29; i >= 0; --i) {
        if (tr[rt][!(x >> i & 1)] && cnt[tr[rt][!(x >> i & 1)]]) {
            ans |= 1 << i;
            rt = tr[rt][!(x >> i & 1)];
        } else {
            rt = tr[rt][x >> i & 1];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    insert(0, 1);
    while (q--) {
        char op;
        int x;
        cin >> op >> x;
        if (op == '+') {
            insert(x, 1);
        } else if (op == '-') {
            insert(x, -1);
        } else {
            cout << query(x) << '\n';
        }
    }
    return 0;
}