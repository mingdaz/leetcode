/*
 * @lc app=leetcode id=170 lang=java
 *
 * [170] Two Sum III - Data structure design
 *
 * https://leetcode.com/problems/two-sum-iii-data-structure-design/description/
 *
 * algorithms
 * Easy (32.47%)
 * Likes:    239
 * Dislikes: 196
 * Total Accepted:    72.1K
 * Total Submissions: 222K
 * Testcase Example:  '["TwoSum","add","add","add","find","find"]\n[[],[1],[3],[5],[4],[7]]'
 *
 * Design and implement a TwoSum class. It should support the following
 * operations: add and find.
 * 
 * add - Add the number to an internal data structure.
 * find - Find if there exists any pair of numbers which sum is equal to the
 * value.
 * 
 * Example 1:
 * 
 * 
 * add(1); add(3); add(5);
 * find(4) -> true
 * find(7) -> false
 * 
 * 
 * Example 2:
 * 
 * 
 * add(3); add(1); add(2);
 * find(3) -> true
 * find(6) -> false
 * 
 */

// @lc code=start
class TwoSum {

    private HashMap<Integer, Integer> num_counts;
    /** Initialize your data structure here. */
    public TwoSum() {
         this.num_counts = new HashMap<Integer, Integer>();
    }
    
    /** Add the number to an internal data structure.. */
    public void add(int number) {
        if (this.num_counts.containsKey(number))
      this.num_counts.replace(number, this.num_counts.get(number) + 1);
    else
      this.num_counts.put(number, 1);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public boolean find(int value) {
         for (Map.Entry<Integer, Integer> entry : this.num_counts.entrySet()) {
      int complement = value - entry.getKey();
      if (complement != entry.getKey()) {
        if (this.num_counts.containsKey(complement))
          return true;
      } else {
        if (entry.getValue() > 1)
          return true;
      }
    }
    return false;
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */
// @lc code=end

