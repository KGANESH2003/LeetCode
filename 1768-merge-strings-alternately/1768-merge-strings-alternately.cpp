class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int i=0,j=0;
        while(i<word1.length()&&j<word2.length())
        {
            res.push_back(word1[i++]);
            res.push_back(word2[j++]);
        }
        while(j<word2.length())
        {
            res.push_back(word2[j++]);
        }
        while(i<word1.length()){
            res.push_back(word1[i++]);
        }return res;
    }
};