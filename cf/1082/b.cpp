#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<PII> ve;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'S')
            continue;
        int j = i;
        ve.push_back({i, j});
        while (j + 1 < n && s[j + 1] == 'G') {
            ++j;
        }
        ve.back().second = j;
        ans = max(ans, j - i + 1);
        i = j;
    }
    for (auto& i : ve) {
        if (ve.size() > 1) {
            ans = max(i.second - i.first + 2, ans);
        }
    }
    for (int i = 1; i < ve.size(); ++i) {
        if (ve[i - 1].second + 2 == ve[i].first) {
            if (ve.size() == 2) {
                ans = max(ans, ve[i].second - ve[i - 1].first);
            } else {
                ans = max(ans, ve[i].second - ve[i - 1].first + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}