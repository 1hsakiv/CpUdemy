void bfs(int si , int sj , vector<vector<int>> &grid , vector<vector<int>> &visited){
    // bfs(si, sj, grid, visited);
    int n=10;
    int m=10;
    // n = no of vertex
    // m = no of edges
    queue<pair<int, int>> q;
    vector<vi> d(n, vi(m, 0));
    vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m, {0, 0}));

    q.push({si, sj});
    visited[si][sj] = true;
    p[si][sj] = {-1, -1};
    while (!q.empty())
    {
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newx = dx[i] + ci;
            int newy = dy[i] + cj;
            if (newx >= 0 && newy >= 0 && newx < grid.size() && newy < grid[0].size() && !visited[newx][newy] && grid[newx][newy] == 0)
            {
                visited[newx][newy] = true;
                q.push({newx, newy});
                d[newx][newy] = d[ci][cj] + 1;
                p[newx][newy] = {ci, cj};
            }
        }
    }

    // bfs ends here
}