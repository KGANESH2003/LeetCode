class Solution {
public:
    string reorganizeString(string s) {
        // Step 1: Count the frequency of each character
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++; // Increment count for each character in the string

    // Step 2: Use a max heap to store characters by their frequency
    priority_queue<pair<int, char>> maxHeap;
    for (auto it : freq) maxHeap.push({it.second, it.first}); // Push frequency and character into the heap

    string result; // The resulting string
    pair<int, char> prev = {0, '#'}; // Track the previous character and its remaining count

    // Step 3: Build the result string
    while (!maxHeap.empty()) {
        // Get the most frequent character
        auto curr = maxHeap.top(); maxHeap.pop();
        result += curr.second; // Append current character to the result

        // If the previous character still has a remaining count, push it back into the heap
        if (prev.first > 0) maxHeap.push(prev);

        // Update the current character's count and set it as the previous character
        curr.first--;
        prev = curr;
    }

    // Step 4: Check if the result is valid (all characters rearranged successfully)
    return result.size() == s.size() ? result : "";
    }
};