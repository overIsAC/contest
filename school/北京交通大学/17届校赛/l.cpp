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

// const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
string p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    int pp = p.back() % 2;
    int v = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> p;
        v = v * pp + (p.back() % 2);
    }
    v %= 2;
    if (v) {
        cout << "odd" << endl;
    } else {
        cout << "even" << endl;
    }
    return 0;
}