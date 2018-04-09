// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int a = 1;
        int g = a+(n-a)/2;
        int result = guess(g); 
        while(result!=0){
            if(result==-1){
                n = g-1;
                g = a +(n-a)/2;
            }
            else{
                a = g+1;
                g = a + (n-a)/2;
            }
            result = guess(g);
        }
        return g;
    }
    
};
