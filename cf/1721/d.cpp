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

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n;
vector<vector<int>> na, nb;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n), b(n);
        for (auto& i : a) {
            cin >> i;
        }
        for (auto& i : b) {
            cin >> i;
        }
        int ans = (1 << 30) - 1;
        na.clear();
        nb.clear();
        na.push_back(a);
        nb.push_back(b);
        auto check = [](vector<int>& a, vector<int>& b, int p) -> bool {
            int za = 0, zb = 0;
            for (auto& i : a) {
                if (i >> p & 1) {
                    ++za;
                }
            }
            for (auto& i : b) {
                if (i >> p & 1) {
                    ++zb;
                }
            }
            return za + zb == (int)a.size();
        };
        for (int i = 30; i >= 0; --i) {
            bool ok = true;
            for (int j = 0; j < na.size(); ++j) {
                if (!check(na[j], nb[j], i)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                vector<vector<int>> ta, tb;
                for (int j = 0; j < na.size(); ++j) {
                    vector<int> aa, ab, ba, bb;
                    for (auto& k : na[j]) {
                        if (k >> i & 1) {
                            aa.push_back(k);
                        } else {
                            ab.push_back(k);
                        }
                    }
                    for (auto& k : nb[j]) {
                        if (k >> i & 1) {
                            ba.push_back(k);
                        } else {
                            bb.push_back(k);
                        }
                    }
                    if (aa.size()) {
                        ta.push_back(aa);
                        tb.push_back(bb);
                    }
                    if (ab.size()) {
                        ta.push_back(ab);
                        tb.push_back(ba);
                    }
                }
                swap(ta, na);
                swap(tb, nb);
            } else {
                ans &= ~(1 << i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}