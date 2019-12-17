/*
 * @lc app=leetcode id=267 lang=java
 *
 * [267] Palindrome Permutation II
 *
 * https://leetcode.com/problems/palindrome-permutation-ii/description/
 *
 * algorithms
 * Medium (34.91%)
 * Likes:    325
 * Dislikes: 42
 * Total Accepted:    31.3K
 * Total Submissions: 89.7K
 * Testcase Example:  '"aabb"'
 *
 * Given a string s, return all the palindromic permutations (without
 * duplicates) of it. Return an empty list if no palindromic permutation could
 * be form.
 * 
 * Example 1:
 * 
 * 
 * Input: "aabb"
 * Output: ["abba", "baab"]
 * 
 * Example 2:
 * 
 * 
 * Input: "abc"
 * Output: []
 * 
 */

// @lc code=start
class Solution {
    public List<String> generatePalindromes(String s) {
        Set<String> res = new HashSet<>();
        int[] charCnt = new int[128];
        if(!canPalindrome(charCnt,s)){
            return new ArrayList<>();
        }
        char[] st = new char[s.length()/2];
        char center = 0;
        int k = 0;
        for(int i=0;i<128;i++){
            if(charCnt[i]%2==1){
                center = (char)i;    
            } 
            for(int j=0;j<charCnt[i]/2;j++){  
                st[k++] = (char)i;
            }
        }
        permutation(res,st,center,0);
        return new ArrayList<String>(res);
    }
    
    private boolean canPalindrome(int[] charCnt, String s){
        for(int i=0;i<s.length();i++){
            charCnt[s.charAt(i)]++;
        }
        boolean hasOdd = false;
        for(int i=0;i<128;i++){
            if(charCnt[i]%2==1){
                if(hasOdd)
                    return false;
                else
                    hasOdd=true;
            }
        }
        return true;
    }
    
    private void permutation(Set<String> res, char[] st, char center, int index){
        if(index==st.length){
            res.add(
                new String(st) + (center==0?"": center) + new StringBuffer(new String(st)).reverse());
            return;
        }
        for(int i=index;i<st.length;i++){
            if(st[i]!=st[index]||i==index){
            swap(st,index,i);
            permutation(res,st,center,index+1);
            swap(st,index,i);
            }
        }
        
    }
    
    private void swap(char[] st, int i, int j){
        char tmp = st[i];
        st[i] = st[j];
        st[j] = tmp;
    }
}
// @lc code=end

