void dfs(int x,int y,vector<vector<int>> &grid , vector<vector<int>> &visited){
    visited[x][y] = 1;
    for(int i=0;i<4;i++){
        int newx = dx[i] + x;
        int newy = dy[i] + y;
        if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && !visited[newx][newy] && grid[newx][newy]==0){
            dfs(newx,newy,grid,visited);
        }
    }
}