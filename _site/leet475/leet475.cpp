class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int d,r=0,i=0,j=0;
        size_t m = houses.size();
        size_t n = heaters.size();
        while(i<m){
            if(houses[i]<heaters[j]) {
                if(j==0) {
                    r = max(r,heaters[j] - houses[i]);
                    while(i<n&&houses[i]<heaters[j])i++;
                    if(i==m) break;
                } 
                else{
                    while(i<m&&houses[i]<heaters[j]){
                        d = min(houses[i] - heaters[j-1], heaters[j] - houses[i]);
                        r = max(r,d);
                        i++;                        
                    }
                    if(i==m) break;    
                }
                
            }
            if(houses[i]>heaters[j]) {
                while(j<n&&houses[i]>heaters[j])j++;
                if(j==n) d  = houses[i] - heaters[j-1];
                else if(j==0) d =  heaters[j] - houses[i];
                else d = min(houses[i] - heaters[j-1],heaters[j] - houses[i]);
                r = max(r,d);
            }
            i++;
        }
        return r;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> houses = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> heaters = stringToIntegerVector(line);
        
        int ret = Solution().findRadius(houses, heaters);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
