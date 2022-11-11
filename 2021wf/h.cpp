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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n;
string s[N];

struct Node {
    int L, R, idx;
};

vector<int> ans;
vector<Node> u, v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        int cnt = 0;
        int L = 0, R = 0;
        for (int j = 0; j < s[i].size(); ++j) {
            if (s[i][j] == '(') {
                ++cnt;
            } else {
                --cnt;
            }
            if (cnt < 0) {
                R -= cnt;
                cnt = 0;
            }
        }
        L = cnt;
        if (L > R) {
            u.push_back({L, R, i});
        } else {
            v.push_back({L, R, i});
        }
    }
    sort(u.begin(), u.end(),
         [&](const Node& a, const Node& b) { return a.R < b.R; });
    sort(v.begin(), v.end(),
         [&](const Node& a, const Node& b) { return a.L > b.L; });
    int now = 0;
    for (auto& i : u) {
        if (now < i.R) {
            cout << "impossible" << endl;
            return 0;
        }
        now = now - i.R + i.L;
        ans.push_back(i.idx);
    }
    for (auto& i : v) {
        if (now < i.R) {
            cout << "impossible" << endl;
            return 0;
        }
        now = now - i.R + i.L;
        ans.push_back(i.idx);
    }
    if (now) {
        cout << "impossible" << endl;
        return 0;
    }
    for (auto& i : ans) {
        cout << i << endl;
    }
    return 0;
}