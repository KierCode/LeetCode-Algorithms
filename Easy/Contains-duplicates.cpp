/*
- 217 Contains Duplicate
    
    Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.
    
    **Example 1:**
    
    ```
    Input: nums = [1,2,3,1]
    Output: true
    
    ```
    
    **Example 2:**

    Input: nums = [1,2,3,4]
Output: false



*/






//  using std::sort

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      sort(nums.begin(),nums.end()) ;         //sort from least to greatest
      int n = nums.size();                     //get vector size
      for(int i =0 ;i<n-1;i++){                 //iterate through vector based on size
        if(nums[i]== nums[i+1]){                // if current value is equal to next value
            return true;                            //return true
        }
      } 
      return false;
    }
};











