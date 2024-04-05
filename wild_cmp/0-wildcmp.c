#include <stdio.h>

int wildcmp(char *s1, char *s2) {
    if (*s1 == '\0' && *s2 == '\0') {
        return 1;
    }

    if (*s2 == '*') {
        while (*s1 != '\0') {
            if (wildcmp(s1, s2 + 1)) {
                return 1;
            }
            s1++;
        }
        return wildcmp(s1, s2 + 1);
    }


    if (*s1 == *s2) {
        return wildcmp(s1 + 1, s2 + 1);
    }

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
