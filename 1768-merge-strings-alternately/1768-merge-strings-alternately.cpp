class Solution {
public:
    string mergeAlternately(string s1, string s2) {

        string res;
        int i=0,j=0;
        while(i<s1.length()&&j<s2.length())
        {
            res+=s1[i++];
            res+=s2[j++];
        }
        while(i<s1.length())
        {
            res+=s1[i++];
        }
        while(j<s2.length())
        {
            res+=s2[j++];
        }
        return res;
        
    }
};