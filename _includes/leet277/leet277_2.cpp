// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> indegree(n,0);
        vector<int> outdegree(n,0);
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(i==j) continue;
               if(knows(i,j)){
                   outdegree[i]++;
                   indegree[j]++;
               }
           }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==n-1&&outdegree[i]==0)
                return i;
        }
        return -1;
    }
};