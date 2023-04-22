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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int k;
    vector<PII> ans;
    cin >> k;
    ans.push_back({150, 1});
    int c = 0;
    for (int i = 1; i <= 1000; ++i) {
        ans.push_back({150 + i, i});
        ans.push_back({150 - i, i});
        ans.push_back({150 + i, i + 1});
        ans.push_back({150 - i, i + 1});
        c += 2;
    }
    while (c >= k) {
        if (ans.size()) ans.pop_back();
        if (ans.size()) ans.pop_back();
        c -= 1;
    }
    if (ans.empty()) {
        ans.push_back({1, 1});
    }
    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}