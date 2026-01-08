class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int source = image[sr][sc];
        if(color == source){
            return image;
        }
        vector<vector<int>>dup = image;
        queue<pair<int,int>>q;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        q.push({sr,sc});
        dup[sr][sc] = color;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] == source && dup[nr][nc] == source){
                    q.push({nr,nc});
                    dup[nr][nc] = color;
                }
            }
        }
        return dup;
    }
};