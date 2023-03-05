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
        string s;
        cin >> n >> s;
        while (s.size() && s.back() % 2 == 0) {
            s.pop_back();
        }
        if (s.empty()) {
            cout << -1 << endl;
            continue;
        }
        int sum = 0;
        for (auto &i : s) {
            sum += i - '0';
        }
        if (sum % 2) {
            bool ok = false;
            for (int i = 0; i + 1 < s.size(); ++i) {
                if (s[i] % 2) {
                    s.erase(s.begin() + i);
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                s = "-1";
            }
        }
        reverse(s.begin(), s.end());
        while (s.size() && s.back() == '0') {
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}