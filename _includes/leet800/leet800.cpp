class Solution {
public:
    string similarRGB(string color) {
        if(color.size()<6) return color;
        char x = helper(&color[1]);
        char y = helper(&color[3]);
        char z = helper(&color[5]);
        return "#"+string(2,x)+string(2,y)+string(2,z);
    }
    
    char helper(char a[]){
        int ret = 0;
        if(isdigit(a[0])){
            ret += (a[0]-'0')*16;
        }
        else if(a[0]>='a'){
            ret += (a[0]- 'a'+10)*16;
        }
        else {
            ret += (a[0] - 'A'+10)*16;
        }
        if(isdigit(a[1])){
            ret += (a[1]-'0');
        }
        else if(a[1]>='a'){
            ret += (a[1]- 'a'+10);
        }
        else {
            ret += (a[1] - 'A'+10);
        }
        int b = ret/17;
        b = ret  - b*17 > 8.5 ? b+1:b;
        if(b<10) return '0'+b;
        return b+'a'-10;
    }
};