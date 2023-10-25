#include <bits/stdc++.h>
using namespace std;

const int N = 103;

int t, n, m;
int a[N][N];
int num[N];
int ans;
int d[N];

void dfs1(int day, int money);
void dfs2(int day, int money, int p);

void dfs1(int day, int money) {
    // cout << __func__ << ' ' << day << ' ' << money << endl;
    int temp[N];
    memcpy(temp, num, sizeof(num));
    int oldMoney = money;
    for (int i = 1; i <= n; ++i) {
        money += a[day][i] * num[i];
        num[i] = 0;
    }

    if (d[day] >= money) {
        memcpy(num, temp, sizeof(num));
        money = oldMoney;
        return;
    }
    d[day] = money;

    if (day == t) {
        ans = max(ans, money);
        memcpy(num, temp, sizeof(num));
        money = oldMoney;
        return;
    }
    dfs2(day, money, 1);
    memcpy(num, temp, sizeof(num));
    money = oldMoney;
}

void dfs2(int day, int money, int p) {
    // cout << __func__ << ' ' << day << ' ' << money << ' ' << p << endl;
    if (p == n + 1) {
        dfs1(day + 1, money);
        return;
    }
    dfs2(day, money, p + 1);
    int oldMoney = money;
    while (money >= a[day][p]) {
        ++num[p];
        money -= a[day][p];
        dfs2(day, money, p + 1);
    }
    num[p] = 0;
    money = oldMoney;
}

int main() {
    cin >> t >> n >> m;
    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    dfs1(1, m);
    cout << ans << endl;
    return 0;
}