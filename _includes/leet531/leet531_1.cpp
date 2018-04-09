class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        if(!m) return 0;
        int n = picture[0].size();
        vector<int> row(m,0);
        vector<int> col(n,0);
        vector<int> x(m,-1);
        vector<int> y(n,-1);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(picture[i][j]=='B') {
                    row[i]++;
                    col[j]++;
                    x[i] = j;
                    y[j] = i;
                }
            }
        }
        int cnt = 0;
        if(m<=n){
            for(int i=0;i<m;i++){
                if(row[i]==1&&col[x[i]]==1)
                    cnt++;
            }
        }
        else{
            for(int j=0;j<n;j++){
                if(col[j]==1&&row[y[j]]==1)
                    cnt++;          
            }
        }
        return cnt;
    }
};
