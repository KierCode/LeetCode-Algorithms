/*      242 Valid Anagram

Given two strings `s` and `t`, return `true` *if* `t` *is an anagram of* `s`*, and* `false` *otherwise*.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**

```
Input: s = "anagram", t = "nagaram"
Output: true

```

**Example 2:**

```
Input: s = "rat", t = "car"
Output: false

```

**Constraints:**

- `1 <= s.length, t.length <= 5 * 104`
- `s` and `t` consist of lowercase English letters.




*/


//Fastest variation


class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;

        for(int i=0;i<s.size();i++){
          mp[s[i]]++;
        }

        for(int j=0;j<t.size();j++){
          mp[t[j]]--;
        }

        for(auto pr:mp){
          if(pr.second !=0)
          return false;
        }
        return true;
    }
};






//Using all_of and for_each 

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        vector<int> count(26, 0);
        
        for_each(s.begin(), s.end(), [&count](char c) { count[c - 'a']++; });           //increment count of each char of s
        for_each(t.begin(), t.end(), [&count](char c) { count[c - 'a']--; });           //increment count of each char of t
        
        return all_of(count.begin(), count.end(), [](int i) { return i == 0; });        // all_of checks that all char have count of zero (s and t have same char count)
    }                                                       //true if i == 0
};


















