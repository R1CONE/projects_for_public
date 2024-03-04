#include <string>
#include <sstream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        std::stringstream ss;
        ss << x;
        std::string x_str = ss.str();
        
        std::string x_rev;
        for (int i = x_str.length() - 1; i >= 0; --i) {
            x_rev.push_back(x_str[i]);
        }

        return x_str == x_rev;
    }
};
