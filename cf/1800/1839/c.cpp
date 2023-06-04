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
const int N = 3 + 2e5;

int n;
int a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        if (a[n] == 1) {
            cout << "NO" << endl;
            continue;
        }
        vector<int> ans;
        for (int i = n; i >= 1; --i) {
            int j = i;
            while (i - 1 >= 1 && a[i - 1] == 0) {
                --i;
            }
            int p = i;
            while (i - 1 >= 1 && a[i - 1] == 1) {
                --i;
            }
            for (int k = 1; k <= j - i; ++k) {
                ans.push_back(0);
            }
            ans.push_back(p - i);
        }
        cout << "YES" << endl;
        for (auto &i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}