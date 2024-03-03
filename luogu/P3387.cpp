#include <bits/stdc++.h>
using namespace std;

const int N = 3 + 1e4;

int n, m;
int a[N];
vector<int> edge[N];

int dfn[N], low[N], stk[N], ins[N], id, top;
int color[N]; // color[i] 表示i属于 scc color[i]的点

int num;
vector<int> newEdge[N]; // 新图
int weight[N], ww[N]; // weight表示新图的点权， ww是拓扑
int du[N];  // 新图的 入度数

void tarjan(int x) {
    stk[++top] = x;  // stack
    ins[x] = 1;      // in stack
    dfn[x] = ++id;
    low[x] = id;

    for (auto& y : edge[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (ins[y]) {
            low[x] = min(low[x], low[y]);
        }
    }
    if (dfn[x] == low[x]) {
        int y;
        ++num;
        do {
            y = stk[top--];
            ins[y] = 0;

            color[y] = num;
        } while (y != x);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }


    // 建图，缩点
    for (int x = 1; x <= n; ++x) {
        for (auto& y : edge[x]) {
            if (color[x] == color[y]) { 
                continue;
            }
            newEdge[color[x]].push_back(color[y]);
            ++du[color[y]];
        }
        weight[color[x]] += a[x];
    }

    queue<int> q;
    for (int i = 1; i <= num; ++i) {
        if (!du[i]) {
            q.push(i);
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();

        ww[x] += weight[x];

        for (auto& y : newEdge[x]) {
            --du[y];
            if (du[y] == 0) {
                q.push(y);
            }
            ww[y] = max(ww[y], ww[x]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= num; ++i) {
        ans = max(ans, ww[i]);
    }
    cout << ans << endl;

    return 0;
}