#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 1e5;

int tr[N], n, q;

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
    cin >> n >> q;
    for (int i = 1; i <= q; ++i) {
        char op;
        int a, b;
        cin >> op >> a;
        if (op == '-') {
            add(a, 1);
        } else if (op == '+') {
            add(a, -1);
        } else {
            cin >> b;
            bool flag = true;
            if (a > b) {
                swap(a, b);
            }
            if (ask(b) - ask(a - 1) == 0) {
                flag = false;
            }
            if (ask(a) == 0 && ask(n) - ask(b - 1) == 0) {
                flag = false;
            }
            if (flag) {
                cout << "impossible" << endl;
            } else {
                cout << "possible" << endl;
            }
        }
    }
    return 0;
}