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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            ans.push_back(i);
        }
        if (n & 1) {
            for (int i = 1; ans[i] < n - 1; i += 2) {
                swap(ans[i], ans[i + 1]);
            }
        } else {
            for (int i = 0; ans[i] < n - 1; i += 2) {
                swap(ans[i], ans[i + 1]);
            }
        }
        for (auto &i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}