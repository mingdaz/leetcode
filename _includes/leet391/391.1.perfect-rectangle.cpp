class Solution {
public:
  //variabile globale
  struct Event {
    int x;
    int y1;
    int y2;
    bool open;

    bool operator < (Event a) const {
      if(x != a.x) {
        return x < a.x;
      } else if(open != a.open){
        return open < a.open;
      } else if(y1 != a.y1) {
        return y1 < a.y1;
      } else
        return y2 < a.y2;
    }

    bool concat(Event other) {
      if(x == other.x && open == other.open){
        if(y2 == other.y1) {
          y2 = other.y2;
          return 1;
        } else
          return 0;
      } else {
        cout<<"Eroare!";
        return 0;
      }
    }
  };

  //[stanga, jos, dreapta, sus], [stanga, jos, dreapta, sus], [stanga,jos,dreapta,sus]
  bool isRectangleCover(vector<vector<int> >& rectangles) {
    vector<Event> v;

    int n = rectangles.size();
    for(int i = 0 ; i < n; i++) {
      v.push_back({rectangles[i][0], rectangles[i][1], rectangles[i][3], 1});
      v.push_back({rectangles[i][2], rectangles[i][1], rectangles[i][3], 0});
    }
    sort(v.begin(),v.end());

    n = 2 * n; //de acum incolo nu mai avem dreptunghiuri, doar evenimente
    int p = 1;
    Event first = v[0];
    while(p < n && first.x == v[p].x) {
      if(first.concat(v[p]) == 0) {
        return 0;
      }
      p++;
    }
    int q = n - 2;
    Event stop = v[n - 1];
    while(0 <= q && stop.x == v[q].x) {
      q--;
    }
    q++;
    int q2 = q;
    stop = v[q];
    q++;
    while(q < n) {
      if(stop.concat(v[q]) == 0) {
        return 0;
      }
      q++;
    }
    if(first.y1 == stop.y1 && first.y2 == stop.y2) {
      vector<Event> open;
      vector<Event> closed;
      int oldx = v[p-1].x;
      int i = p;
      while(i < q2) {
        if(v[i].x == oldx) {
          if(v[i].open == 0) {
            if(0 < closed.size()) {
              Event &last = closed[closed.size() - 1];
              if(last.concat(v[i]) == 0){
                if(v[i].y1 < last.y2)
                  return 0;
                closed.push_back(v[i]);
              }
            } else
              closed.push_back(v[i]);
          } else {
            if(0 < open.size()) {
              Event &last = open[open.size() - 1];
              if(last.concat(v[i]) == 0){
                if(v[i].y1 < last.y2)
                  return 0;
                open.push_back(v[i]);
              }
            } else
              open.push_back(v[i]);
          }
          i++;
        } else {
          //verifici open si closed ca sunt identice
          if(open.size() == closed.size()){
            for(int j = 0 ; j < open.size() ;j++){
              if(!(open[j].y1 == closed[j].y1 && open[j].y2 == closed[j].y2))
                return 0;
            }
          } else
            return 0;
          open.clear();
          closed.clear();
          oldx = v[i].x;
        }
      }
    } else
      return 0;
    return 1;
  }
};