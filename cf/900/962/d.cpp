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
const int N = 3 + 2e5;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    map<LL, vector<int>> mp;
    vector<pair<int, LL>> ans;
    for (int i = 1; i <= n; ++i) {
        mp[a[i]].push_back(i);
    }
    for (auto &i : mp) {
        auto &ve = i.second;
        sort(ve.begin(), ve.end());
        for (int j = 0; j < ve.size(); j += 2) {
            if (j + 1 == ve.size()) {
                ans.push_back({ve[j], i.first});
            } else {
                mp[i.first * 2].push_back(ve[j + 1]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i.second << ' ';
    }
    return 0;
}