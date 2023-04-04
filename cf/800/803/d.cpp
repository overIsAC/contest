#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int k;
vector<string> ve;
string s;

int main() {
    cin >> k;
    while (cin >> s) {
        string t = s;
        s = "";
        for (auto &i : t) {
            if (i == '-') {
                ve.push_back(s);
                s = "";
            } else {
                s += i;
            }
        }
        ve.push_back(s);
    }
    int l = 0, r = 1e6;
    for (int i = 0; i < s.size(); ++i) {
        l = max<int>(l, s[i].size() + (i + 1 != s.size()));
    }
    cout << l << endl;

    auto ok = [&](int v) -> bool {
        int cnt = 0, line = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (cnt + s[i] + (i + 1 != s.size()) <= v) {
                cnt += s[i] + (i + 1 != s.size());
            } else {
                cnt = s[i] + (i + 1 != s.size());
                if (cnt > v) {
                    return false;
                }
                ++line;
            }
        }
        return line <= v;
    };

    while (l < r) {
        int mid = l + r >> 1;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << endl;
    return 0;
}