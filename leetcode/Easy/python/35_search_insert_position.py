def search_position(nums, target):
    return nums.index(target) if target in nums else nums.index(target + 1) or nums.index(target - 1)

nums = [1,3,5,6]
print(search_position(nums, 5))
print(search_position(nums, 2))