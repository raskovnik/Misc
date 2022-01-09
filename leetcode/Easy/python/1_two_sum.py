class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        s = set()
        for i in range(len(nums)):
            temp = target - nums[i]
            if temp in s: return [nums.index(temp), i]
            
            s.add(nums[i])