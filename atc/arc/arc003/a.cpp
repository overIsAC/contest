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

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << fixed << setprecision(11)
         << 1.0 *
                accumulate(s.begin(), s.end(), 0,
                           [](int ans, char c) {
                               if (c == 'F') {
                                   return ans;
                               }
                               return ans + 'E' - c;
                           }) /
                n
         << endl;
    return 0;
}