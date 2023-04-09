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
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto &i : s) {
        ++mp[i];
    }
    vector<char> ve;
    for (auto &i : mp) {
        if (i.second & 1) {
            --i.second;
            ve.push_back(i.first);
        }
    }
    while (ve.size() > 1) {
        ve.pop_back();
        ++mp[ve[0]];
        ++mp[ve[0]];
        ve.erase(ve.begin());
    }
    string u, v;
    string c;
    if (ve.size()) {
        c = ve[0];
    }
    for (auto &i : mp) {
        if (i.second & 1) {
            c += i.first;
            --i.second;
        }
        while (i.second) {
            u += i.first;
            v += i.first;
            i.second -= 2;
        }
    }
    reverse(v.begin(), v.end());
    cout << u << c << v << endl;
    return 0;
}