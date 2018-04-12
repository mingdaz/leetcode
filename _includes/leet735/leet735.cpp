class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> s; // use vector to simulate stack.
        for (int i : a) {
            while (!s.empty() && s.back() > 0 && s.back() < -i)
                s.pop_back();
                //^while top element gets lashed out by an Opposite Asteroid which is of Higher Value
            	//Eg. top([5, 10]) < -(-15) -> Pop Until Opposite asteroid is lashed out by Stack Top
            if (s.empty() || i > 0 || s.back() < 0)
                s.push_back(i);
            	//^ If it's empty or if AST is greater value or Stack top is of Lesser Value -> Keep pushing
            else if (i < 0 && s.back() == -i)//when TOP and AST are Equal Eg. top([5, 10]) == -(-10) -> Pop
                s.pop_back();
        }
        return s;
    }
};