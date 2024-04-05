#include <stdio.h>

int wildcmp(char *s1, char *s2) {
    // Base case: if both strings are empty, they are considered identical
    if (*s1 == '\0' && *s2 == '\0') {
        return 1;
    }

    // If the current character in s2 is '*', it can replace any string
    if (*s2 == '*') {
        // Continue to the next character in s2 to see if it can match the remaining of s1
        while (*s1 != '\0') {
            if (wildcmp(s1, s2 + 1)) {
                return 1;
            }
            s1++;
        }
        // If we reach here, it means the rest of s1 doesn't match s2, so return 0
        return wildcmp(s1, s2 + 1);
    }

    // If the current characters in s1 and s2 match, continue to the next characters
    if (*s1 == *s2) {
        return wildcmp(s1 + 1, s2 + 1);
    }

    // If the characters don't match, return 0
    return 0;
}

int main() {
    char s1[] = "hello";
    char s2[] = "h*o";

    if (wildcmp(s1, s2)) {
        printf("Strings are identical\n");
    } else {
        printf("Strings are not identical\n");
    }

    return 0;
}
