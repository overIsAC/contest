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

int isLeap(int y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

int main() {
    int x;
    cin >> x;
    int sum = 0;
    int flag = isLeap(x);
    do {
        ++x;
        sum += 365;
        sum += isLeap(x);
    } while (sum % 7 || isLeap(x) != flag);
    cout << x << endl;
    return 0;
}