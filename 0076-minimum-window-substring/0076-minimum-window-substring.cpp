class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char c : t) {
            mp[c]++;
        }

        int count = t.size();  // Number of characters in `t` we still need to match
        int l = 0, r = 0;      // Two pointers for the sliding window
        int minLen = INT_MAX;  // Minimum window length
        int startIndex = -1;   // Starting index of the minimum window

        while (r < s.size()) {
            // Expand the window
            if (mp[s[r]] > 0) {
                count--;
            }
            mp[s[r]]--;
            r++;

            // Shrink the window
            while (count == 0) {
                if (r - l < minLen) {
                    minLen = r - l;
                    startIndex = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    count++;
                }
                l++;
            }
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};
