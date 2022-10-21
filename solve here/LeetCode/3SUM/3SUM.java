class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:        
        # special case
        if len(nums) <= 2:
            return []

        result = set()  # result will contain the unique tuples

        nums = sorted(nums) # nlog(n) complexity

        for x in range(len(nums)-2):
            b = x+1          # begining pointer points to next
            e = len(nums)-1  # end pointer points to last element in nums

            while b < e: # while pointers don't cross one another
                val = nums[x]+ nums[b] + nums[e]
                if val == 0: # we have found the sum
                    result.add(tuple(sorted((nums[x],nums[b],nums[e])))) # need to convert to tuple as it's immutable

                    b += 1
                    e -= 1

                if val < 0: # we need to increase the result, so move towards the right side
                    b += 1
                if val > 0:  # we need to decrease the result, so move towards the left side
                    e -= 1
        return result
