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

int n, a[N], pre[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int sum = 0;
        for (auto &i : s) {
            sum += i - '0';
        }
        int cnt = 0;
        string a, b;
        for (auto &i : s) {
            int v = i - '0';
            a += '0';
            b += '0';
            while (cnt < sum / 2 && v && a.back() < '9') {
                ++a.back();
                ++cnt;
                --v;
            }
            while (v) {
                ++b.back();
                --v;
            }
        }
        cout << stoll(a) << ' ' << stoll(b) << endl;
    }
    return 0;
}