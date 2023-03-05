#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<PII> ans;
        bool ok = true;
        for (int i = 1; i <= n; i += 2) {
            ans.push_back({i, i + 1});
            if ((LL)(i + k) * (i + 1) % 4) {
                swap(ans.back().first, ans.back().second);
                if ((LL)(i + 1 + k) * i % 4) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            cout << "YES" << endl;
            for (auto &i : ans) {
                cout << i.first << ' ' << i.second << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}