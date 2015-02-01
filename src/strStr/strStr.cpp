/*Implement strStr().
 
 Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of
 haystack.*/

#include <stdio.h>
#include <string.h>
#include <assert.h>

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        size_t len1 = strlen(haystack), len2 = strlen(needle);
        
        if (len1 < len2)
            return -1;
        
        if (len2 == 0)
            return 0;
        
        for (int i = 0; i <= len1 - len2; i++) {
            int index1 = i, index2 = 0;
            while (haystack[index1] == needle[index2]) {
                index1++;
                index2++;
                if (index2 == len2)
                    return i;
            }
        }
        
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    assert(s.strStr("abc", "a") == 0);
    assert(s.strStr("abc", "bv") == -1);
    assert(s.strStr("abc", "bc") == 1);
    assert(s.strStr("abc", "c") == 2);
    assert(s.strStr("", "") == 0);
    assert(s.strStr("a","") == 0);
    
    return 0;
}
