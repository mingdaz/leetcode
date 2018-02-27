class Solution {
public:
      /* Theroem 1: all the integer can be represented as sum of squares and the minimal number of square can only be 
      1, 2, 3, 4
         Theroem 2: if a number can be divided by 4, then, the result is the same before and after devided by 4, like
      2, 8 and 3, 12  
         Theroem 3, if a number mod 8 and have 7 as reminder, then at least 4 is the result
      */   
    int numSquares(int n) {
      while(n%4==0) n/=4;
      if(n%8 == 7) return 4;
    
      for(int a = 0; a*a <=n; a++)
      {
        int b = sqrt(n - a*a);
        if((a*a + b*b) == n)
        {
            return !!a+!!b;
        }
      }
      return 3;
    }
};