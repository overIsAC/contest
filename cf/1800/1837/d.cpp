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
        cin >> n;
        string s;
        cin >> s;
        int cnt[2] = {};
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                if (cnt[1]) {
                    --cnt[1];
                    ans.push_back(2);
                } else {
                    ++cnt[0];
                    ans.push_back(1);
                }
            } else {
                if (cnt[0]) {
                    --cnt[0];
                    ans.push_back(1);
                } else {
                    ++cnt[1];
                    ans.push_back(2);
                }
            }
        }
        if (cnt[1] || cnt[0]) {
            cout << -1 << endl;
        } else {
            int c = set<int>(ans.begin(), ans.end()).size();
            cout << c << endl;

            for (auto &i : ans) {
                if (c == 1) {
                    i = 1;
                }
                cout << i << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}