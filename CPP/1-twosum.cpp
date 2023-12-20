// 1. Two Sum
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.

#include <iostream>
#include <vector>
#include <unordered_map>

// Solution 1: (Brute Force)
class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    int n = nums.size();
    for (int i=0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }
    return {}; // No solution found
  }
};

// Solution 2: (Two pass hash table)
class SolutionTwo {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap;
    int n = nums.size();

    // Build the hast table
    for (int i = 0; i < n; i++) {
      numMap[nums[i]] = i;
    }

    // Find the complement
    for (int i = 0; i < n; i++) {
      int complement = target - nums[i];
      if (numMap.count(complement) && numMap[complement] != i) {
        return {i, numMap[complement]};
      }
    }

    return {}; // No solution found
  }
};

// Solution 3: (One pass hash table)
class SolutionThree {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      int complement = target - nums[i];
      if (numMap.count(complement)) {
        return {numMap[complement], i};
      }
      numMap[nums[i]] = i;
    }

    return {}; // No solution found
  }
};
