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
        vector<PII> a(n);
        for (auto& i : a) {
            cin >> i.first;
        }
        for (auto& i : a) {
            cin >> i.second;
        }
        sort(a.begin(), a.end(), [](PII& a, PII& b) -> int {
            if (a.first < b.first && a.second < b.second) {
                return 1;
            }
            if (a.first > b.first && a.second > b.second) {
                return 0;
            }
            return a < b;
        });
        for (auto& [u, v] : a) {
            cout << u << ' ';
        }
        cout << endl;
        for (auto& [u, v] : a) {
            cout << v << ' ';
        }
        cout << endl;
    }
    return 0;
}