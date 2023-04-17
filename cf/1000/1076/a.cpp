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
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] > s[i + 1]) {
            s.erase(s.begin() + i);
            cout << s << endl;
            return 0;
        }
    }
    s.pop_back();
    cout << s << endl;

    return 0;
}