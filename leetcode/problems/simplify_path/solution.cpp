class Solution {
public:
    string simplifyPath(string path) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        istringstream ss(path);
        vector<string> sPath;

        string current="";
        while(getline(ss,current,'/')) {
            if(current=="." || current=="") continue;
            if(current==".." ) {
                if(sPath.size()!=0) sPath.pop_back();
            } 
            else
            {sPath.push_back(current);}
        }

        string finalPath = "";
        for(auto pathPart:sPath) {
            finalPath += "/"+pathPart;
        }
        if(finalPath=="") return "/";
        return finalPath;
    }
};