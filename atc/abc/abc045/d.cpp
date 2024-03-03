#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
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

int n, h, w;
vector<PII> a;
PII b[N];

bool check(int x, int y) { return 1 <= x && x <= h && 1 <= y && y <= w; }

set<PII> st;
LL ans[123];

int main() {
    cin >> h >> w >> n;

    auto ok = [&](int x, int y) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (!check(i + x, j + y)) {
                    return false;
                }
            }
        }
        return true;
    };
    for (int i = 1; i <= n; ++i) {
        cin >> b[i].first >> b[i].second;

        for (int u = 0; u >= -2; --u) {
            for (int v = 0; v >= -2; --v) {
                if (ok(b[i].first + u, b[i].second + v)) {
                    a.push_back({b[i].first + u, b[i].second + v});
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        st.insert({b[i].first, b[i].second});
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for (auto &i : a) {
        int c = 0;
        for (int u = 0; u <= 2; ++u) {
            for (int v = 0; v <= 2; ++v) {
                if (st.count({i.first + u, i.second + v})) {
                    ++c;
                }
            }
        }
        ++ans[c];
    }
    ans[0] = (LL)(h - 2) * (w - 2);
    for (int i = 1; i <= 9; ++i) {
        ans[0] -= ans[i];
    }
    for (int i = 0; i <= 9; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}