class Solution {
public:
    bool dfs(int index ,int i, int j , vector<vector<char>>&board, string word){
        int n = board.size();
        int m = board[0].size();
        int size = word.size();
        if(index == size) return true;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j] != word[index]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool found= dfs(index+1, i-1, j, board, word) ||
                    dfs(index+1, i+1, j, board, word) ||
                    dfs(index+1, i, j-1, board, word) ||
                    dfs(index+1, i, j+1, board, word);
        board[i][j] = temp;
        return found;            
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int first = word[0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == first){
                    if(dfs(0,i,j,board,word)) return true;
                }
            }
        }
        return false;
    }
};