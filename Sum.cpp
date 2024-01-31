/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

class Solution {
public:
    auto twoSum(vector<int>& nums, int target)
    {
        return twoSumSlow(nums, target);
        //return twoSumFast(nums, target);
    }
    vector<int> twoSumSlow(vector<int>& nums, int target) {
        for(int i =0; i<nums.size()-1;  ++i)
        {
         for(int j =i+1; j<nums.size();  ++j)
            if( nums[i] + nums[j] == target)
                return {i,j};
        }
        return {};
    }
    vector<int> twoSumFast(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> map;
        for(int i=0; i<nums.size(); ++i)
        {
            int remaining = target - nums[i];
            if( map.find(remaining) != map.end() )
                return {map[remaining], i};
            map[nums[i]] = i;
        }
        return {};
    }
};

// Two Sum II - Input Array Is Sorted 
// Two pointer notation
   vector<int> twoSumOnSorted(vector<int>& numbers, int target) 
    {
        int left =0, right = numbers.size()-1;
        while ( left < right )
        {
            int sum = numbers[left] + numbers [right];
            if ( sum == target )
                return { left+1, right +1};
            else if ( sum  > target )
                --right;
            else
                ++left;
        }
        return {};
    }
/****************************************************/
/* 3 sum - https://leetcode.com/problems/3sum/
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
*/

    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++) 
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate numbers to avoid duplicate triplets. 
            int left = i + 1, right = nums.size() - 1;
            while (left < right) 
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) 
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;  // skip duplicate numbers to avoid duplicate triplets.
                    while (left < right && nums[right] == nums[right - 1]) right--; // skip duplicate numbers to avoid duplicate triplets.
                    left++; right--;
                }
                else if (sum < 0) 
                    left++;
                else 
                    right--;
            }
        }
    return result;
    }

/* 4sum - https://leetcode.com/problems/4sum/
  vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        std::vector<std::vector<int>> result;
        if (nums.size() < 4) return result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) 
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) 
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right) 
                {
                    //cast one of the number to long
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    //long long sum = static_cast<long long>(nums[i] + nums[j] + nums[left] + nums[right]); // does not work
                    if (sum == target) 
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++; right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
