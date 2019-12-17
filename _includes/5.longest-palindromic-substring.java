/*
 * @lc app=leetcode id=5 lang=java
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.40%)
 * Likes:    4944
 * Dislikes: 437
 * Total Accepted:    740K
 * Total Submissions: 2.6M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
    /*
     * 返回最长公共子串  用manacher算法  O(N)
     * */
    public String longestPalindrome(String str) {
        if (str == null || str.length() < 2)
            return str;
        //构建便于manacher处理的字符数组
        char[] charArr = manacherCharArr(str);
        //回文半径数组
        int[] rArr = new int[charArr.length];
        int C, R, index = -1, max = Integer.MIN_VALUE;
        //C和R是用来求回文半径数组的中间状态变量，与最后的最大回文子串无关
        C = -1;//最早到达回文右边界的中心
        R = -1;//所有回文半径中的回文右边界，就是[L,R]之外的下一个要比对的位置
        for (int i = 0; i < charArr.length; i++) {
            /*
            下面的一行代码是关键。R > i如果成立，则是i在R里面的3种情况。
            R > i不成立，则是i在R外面的1种情况，回文半径长度为1
            下面的R是[L,R]之外的下一个要比对的位置
             */
            rArr[i] = R > i ? Math.min(rArr[2 * C - i], R - i) : 1;
            //下面的while循环代码是对上面的4种情况都往外继续扩。
            while (i + rArr[i] < charArr.length && i - rArr[i] > -1) {
                if (charArr[i + rArr[i]] == charArr[i - rArr[i]])
                    rArr[i]++;
                else
                    break;
            }
            //当前位置回文右边界大于之前的回文右边界，则更新R,C
            if (i + rArr[i] > R) {
                R = i + rArr[i];
                C = i;
            }
            // max存储回文半径数组中的最大值
            // max-1就是最大回文字符串的长度
            if (rArr[i] > max) {
                index = i;//最大回文半径的中心位置
                max = rArr[i];//最大回文半径
            }
        }
        //根据index和max求得包含“#”的最大回文子串
        // startIndex = index - max + 1; endIndex = index + max - 1;
        // 然后抛弃“#”即可得到真正的最大回文子串
        StringBuilder res = new StringBuilder();
        for (int startIndex = index - max + 1, endIndex = index + max - 1;
             startIndex <= endIndex; startIndex++)
            if (charArr[startIndex] != '#')
                res.append(charArr[startIndex]);
        return res.toString();
    }
    
    /*
     * 在字符串的开头、结尾、和字符中间添加“#”
     * */
    private char[] manacherCharArr(String str) {
        char[] charArr = str.toCharArray();
        char[] res = new char[2 * charArr.length + 1];
        int index = 0;
        for (int i = 0; i < res.length; i++)
            res[i] = (i & 1) == 0 ? '#' : charArr[index++];
        return res;
    }
}

// Human Way Expand from center
class Solution {
    public int left,max;
    public String longestPalindrome(String s) {
        if(s.length()<2)return s;
        //max=0;
        for(int i=0;i<s.length();i++){
            findLongest(s,i,i);
            findLongest(s,i,i+1);
        }
        return s.substring(left,left+max);
    }
    private void findLongest(String s,int i,int j){
        while(i>=0 && j<s.length() && s.charAt(i)==s.charAt(j)){
            i--;j++;
        }
        if(max<j-i-1){
            left=i+1;
            max=j-i-1;
        }
    }
}

// Reversed the String And Find Longest Common SubString
// @lc code=end

