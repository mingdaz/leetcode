/*
 * @lc app=leetcode id=28 lang=java
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (33.36%)
 * Likes:    1162
 * Dislikes: 1593
 * Total Accepted:    538.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */

// @lc code=start
// Rabin Warp Rolling Hashing
class Solution {
    // function to convert character to integer
    public int charToInt(int idx, String s) {
      return (int)s.charAt(idx) - (int)'a';
    }
  
    public int strStr(String haystack, String needle) {
      int L = needle.length(), n = haystack.length();
      if (L > n) return -1;
  
      // base value for the rolling hash function
      int a = 26;
      // modulus value for the rolling hash function to avoid overflow
      long modulus = (long)Math.pow(2, 31);
  
      // compute the hash of strings haystack[:L], needle[:L]
      long h = 0, ref_h = 0;
      for (int i = 0; i < L; ++i) {
        h = (h * a + charToInt(i, haystack)) % modulus;
        ref_h = (ref_h * a + charToInt(i, needle)) % modulus;
      }
      if (h == ref_h) return 0;
  
      // const value to be used often : a**L % modulus
      long aL = 1;
      for (int i = 1; i <= L; ++i) aL = (aL * a) % modulus;
  
      for (int start = 1; start < n - L + 1; ++start) {
        // compute rolling hash in O(1) time
        h = (h * a - charToInt(start - 1, haystack) * aL
                + charToInt(start + L - 1, haystack)) % modulus;
        if (h == ref_h) return start;
      }
      return -1;
    }
}

// KMP
class Solution {
  public int strStr(String haystack, String needle) {
      int n = needle.length();
      int m = haystack.length();
      if(n>m) return -1;
      if(n==0) return 0;
      int[] p = new int[n+1];
      int k = 0;
      int i;
      p[0] = -1;
      for(i=1;i<n;i++){
          if(needle.charAt(k)==needle.charAt(i)) 
              p[i] = p[k];
          else{
              p[i] = k;
              k = p[k];
              while(k>=0 && needle.charAt(k) != needle.charAt(i))
                  k = p[k];
          }
          k++;
      }
      p[i] = k; 
      
      k = 0;
      i = 0;
      while(i<m){
          if(needle.charAt(k)==haystack.charAt(i)){
              i++;
              k++;
              if(k==n)
                  return i-n;
          } else{
              k = p[k];
              if(k<0){
                  i++;
                  k++;
              }
          }
      }
      return -1;
  }
}

// @lc code=end

