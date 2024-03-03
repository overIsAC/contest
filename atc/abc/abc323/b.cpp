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
    int n;
    cin >> n;
    vector<PII> a;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        int cnt = 0;
        for (auto& j : s) {
            if (j == 'o') {
                ++cnt;
            }
        }
        a.push_back({-cnt, i});
    }
    sort(a.begin(), a.end());
    for (auto [i, j] : a) {
        cout << j << ' ';
    }
    return 0;
}