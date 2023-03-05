#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
string s;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        int ans = 0;
        for (int i = n - 1, j = 0; j < n; ++j, --i) {
            if (s[i] - '0' == 0) continue;
            ans += s[i] - '0';
            if (i!= n-1) ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}