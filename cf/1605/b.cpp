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
        int n;
        string s;
        cin >> n >> s;
        vector<int> ans;
        for (int i = 0, j = n - 1;;) {
            while (i < j && s[i] != '1') {
                ++i;
            }
            while (i < j && s[j] != '0') {
                --j;
            }
            if (i >= j) {
                break;
            }
            ans.push_back(i);
            ans.push_back(j);
            ++i;
            --j;
        }
        sort(ans.begin(), ans.end());
        if (ans.empty()) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
            cout << ans.size() << ' ';
            for (auto &i : ans) {
                cout << i + 1 << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}