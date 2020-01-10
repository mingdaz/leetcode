/*
 * @lc app=leetcode id=373 lang=java
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums1.length==0 || nums2.length==0) return res;
        boolean[][] visited = new boolean[nums1.length][nums2.length];
        PriorityQueue<List<Integer>> pq = new PriorityQueue<>(new Cmp(nums1, nums2));
        pq.add(Arrays.asList(0,0));
        visited[0][0] = true;
        while(res.size()<k && !pq.isEmpty()){
            List<Integer> index = pq.poll();
            int i = index.get(0);
            int j = index.get(1);
            res.add(Arrays.asList(nums1[i], nums2[j]));
            if(i+1<nums1.length && !visited[i+1][j]){
                visited[i+1][j] = true;
                pq.add(Arrays.asList(i+1,j));
            }
            if(j+1<nums2.length && !visited[i][j+1]){
                visited[i][j+1] = true;
                pq.add(Arrays.asList(i,j+1));
            }
        }
        return res;
    }
}

class Cmp implements Comparator<List<Integer>> {
    int[] nums1;
    int[] nums2;
    Cmp(int[] nums1, int[] nums2){
        this.nums1 = nums1;
        this.nums2 = nums2;
    }
    public int compare(List<Integer> a, List<Integer> b){
        int sumA = nums1[a.get(0)] + nums2[a.get(1)];
        int sumB = nums1[b.get(0)] + nums2[b.get(1)];
        return Integer.compare(sumA, sumB);
    }
}
// @lc code=end

