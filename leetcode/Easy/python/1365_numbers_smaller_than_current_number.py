def smaller_numbers_than_current(nums: list, memo={}, count=[]):
    s_nums = sorted(nums ,reverse=True)
    if len(s_nums) == 1: return s_nums[]
