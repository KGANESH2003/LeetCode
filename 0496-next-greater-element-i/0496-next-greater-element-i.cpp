class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>res;
        nums2.push_back(-1);

        int n=nums1.size();
        int m=nums2.size();

        for(int i=0;i<n;i++)
        {
            bool flag=false;
            int j=0;
            while(j<m)
            {
                if(nums1[i]==nums2[j])flag=true;
                if((nums2[j]>nums1[i]||nums2[j]==-1)&&flag==true)
                {
                    res.push_back(nums2[j]);
                    break;
                }j++;
            }
        }return res;

    }
};