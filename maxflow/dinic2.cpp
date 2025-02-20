#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int v, cap, flow, rev;
};

class MaxFlow {
public:
    int n;  
    vector<vector<Edge>> adj;
    vector<int> level, ptr;

    MaxFlow(int n) : n(n), adj(n), level(n), ptr(n) {}

    void addEdge(int u, int v, int cap) {
        adj[u].push_back({v, cap, 0, (int)adj[v].size()});
        adj[v].push_back({u, 0, 0, (int)adj[u].size() - 1});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : adj[u]) {
                if (level[e.v] == -1 && e.flow < e.cap) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int u, int t, int pushed) {
        if (u == t) return pushed;
        for (int &cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            Edge &e = adj[u][cid];
            if (level[e.v] == level[u] + 1 && e.flow < e.cap) {
                int tr = dfs(e.v, t, min(pushed, e.cap - e.flow));
                if (tr > 0) {
                    e.flow += tr;
                    adj[e.v][e.rev].flow -= tr;
                    return tr;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, t, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
};
