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
    vector<pair<string, string>> a(n);
    for (auto& [u, v] : a) {
        cin >> v;
        u = v;
        reverse(u.begin(), u.end());
    }
    sort(a.begin(), a.end());
    for (auto [u, v] : a) {
        cout << v << endl;
    }
    return 0;
}