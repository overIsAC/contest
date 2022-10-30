#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];
int b[N];

int query(int x, int y, int z) {
    cout << "? " << x << ' ' << y << ' ' << z << endl;
    cin >> x;
    return x;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int p1 = 0, p2 = 0;
        for (int i = 0; i < n / 3; ++i) {
            a[i] = query(3 * i + 1, 3 * i + 2, 3 * i + 3);
            if (a[i])
                p1 = i;
            else
                p2 = i;
        }
        // n/3
        int c[3] = {0};
        c[0] = query(p1 * 3 + 1, p1 * 3 + 2, p2 * 3 + 1);
        c[1] = query(p1 * 3 + 1, p1 * 3 + 2, p2 * 3 + 2);
        c[2] = query(p1 * 3 + 1, p1 * 3 + 2, p2 * 3 + 3);
        int w1, w2;
        if (c[0] && c[1] && c[2]) {
            b[p1 * 3 + 1] = 1;
            b[p1 * 3 + 2] = 1;

            c[0] = query(p1 * 3 + 1, p2 * 3 + 1, p2 * 3 + 2);
            c[1] = query(p1 * 3 + 1, p2 * 3 + 1, p2 * 3 + 3);
            c[2] = query(p1 * 3 + 1, p2 * 3 + 2, p2 * 3 + 3);

            if (c[0] == 0 && c[1] == 0 && c[2] == 0) {
                b[p2 * 3 + 1] = 0;
                b[p2 * 3 + 2] = 0;
                b[p2 * 3 + 3] = 0;
                w2 = p2 * 3 + 3;
            } else {
                if (c[0] == 0) {
                    b[p2 * 3 + 1] = 0;
                    b[p2 * 3 + 2] = 0;
                    b[p2 * 3 + 3] = 1;
                    w2 = p2 * 3 + 1;
                } else if (c[1] == 0) {
                    b[p2 * 3 + 1] = 0;
                    b[p2 * 3 + 2] = 1;
                    b[p2 * 3 + 3] = 0;
                    w2 = p2 * 3 + 3;
                } else {
                    b[p2 * 3 + 1] = 1;
                    b[p2 * 3 + 2] = 0;
                    b[p2 * 3 + 3] = 0;
                    w2 = p2 * 3 + 3;
                }
            }

            b[p1 * 3 + 3] = query(p1 * 3 + 1, w2, p1 * 3 + 3);

            w1 = p1 * 3 + 1;
        } else {
            b[p1 * 3 + 3] = 1;
            b[p2 * 3 + 1] = c[0];
            b[p2 * 3 + 2] = c[1];
            b[p2 * 3 + 3] = c[2];
            for (int i = 1; i <= 3; ++i) {
                if (b[p2 * 3 + i] == 0) {
                    b[p1 * 3 + 1] = query(p1 * 3 + 1, p1 * 3 + 3, p2 * 3 + i);
                    break;
                }
            }
            b[p1 * 3 + 2] = 1 - b[p1 * 3 + 1];

            w1 = p1 * 3 + 1;
            w2 = p1 * 3 + 2;
            if (b[p1 * 3 + 1] == 0) swap(w1, w2);
        }

        // (n - 6)
        for (int i = 0; i < n / 3; ++i) {
            if (i == p1 || i == p2) continue;
            if (a[i] == 1) {
                c[0] = query(w2, i * 3 + 1, i * 3 + 2);
                c[1] = query(w2, i * 3 + 2, i * 3 + 3);
                if (c[0] && c[1]) {
                    b[i * 3 + 1] = 1;
                    b[i * 3 + 2] = 1;
                    b[i * 3 + 3] = 1;
                } else if (c[0] == 0 && c[1] == 0) {
                    b[i * 3 + 1] = 1;
                    b[i * 3 + 2] = 0;
                    b[i * 3 + 3] = 1;
                } else if (c[0] == 0) {
                    b[i * 3 + 1] = 0;
                    b[i * 3 + 2] = 1;
                    b[i * 3 + 3] = 1;
                } else {
                    b[i * 3 + 1] = 1;
                    b[i * 3 + 2] = 1;
                    b[i * 3 + 3] = 0;
                }
            } else {
                c[0] = query(w1, i * 3 + 1, i * 3 + 2);
                c[1] = query(w1, i * 3 + 2, i * 3 + 3);
                if (!c[0] && !c[1]) {
                    b[i * 3 + 1] = 0;
                    b[i * 3 + 2] = 0;
                    b[i * 3 + 3] = 0;
                } else if (c[0] == 1 && c[1] == 1) {
                    b[i * 3 + 1] = 0;
                    b[i * 3 + 2] = 1;
                    b[i * 3 + 3] = 0;
                } else if (c[0] == 1) {
                    b[i * 3 + 1] = 1;
                    b[i * 3 + 2] = 0;
                    b[i * 3 + 3] = 0;
                } else {
                    b[i * 3 + 1] = 0;
                    b[i * 3 + 2] = 0;
                    b[i * 3 + 3] = 1;
                }
            }
        }
        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            if (b[i] == 0) ans.push_back(i);
        }
        cout << "! " << ans.size();
        for (int &i : ans) {
            cout << ' ' << i;
        }
        cout << endl;
    }
    return 0;
}