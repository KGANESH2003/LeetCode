class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int pos=0,neg=1;
        vector<int>res(n,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                res[neg]=nums[i];
                neg=neg+2;
            }else{
                res[pos]=nums[i];
                pos+=2;
            }
        }return res;
    }
};