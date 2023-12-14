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
const int N = 3 + 5e5;

int n;
string t, s[N];
vector<int> a, b;

int f(string& s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            ++j;
        }
        ++i;
    }
    return i;
}

int main() {
    cin >> n >> t;

    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; ++i) {
        a.push_back(f(s[i], t));
    }
    sort(a.begin(), a.end());
    reverse(t.begin(), t.end());

    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        reverse(s[i].begin(), s[i].end());
        int p = f(s[i], t);
        int q = lower_bound(a.begin(), a.end(), t.size() - p) - a.begin();
        ans += a.size() - q;
    }
    cout << ans << endl;

    return 0;
}