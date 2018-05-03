class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<int,unordered_set<char>> dict;
        for(int i=0;i<allowed.size();i++){
            dict[(allowed[i][0]-'A')*7+(allowed[i][1]-'A')].insert(allowed[i][2]);
        }
        return helper(bottom,dict);
    }
private:
    void generate_next(vector<string>& res,string& bottom, string& path, unordered_map<int,unordered_set<char>>& dict){
        if(path.size()+1==bottom.size()){
            res.push_back(path);
            return;
        } 
        int i= path.size();
        int key = 7*(bottom[i] - 'A')+(bottom[i+1]-'A');
        if(dict.count(key)==0) return;
        for(char c: dict[key]){
            path.push_back(c);
            generate_next(res,bottom,path,dict);
            path.pop_back();
        }        
    }
    bool helper(string& bottom, unordered_map<int,unordered_set<char>>& dict){
        // std::cout<<bottom<<endl;
        if(bottom.size()==1) return true;
        vector<string> next;
        string path = "";
        generate_next(next,bottom,path,dict);
        for(int i=0;i<next.size();i++){
            if(helper(next[i],dict))
                return true;
        }
        return false;
        
    }    
};