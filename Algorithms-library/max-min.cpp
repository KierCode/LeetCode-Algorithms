
#include <algorithm>  /// for std::max, std::min
#include <array>     
#include <cmath>     
#include <iostream>  




template <size_t T>                                             //Take array of size T
int minmax(int depth, int node_index, bool is_max,              //
            const std::array<int, T> &nums, double height) {
    if (depth == height) {      //check max depth of tree
        return nums[node_index];
    }

    int v1 = minmax(depth + 1, node_index * 2, !is_max, nums, height);          //left and right children calls
    int v2 = minmax(depth + 1, node_index * 2 + 1, !is_max, nums, height);      // depth increase, node index

    return is_max ? std::max(v1, v2) : std::min(v1, v2); //return max of two child values or minimum
}


int main() {
    std::array<int, 8> nums = {90, 53, 68, 393, 1989, 6325, 1923, 34423};
    double height = log2(nums.size()); //calculate height

    std::cout << "Optimal value: "          //provide depth, node_index, array, ______
              << minmax(0, 0, true, nums, height) << std::endl;
              
    std::array<int, 8> minNums = {90, 81, 80, 45, 33, 16, 8, 1};
    double heightTwo = log2(minNums.size()); //calculate height

    std::cout << "Optimal value: "          //provide depth, node_index, array, ______
              << minmax(0, 0, true, minNums, heightTwo) << std::endl; 

    return 0;
}
