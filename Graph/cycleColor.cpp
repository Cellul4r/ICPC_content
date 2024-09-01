int color[N]; // เริ่มมาเป็น 0 หมด
bool dfs(int u) {
    if (color[u] == 1) // เจอ cycle
        return true;
    if (color[u] == 2) // เจอ node ที่เคยผ่านในรอบอื่นแล้ว
        return false;
    color[u] = 1; // ตอนเริ่มทำ เซตเป็นสีเทา
    for (auto v : G[u]) {
        if (dfs(v)) // ถ้า dfs แล้วเจอ cycle ก็ return true เลย
            return true;
    }
    color[u] = 2; // พอทำเสร็จแล้วก็เซตเป็นสีดำ
}
