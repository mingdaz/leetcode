class Solution {
public:
    string countOfAtoms(string formula) {
        int i=0;
        map<string,int> tmp = helper(formula,i);
        string ret="";
        for(auto it = tmp.begin();it!=tmp.end();++it){
            ret.append(it->first+(it->second==1?"":to_string(it->second)));
        }
        return ret;
    }
    map<string,int> helper(string& formula, int& idx){
        map<string,int> ret;
        while(idx<formula.size()){
            if(formula[idx]==')') break;
            if(formula[idx]=='('){
                idx++;
                map<string,int> tmp = helper(formula,idx);
                int times = 0;
                while(isdigit(formula[idx])) {
                    times = times*10 + formula[idx] - '0';
                    idx++;
                }
                if(times==0) times = 1;
                for(auto it = tmp.begin();it!=tmp.end();++it){
                    ret[it->first] += it->second*times;
                }
            }
            if(isupper(formula[idx])){
                string ele = string(1,formula[idx]);
                idx++;
                if(islower(formula[idx])){
                    ele.push_back(formula[idx]);
                    idx++;
                }
                int times = 0;    
                if(isdigit(formula[idx])){
                    while(isdigit(formula[idx])) {
                        times = times*10 + formula[idx] - '0';
                        idx++;
                    }
                }
                if(times==0) times = 1;
                ret[ele] += times;
            }
        }
        idx++;
        return ret;
    }
};