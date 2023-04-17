#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        n /= 2;
        while (n) {
            if (n % 2) {
                ans.push_back(2);
            } else {
                ans.push_back(1);
            }
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto& i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}