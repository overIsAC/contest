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
const int N = 3 + 1e5;

int main() {
    int a, b, x;
    cin >> a >> b >> x;
    string ans;
    if (a > 0) {
        --a;
        ans += '0';
    }
    if (b > 0) {
        --b;
        ans += '1';
        if (ans.size() > 1) {
            --x;
        }
    }
    while (x > 0) {
        if (a and ans.back() == '1') {
            ans += '0';
            --x;
            --a;
            continue;
        }
        if (a and ans[0] == '1') {
            ans.insert(ans.begin(), '0');
            --x;
            --a;
            continue;
        }
        if (b and ans.back() == '0') {
            ans += '1';
            --x;
            --b;
            continue;
        }
        if (b and ans[0] == '0') {
            ans.insert(ans.begin(), '1');
            --x;
            --b;
            continue;
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] == '0') {
            while (a > 0) {
                ans.insert(ans.begin() + i, '0');
                --a;
            }
            break;
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] == '1') {
            while (b > 0) {
                ans.insert(ans.begin() + i, '1');
                --b;
            }
            break;
        }
    }

    cout << ans << endl;
    return 0;
}