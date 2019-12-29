/*
 * @lc app=leetcode id=721 lang=java
 *
 * [721] Accounts Merge
 *
 * https://leetcode.com/problems/accounts-merge/description/
 *
 * algorithms
 * Medium (44.32%)
 * Likes:    907
 * Dislikes: 233
 * Total Accepted:    53.7K
 * Total Submissions: 120.6K
 * Testcase Example:  '[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]'
 *
 * Given a list accounts, each element accounts[i] is a list of strings, where
 * the first element accounts[i][0] is a name, and the rest of the elements are
 * emails representing emails of the account.
 * 
 * Now, we would like to merge these accounts.  Two accounts definitely belong
 * to the same person if there is some email that is common to both accounts.
 * Note that even if two accounts have the same name, they may belong to
 * different people as people could have the same name.  A person can have any
 * number of accounts initially, but all of their accounts definitely have the
 * same name.
 * 
 * After merging the accounts, return the accounts in the following format: the
 * first element of each account is the name, and the rest of the elements are
 * emails in sorted order.  The accounts themselves can be returned in any
 * order.
 * 
 * Example 1:
 * 
 * Input: 
 * accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John",
 * "johnnybravo@mail.com"], ["John", "johnsmith@mail.com",
 * "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
 * Output: [["John", 'john00@mail.com', 'john_newyork@mail.com',
 * 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary",
 * "mary@mail.com"]]
 * Explanation: 
 * The first and third John's are the same person as they have the common email
 * "johnsmith@mail.com".
 * The second John and Mary are different people as none of their email
 * addresses are used by other accounts.
 * We could return these lists in any order, for example the answer [['Mary',
 * 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
 * ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']]
 * would still be accepted.
 * 
 * 
 * 
 * Note:
 * The length of accounts will be in the range [1, 1000].
 * The length of accounts[i] will be in the range [1, 10].
 * The length of accounts[i][j] will be in the range [1, 30].
 * 
 */

// @lc code=start
class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        // write your code here
        Map<String, Integer> email2id = new HashMap<>();
        int n = accounts.size();
        int[] f = new int[n]; 
        
        for(int i=0;i<n;i++){
            f[i] = i;
            List<String> a = accounts.get(i);
            String name = a.get(0);
            for(int j=1;j<a.size();j++){
                String email = a.get(j);
                if(email2id.containsKey(email)){
                    union(email2id.get(email),i,f); 
                } else {
                    email2id.put(email,i);
                }
            }
        }
        
        Map<Integer, TreeSet<String>> id2emailList = new HashMap<>(); 
        for(Map.Entry<String,Integer> entry: email2id.entrySet()){
            String email = entry.getKey();
            int id = entry.getValue();
            int pid = find(id,f);
            if(!id2emailList.containsKey(pid)){
                id2emailList.put(pid,new TreeSet());
            }
            id2emailList.get(pid).add(email);
        }
        List<List<String>> ret = new ArrayList<>();
        for(Map.Entry<Integer, TreeSet<String>> entry: id2emailList.entrySet()){
            int pid = entry.getKey();
            List<String> emails = new ArrayList<String>(entry.getValue());
            emails.add(0,accounts.get(pid).get(0));
            ret.add(emails);
        }    
        return ret;
    }
    
    private void union(int a, int b, int[] f){
        int pa = find(a,f);
        int pb = find(b,f);
        if(pa!=pb){
            f[pa] = pb;
        }
    }
    
    private int find(int a, int[] f){
        int pa,px,x = a;
        while(f[x]!=x){
            x = f[x];
        }
        pa = x;
        x = a;
        while(x!=pa){
            px = f[x];
            f[x] = pa;
            x = px;
        }
        return pa;
    }
}
// @lc code=end

