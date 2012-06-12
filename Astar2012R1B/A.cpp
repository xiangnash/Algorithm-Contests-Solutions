#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


typedef long long lint;

const int MAXN = 100009;

int n, b;
lint v[MAXN];

int gauss(int n, int m=34) {
    int l = 0, i, j;
    for(i = m-1; i >= 0; --i) {
        for(j = l; j < n; ++j) {
            if((v[j]>>i)&1)
                break;
        }
        if(j < n) {
            swap(v[l], v[j]);
            for(j = 0; j < n; ++j) {
                if(l != j && ((v[j]>>i) & 1)) {
                    v[j] ^= v[l];
                }
            }
            l++;
        }
    }
    return l;

}

lint get_v(lint k) {
    if(b < n) {
        if(k == 1) { 
            return 0;
        } else {
            k--;
        }
    }
    if((1LL<<b) <= k) {
        ;
    }
    else {
        lint ans = 0;
        for(int i = 0; i < b; ++i) {
            if((k>>i)&1) {
                ans ^= v[b-1-i];
            }
        }
        return ans;
    }
    return 0;
}

int main() 
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &v[i]);
    }
    b = gauss(n);
    lint k = 1LL<<b;
    if (k < n) k = n;
    if (n <= 2) --k;
    lint ans0 = get_v(k), ans1 = get_v(k-1);
    printf("%lld %lld\n", ans0, ans1);
    return 0;
}
