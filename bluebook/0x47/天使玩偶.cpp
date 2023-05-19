#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 3 + 1e6;

int n, m, x[N], y[N], o[N];
int p[N], q[N];
int ans[N];

int tr[N];

void cdq(int l, int r) {
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);

    {
        int u = l, v = mid + 1, w = l;
        while (u <= mid && v <= r) {
            if (x[p[u]] < x[p[v]]) {
                q[w++] = p[u++];
            } else {
                q[w++] = p[v++];
            }
        }
        while (u <= mid) {
            q[w++] = p[u++];
        }
        while (v <= r) {
            q[w++] = p[v++];
        }
        for (int i = l; i <= r; ++i) {
            p[i] = q[i];
        }
    }

    for (int i = l; i <= mid; ++i) {
        int id = p[i];
        if (o[id]) {
            for (int j = y[id] + 1; j <= 1e6 + 1; j += j & -j) {
                tr[j] = min(tr[j], -x[id] - y[id]);
            }
        }
    }
    for (int i = mid + 1; i <= r; ++i) {
        int id = p[i];
        if (!o[id]) {
            for (int j = y[id] + 1; j >= 1; j -= j & -j) {
                ans[id] = min(ans[id], x[id] + y[id] + tr[j]);
                cout << __LINE__ << ' ' << id << ' ' << ans[id] << endl;
            }
        }
    }
    for (int i = l; i <= mid; ++i) {
        int id = p[i];
        if (o[id]) {
            for (int j = y[id] + 1; j <= 1e6 + 1; j += j & -j) {
                tr[j] = 1e9;
            }
        }
    }

    for (int i = l; i <= mid; ++i) {
        int id = p[i];
        if (o[id]) {
            for (int j = y[id] + 1; j >= 1; j -= j & -j) {
                tr[j] = min(tr[j], -x[id] + y[id]);
            }
        }
    }
    for (int i = mid + 1; i <= r; ++i) {
        int id = p[i];
        if (!o[id]) {
            for (int j = y[id] + 1; j <= 1e6 + 1; j += j & -j) {
                ans[id] = min(ans[id], x[id] - y[id] + tr[j]);
                cout << __LINE__ << ' ' << x[id] - y[id] << ' ' << tr[j] << ' ' << o[id] << ' ' << id << ' ' << x[id] << ' ' << y[id] << ' ' << endl;
                cout << __LINE__ << ' ' << id << ' ' << ans[id] << endl;
            }
        }
    }
    for (int i = l; i <= mid; ++i) {
        int id = p[i];
        if (o[id]) {
            for (int j = y[id] + 1; j >= 1; j -= j & -j) {
                tr[j] = 1e9;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        o[i] = 1;
    }
    for (int i = n + 1; i <= n + m; ++i) {
        cin >> o[i] >> x[i] >> y[i];
        cout << x[i] - y[i] << endl;
        if (o[i] == 2) {
            o[i] = 0;
        }
    }
    for (int i = 1; i <= 1e6 + 1; ++i) {
        tr[i] = 1e9;
    }
    for (int i = 1; i <= n + m; ++i) {
        ans[i] = 1e9;
        p[i] = i;
    }

    cdq(1, n + m);
    // for (int i = 1; i <= n + m; ++i) {
    //     swap(x[i], y[i]);
    //     p[i] = i;
    // }
    // cdq(1, n + m);
    for (int i = 1; i <= n + m; ++i) {
        if (!o[i]) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}