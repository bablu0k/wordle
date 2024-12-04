#include <stdio.h>
#include <string.h>

void string_match(char*, char*, int*);
void char_is_in(char*, char*, int*);

void wordle(char* word, char* guess, int* indices, int* dict) {
   
    char* ptr1 = word;
    char* ptr2 = guess;
    int i = 0;
    // first search for matching indices
    while (*ptr1 && *ptr2) {
        if (*ptr1 == *ptr2) {
            indices[i++] = 1;    
            dict[*ptr1-97]--;
        } else {
            indices[i++] = -1;
        } 
        ptr1++;
        ptr2++;
    }
   
    // second update for is_in characters
    for (int j = 0; j < i; j++) {
        if (indices[j] == 1) {
            continue;
        } else {
            if (dict[guess[j] - 97] > 0) {
                dict[guess[j] - 97]--;
                indices[j] = 2;
            }
        }
    }
}

int main () {
    char* word = "aabbc";
    char guess[6];
    int indices[5], dict[26];          // Making use of ascii to convert an array to dict: 97
    memset(dict, 0, sizeof(dict));
    
    char *ptr = word;
    while (*ptr) {
        dict[(int)(*ptr) - 97]++;
        ptr++;
    }

    while (1) {
        char *ptr = word;
        while (*ptr) {
            dict[(int)(*ptr) - 97]++;
            ptr++;
        }
        printf("\n--------------------");
        printf("\nEnter your guess:");
        scanf("%5s", guess);
        wordle(word, guess, indices, dict);
        int all_indices_1 = 1;
        printf("\nyour guess: |     %s     ", guess);
        printf("\nresult    : |     ");
        for (int i = 0; i < 5; i++) {
            if (indices[i] == 1) {
                printf("\033[42m%c\033[0m", guess[i]);
            } else if (indices[i] == 2) {
                all_indices_1 = 0;
                printf("\033[43m%c\033[0m", guess[i]);
            } else {
                all_indices_1 = 0;
                printf("\033[41m%c\033[0m", guess[i]);
            }
        } 
        printf("     ");
        printf("\n--------------------");
        if (all_indices_1) {
            printf("\ngreat you got it right...., thanks for playing..., see ya!\n");
            break;
        } else {
            printf("\nNah, try again...");
        } 
        memset(dict, 0, sizeof(dict));
    }
    return 0;
}
