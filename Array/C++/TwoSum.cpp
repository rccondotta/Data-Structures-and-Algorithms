#include <iostream>
#include <vector>
using namespace std;

/*
TwoSum LeetCode

Time complexity of O(n^2)
Space complexity of O(1) as we are iterating through the array once and only storing 2 integers.
*/
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return res;
}

/*
Optimize the above solution by using a hashmap to store the array elements and corresponding indices,
this would make the solution run in O(n) time complexity and O(n) space complexity
*/
#include <unordered_map>

vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> hashmap;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (hashmap.count(complement) > 0) {
            return { hashmap[complement], i };
        }

        hashmap[nums[i]] = i;
    }

    return {-1, -1};
}