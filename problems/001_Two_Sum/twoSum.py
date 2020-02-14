import numpy as np 

class Solution:
	"""docstring for twoSum"""
	def twoSum(self, nums, target):
		if len(nums)<1:
			return False
		buf_dict={}
		for i in range(len(nums)):
			if nums[i] in buf_dict:
				return [buf_dict[nums[i]], i]
			else:
				buf_dict[target - nums[i]] = i

nums=[1,2,3,4,5,6,7]
target = 5
solu = Solution()
res = solu.twoSum(nums, target)
print (res)
