#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

int main() {
    char target[MAX_LENGTH + 1];
    char mask[MAX_LENGTH + 1];
    char result[MAX_LENGTH + 1];

    printf("Enter the (target) text that should be no longer than 50 characters: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = '\0'; 

    printf("Enter the (mask) text that should be 50 characters or less.: ");
    fgets(mask, sizeof(mask), stdin);
    mask[strcspn(mask, "\n")] = '\0'; 

    // check
    int target_length = strlen(target);
    int mask_length = strlen(mask);

    int max_length = (target_length > mask_length) ? target_length : mask_length;
    
    //loop check
    for (int i = 0; i < max_length; i++) {
        char t = (i < target_length) ? target[i] : ' ';
        char m = (i < mask_length) ? mask[i] : ' ';

        if (isupper(t) && isupper(m)) {
            result[i] = t;
        } else if (islower(t) && islower(m)) {
            result[i] = m;
        } else if (isupper(t) && islower(m)) {
            result[i] = m;
        } else if (islower(t) && isupper(m)) {
            result[i] = '$';
        } else {
            result[i] = '#';
        }
    }

    result[max_length] = '\0';

    printf("RESULT: %s\n", result);

    return 0;
}