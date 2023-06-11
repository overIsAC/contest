#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 3 + 1e5;

int n, m;

map<int, LL> need[N];
map<int, vector<int>> ned;
vector<PII> bonus[N];
map<int, LL> source;
vector<int> ve;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        source[a] += b;
    }

    cin >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b, k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            cin >> a >> b;
            if (source[a] >= b) {
                continue;
            }
            need[i][a] += b;
            ned[a].push_back(i);
        }
        if (need[i].empty()) {
            ve.push_back(i);
        }
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            cin >> a >> b;
            bonus[i].push_back({a, b});
        }
    }
    for (auto &[x, y] : ned) {
        sort(y.begin(), y.end(), [&](int &a, int &b) {
            return need[a][x] > need[b][x];
        });
    }

    int ans = 0;

    while (ve.size()) {
        int x = ve.back();
        ve.pop_back();
        ++ans;
        for (auto &i : bonus[x]) {
            // i.first 获得的种类，i.second 获得的数量
            auto &now = source[i.first];
            now += i.second;
             if (ned.count(i.first)) {
                auto &seq = ned[i.first];
                while (seq.size()) {
                    int num = seq.back();
                    if (need[num][i.first] <= now) {
                        seq.pop_back();
                        need[num].erase(i.first);
                        if (need[num].empty()) {
                            ve.push_back(num);
                        }
                    } else {
                        break;
                    }
                }
                if (seq.empty()) {
                    ned.erase(i.first);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}