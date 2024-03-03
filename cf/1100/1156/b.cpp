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
        string s;
        cin >> s;
        map<char, int> mp;
        for (auto& i : s) {
            ++mp[i];
        }
        vector<pair<char, int>> ve(mp.begin(), mp.end());
        if (ve.size() == 1) {
            cout << s << endl;
            continue;
        }
        if (ve.size() == 2) {
            if (ve[0].first + 1 != ve.back().first) {
                cout << s << endl;
            } else {
                cout << "No answer" << endl;
            }
            continue;
        }
        if (ve.size() == 3) {
            string ans = "No answer";
            do {
                if (abs(ve[0].first - ve[1].first) != 1 && abs(ve[1].first - ve[2].first) != 1) {
                    ans = string(ve[0].second, ve[0].first);
                    ans += string(ve[1].second, ve[1].first);
                    ans += string(ve[2].second, ve[2].first);
                    break;
                }
            } while (next_permutation(ve.begin(), ve.end()));
            cout << ans << endl;
            continue;
        }
        string ans;
        for (int i = 0, j = ve.size() / 2; i < ve.size() / 2 || j < ve.size(); ++i, ++j) {
            if (j < ve.size()) {
                ans += string(ve[j].second, ve[j].first);
            }
            if (i < ve.size() / 2) {
                ans += string(ve[i].second, ve[i].first);
            }
        }
        cout << ans << endl;
    }
    return 0;
}