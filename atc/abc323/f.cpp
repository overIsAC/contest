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

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

map<pair<LL, LL>, LL> d;
map<pair<LL, LL>, vector<pair<pair<LL, LL>, LL>>> edge;
LL xa, ya, xb, yb, xc, yc;

int main() {
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    auto push_back = [](LL ax, LL ay, LL bx, LL by, LL w) {
        edge[{ax, ay}].push_back({{bx, by}, w});
    };

    auto push_back2 = [](LL ax, LL ay, LL bx, LL by) {
        edge[{ax, ay}].push_back({{bx, by}, abs(ax - bx) + abs(ay - by)});
        edge[{bx, by}].push_back({{ax, ay}, abs(ax - bx) + abs(ay - by)});
    };

    for (int i = 0; i < 4; ++i) {
        push_back(xb + dx[i], yb + dy[i], xb + dx[(i + 2) % 4],
                  yb + dy[(i + 2) % 4], 1);
        push_back2(xa, ya, xb + dx[i], yb + dy[i]);
        push_back2(xc, yc, xb + dx[i], yb + dy[i]);
    }

    push_back2(xa, ya, xc, yc);

    for (auto [x, e] : edge) {
        for (auto [y, w] : e) {
            d[x] = 1e18;
            d[y] = 1e18;
        }
    }
    d[{xa, ya}] = 0;
    for (int i = 1; i <= 5; ++i) {
        for (auto [x, e] : edge) {
            for (auto [y, w] : e) {
                if (d[y] > d[x] + w) {
                    cout << x.first << ' ' << x.second << ' ' << y.first << ' '
                         << y.second << ' ' << w << endl;
                }
                d[y] = min(d[y], d[x] + w);
            }
        }
    }
    cout << d[{xc, yc}] << endl;
    return 0;
}