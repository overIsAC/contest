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
        string s;
        int n;
        cin >> n >> s;
        vector<int> ans(s.begin(), s.end());
        for (auto& i : ans) {
            i -= '0';
        }

        LL sum = 0;
        for (auto& i : ans) {
            sum = i = sum + i;
        }
        reverse(ans.begin(), ans.end());
        LL g = 0;
        for (int i = 0; i < ans.size() || g; ++i) {
            if (i < ans.size()) {
                g += ans[i];
            } else {
                ans.push_back(0);
            }
            ans[i] = g % 10;
            g /= 10;
        }
        while (ans.size() && ans.back() == 0) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        for (auto& i : ans) {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}