#include <bits/stdc++.h>
using namespace std;

const int N = 3 + 1e5;

struct Edge {
    int next, ver, flow, weight;
} edge[N];

int head[N], tot;
queue<int> q;
int n, m, a[N];
int d[N];
bool vis[N];
int pre[N];
int flow[N];
int s, t;
int maxFlow, cost;
int e[N];

void add(int u, int v, int w, int f) {
    ++tot;
    edge[tot] = {head[u], v, f, w};
    head[u] = tot;
    ++tot;
    edge[tot] = {head[v], u, 0, -w};
    head[v] = tot;
}

bool spfa() {
    for (int i = 1; i <= t; ++i) {
        d[i] = 1e9;
        vis[i] = false;
    }
    d[s] = 0;
    flow[s] = 1e9;
    while (q.size()) {
        q.pop();
    }
    q.push(s);
    while (q.size()) {
        int x = q.front();
        q.pop();
        vis[x] = false;
        for (int i = head[x]; i; i = edge[i].next) {
            int &y = edge[i].ver;
            if (!edge[i].flow) {
                continue;
            }
            if (d[y] > d[x] + edge[i].weight) {
                d[y] = d[x] + edge[i].weight;
                pre[y] = i;
                flow[y] = min(flow[x], edge[i].flow);
                if (!vis[y]) {
                    vis[y] = true;
                    q.push(y);
                }
            }
        }
    }
    return d[t] < 1e8;
}

void update() {
    int x = t;
    while (x != s) {
        int i = pre[x];
        edge[i].flow -= flow[t];
        edge[i ^ 1].flow += flow[t];
        x = edge[i ^ 1].ver;
    }
    maxFlow += flow[t];
    cost += flow[t] * d[t];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        s = 2 * (n + m) + 1;
        t = s + 1;
        for (int i = 1; i <= t; ++i) {
            head[i] = 0;
        }
        tot = 1;
        for (int i = 1; i <= n; ++i) {
            add(s, i, 0, 1e9);
            add(i, i + n, 0, a[i]);
            add(i, i + n, 1, 1e9);
        }
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            add(u + n, 2 * n + i, 0, 1);
            e[i] = tot;
            add(v + n, 2 * n + i, 0, 1);
            e[i] = tot;
            add(2 * n + i, 2 * n + m + i, 0, 1);
            add(2 * n + m + i, t, 0, 1e9);
        }
        maxFlow = 0;
        cost = 0;
        while (spfa()) {
            update();
        }
        cout << cost << endl;
        for (int i = 1; i <= m; ++i) {
            cout << (!edge[e[i]].flow);
        }
        cout << endl;
    }
    return 0;
}
