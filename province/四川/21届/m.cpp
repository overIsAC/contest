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

vector<vector<string>> a;

int main() {
    // 0
    a.push_back({
        "*****",
        "*...*",
        "*...*",
        "*...*",
        "*****",
    });
    // 1
    a.push_back({
        "....*",
        "....*",
        "....*",
        "....*",
        "....*",
    });
    // 2
    a.push_back({
        "*****",
        "....*",
        "*****",
        "*....",
        "*****",
    });
    // 3
    a.push_back({
        "*****",
        "....*",
        "*****",
        "....*",
        "*****",
    });
    // 4
    a.push_back({
        "*...*",
        "*...*",
        "*****",
        "....*",
        "....*",
    });
    // 5
    a.push_back({
        "*****",
        "*....",
        "*****",
        "....*",
        "*****",
    });
    // 6
    a.push_back({
        "*****",
        "*....",
        "*****",
        "*...*",
        "*****",
    });
    // 7
    a.push_back({
        "*****",
        "....*",
        "....*",
        "....*",
        "....*",
    });
    // 8
    a.push_back({
        "*****",
        "*...*",
        "*****",
        "*...*",
        "*****",
    });
    // 9
    a.push_back({
        "*****",
        "*...*",
        "*****",
        "....*",
        "*****",
    });
    vector<string> b;
    string s;
    while (cin >> s) {
        b.push_back(s);
    }
    int c = b.size() / 5;

    auto get = [&](vector<string> d) -> int {
        int idx = 0;
        for (auto &i : a) {
            if (i == d) {
                return idx;
            }
            ++idx;
        }
        return idx;
    };

    for (int i = 0; i < c; ++i) {
        cout << get({b[i], b[i + c], b[i + 2 * c], b[i + 3 * c], b[i + 4 * c]});
    }
    return 0;
}