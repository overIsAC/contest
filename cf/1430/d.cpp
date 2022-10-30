#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n;
char s[N];

void solve() {
    vector<int> ve;
    for (int i = 1; i <= n; ++i) {
        int j = i;
        while (j + 1 <= n && s[j + 1] == s[j]) ++j;
        ve.push_back(j - i + 1);
        i = j;
    }
    int ans = 0;
    for (int i = 0, j = 0; i < ve.size(); ++i) {
        ++ans;
        if (j < i) ++j;
        while (j < ve.size() && ve[j] == 1) ++j;
        if (j >= ve.size()) {
            ve.pop_back();
        } else {
            --ve[j];
        }
        if (i == ve.size()) {
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s + 1;
        solve();
    }
    return 0;
}
