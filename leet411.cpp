class Solution {
private:
    // Return the length of abbreviation given bit sequence.
    int getAddrevationLength(const int mask,  
                             const int target_size) {
        int max_bit_val = 1 << target_size;
        int count = target_size;
        for (int b = 3; b < max_bit_val; b <<= 1)
            if ((mask & b) == 0) {
                --count;
            }
        return count;
    }
    
     // DFS backtracking
    void dfs(const int bit, 
             const int mask, 
             const int target_size, 
             int &len_of_min_abbr, 
             const int cand, 
             int &min_abbr,  
             const vector<int> &bit_expressions_of_words) {
        
        int cur_abbre_len = getAddrevationLength(mask,  target_size);
        
        // If length of current abbreviation is longer, return.
        if (cur_abbre_len >= len_of_min_abbr) {
            return;
        }
        
        bool is_differentiable(true);
        for (auto d : bit_expressions_of_words) {
            if ((mask & d) == 0) { 
                // Can't distinguish abbreviations
                is_differentiable = false;
                break;
            }
        }
        
        if (is_differentiable) {
            len_of_min_abbr = cur_abbre_len;
            min_abbr = mask;
        } else {
            int max_bit_val = 1 << target_size;
            for (int b = bit; b < max_bit_val; b <<= 1) {
                if (cand & b) {
                    dfs(b << 1, mask + b, target_size, len_of_min_abbr, cand, min_abbr, bit_expressions_of_words);
                }
            }
        }
    }
    
    // Use bit expression to represents the same character of a word 
    // and target. Add the bit expression into bit_map.
    // Also generate the OR-value of all the bit expressions.
    void preprocessing(const vector<string>& dictionary,
                        const std::string &target,
                        vector<int> &bit_map,
                        int &cand) {
        const int target_size = target.size();
        // Preprocessing with bit manipulation
        for (auto w : dictionary) {
            
            // Ignore words with different length.
            // They will never have conflicted abbreviation with target.
            if (w.size() != target_size) continue; 
            
            int bit_expression = 0;
            // If character on index i is the same, set its bit to be 1.
            for (int i = target_size - 1, bit = 1; i >= 0; --i, bit <<= 1) {
                if (target[i] != w[i]) bit_expression += bit;
            }
            bit_map.push_back(bit_expression);
            cand |= bit_expression;
        }
    }
    
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        const int target_size = target.size();
        
        int cand = 0;
        vector<int> bit_map;
        preprocessing(dictionary, target, bit_map, cand);
        
        int min_abbr(0), len_of_min_abbr(INT_MAX);
        dfs(1, 0, target_size, len_of_min_abbr, cand, min_abbr, bit_map);

        string res("");
        // Reconstruct abbreviation from bit sequence
        for (int i = target_size - 1, pre = i; i >= 0; --i, min_abbr >>= 1) {
            if (min_abbr & 1) {
                if (pre - i > 0) res = to_string(pre-i) + res;
                pre = i - 1;
                res = target[i] + res;
            }
            else if (i == 0) res = to_string(pre-i+1) + res;
        }
        return res;
    }
};