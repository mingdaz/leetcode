class MyCalendar {
public:
    MyCalendar() = default;
    bool book(int start, int end) {
        auto finder = bounds.lower_bound(start); // ceiling
        if (finder != bounds.cend() && finder->first < end)
            return false;

        if (finder != bounds.cbegin()) {
            --finder; // "floor"
            if (finder->second >= start)
                return false;
        }

        bounds[start] = end - 1;
        return true;
    }
private:
    map<int, int> bounds;
};
