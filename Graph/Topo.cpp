int indeg[N];
// edge(u,v) ++indeg[v]
// DAG Graph
queue<int> Q;
for (int u = 1; u <= n; ++u) {
    if (indeg[u] == 0)
        Q.push(u);
}
vector<int> seq; // sequence
while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    seq.push_back(u); // นำใส่ topo-sort
    for (auto v : G[u]) {
        --indeg[v]; // ลด in-degree node อื่น ๆ
        if (indeg[v] == 0) // ถ้าเหลือ 0 ก็ใส่คิว
            Q.push(v);
    }
}
