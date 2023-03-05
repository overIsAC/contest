#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
LL x;
int ans = 100000;

map<LL, int> d;

pair<int, vector<int>> get(LL x) {
    set<int> s;
    int c = 0;
    while (x) {
        s.insert(x % 10);
        x /= 10;
        ++c;
    }
    return {c, vector<int>(s.rbegin(), s.rend())};
}

int dfs(LL x) {
    if (d.count(x)) return d[x];
    auto pi = get(x);
    auto g = pi.second;

    if (pi.first == n) {
        return d[x] = 0;
    }

    int ans = 1232122;
    for (int &i : g) {
        if (i <= 1) break;
        ans = min(dfs(x * i) + 1, ans);
    }
    return d[x] = ans;
}

int main() {
    cin >> n >> x;
    if (x == 1) {
        if (n == 1)
            cout << 1 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    int ans =dfs(x);
    if (ans > 123123) ans = -1;
    cout << ans << endl;
    return 0;
}