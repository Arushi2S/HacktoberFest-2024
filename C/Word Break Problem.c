#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

int wordBreakUtil(char *s, char **wordDict, int dictSize, int start, char *result, int pos) {
    if (start == strlen(s)) {
        result[pos] = '\0';
        printf("%s\n", result);
        return 1; // Found a valid segmentation
    }

    for (int end = start + 1; end <= strlen(s); end++) {
        char temp[MAX_LENGTH];
        strncpy(temp, s + start, end - start);
        temp[end - start] = '\0';

        // Check if the substring is in the dictionary
        for (int i = 0; i < dictSize; i++) {
            if (strcmp(temp, wordDict[i]) == 0) {
                // Include the word in the result and backtrack
                strcpy(result + pos, temp);
                result[pos + strlen(temp)] = ' ';
                if (wordBreakUtil(s, wordDict, dictSize, end, result, pos + strlen(temp) + 1)) {
                    return 1;
                }
            }
        }
    }
    return 0; // No valid segmentation found
}

void wordBreak(char *s, char **wordDict, int dictSize) {
    char result[MAX_LENGTH];
    if (!wordBreakUtil(s, wordDict, dictSize, 0, result, 0)) {
        printf("No valid segmentation found.\n");
    }
}

int main() {
    char s[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", s);

    int dictSize;
    printf("Enter number of words in dictionary: ");
    scanf("%d", &dictSize);
    
    char *wordDict[MAX_WORDS];
    printf("Enter dictionary words:\n");
    for (int i = 0; i < dictSize; i++) {
        wordDict[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
        scanf("%s", wordDict[i]);
    }

    wordBreak(s, wordDict, dictSize);

    // Free allocated memory
    for (int i = 0; i < dictSize; i++) {
        free(wordDict[i]);
    }

    return 0;
}
