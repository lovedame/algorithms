#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long INF = 8765432187654321;

struct edge {
    int u, v;
    int w;
    bool operator < (const edge &e2) const {
        return w < e2.w;
    }
};

class FloydWarshall {

private:
    int V;
    int E;
    vector<edge> edges;
    long long **d;
    vector<vector<int>> path;

public:
    // time complexity: O(theta(N^3)).
    FloydWarshall(int v, int e, vector<edge> &es) {

        V = v;
        E = e;
        edges = es;
        d = new long long*[V+1];
        for(int i=0; i<V+1; i++)
            d[i] = new long long[V+1];
        // TODO
        vector<vector<int>> path;
    }

    void solve() {

        for(int i=0; i<V+1; i++)
            for(int j=0; j<V+1; j++)
                d[i][j] = (i==j)? 0:INF;

        for(int i=0; i<E; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            d[u][v] = min(d[u][v], (long long)edges[i].w);
        }

        for(int k=1; k<V+1; k++)
            for(int i=1; i<V+1; i++)
                for(int j=1; j<V+1; j++)
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    }

    long long min_distance(int a, int b) {

        return d[a][b];
    }
};