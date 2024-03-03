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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;
    for (int i = n; i > m; --i) {
        if (i > x) continue;
        t -= d;
    }
    cout << t << endl;

    return 0;
}