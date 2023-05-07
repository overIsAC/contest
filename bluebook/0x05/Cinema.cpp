#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 2e5;

int n, a[N], b[N], c[N], m;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> c[i];
    }
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        ++mp[a[i]];
    }

    auto cmp = [&](int i, int j) {
        if (mp[b[i]] != mp[b[j]]) {
            return mp[b[i]] > mp[b[j]];
        }
        return mp[c[i]] > mp[c[j]];
    };

    int p = 1;

    for (int i = 1; i <= m; ++i) {
        if (cmp(i, p)) {
            p = i;
        }
    }
    cout << p << endl;

    return 0;
}