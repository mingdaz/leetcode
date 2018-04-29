class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string finalState = "123450";
        
        string init = getState(board);
        queue<string> q;
        q.push(init);
        
        int moves = 0;
        unordered_set<string> visited;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                string state = q.front();
                q.pop();
                if(state == finalState)
                    return moves;
                visited.insert(state);
                getNextStates(state, visited, q);
            }
            moves++;
        }
        return -1;
    }
    
private:
    string getState(vector<vector<int> >& board) {
        string state;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                state += to_string(board[i][j]);
            }
        }
        return state;
    }
    
    void getNextStates(string state, unordered_set<string>& visited, queue<string>& q) {
        int pos = state.find('0');
        int x = pos/3;
        int y = pos%3;
        int ex[] = {-1, 1, 0, 0};
        int ey[] = {0, 0, -1, 1};
        for(int k = 0; k < 4; k++)
        {
            int nx = x + ex[k];
            int ny = y + ey[k];
            if(nx < 0 || ny < 0 || nx >= 2 || ny >= 3)
                continue;
            int idx = nx*3 + ny;
            char tmp = state[idx];
            state[idx] = '0';
            state[pos] = tmp;
            if(visited.find(state) == visited.end())
            {
                visited.insert(state);
                q.push(state);
            }
            state[idx] = tmp;
            state[pos] = '0';
            
        }
    }
};