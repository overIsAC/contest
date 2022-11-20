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

map<char, char> mp = {{'C', '1'}, {'D', '2'}, {'E', '3'}, {'F', '4'},
                      {'G', '5'}, {'A', '6'}, {'B', '7'}};

int main() {
    string s;
    cin >> s;
    int v = 0;
    string ans;
    for (auto &i : s) {
        if (i == '<') {
            --v;
        } else if (i == '>') {
            ++v;
        } else {
            ans += mp[i];
            if (v) {
                ans += string(abs(v), v < 0 ? '.' : '*');
            }
        }
    }
    cout << ans << endl;
    return 0;
}