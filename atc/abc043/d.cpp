#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
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
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            cout << i << ' ' << i + 1 << endl;
            return 0;
        }
        if (i - 2 >= 0 && s[i] == s[i - 2]) {
            cout << i - 1 << ' ' << i + 1 << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}