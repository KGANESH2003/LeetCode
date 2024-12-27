class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int,int>intcount;
        for(int num:nums)
        {
            intcount[num]++;
        }

        sort(nums.begin(),nums.end(),[&intcount](int a,int b)
        {
            if(intcount[a]==intcount[b])
            {
                return a>b;
            }else{
                return intcount[a]<intcount[b];
            }
        });return nums;
    }
};