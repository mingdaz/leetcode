struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        i = 0;
        this->food = food;
        this->height = height;
        this->width = width;
        B.insert(make_pair(0,0));
        S.push_back(make_pair(0,0));
        
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto head = S.front();
        switch(direction[0]){
            case 'U': 
                head.first--;
                if(head.first < 0 ) return -1;
                break;
            case 'L': 
                head.second--;
                if(head.second < 0) return -1;
                break;
            case 'R': 
                head.second++;
                if(head.second >= width) return -1;
                break;
            case 'D': 
                head.first++; 
                if(head.first >= height) return -1;
                break;
            default: return -1;
        }
        return move(head);

    }
    
private:
    std::unordered_set <std::pair <int, int>,pairhash> B;
    vector<pair<int, int>> food;
    deque<pair<int, int>> S;
    int height;
    int width;
    int i;
    int move(pair<int,int>& head){
        S.push_front(head);               
        if(i<food.size()&&head == food[i]){
            i++;
        }
        else{
            auto tail = S.back();
            B.erase(tail);
            S.pop_back();
        }
        if(B.count(head)>0) return -1;
        else B.insert(head);
        return S.size()-1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
