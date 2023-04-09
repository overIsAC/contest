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

string s;
vector<PII> ve;
int n;

int main() {
    cin >> n >> s;
    for (auto &i : s) {
        if (ve.empty() || ve.back().second != i) {
            ve.push_back({1, i});
        } else {
            ++ve.back().first;
        }
    }
    LL ans = 0;
    int u = 0;
    for (auto &i : ve) {
        if (i.first == 1) {
            u = 0;
        } else {
            ans += (LL)u * (i.first - 1);
            ans += (LL)i.first * (i.first - 1) / 2;
            u += i.first - 1;
        }
    }
    cout << ans << endl;
    return 0;
}