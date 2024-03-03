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

int n, m;
string s;

int ok(int v) {
    int a = v, b = m;
    for (auto& i : s) {
        if (i == '0') {
            a = v;
            b = m;
        } else if (i == '1') {
            if (b) {
                --b;
            } else if (a) {
                --a;
            } else {
                return 0;
            }
        }else {
            if (!a) {
                return 0;
            }
            --a;
        }
    }
    return 1;
}

int main() {
    cin >> n >> m;
    cin >> s;
    int l = 0, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << endl;
    return 0;
}