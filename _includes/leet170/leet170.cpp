class TwoSum {
public:
    void add(int number) {
        elemCount[number]++;
    }

    bool find(int value) {
        for (auto elem : elemCount) {
            if ( (elem.first< value-elem.first && elemCount.count(value - elem.first))||
            (elem.first == value - elem.first && elem.second > 1)) {
                return true;
            }
        }
        return false;
    }
private:
    unordered_map<int, int> elemCount;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
