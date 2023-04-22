#include <bits/stdc++.h>
using namespace std;

const int N = 17;

int stk[N], top;
int n;

void dfs(int step) {
    if (step == n + 1) {
        for (int i = 1; i <= top; ++i) {
            cout << stk[i] << ' ';
        }
        cout << endl;
        return;
    }
    dfs(step + 1);
    stk[++top] = step;
    dfs(step + 1);
    --top;
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}