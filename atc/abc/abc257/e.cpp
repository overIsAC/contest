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
const int N = 3 + 200;

int n, c[N];
vector<int> ans;

int main() {
    cin >> n;
    for (int i = 1; i <= 9; ++i) {
        cin >> c[i];
    }
    int p = 1;
    for (int i = 1; i <= 9; ++i) {
        if (c[i] <= c[p]) {
            p = i;
        }
    }
    for (int i = 1; i <= n / c[p]; ++i) {
        ans.push_back(p);
    }
    n %= c[p];
    for (auto &i : ans) {
        for (int j = 9; j > i; --j) {
            if (n + c[i] - c[j] >= 0) {
                n = n + c[i] - c[j];
                i = j;
                break;
            }
        }
    }
    for (auto &i : ans) {
        cout << i;
    }
    return 0;
}
