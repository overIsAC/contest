#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3e5;

int tr[N * 30][2], id;
int cnt[N * 30], val[N * 30];
int rt;

void up(int rt, int p) {
    cnt[rt] = 0;
    val[rt] = INT_MAX;
    if (tr[rt][0]) {
        cnt[rt] += cnt[tr[rt][0]];
    }
    if (tr[rt][1]) {
        cnt[rt] += cnt[tr[rt][1]];
    }
    if (cnt[rt] == 1) {
        if (tr[rt][0] && cnt[tr[rt][0]]) {
            val[rt] = val[tr[rt][0]];
        }
        if (tr[rt][1] && cnt[tr[rt][1]]) {
            val[rt] = val[tr[rt][1]] | (1 << p);
        }
    } else if (cnt[rt] >= 2) {
        if (tr[rt][0] && cnt[tr[rt][0]] > 1) {
            val[rt] = min(val[rt], val[tr[rt][0]]);
        }
        if (tr[rt][1] && cnt[tr[rt][1]] > 1) {
            val[rt] = min(val[rt], val[tr[rt][1]]);
        }
        if (tr[rt][0] && cnt[tr[rt][0]] && tr[rt][1] && cnt[tr[rt][1]]) {
            val[rt] = min(val[rt], val[tr[rt][0]] ^ val[tr[rt][1]] ^ (1 << p));
        }
    }
}

void insert(int p, int &rt, int a, int v) {
    if (!rt) {
        rt = ++id;
    }
    if (p < 0) {
        cnt[rt] += v;
        return;
    }
    insert(p - 1, tr[rt][a >> p & 1], a, v);
    up(rt, p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, x, op;
    cin >> q;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            insert(29, rt, x, 1);
        } else if (op == 2) {
            cin >> x;
            insert(29, rt, x, -1);
        } else {
            cout << val[rt] << endl;
        }
    }
    return 0;
}