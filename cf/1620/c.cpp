#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        LL x;
        string s;
        cin >> n >> k >> x >> s;
        string ans;
        x -= 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'a') {
                ans += 'a';
                continue;
            }
            int j = i;
            while (j - 1 >= 0 && s[j - 1] == s[i]) {
                --j;
            }
            LL c = (i - j + 1) * k + 1;
            ans += string(x % c, 'b');
            x /= c;
            i = j;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}