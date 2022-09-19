class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(auto path : paths){
            int i = 0;
            int n = path.size();
            string pathy = "";
            while(i < n && path[i]!=' '){
                pathy += path[i];
                i++;
            }
            pathy += '/';
            i++;
            while(i < n){
                string file = "";
                string content = "";
                while(i < n && path[i]!='('){
                    file += path[i];
                    i++;
                }
                i++;
                while(i < n && path[i]!=')'){
                    content += path[i];
                    i++;
                }
                i++;
                i++;
                mp[content].push_back(pathy+file);
            }
        }
        for(auto it : mp){
            if(it.second.size() > 1){
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};