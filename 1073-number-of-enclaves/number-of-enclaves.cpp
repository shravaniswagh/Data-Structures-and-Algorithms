class Solution {
public:
    void dfs(int i, int j , vector<vector<int>>&vis, vector<vector<int>>&board,int dr[],int dc[]){
        vis[i][j] =1;
        int n = board.size();
        int m = board[0].size();
        for(int k=0;k<4;k++){
            int nr = i+dr[k];
            int nc = j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc] == 1){
                dfs(nr,nc,vis,board,dr,dc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        if(n ==0 || m == 0) return 0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int count = 0;
        vector<vector<int>>vis(n,vector<int>(m));
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]==1) dfs(0,j,vis,board,dr,dc);
            if(!vis[n-1][j] && board[n-1][j] == 1) dfs(n-1,j,vis,board,dr,dc);
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]==1) dfs(i,0,vis,board,dr,dc);
            if(!vis[i][m-1] && board[i][m-1] == 1) dfs(i,m-1,vis,board,dr,dc);
        }
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 1) count++;
            }
        }
        return count;

    }
};