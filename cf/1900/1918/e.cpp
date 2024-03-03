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
const int N = 3 + 111;

mt19937 rnd(time(NULL));

int n, a[N];

int rand(int l, int r) {
    return rnd() % (r - l + 1) + l;
}

void quickSort(int l, int r) {
    if (l >= r) {
        return;
    }
    int pivot = a[rand(l, r)];
    int i = l, j = r;
    while (i < j) {
        while (i < j && a[i] <= pivot) {
            ++i;
        }
        while (i < j && a[j] >= pivot) {
            --j;
        }
        swap(a[i], a[j]);
    }
    quickSort(l, i - 1);
    quickSort(i + 1, r);
}

#if 0
5
2 1 5 3 1

pivot = 3
2 1 1 3 5

#endif

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    quickSort(1, n);
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    return 0;
}