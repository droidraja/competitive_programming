class Solution(object):
    def defangIPaddr(self, address):
        """
        :type address: str
        :rtype: str
        """
        frags = []
        for char in address:
            if char==".":
                frags.extend(["[",".","]"])
            else:
                frags.append(char)
        return "".join(frags)
        