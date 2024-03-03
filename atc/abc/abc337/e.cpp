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

int f(int n) {
    int ans = 0;
    do {
        ans += 1;
        n /= 2;
    } while (n);
    return ans;
}

int main() {
    int n;
    cin >> n;
    int m = f(n - 1);
    vector<vector<int>> qry(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i >> j & 1) {
                qry[j].push_back(i + 1);
            }
        }
    }
    cout << qry.size() << endl;
    for (auto& i : qry) {
        cout << i.size() << " ";
        for (auto& j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    string s;
    cin >> s;
    int ans = 0;
    // for (int i = 0; i < s.size(); ++i) {
    //     if (s[i] == '1') {
    //         ans |= 1 << i;
    //     }
    // }
    for (int i = s.size() - 1; i >= 0; --i) {
        ans = ans * 2 + s[i] - '0';
    }
    cout << ans + 1 << endl;

    return 0;
}