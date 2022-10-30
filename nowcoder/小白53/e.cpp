#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e6;

LL a[10];
LL s;

set<vector<int>> st;
vector<int> stk(3, 0);
bool vis[6][6];

void dfs(int x, int y) {
    st.insert(stk);
    cout << st.size() << endl;
    if (y == 6) {
        x += 1;
        y = 0;
    }
    if (x == 6) {
        return;
    }
    dfs(x, y + 1);
    for (int len = 1; len <= 3; ++len) {
        bool ok = true;
        for (int q = 0; q < len && ok; ++q) {
            for (int w = 0; w < len && ok; ++w) {
                if (q + x >= 6 || w + y >= 6 || vis[q + x][w + y]) ok = false;
            }
        }
        if (ok) {
            for (int q = 0; q < len; ++q) {
                for (int w = 0; w < len; ++w) {
                    vis[q + x][w + y] = true;
                }
            }
            stk[len - 1] += 1;
            dfs(x, y + 1);
            stk[len - 1] -= 1;
            for (int q = 0; q < len; ++q) {
                for (int w = 0; w < len; ++w) {
                    vis[q + x][w + y] = false;
                }
            }
        }
    }
}

int main() {
    dfs(0, 0);
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        for (int i = 1; i <= 6; ++i) {
            cin >> a[i];
        }
        if (a[6] + a[5] + a[4] > s) {
            cout << "No" << endl;
            continue;
        }
        s -= a[6];
        s -= a[5];
        s -= a[4];

        a[1] -= a[5] * 11;
        LL t = a[4];
        t *= 5;

        LL g = min(a[2], t);
        a[2] -= g;
        t -= g;
        a[1] -= 4 * g;
    }
    return 0;
}