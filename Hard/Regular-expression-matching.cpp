/*
- 10) Regular Expression Matching
    
    Given an input string `s` and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:
    
    - `'.'` Matches any single character.
    - `'*'` Matches zero or more of the preceding element.
    
    The matching should cover the **entire** input string (not partial).
    
    **Example 1:**
    
    ```
    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".
    
    ```
    
    **Example 2:**
    
    ```
    Input: s = "aa", p = "a*"
    Output: true
    Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
    
    ```
    
    **Example 3:**
    
    ```
    Input: s = "ab", p = ".*"
    Output: true
    Explanation: ".*" means "zero or more (*) of any character (.)".
    
    ```
    
    **Constraints:**
    
    - `1 <= s.length <= 20`
    - `1 <= p.length <= 20`
    - `s` contains only lowercase English letters.
    - `p` contains only lowercase English letters, `'.'`, and `'*'`.
    - It is guaranteed for each appearance of the character `'*'`, there will be a previous valid character to match.




*/



//runs at 0ms 
class Solution {
public:
    int dp[21][21];      //meet constraints, 2D array
    
    bool solve(int i, int j, const string &s, const string &p) {
        if (j == p.size())          //if j = size of p end
            return i == s.size();       //return true at end of string of s
        if (dp[i][j] != -1)         //if already computed result for state (i, j), return result
            return dp[i][j];
        
        bool isMatch = i < s.size() && (s[i] == p[j] || p[j] == '.');       //check T/F for size match, match of character in s and p and for '.' in pattern
        return dp[i][j] = j + 1 < p.size() && p[j+1] == '*' ?                   // check next character for '*'
            solve(i, j+2, s, p) || (isMatch && solve(i+1, j, s, p)) :               //if true, gores to next char calling solve() or match current char and repeats
            isMatch && solve(i+1, j+1, s, p);                                       //match curr char, move to next char in s & p, iterates to next position in i & j
    }
    

    //Called first
    bool isMatch(string s, string p) {           
        memset(dp, -1, sizeof(dp));     //initialize dp elements of dp array to -1, reset
        return solve(0, 0, s, p);       //call solve(), set i & j to 0, pass s & p
                    //return bool based off matching
    }
};





// The following is the same as above, but further 
//broken up to follow the one task rule
//runs at 2ms

class Solution {
public:
    int dp[21][21];

    bool isPatternEnd(int j, const string &p) {
        return j == p.size();
    }

    bool isSolved(int i, int j) {
        return dp[i][j] != -1;
    }

    bool isCurrMatch(int i, const string &s, const string &p, int j) {
        return i < s.size() && (s[i] == p[j] || p[j] == '.');
    }

    bool nextAsterisk(int j, const string &p) {
        return j + 1 < p.size() && p[j+1] == '*';
    }

    bool currAsterisk(int i, int j, const string &s, const string &p, bool isMatch) {
        return solve(i, j+2, s, p) || (isMatch && solve(i+1, j, s, p));
    }

    bool currRegularChar(int i, int j, const string &s, const string &p, bool isMatch) {
        return isMatch && solve(i+1, j+1, s, p);
    }

    bool solve(int i, int j, const string &s, const string &p) {
        if (isPatternEnd(j, p))
            return i == s.size();
        if (isSolved(i, j))
            return dp[i][j];
        
        bool isMatch = isCurrMatch(i, s, p, j);
        return dp[i][j] = nextAsterisk(j, p) ?
            currAsterisk(i, j, s, p, isMatch) :
            currRegularChar(i, j, s, p, isMatch);
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, p);
    }
};

















