class Solution {
    public int N;
    public int count(int mask, long num) {
        if (num > N) return 0;
        
        int ret = 1;
        for (int nd = num == 0 ? 1 : 0; nd < 10; nd++) {
            if (((mask>>nd) & 1) == 0) {
                ret += count(mask|(1<<nd), num*10+nd);
            }
        }
        return ret;
    }
    public int numDupDigitsAtMostN(int _N) {
        N = _N;
        return N + 1 - count(0, 0);
    }


}

class Tester {
    public static void main(String args[]){
        Solution A = new Solution();
        int N = 20;
        int ans= 1;
        System.out.println("Test 1: N=" + N+ ",expect "+ ans + " get " + A.numDupDigitsAtMostN(N));
        N =100;
        ans = 10;
        System.out.println("Test 2: N=" + N+ ",expect "+ ans + " get " + A.numDupDigitsAtMostN(N));
        N = 1000;
        ans = 262;
        System.out.println("Test 3: N=" + N+ ",expect "+ ans + " get " + A.numDupDigitsAtMostN(N));

    }
}