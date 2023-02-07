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

int n, a[N], m;
int pre[N];

struct Trie {
    int ch[N][2], cnt[N], id;
    int root[N], v;
    void insert(int p, int u, int &v, int val) {
        cnt[v = ++id] = cnt[u] + 1;
        if (p < 0) {
            return;
        }
        int o = val >> p & 1;
        insert(p - 1, ch[u][o], ch[v][o], val);
    }
    void insert(int p, int v) {
        insert(30, root[p], root[p + 1], v);
    }
} tr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
        tr.insert(i, pre[i - 1]);
    }
   
    return 0;
}