// backtracing
class Solution {
private:
    vector<string> results;    
    
    void backtrack(int index, int size, string& expression, long value, long result, const string& num, int target){
        if(index == num.size()){
            if(value + result == target){
                results.push_back(expression.substr(0, size));
            }
            return;
        }
        long current = 0;
        int op_position = size == 0 ? -1 : size++;   
           
        for(int i = index; i < num.size(); ++i){
            current *= 10;
            current += num[i] - '0';
            expression[size++] = num[i];
            
            if(op_position == -1){
                backtrack(i + 1, size, expression, current, 0, num, target);
            } else {
                expression[op_position] = '+';
                backtrack(i + 1, size, expression, current, result + value, num, target);
                
                expression[op_position] = '-';
                backtrack(i + 1, size, expression, -current, result + value, num, target);
                
                expression[op_position] = '*';
                backtrack(i + 1, size, expression, value * current, result, num, target);
            }
            if(current == 0){
                break;
            }
        }
    }
    
public:
    vector<string> addOperators(string num, int target) {
        string expression(num.size() * 2, '\0');

          backtrack(0, 0, expression, 0, 0, num, target);
          return results;
    }
};

// DFS solution
class Solution {
    void dfs(const string& num, string path, vector<string>& ret,
             int target, long long t, long long f, long long n, int idx) {
        if (idx == num.size()) {
            if (t + f * n == target)
                ret.push_back(path);
        }
        else {
            char c = num[idx++];
            string cs(1, c);
            int d = c - '0';
            dfs(num, path + "+" + cs, ret, target, t + f * n, 1, d, idx);
            dfs(num, path + "-" + cs, ret, target, t + f * n, -1, d, idx);
            dfs(num, path + "*" + cs, ret, target, t, f * n, d, idx);
            if (n)
                dfs(num, path + cs, ret, target, t, f, n * 10 + d, idx);
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        if (num.empty())
            return ret;
        dfs(num, string(1, num[0]), ret, target, 0, 1, num[0] - '0', 1);
        return ret;
    }
};