#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
char s[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s + 1;
        int r = (n + 1) / 2;
        while (r + 1 <= n && s[r + 1] == s[n + 1 >> 1]) ++r;
        int l = n - r + 1;
        cout << r - l + 1 << endl;
    }
    return 0;
}
