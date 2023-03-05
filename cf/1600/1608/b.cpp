#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
const int N = 3 + 1e5;

int n, a, b;
int tr[N];

void add(int p, int v) {
    for (; p <= n; p += p & -p) {
        tr[p] += v;
    }
}

int ask(int p) {
    int ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        if (abs(a - b) > 1 || a + b > n - 2) {
            cout << -1 << endl;
        } else {
            int f = a > b ? 1 : 0;
            int i = 1, j = n;
            while (i <= j) {
                if (f) {
                    cout << i << ' ';
                    ++i;
                } else {
                    cout << j << ' ';
                    --j;
                }
                if (a || b) {
                    if (f)
                        --a;
                    else
                        --b;
                    f ^= 1;
                }
            }
            cout << endl;
        }
    }
    return 0;
}