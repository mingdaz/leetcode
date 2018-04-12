class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        // mySet keeps the valid path
        unordered_set<string> mySet(wordList.begin(),wordList.end());
        if (mySet.find(endWord)==mySet.end()) return result;
        queue<vector<string>> myQ;
        myQ.push(vector<string>(1,beginWord));
        while (!myQ.empty())
        {
            int sz=myQ.size();
            unordered_set<string> cur;
            for (int i=0;i<sz;i++)
            {
                // handle each vector of string in myQ
                vector<string> vec=myQ.front();
                string lst=vec.back();
                myQ.pop();
                // first look at if we already can get to endWord
                if (dist(lst,endWord)==1)
                {
                    vec.push_back(endWord);
                    result.push_back(vec);
                    continue;
                }
                if (!result.empty()) continue;
                // if not, loop through each string in mySet and try to append to vec
                for (int j=0;j<beginWord.size();j++)
                {
                    string cp=lst;
                    for (char c='a';c<='z';c++)
                    {
                        if (c!=lst[j]) 
                        {
                            cp[j]=c;
                            if (mySet.find(cp)!=mySet.end())
                            {
                                // append s to vec, and add to myQ, then record s in cur
                                vec.push_back(cp);
                                myQ.push(vec);
                                vec.pop_back();
                                cur.insert(cp);
                            }
                        }
                    }
                }
                
            }
            
            // if there are already results in result, we break
            if (!result.empty()) break;
            // delete those appended in this iteration, since we want shortest path
            for (auto s:cur) mySet.erase(s);
        }
        return result;
    }
    int dist(const string& s1, const string& s2)
    {
        int dis=0,s=s1.size();
        for (int i=0;i<s;i++)
        {
            dis+=(s1[i]!=s2[i]);
        }
        return dis;
    }
};