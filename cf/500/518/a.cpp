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
    string a, b;
    cin >> a >> b;
    int f = 0;
    for (int i = 0; i < a.size(); ++i) {
        if ((f && a[i] != 'z') || a[i] + 1 < b[i]) {
            ++a[i];
            cout << a << endl;
            return 0;
        }
        if (a[i] < b[i]) {
            f = 1;
        }
    }
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        if (a[i] < b[i] && a[i] != 'z') {
            a[i] += 1;
            for (int j = i + 1; j < a.size(); ++j) {
                a[j] = 'a';
            }
            if (a < b) {
                cout << a << endl;
                return 0;
            }
            break;
        }
    }
    cout << "No such string" << endl;
    return 0;
}