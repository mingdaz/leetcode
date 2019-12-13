import javafx.util.Pair;

import java.util.*;

class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        Stack<Integer> stack = new Stack<>();
        int prev = 0;
        int[] res = new int[n];

        for (String log : logs) {
            String[] array = log.split(":");
            int index = Integer.parseInt(array[0]);

            int currTime = Integer.parseInt(array[2]);

            if(!stack.isEmpty()) {
                res[stack.peek()] += currTime - prev;
            }

            prev = currTime;

            if(array[1].equals("start")) {
                stack.add(index);
            } else {
                res[stack.pop()]++;
                prev++;
            }
        }

        return res;
    }
}

class Tester {
    public static void main(String args[]) {
        Solution s = new Solution();
        int n = 2;
        List<String> logs = new ArrayList<String>();
        logs.add("0:start:0");
        logs.add("1:start:2");
        logs.add("1:end:5");
        logs.add("0:end:6");
        int[] ret = s.exclusiveTime(2, logs);
        System.out.println(ret[0] + ";"+ret[1]);
    }
}