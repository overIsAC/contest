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
const int N = 3 + 1e5;

struct Node {
    int l, r, ls, rs;
    int cnt, lazy;
} tr[80 * N];

int id, rt;



void update1(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        tr[rt].lazy = 1;
        tr[rt].cnt = r - l + 1;
        return;
    }
    int mid = l + r >> 1;
}

int main() {
    return 0;
}