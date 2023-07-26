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
const int N = 3 + 1e6;

int n;
char s[N];
int pre[222];
int suf[222];
int mid[222];

int main() {
    cin >> n;
    cin >> s + 1;
    int prep = 0;
    int sufp = 0;
    for (int i = 1; i <= n; ++i) {
        ++pre[s[i]];
        if (pre[s[i]] == 5) {
            prep = i;
            break;
        }
    }
    if (!prep) {
        cout << "none" << endl;
        return 0;
    }
    for (int i = n; i; --i) {
        ++suf[s[i]];
        if (suf[s[i]] == 5) {
            sufp = i;
            break;
        }
    }
    char md = 0;
    for (int i = prep + 1; i < sufp; ++i) {
        ++mid[s[i]];
        if (mid[s[i]] == 7) {
            md = s[i];
            break;
        }
    }
    if (!md) {
        cout << "none" << endl;
        return 0;
    }
    for (int i = 1; i <= 5; ++i) {
        cout << s[prep];
    }
    for (int i = 1; i <= 7; ++i) {
        cout << md;
    }
    for (int i = 1; i <= 5; ++i) {
        cout << s[sufp];
    }
    return 0;
}