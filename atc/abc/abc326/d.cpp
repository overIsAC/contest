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
const int N = 3 + 3e5;

int n;
char r[22], c[22];
string ans[22];

int valid() {
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (ans[i][j] != '.') {
                if (ans[i][j] != c[j]) {
                    return 0;
                }
                break;
            }
        }
    }

    for (int j = 0; j < n; ++j) {
        map<char, int> mp;
        for (int i = 0; i < n; ++i) {
            ++mp[ans[i][j]];
        }
        if (mp['A'] != 1 || mp['B'] != 1 || mp['C'] != 1) {
            return 0;
        }
    }
    return 1;
}

int check(int p) {
    if (p == 0) {
        return 1;
    }
    for (int i = p - 1, j = 0; j < n; ++j) {
        if (ans[i][j] != '.') {
            if (ans[i][j] != r[i]) {
                return 0;
            }
            break;
        }
    }
    return 1;
}

int cnt = 0;
void dfs(int p) {
    if (!check(p)) {
        return;
    }

    if (p == n) {
        // if (cnt % 10000 == 0) {
        //     cout << ++cnt << endl;
        // }

        if (valid()) {
            valid();
            cout << "Yes" << endl;
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << endl;
            }
            exit(0);
        }
        return;
    }
    do {
        dfs(p + 1);
    } while (next_permutation(ans[p].begin(), ans[p].end()));
}

int main() {
    cin >> n;
    cin >> r;
    cin >> c;

    for (int i = 0; i < n; ++i) {
        ans[i] = string(n - 3, '.') + "ABC";
    }

    dfs(0);

    cout << "No" << endl;

    return 0;
}