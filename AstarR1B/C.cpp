#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

class DisjointSet {
    int parent[MAXN];
public:
    void make_set(const int n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int get_set(const int a) {
        if (parent[a] != a) {
            parent[a] = get_set(parent[a]);
        }
        return parent[a];
    }

    bool union_set(const int a, const int b) {
        int as = get_set(a), bs = get_set(b);
        if (as != bs) {
            parent[as] = bs;
            return true;
        }
        return false;
    }
};

struct pos_t {
    double x, y, z;
};

struct dis_t {
    int i, j;
    double d;
};


bool d_cmp(const dis_t &a, const dis_t &b) {
    return a.d <= b.d;
}

inline double get_similarity(const pos_t &a, const pos_t &b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
}

int main()
{
    int N, K, D;
    scanf("%d %d", &N, &K);
    pos_t p[N];
    for (int i = 0; i < N; ++i) {
        scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
    }
    
    //get similarity
    double sim[N][N];
    dis_t dis[N*N/2];
    double low = get_similarity(p[0], p[1]), up = low;
    D = 0;
    for (int i = 0; i < N; ++i) {
        sim[i][i] = 0;
        for(int j = 0; j < i; ++j) {
            sim[i][j] = sim[j][i] = get_similarity(p[i], p[j]);
            low = min(low, sim[i][j]);
            up = max(up, sim[i][j]);
            dis[D].d = sim[i][j];
            dis[D].i = i, dis[D].j = j;
            ++D;
        }
    }
    
    //enumerate distance from up to low
    DisjointSet dset;
    sort(dis, dis+D, d_cmp);
    dset.make_set(N);
    int cnt = N;
    double ans = dis[0].d;
    for (int i = 0; i < D; ++i) { 
        if (cnt >= K) {
            ans = dis[i].d;
        }
        if (dset.union_set(dis[i].i, dis[i].j)) {
            --cnt;
        }
    }
    
    printf("%.6lf\n", ans);
    return 0;
}

