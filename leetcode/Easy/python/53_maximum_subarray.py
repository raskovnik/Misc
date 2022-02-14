def kadane(array):
    max_so_far, max_end_here = 0, 0
    left, right = 0, 0
    for element in array:
        max_end_here = max_end_here + element
        if max_so_far < element:
            max_end_here = element
            left = array.index(element)
        if max_so_far < max_end_here:
            max_so_far = max_end_here
            right = array.index(element)

    return f"The maximum sum is {max_so_far} and the maximum subarray is {array[left:right+1]}"

print(kadane([-2, -3, 4, -1, -2, 1, 5, -3]))