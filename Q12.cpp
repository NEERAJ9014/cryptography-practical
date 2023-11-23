#include <stdio.h>

void hillCipherEncrypt(int plaintext[], int key[2][2], int length) {
    int i;
    for (i = 0; i < length; i += 2) {
        int p1 = plaintext[i];
        int p2 = plaintext[i + 1];

        int encrypted1 = (key[0][0] * p1 + key[0][1] * p2) % 26;
        int encrypted2 = (key[1][0] * p1 + key[1][1] * p2) % 26;

        printf("%c%c", (char)(encrypted1 + 'A'), (char)(encrypted2 + 'A'));
    }
}

int main() {
    int key[2][2] = {{9, 4}, {5, 7}};
    int plaintext[] = {
        12, 4, 4, 19, 12, 4, 19, 19, 20, 8, 5, 20, 21, 19, 1, 12, 16, 12, 1, 3, 5, 1, 20, 20,
        5, 14, 18, 1, 20, 8, 1, 14, 5, 20, 8, 1, 14, 5, 9, 7, 8, 20, 15, 12, 15, 3, 11
    };
    int length = sizeof(plaintext) / sizeof(plaintext[0]);

    printf("Encrypted ciphertext:\n");
    hillCipherEncrypt(plaintext, key, length);

    return 0;
}

