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
    int T;
    cin >> T;
    while (T--) {
        vector<int> a;
        string s;
        cin >> s;
        for (auto &i : s) {
            a.push_back(i - '0');
        }
        sort(a.begin(), a.end());
        if (a[0]) {
            cout << "cyan" << endl;
            continue;
        }
        a.erase(a.begin());
        int sum = 0;
        for (auto &i : a) {
            sum += i;
        }
        int ok = 0;
        for (int &i : a) {
            if (((sum - i) * 4 + i) % 6 == 0) {
                ok = 1;
            }
        }
        if (ok) {
            cout << "red" << endl;
        } else {
            cout << "cyan" << endl;
        }
    }
    return 0;
}