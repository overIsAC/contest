#include <bits/stdc++.h>
using namespace std;

const int N = 26;

int stk[N], top;
int n, m;
int vis[N];

void dfs(int step) {
    if (top == m) {
        for (int i = 1; i <= top; ++i) {
            cout << stk[i] << ' ';
        }
        cout << endl;
        return;
    }
    if (step == n + 1) {
        return;
    }
    stk[++top] = step;
    dfs(step + 1);
    --top;
    dfs(step + 1);
}

int main() {
    cin >> n >> m;
    dfs(1);
    return 0;
}