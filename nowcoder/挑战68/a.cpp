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

int f[N], p[N];
int t;

int isPrime(int n) {
    if (n < N) {
        return f[n] == 0;
    }
    for (int i = 1; p[i] * p[i] <= n; ++i) {
        if (n % p[i] == 0) {
            return 0;
        }
    }
    return n > 1;
}

int main() {
    f[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!f[i]) {
            p[++t] = i;
            for (int j = i + i; j < N; j += i) {
                f[j] = 1;
            }
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        if (n == 2) {
            cout << 2 << '\n';
            continue;
        }
        if (n == 3) {
            cout << 3 << '\n';
            continue;
        }
        if (n == 4) {
            cout << 4 << '\n';
            continue;
        }
        int m = n;
        while (!isPrime(m)) {
            --m;
        }
        cout << m << '\n';
    }
    return 0;
}
/*

10
1
2
3
4
5
6
7
8
9
12

*/