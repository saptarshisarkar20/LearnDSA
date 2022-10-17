def isPalindrome(s):
    return s == s[::-1]
 
 
# Driver code
s = input()
ans = isPalindrome(s)
 
if ans:
    print("true")
else:
    print("false")