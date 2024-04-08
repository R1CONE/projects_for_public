
class Solution {
public:
    string longestCommonPrefix(vector<string>& v) { // v это Лист со словами
        string ans = ""; //ответ
        sort(v.begin(), v.end());
        int n = v.size(); //3 короче
        string first=v[0],last=v[n-1];
        for(int i=0; i<min(first.size(), last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};
