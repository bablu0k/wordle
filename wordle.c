#include <stdio.h>
#include <string.h>


void string_match(char*, char*, int*);
void char_is_in(char*, char*, int*);

// TODO: Complete character is in function.  
// NOTE: printf("\033[43mThis text has a yellow background.\033[0m\n");

void string_match(char* word, char* guess, int* indices) {
    int i = 0;
    while (*word && *guess) {
        if (*word == *guess) {
           indices[i] = 1; 
        } else {
            indices[i] = -1;
        }
        i++;
        word++;
        guess++;
    }
}


void char_is_in(char* word, char* guess, int* indices) {
     
}



int main () {
    char* word = "naras";
    char guess[6];
    int indices[5];
    printf("Enter your guess:");
    scanf("%5s", guess);
    string_match(word, guess, indices);
    char_is_in(word, guess, indices);
    for(int i = 0; i < strlen(word); i++) {
        if (indices[i] == 1) {
            printf("\033[42m%c\033[0m", guess[i]);
        }
        else { 
            printf("\033[41m%c\033[0m", guess[i]);
        }
    }
    printf("\n");
    return 0;
}
