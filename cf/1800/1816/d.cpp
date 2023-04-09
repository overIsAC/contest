#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];

int query(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    cin >> i;
    return i;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int v;
        cin >> n;
        cout << "+ " << n + 1 << endl;
        cin >> v;
        cout << "+ " << n + 2 << endl;
        cin >> v;
        int ps = 1, pt = 2;
        int dif = query(ps, pt);
        vector<vector<int>> a, b, c;
        for (int i = 3; i <= n; ++i) {
            int u = query(ps, i);
            int v = query(pt, i);
            if (u + v == dif) {
                b.push_back({i, u, v});
            } else if (u < v) {
                a.push_back({i, u, v});
            } else {
                c.push_back({i, u, v});
            }
        }
        sort(a.begin(), a.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] > b[1];
        });
        sort(b.begin(), b.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        sort(c.begin(), c.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        // cout << " ----------- a -----------" << endl;
        // for (auto &i : a) {
        //     cout << i[0] << ' ' << i[1] << ' ' << i[2] << endl;
        // }
        // cout << " ----------- b -----------" << endl;
        // for (auto &i : b) {
        //     cout << i[0] << ' ' << i[1] << ' ' << i[2] << endl;
        // }
        // cout << " ----------- c -----------" << endl;
        // for (auto &i : c) {
        //     cout << i[0] << ' ' << i[1] << ' ' << i[2] << endl;
        // }

        vector<int> ans;

        for (auto &i : a) {
            ans.push_back(i[0]);
        }
        ans.push_back(ps);
        for (auto &i : b) {
            ans.push_back(i[0]);
        }
        ans.push_back(pt);
        for (auto &i : c) {
            ans.push_back(i[0]);
        }

        cout << "!";
        for (auto &i : ans) {
            cout << ' ' << i;
        }
        reverse(ans.begin(), ans.end());
        for (auto &i : ans) {
            cout << ' ' << i;
        }
        cout << endl;
        cin >> v;
    }
    return 0;
}
// #1,4,2,5,3,6

/*
12312
6
5
2 3
3 2
4 1
1 4

9
1 1
3
5 2
4 1
1 2
2 1
1 4
2 5
3 6

*/