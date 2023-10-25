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

int n;
map<int, string> id;
map<string, int> money;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string name;
        cin >> name;
        id[i] = name;
    }
    for (int i = 1; i <= n; ++i) {
        int m, c;
        string name;
        cin >> name;
        cin >> m >> c;
        for (int j = 1; j <= c; ++j) {
            string s;
            cin >> s;
            money[name] -= m / c;
            money[s] += m / c;
        }
    }
    for (auto [x, y] : id) {
        cout << y << ' ' << money[y] << endl;
    }
    return 0;
}