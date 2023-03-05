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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

string s;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        bool ok = true;
        int last = 0, cnt = 1111;
        for (auto& i : s) {
            if (i != last) {
                if (cnt < 2) {
                    ok = false;
                }
                cnt = 1;
                last = i;
            } else {
                ++cnt;
            }
        }
        if (cnt < 2) {
            ok = false;
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}