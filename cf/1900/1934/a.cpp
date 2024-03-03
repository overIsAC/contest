#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& i : a) {
            cin >> i;
        }
        sort(a.begin(), a.end());
        vector<int> b;
        for (int i = 1; i <= 4 && a.size(); ++i) {
            b.push_back(a.back());
            a.pop_back();
        }
        for (int i = 0; i < 4 && i < a.size(); ++i) {
            b.push_back(a[i]);
        }
        sort(b.begin(), b.end());
        int ans = 0;
        do {
            int cnt = 0;
            for (int i = 1; i < n && i < 4; ++i) {
                cnt += abs(b[i] - b[i - 1]);
            }
            cnt += abs(b[3] - b[0]);
            ans = max(ans, cnt);
        } while (next_permutation(b.begin(), b.end()));
        cout << ans << endl;
    }
    return 0;
}