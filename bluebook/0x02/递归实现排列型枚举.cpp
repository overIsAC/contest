#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int stk[N];
int n;
int vis[N];

void dfs(int step) {
    if (step == n + 1) {
        for (int i = 1; i <= n; ++i) {
            cout << stk[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            continue;
        }
        vis[i] = 1;
        stk[step] = i;
        dfs(step + 1);
        vis[i] = 0;
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}