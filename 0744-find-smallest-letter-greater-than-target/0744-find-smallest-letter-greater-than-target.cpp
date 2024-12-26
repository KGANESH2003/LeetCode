class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int left=0;
        int right=letters.size()-1;
        char res=letters[left];

        while(left<=right)
        {
            int mid=(left+right)/2;
            if(letters[mid]==target)
            {
                left=mid+1;

            }
            else if(letters[mid]>target)
            {
                res=letters[mid];
                right=mid-1;
            }else{
                left=mid+1;
            }
        }return res;
    }
};