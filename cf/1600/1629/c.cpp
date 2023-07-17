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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector a(n, 0);
        for (auto &i : a) {
            cin >> i;
        }
        vector p(n + 2, vector<int>());
        for (int i = 0; i < n; ++i) {
            p[a[i]].push_back(i);
        }
        for (auto &i : p) {
            reverse(i.begin(), i.end());
        }
        vector<int> ans;
        int w = 0;
        while (w < n) {
            while (p[0].size() && p[0].back() < w) {
                p[0].pop_back();
            }
            if (p[0].empty()) {
                ans.push_back(0);
                ++w;
                continue;
            }
            int mex = 0;
            int q = w;
            while (true) {
                while (p[mex].size() && p[mex].back() < w) {
                    p[mex].pop_back();
                }
                if (p[mex].size()) {
                    q = max(p[mex].back(), q);
                    ++mex;
                } else {
                    break;
                }
            }
            ans.push_back(mex);
            w = q + 1;
        }
        cout << ans.size() << endl;
        for (auto &i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}