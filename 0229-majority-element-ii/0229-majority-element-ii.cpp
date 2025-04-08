class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int>ans;
        unordered_map<int,int>mp;
        int n=nums.size();
        int count=(n/3)+1;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==count)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};