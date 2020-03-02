class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        jewels = set([i for i in J])
        cnt = 0
        for stone in S:
            if stone in jewels:
                cnt+=1
        
        return cnt
        
        
        