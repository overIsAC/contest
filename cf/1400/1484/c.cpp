#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
using namespace std;

void h(int *a, int p, int q, int r) {  // merge two sorted subarrays.
    int n1 = q - p + 1, n2 = r - q;
    int *a1 = (int *)malloc(sizeof(int) * (n1 + 1));
    int *a2 = (int *)malloc(sizeof(int) * (n2 + 1));
    for (int i = 0; i < n1; i++) a1[i] = a[p + i];
    for (int i = 0; i < n2; i++) a2[i] = a[q + i + 1];  // copy the left and the right parts into a new array.
    a1[n1] = a2[n2] = 1e9;
    int t1 = 0, t2 = 0;
    for (int i = p; i <= r; i++) {
        if (a1[t1] <= a2[t2])
            a[i] = a1[t1++];
        else
            a[i] = a2[t2++];
    }
    free(a1);
    free(a2);
}
void s(int *a, int l, int r) {  // sort an array.
    if (l < r - 1) {
        int q = (l + r) / 2;
        s(a, l, q);
        s(a, q + 1, r);
        h(a, l, q, r);
    } else {
        int t = max(a[l], a[r]);
        a[l] = a[l] + a[r] - t, a[r] = t;
        return;
    }
}
int main() {
    int m;
    cin >> m;
    int *a = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) cin >> a[i];
    s(a, 0, m - 1);
    for (int i = 0; i < m; i++) cout << a[i] << " ";
    return 0;
}