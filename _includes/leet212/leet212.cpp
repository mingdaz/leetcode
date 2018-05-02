class Solution {
struct TrieNode{
    bool leaf;
    bool find;
    TrieNode* children[26];
    TrieNode(){
        leaf = false;
        find = false;
        memset(children, 0, sizeof(TrieNode*)*26);
    }
};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(int i=0;i<words.size();i++){
            TrieNode* cur = root;
            for(int j=0;j<words[i].size();j++){
                int key = words[i][j] - 'a';
                if(cur->children[key]==NULL){
                    cur->children[key] = new TrieNode();
                }
                cur = cur->children[key];
            }
            cur->leaf = true;
        }
        int m = board.size();
        int n = board[0].size();
        vector<string> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                string path;
                backtracking(res,board,path,i,j,root,m,n);
            }
        }
        return res;
    }
private:
    void backtracking(vector<string>& res, vector<vector<char>>& board, string& path,int i,int j, TrieNode* root, const int m, const int n){
        if(root==NULL||board[i][j]=='$') return;
        char tmp = board[i][j];
        int key = tmp - 'a';
        board[i][j] = '$';
        path.push_back(tmp);
        root = root->children[key];
        if(root!=NULL&&root->leaf&&!root->find){
            root->find = true;
            res.push_back(path);
        }
        if(i>0)
            backtracking(res,board,path,i-1,j,root,m,n);
        if(i+1<m)
            backtracking(res,board,path,i+1,j,root,m,n);
        if(j>0)
            backtracking(res,board,path,i,j-1,root,m,n);
        if(j+1<n)
            backtracking(res,board,path,i,j+1,root,m,n);
        path.pop_back();        
        board[i][j] = tmp;
    }
    TrieNode* root = new TrieNode();    
};