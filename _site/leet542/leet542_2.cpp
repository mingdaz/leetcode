
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& in) {
        int m = in.size();
        int n = in[0].size();

        queue<pair<int,int>> que;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(in[i][j] == 0)
                    que.push(pair<int,int>(i,j));
                else
                    in[i][j] = INT_MAX;
            }
        }
        int temp[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        pair<int,int> e;
        while(que.size() != 0)
        {
            e = que.front();
            que.pop();
            for(int i=0;i<4;i++)
            {
                int x = e.first + temp[i][0];
                int y = e.second + temp[i][1];
                if(x<0||x>=m||y<0||y>=n||in[x][y] <= in[e.first][e.second]+1)
                    continue;

                que.push(pair<int,int>(x,y));
                in[x][y] = in[e.first][e.second]+1;
            }
        }
        return in;

    }
};
