#include<iostream>
using namespace std;
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 1

int n, M[N][N];
int color[N], s[N], f[N], ts; 

void dfs_visit(int u) {
    int v;
    color[u] = GRAY;
    s[u] = ++ts;
    for (v=0; v<n; v++) {
        if(M[u][v]==0){
            continue;
        }
        if (color[v]==WHITE) {
            dfs_visit(v);
        }
    }
    color[u] = BLACK;
    f[u] = ++ts;
}

void dfs() {
    int u;
    for (u=0; u<n; u++) {
        color[u] = WHITE;
    }
    ts = 0;
    for (u=0; u<n; u++) {
        if (color[u]==WHITE){
            dfs_visit(u);
        }
    }
    for (u=0; u<n; u++) {
        printf("%d %d %d\n", u+1, s[u], f[u]);
    }
}

int main() {
    int u, k, tmp;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            M[i][j] = 0;
        }
    }

    for (int i=0; i<n; i++) {
        cin >> u >> k;
        for (int j=0; j<k; j++) {
            cin >> tmp;
            M[u-1][tmp-1] = 1;
        }
    }
    dfs();
    return 0;
}