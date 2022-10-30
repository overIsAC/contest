#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n, a, b;

int fa[N];
int v[N];

int find(int p) { return p == fa[p] ? p : fa[p] = find(fa[p]); }

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        fa[i] = i;
        fa[i + n] = i + n;
        v[a] = i;
        v[b] = -i;
    }
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        if (v[i] > 0) {
            s.insert(v[i]);
        } else {
            int c = v[i];
            
        }
    }

    return 0;
}