#include <vector>
#include <string>
using namespace std;

class Solution {
public:
   

void generateParenthesesHelper(int open, int close, string current, vector<string>& result) {
    // Base case: when no more parentheses can be added
    if (open == 0 && close == 0) {
        result.push_back(current);  // Add the valid combination to the result
        return;
    }

    // Add an opening parenthesis if any are left
    if (open > 0) {
        generateParenthesesHelper(open - 1, close, current + "(", result);
    }

    // Add a closing parenthesis if it keeps the sequence valid
    if (close > open) {
        generateParenthesesHelper(open, close - 1, current + ")", result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesesHelper(n, n, "", result);
    return result;
}

        
    
};