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
const int N = 3 + 1e5;

int n;
string stk;

void dfs(int last, int cnt) {
    if (!cnt) {
        cout << stk << endl;
        return;
    }
    if (stk.size()) {
        stk += '+';
    }
    for (int i = last; i <= cnt; ++i) {
        if (i == n) {
            continue;
        }
        string t = to_string(i);
        stk += t;
        dfs(i, cnt - i);
        for (int j = 1; j <= t.size(); ++j) {
            stk.pop_back();
        }
    }
    if (stk.size()) {
        stk.pop_back();
    }
}

int main() {
    cin >> n;
    dfs(1, n);
    return 0;
}