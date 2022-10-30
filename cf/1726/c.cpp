#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

char s[N * 2];
int n;

int fa[N * 2];
int stk[N * 2], top;
bool v[N];

int find(int p) { return p == fa[p] ? p : fa[p] = find(fa[p]); }

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    fa[u] = v;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s + 1;
        for (int i = 1; i <= 2 * n; ++i) {
            fa[i] = i;
            v[i] = false;
        }
        for (int i = 1; i <= 2 * n; ++i) {
            if (s[i] == '(')
                stk[++top] = i;
            else {
                if (top) {
                    merge(stk[top], i);
                    v[stk[top]] = true;
                    v[i] = true;
                    --top;
                }
            }
        }
        for (int i = 1; i < 2 * n; ++i) {
            if (s[i] == ')' && s[i + 1] == '(') {
                if (v[i] && v[i + 1]) {
                    merge(i, i + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= 2 * n; ++i) {
            if (find(i) == i) {
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}