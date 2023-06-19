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

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        set<char> st(s.begin(), s.end());
        int ans = s.size();
        for (auto &i : st) {
            int cnt = 0;
            for (int j = 0; j < s.size(); ++j) {
                if (s[j] == i) {
                    continue;
                }
                int k = j;
                while (k + 1 < s.size() && s[k + 1] != i) {
                    ++k;
                }
                int temp = k - j + 1, t = 0;
                while (temp) {
                    t += 1;
                    temp /= 2;
                }
                cnt = max(t, cnt);
                j = k;
            }
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}