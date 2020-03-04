class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        absent = 0
        cnt_late = 0
        for l in s:
            if l=='A':
                absent+=1
                cnt_late = 0
            elif l=='L':
                cnt_late+=1
            else:
                cnt_late=0
            
            if cnt_late==3 or absent==2:
                return False
        
        return True
        