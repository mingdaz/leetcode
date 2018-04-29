//
//  15_hilbert_curve.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/27/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Test.hpp"
using namespace std;

class Hilbert{
public:
    
    int hilbertCurve(int x, int y, int iter) {
        if (iter == 0) return 1;
        int len = 1 << (iter - 1);
        int num = 1 << (2 * (iter - 1));
        if (x >= len && y >= len) {
            // 3 Shape is identical with previous iteration
            return 2 * num + hilbertCurve(x - len, y - len, iter - 1);
        } else if (x < len && y >= len) {
            // 2 Shape is identical with previous iteration
            return num + hilbertCurve(x, y - len, iter - 1);
        } else if (x < len && y < len) {
            // 1 Clock-wise rotate 90
            return hilbertCurve(y, x, iter - 1);
        } else {
            // 4 Anti-Clockwise rotate 90
            return 3 * num + hilbertCurve(len - y - 1, 2 * len - x - 1, iter - 1);
        }
    }
    
    //convert (x,y) to d
    int xy2d (int iter, int x, int y) {
        int rx, ry, s = 1<<(iter-1), d=0;
        for (; s>0; s/=2) {
            rx = (x & s) > 0;
            ry = (y & s) > 0;
            d += s * s * ((3 * rx) ^ ry);
            rot(s, x, y, rx, ry);
        }
        return d;
    }
    
    //convert d to (x,y)
    void d2xy(int n, int d, int& x, int& y) {
        int rx, ry, s, t=d;
        x = y = 0;
        for (s=1; s<n; s*=2) {
            rx = 1 & (t/2);
            ry = 1 & (t ^ rx);
            rot(s, x, y, rx, ry);
            x += s * rx;
            y += s * ry;
            t /= 4;
        }
    }
    
    //rotate/flip a quadrant appropriately
    void rot(int n, int& x, int& y, int rx, int ry) {
        if (ry == 0) {
            if (rx == 1) {
                x = n-1 - x;
                y = n-1 - y;
            }
            
            //Swap x and y
            int t  = x;
            x = y;
            y = t;
        }
    }
};


class HilbertTest: public Test{
public:
    void test(){
        cout<<"15. Hilbert Curve:"<<endl;
        Hilbert H;
        cout<<H.xy2d(2, 0, 0)<<endl;
        cout<<H.hilbertCurve(0, 0, 2)<<endl;
        
        cout<<H.xy2d(2, 2, 2)<<endl;

        printsep();
    }
};

