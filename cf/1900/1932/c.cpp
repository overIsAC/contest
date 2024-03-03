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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto& i : a) {
            cin >> i;
        }
        string s;
        cin >> s;
        int L = 0, R = n - 1;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == 'L') {
                ++L;
            } else {
                --R;
            }
        }
        vector<int> ans;
        LL now = a[R] % m;
        ans.push_back(now);
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == 'L') {
                --L;
                now *= a[L];
            } else {
                ++R;
                now *= a[R];
            }
            now %= m;
            ans.push_back(now);
        }
        reverse(ans.begin(), ans.end());
        for (auto& i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}