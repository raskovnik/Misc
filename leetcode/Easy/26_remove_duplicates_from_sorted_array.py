def removeDuplicates(nums) -> int:
    temp = []
    for i in nums:
        if i not in temp: temp.append(i)

    return len(temp)

def removeD(nums) -> int:
    for i in nums:
        try:
            if i == nums[nums.index(i) + 1]: nums.pop(nums.index(i))
        except IndexError:
            pass
    return len(nums)
    
nums = [0,0,1,1,1,2,2,3,3,4]
print(removeD(nums))
print(removeDuplicates(nums))