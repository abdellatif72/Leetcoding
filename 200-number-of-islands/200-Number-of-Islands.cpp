class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const size_t& n = grid.size();
        const size_t& m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
        int dx[]{1,0,-1,0};
        int dy[]{0,1,0,-1};
        function<bool(int,int)> available = [&](int x, int y){
            return (x<n && x>=0 && y<m && y>=0 && !visited[x][y] && grid[x][y]=='1');
        };
        function<void(int,int)> dfs = [&](int x, int y){
            visited[x][y]=true;
            for(size_t i = 0; i < 4; i++){
                int nx = dx[i]+x;
                int ny = dy[i]+y;
                if(available(nx,ny)){
                    dfs(nx,ny);
                }
            }
        };
        for(size_t i = 0; i < n; i++){
            for(size_t j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(i,j); ans++;
                }
            }
        }
        return ans;
    }
};