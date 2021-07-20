
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        
        
        words = paragraph.split(" ")
        banned = set(banned)
        word_count = {}
        
        words = []
        
        
        current_word = ''
        for c in paragraph:
            if not ((c>='a' and c<='z') or (c>='A' and c<='Z')):
                if current_word!='':
                    words.append(current_word.lower())
                    current_word=''
            else:
                current_word+=c
        if current_word!='':
            words.append(current_word)
        
        
        for word in words:
            if word.lower() not in banned:
                if word.lower() not in word_count:
                    word_count[word.lower()] = 1
                else:
                    word_count[word.lower()]+=1
        
        biggest = ""
        max_occur = 0
        for key in word_count:
            if word_count[key]>max_occur:
                biggest = key
                max_occur = word_count[key]
        print(word_count)
        print(max_occur)
        return biggest
    
                
        
        