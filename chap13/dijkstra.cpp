#include<iostream>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];

void dijkstra(int s) {
    int color[n], d[n], p[n];
    for (int i=0; i<n; i++) {
        color[i] = WHITE;
        d[i] = INFTY;
    }
    d[s] = 0;
    color[s] = GRAY;

    while (1) {
        int mincost = INFTY;
        int u = -1;
        for (int i=0; i<n; i++) {
            if (color[i]!=BLACK && d[i]<mincost) {
                mincost = d[i];
                u = i;
            }
        }

        if (mincost == INFTY) {
            break; // All nodes visited
        }

        color[u] = BLACK;
        for (int v=0; v<n; v++) {
            if (color[v]!=BLACK && M[u][v]<INFTY) {
                if (d[u]+M[u][v]<d[v]) {
                    d[v] = d[u]+M[u][v];
                    color[v] = GRAY;
                }
            }
        }
    }

    for (int i=0; i<n; i++) {
        cout << i << " " << d[i] << endl;
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            M[i][j] = INFTY;
        }
    }

    int u, k, v, c;
    for (int i=0; i<n; i++) {
        cin >> u >> k;
        for (int j=0; j<k; j++) {
            cin >> v >> c;
            M[u][v] = c;
        }
    }
 
    dijkstra(0);
    return 0;
}