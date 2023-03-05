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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 120000;

string s;

int main() {
    cin >> s;
    int ans = 0, cnt = 0, sum = 0;
    for (auto& i : s) {
        if (i % 3 == 0) {
            ++ans;
            cnt = 0, sum = 0;
        } else {
            sum += i - '0';
            ++cnt;
            if (cnt == 3 || sum % 3 == 0) {
                cnt = 0;
                sum = 0;
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}