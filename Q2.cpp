#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26


void monoalphabeticSubstitution(char *plaintext, char *key) {
    int length = strlen(plaintext);
    char ciphertext[length + 1];

    for (int i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            int index = plaintext[i] - base;
            ciphertext[i] = isupper(plaintext[i]) ? toupper(key[index]) : tolower(key[index]);
        } else {
            ciphertext[i] = plaintext[i]; 
        }
    }

    ciphertext[length] = '\0';
    printf("Encrypted text: %s\n", ciphertext);
}

int main() {
    char plaintext[1000];
    char key[ALPHABET_SIZE + 1];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    printf("Enter the key (a string of 26 unique characters): ");
    scanf("%s", key);

    
    int keyLength = strlen(key);
    if (keyLength != ALPHABET_SIZE) {
        printf("Invalid key. Key length should be 26 characters.\n");
        return 1;
    }

    
    for (int i = 0; i < keyLength; i++) {
        if (!isalpha(key[i])) {
            printf("Invalid key. Key should contain only alphabetic characters.\n");
            return 1;
        }
    }

    
    for (int i = 0; i < keyLength - 1; i++) {
        for (int j = i + 1; j < keyLength; j++) {
            if (tolower(key[i]) == tolower(key[j])) {
                printf("Invalid key. Key should contain unique characters.\n");
                return 1;
            }
        }
    }

    monoalphabeticSubstitution(plaintext, key);

    return 0;
}

