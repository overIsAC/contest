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
const int N = 3 + 1e5;

int n;
string s;
LL ans;

int main() {
    cin >> n;
    cin >> s;
    sort(s.begin(), s.end(), greater<char>());

    for (int i = 0; (LL)i * i < 1e14; ++i) {
        string t = to_string((LL)i * i);
        if (t.size() > s.size()) {
            break;
        }
        sort(t.begin(), t.end(), greater<char>());
        if (s.size() > t.size()) {
            if (s[t.size()] > '0') {
                continue;
            }
        }
        int ok = 1;
        for (int i = 0; i < t.size() && ok; ++i) {
            if (s[i] != t[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}