#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct pre_t {
    int x, y;
    int w0, w1;
};

int main()
{
    int n;
    scanf("%d", &n);
    pre_t p[n+1];
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    int k[2], A[2], B[2];
    for (int i = 0; i < 2; ++i) {
        scanf("%d %d %d", &k[i], &A[i], &B[i]);
    }
    for (int i = 1; i <= n; ++i) {
        p[i].w0 = A[0] * p[i].x + B[0] * p[i].y;
        p[i].w1 = A[1] * p[i].x + B[1] * p[i].y;
    }
    
    int f[n+1][n+1];
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        int ui = min(i, k[0]);
        if (i <= k[1]) {
            f[i][0] = f[i-1][0] + p[i].w1;
        }
        for (int j = 1; j <= ui; ++j) {
            int j1 = i-j;
            if (j1 > k[1]) continue;
            if (j < i) {
                f[i][j] = max(f[i-1][j] + p[i].w1,
                        f[i-1][j-1] + p[i].w0);
            } else {
                f[i][j] = f[i-1][j-1] + p[i].w0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k[0]; ++i) {
        int j = n-i;
        if (j > k[1]) continue;
        ans = max(ans, f[n][i]);
    }
    printf("%d\n", ans);
    return 0;
}

