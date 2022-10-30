#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2.5e5;

int n, a[N];
int f1[N][20];
int f2[N][20];
int lg[N];
int inv[N];

int get1(int l, int r) {
    int w = lg[r - l + 1];
    return min(f1[l][w], f1[r - (1 << w) + 1][w]);
}

int get2(int l, int r) {
    int w = lg[r - l + 1];
    return max(f2[l][w], f2[r - (1 << w) + 1][w]);
}

int dfs(int l, int r) {
    if (l == r) return 0;
    if (l + 1 == r) return 1;
    int q = inv[get1(l, r)], w = inv[get2(l, r)];
    if (q > w) swap(q, w);
    return dfs(l, q) + 1 + dfs(w, r);
}

int main() {
    for (int i = 2; i < N; ++i) {
        lg[i] = lg[i / 2] + 1;
    }

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            f1[i][0] = f2[i][0] = a[i];
            inv[a[i]] = i;
        }
        for (int j = 1; j <= 19; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                f1[i][j] = min(f1[i][j - 1], f1[i + (1 << j - 1)][j - 1]);
                f2[i][j] = max(f2[i][j - 1], f2[i + (1 << j - 1)][j - 1]);
            }
        }
        cout << dfs(1, n) << endl;
    }
    return 0;
}