// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
    if(n <= 1)
    {
        return -1;
    }

    int k = 0;
    for(int i=0; i < n-1; i++)
    {
        if(knows(k,i+1))
        {
            k = i+1;
        }
    }

    for(int i=0; i < n; i++)
    {
        if(k != i)
        {
            if(!knows(i,k) || knows(k,i))
            {
                return -1;
            }
        }
    }

    return k;
}
};