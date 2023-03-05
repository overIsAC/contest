#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int ans = 0;
        for (auto& i : s) {
            ans += i - 'a' + 1;
        }
        if (s.size() % 2 == 0) {
            cout << "Alice " << ans << endl;
        } else {
            int a = max(ans - s[0] + 'a' - 1, ans - s.back() + 'a' - 1);
            int b = ans - a;
            if (a > b) {
                cout << "Alice " << a - b << endl;
            } else {
                cout << "Bob " << b - a << endl;
            }
        }
    }
    return 0;
}