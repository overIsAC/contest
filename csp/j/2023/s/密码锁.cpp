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

map<vector<int>, int> mp;
int n;

void f(vector<int> a) {
    for (int i = 0; i < a.size(); ++i) {
        auto b = a;
        for (int j = 0; j < 10; ++j) {
            b[i] = (b[i] + 1) % 10;
            ++mp[b];
        }
    }
    for (int i = 0; i + 1 < a.size(); ++i) {
        auto b = a;
        for (int j = 0; j < 10; ++j) {
            b[i] = (b[i] + 1) % 10;
            b[i + 1] = (b[i + 1] + 1) % 10;
            ++mp[b];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        vector<int> a(5);
        for (auto &j : a) {
            cin >> j;
        }
        mp[a] = -1e9;
        f(a);
    }
    int ans = 0;
    for (auto &[x, y] : mp) {
        if (y == n) {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}