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
        vector<int> a(n * (n - 1) / 2);
        for (auto &i : a) {
            cin >> i;
        }
        sort(a.begin(), a.end());
        vector<int> ans = {(int)1e9};
        int t = n - 1;
        for (int i = 0; i < n * (n - 1) / 2; i += t, t -= 1) {
            ans.push_back(a[i]);
        }
        for (auto &i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}