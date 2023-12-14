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

string s[8];
map<int, int> mx, my, mu, mv;

void dfs(int x, int y, int cnt) {
    if (cnt == 8) {
        for (auto& i : s) {
            cout << i << endl;
        }
        exit(0);
        return;
    }
    if (y == 8) {
        y = 0;
        ++x;
    }
    if (x == 8) {
        return;
    }
    dfs(x, y + 1, cnt);
    if (s[x][y] != 'Q') {
        s[x][y] = 'Q';
        if (!mx[x] && !my[y] && !mu[x + y] && !mv[x - y]) {
            mx[x] = my[y] = mu[x + y] = mv[x - y] = 1;
            dfs(x, y + 1, cnt + 1);
            mx[x] = my[y] = mu[x + y] = mv[x - y] = 0;
        }
        s[x][y] = '.';
    }
}

int main() {
    for (auto& i : s) {
        cin >> i;
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (s[i][j] == 'Q') {
                ++mx[i];
                ++my[j];
                ++mu[i + j];
                ++mv[i - j];
            }
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (mx[i] > 1) {
                cout << "No Answer" << endl;
                return 0;
            }
            if (my[j] > 1) {
                cout << "No Answer" << endl;
                return 0;
            }
            if (mu[i + j] > 1) {
                cout << "No Answer" << endl;
                return 0;
            }
            if (mv[i - j] > 1) {
                cout << "No Answer" << endl;
                return 0;
            }
        }
    }
    dfs(0, 0, 3);
    cout << "No Answer" << endl;
    return 0;
}