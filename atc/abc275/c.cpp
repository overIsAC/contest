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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 33;

struct Node {
    int x, y;
    Node operator-(const Node& b) const { return {x - b.x, y - b.y}; }
};
vector<Node> ve;

char s[N][N];

int calc(Node& a, Node& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int dot(const Node& a, const Node& b) {
    return a.x * b.x + a.y * b.y;
}

int main() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cin >> s[i][j];
            if (s[i][j] == '#') {
                ve.push_back({i, j});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < ve.size(); ++i) {
        for (int j = 0; j < ve.size(); ++j) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < ve.size(); ++k) {
                if (i == k || j == k) {
                    continue;
                }
                if (calc(ve[i], ve[j]) != calc(ve[j], ve[k])) {
                    continue;
                }
                if (dot(ve[i] - ve[j], ve[j] - ve[k])) {
                    continue;
                }
                for (int q = 0; q <= ve.size(); ++q) {
                    if (i == q || j == q || k == q) {
                        continue;
                    }
                    if (calc(ve[k], ve[q]) == calc(ve[j], ve[k]) &&
                        calc(ve[q], ve[i]) == calc(ve[j], ve[k])) {
                        ++ans;
                        break;
                    }
                }
            }
        }
    }
    cout << ans / 8 << endl;
    return 0;
}