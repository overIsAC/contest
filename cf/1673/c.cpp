#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

vector<int> ve;
LL dp[N];

int main() {
    auto check = [](int n) {
        string s = to_string(n);
        string ss = s;
        reverse(s.begin(), s.end());
        return s == ss;
    };
    for (int i = 1; i <= 4e4; ++i) {
        if (check(i))
            ve.push_back(i);
    }
    0 [dp] = 1;
    for (auto& j : ve) {
        for (int i = j; i <= 4e4; ++i) {
            i[dp] += (i - j)[dp];
            i[dp] %= mod;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << n[dp] << endl;
    }
    return 0;
}