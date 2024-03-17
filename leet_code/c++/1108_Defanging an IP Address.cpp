#include <string>

class Solution {
public:
    std::string defangIPaddr(std::string address) {
        std::string temp;
        for (int i = 0; i < address.size(); i++) {
            if (address[i] == '.') {
                temp += "[.]";
            } else {
                temp += address[i];
            }
        }
        return temp;
    }
};
