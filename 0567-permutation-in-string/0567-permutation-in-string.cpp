class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Freq(26, 0), windowFreq(26, 0);

        // Count frequencies of characters in s1
        for (char c : s1) {
            s1Freq[c - 'a']++;
        }

        // Process the first window of size s1.size()
        for (int i = 0; i < s1.size(); i++) {
            windowFreq[s2[i] - 'a']++;
        }

        // Check if the first window matches
        if (s1Freq == windowFreq) return true;

        // Slide the window
        for (int i = s1.size(); i < s2.size(); i++) {
            windowFreq[s2[i] - 'a']++;                   // Add the new character
            windowFreq[s2[i - s1.size()] - 'a']--;       // Remove the old character

            if (s1Freq == windowFreq) return true;       // Check if current window matches
        }

        return false;
    }
};
