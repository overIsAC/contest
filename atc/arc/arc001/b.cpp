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

int n;
string s;

int main() {
    int a, b;
    cin >> a >> b;
    map<int, int> d;
    queue<int> q;
    q.push(a);
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (x == b) {
            cout << d[b] << endl;
            return 0;
        }
        vector<int> z = {x - 1, x + 1, x + 5, x - 5, x - 10, x + 10};
        for (auto& y : z) {
            if (d.count(y)) {
                continue;
            }
            d[y] = d[x] + 1;
            q.push(y);
        }
    }
    return 0;
}