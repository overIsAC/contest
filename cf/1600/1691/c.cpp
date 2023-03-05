#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

char s[N];
int n, k;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        cin >> s + 1;
        int first = 1, last = n;
        while (first <= n && s[first] == '0') ++first;
        if (first == n + 1) {
            cout << 0 << endl;
            continue;
        }
        while (last && s[last] == '0') --last;

        if (n - last <= k) {
            k -= n - last;
            swap(s[last], s[n]);
        }
        if (s[first] != '0' && first != n && first - 1 <= k) {
            swap(s[1], s[first]);
        }

        int ans = 0;
        for (int i = 1; i < n; ++i) {
            ans += (s[i] - '0') * 10 + s[i + 1] - '0';
        }

        cout << ans << endl;
    }
    return 0;
}