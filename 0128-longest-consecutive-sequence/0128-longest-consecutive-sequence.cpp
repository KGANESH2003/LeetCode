class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int maxcount=1;
        unordered_set<int>st;
        for(int num:nums)
        {
            st.insert(num);
        }

        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
            {
                int count=1;
                int x=it;
                while(st.find(x+1)!=st.end())
                {
                    x=x+1;
                    count+=1;
                }
                maxcount=max(maxcount,count);
            }
        }return maxcount;
    }
};