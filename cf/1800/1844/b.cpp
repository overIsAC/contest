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
const int N = 3 + 3e5;

int f[N], p[N], t;

int main() {
    for (int i = 2; i < N; ++i) {
        if (f[i]) {
            continue;
        }
        p[++t] = i;
        for (int j = i; j < N; j += i) {
            f[j] = 1;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        if (n == 2) {
            cout << "1 2\n";
            continue;
        }
        vector<int> ans;
        for (int i = n; i >= 3; --i) {
            ans.push_back(i);
        }
        cout << 2 << ' ';
        for (int i = 0; i < ans.size(); ++i) {
            if (i == ans.size() / 2) {
                cout << 1 << ' ';
            }
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}