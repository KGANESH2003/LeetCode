class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0, maxfreq = 0, maxlength = 0;

        for (int right = 0; right < s.length(); right++) {
            freq[s[right]]++;
            maxfreq = max(maxfreq, freq[s[right]]);

            if ((right - left + 1) - maxfreq > k) {
                freq[s[left]]--;
                left++;
            }

            maxlength = max(maxlength, right - left + 1);
        }

        return maxlength;
    }
};
