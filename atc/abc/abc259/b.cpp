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
const double pi = acos(-1);
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int a, b, d;
    cin >> a >> b >> d;
    cout << fixed << setprecision(9)
         << a * cos(d * pi / 180) - b * sin(d * pi / 180) << ' '
         << a * sin(d * pi / 180) + b * cos(d * pi / 180) << endl;
    return 0;
}