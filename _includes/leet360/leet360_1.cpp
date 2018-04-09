class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res(nums.size(),c); 
        if(a==0){
            if(b>0){
                for(int i=0;i<nums.size();i++){
                    res[i] += nums[i]*b;
                }
            }
            else if(b<0){
                for(int i=0;i<nums.size();i++){
                    res[i] += nums[nums.size()-i-1]*b;
                }
            }
        }
        else{
            float mid = -0.5*b/a;
            std::cout<<mid;
            vector<float> dis(nums.size(),0);
            float min_dis = INT_MAX;
            int k = -1;
            for(int i=0;i<nums.size();i++){
                dis[i] = abs(nums[i] - mid);
                if(dis[i]<min_dis){
                    k = i;
                    min_dis = dis[i];
                }
            }
            if(a>0){
                int i = k,j = k+1;
                for(int l=0;l<nums.size();l++){
                    if(j<nums.size()&&i>=0){
                        if(dis[i]<dis[j]){
                            res[l] = a*nums[i]*nums[i] + b*nums[i] + c;                         
                            i--;
                        }
                        else{
                            res[l] = a*nums[j]*nums[j] + b*nums[j] + c;                         
                            j++;
                        }
                    }
                    else if(i>=0){
                        res[l] = a*pow(nums[i],2) + b*nums[i] + c;                         
                        i--;
                    }
                    else{
                        res[l] = a*pow(nums[j],2) + b*nums[j] + c;                         
                        j++;
                    }
                }
            }
            else{
                int i = 0,j = nums.size()-1;
                for(int l=0;l<nums.size();l++){
                        if(dis[i]>dis[j]){
                            res[l] = a*pow(nums[i],2) + b*nums[i] + c;                         
                            i++;
                        }
                        else{
                            res[l] = a*pow(nums[j],2) + b*nums[j] + c;                         
                            j--;
                        }
                }
                
            }
        }
        return res;
    }
};
