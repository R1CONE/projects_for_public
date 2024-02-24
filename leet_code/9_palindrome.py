class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
            return False
        x_str = str(x)
        x_str_return = x_str[::-1]
        x_return = int(x_str_return)
        if x_return == x:
            return True
        else:
            return False
