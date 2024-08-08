class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<vector<string>> lines;
        vector<int> sizes;
        int currentSize = 0;
        vector<string> currentLine;
        for(auto word:words) {

            if(currentSize+word.size()+currentLine.size()<=maxWidth) {
                currentLine.push_back(word);
                currentSize += word.size();
            } else {
                lines.push_back(currentLine);
                sizes.push_back(currentSize);
                cout<<currentSize<<endl;
                currentLine = {};
                currentLine.push_back(word);
                currentSize = word.size();
            }
        }
        if(currentLine.size()!=0) {
            lines.push_back(currentLine);
            sizes.push_back(currentSize);
        }
        vector<string> answer;
        for(int i=0;i<lines.size();i++) {
            string line="";

            int spaces = maxWidth - sizes[i];
            int totalWords = lines[i].size();

            if(totalWords==1) {
                line += lines[i][0];
                for(int s=0;s<spaces;s++) line+=' ';
            } else if(i==(lines.size()-1)) {
                cout<<" last line"<<endl;
                line +=lines[i][0];
                for(int l=1;l<lines[i].size();l++) {
                    line+=' ';
                    spaces--;
                    line+=lines[i][l];
                }
                for(int s=0;s<spaces;s++) {
                    line+=' ';
                }
            }  else
            
            { 
                cout<<"LINE "<<i<<" "<<lines.size()-1<<endl;
                int spacesToGive = spaces/(totalWords-1);
                int reminderSpaces = spaces%(totalWords-1);
                cout<<spaces<<" "<<spacesToGive<<" "<<reminderSpaces<<endl;

                string spaceToAppend = "";
                for(int s=0;s<spacesToGive;s++) {
                    spaceToAppend+=' ';
                }

                line+=lines[i][0];
                for(int l=1;l<lines[i].size();l++) {
                    line+=spaceToAppend;
                    if(reminderSpaces!=0) 
                    {
                        line+=' ';
                        reminderSpaces--;
                    }
                    line+=lines[i][l];
                }
            } 
            answer.push_back(line);

        }
    return answer;
    }
};