class Solution {
public:
    int a, b;
    bool visited[305][305];
    vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool Valid(int i, int j) {
        if(i < 0 || i >= a || j < 0 || j >= b){
            return false;
        }
        else{
            return true;
        }
    }
    
    void dfs(int si, int sj, vector<vector<char>>& grid){
        visited[si][sj] = true;
        
        for(int i=0;i<4;i++){
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if(Valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '1'){
                dfs(ci, cj, grid); 
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        a = grid.size();
        b = grid[0].size();
        int cnt = 0;
        memset(visited, false, sizeof(visited));
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};