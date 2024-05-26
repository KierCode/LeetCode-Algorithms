/*
Given an integer array nums and an integer val, remove all occurrences of val 
in nums in-place. The order of the elements may be changed. Then return the 
number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, 
to get accepted, you need to do the following things:

- Change the array nums such that the first k elements of nums contain the 
elements which are not equal to val. The remaining elements of nums are not 
important as well as the size of nums.

- Return k.

*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto getVal = std::remove(nums.begin(), nums.end(), val);

        nums.erase(getVal, nums.end());

        return nums.size();

    }
};


/*  OUTLINE OF PROGRAM
      get vector and remove all val(s) in vector
      assign to getVal

      erase val from nums

      return size of nums
*/









