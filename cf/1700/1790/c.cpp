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

int n;
map<int, int> mp[N];

int get(map<int, int>& mp) {
    if (mp.begin()->second > mp.rbegin()->second) {
        return mp.begin()->first;
    } else {
        return mp.rbegin()->first;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            mp[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < n; ++j) {
                int a;
                cin >> a;
                ++mp[j][a];
            }
        }
        vector<int> ans;
        ans.push_back(get(mp[1]));
        for (int i = 1; i < n; ++i) {
            mp[i].erase(ans.back());
            ans.push_back(mp[i].begin()->first);
        }
        for (auto& i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}