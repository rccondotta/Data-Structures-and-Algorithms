"""
TwoSum LeetCode

Time complexity of O(n^2)
Space complexity of O(1) as we are iterating through the array once and only storing 2 integers.
"""
def twoSum(nums, target):
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]

"""
Optimize the above solution by using a hashmap to store the array elements and corresponding indices,
this would make the solution run in O(n) time complexity and O(n) space complexity
"""
def twoSum(nums, target):
    hashmap = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in hashmap:
            return [hashmap[complement], i]
        hashmap[num] = i