class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        inds = [0 for _ in range(0,101)]
        
        for num in nums:
            inds[num]+=1
        answer = []
        for num in nums:
            answer.append(sum(inds[:num]))
        
        return answer
        
        