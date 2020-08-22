class Solution(object):
    def thousandSeparator(self, n):
        
        inp = str(n)
        inp = reversed(inp)
        building = []   
        i = 0
        for char in inp:
            if i%3==0 and i!=0:
                building.append(".")
            building.append(char)
            i+=1

        building.reverse()
        return "".join(building)

        