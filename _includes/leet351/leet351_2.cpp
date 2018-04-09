class Solution {
public:    
    int numberOfPatterns(int m, int n) { 
        assert(m <= n);
        range = make_pair(m, n);
        
        // Initialize jump matrix
        jumps.resize(10, vector<int>(10, 0));
        jumps[1][3] = jumps[3][1] = 2;
        jumps[4][6] = jumps[6][4] = 5;
        jumps[7][9] = jumps[9][7] = 8;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[2][8] = jumps[8][2] = 5;
        jumps[3][9] = jumps[9][3] = 6;
        jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;

        // DP : Three subproblems
        // 1. count paths from corners - 1, 3, 7, 9
        // 2. count paths from boundary - 2, 4, 6, 8
        // 3. Count paths from center - 5
        
        int count = 0;
        
        // 1, 3, 7, 9
        count += 4 * numberOfPatternsFromNum(1, 1);
        
        // 2, 4, 6, 8
        count += 4 * numberOfPatternsFromNum(2, 1);
        
        // 5 
        count += numberOfPatternsFromNum(5, 1);
        
        return count;
    }

private:
    struct hashVal {
        size_t operator()(pair<int, int> val) const {
            return (hash<int>()(val.first) ^ hash<int>()(val.second));
        }
    };
    
    // Count number of path from num at level using backtracking
    int numberOfPatternsFromNum(int num, int level) { 
        // Number num visited at diffrent level will have diffrent visit flag status
        auto it = memo.find(make_pair(num, visited));
        
        if (it != memo.end()) {
            return it->second;
        }
        
         // Count of patterns
        int count = level >= range.first ? 1 : 0;
        
        if (level == range.second) {
            return count;
        }
        
        // Include in path
        setVisited(num);
        
        // 9 possible moves from current location
        for (int next = 1; next <= 9; ++next) {
            int jump = jumps[num][next];
            
            // Skip if visted or jump node if exists not visted
            if (isVisited(next) || (jump != 0 && !isVisited(jump))) {
                continue;
            }
     
            count += numberOfPatternsFromNum(next, level + 1);
        }
        
        // Remove from path
        clearVisited(num);
        
        // Insert in cache
        memo[make_pair(num, visited)] = count;
        
        return count;
    }
    
    // set - | with mask
    void setVisited(int num) {
        visited |= (1 << num);
    }
    
    // clear - & with ~mask
    void clearVisited(int num) {
        visited &= ~(1 << num);
    }
        
    // Check set
    bool isVisited(int num) {
        return visited & (1 << num);
    }
           
    // DP memo cache - <current num and visited nums> -> path count
    unordered_map<pair<int, int>, int, hashVal> memo;
    
    // Jump matrix - Prerequisit num for move from i -> j
    vector<vector<int>> jumps;
    
    // Path num count range
    pair<int, int> range;
    
    // Flag to mark visited num
    int visited;
};
