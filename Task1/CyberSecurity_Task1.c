#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

void encrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - base + key) % 26 + base;
        }
    }
}

void decrypt(char message[], int key) {
    encrypt(message, 26 - key); // Decryption is just encryption with the opposite key
}

int main() {
    char message[MAX_LENGTH];
    int key, choice;

    printf("Enter a message (up to %d characters): ", MAX_LENGTH - 1);
    fgets(message, sizeof(message), stdin);

    printf("Choose an operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    scanf("%d", &choice);

    printf("Enter the key (a positive integer): ");
    scanf("%d", &key);

    switch (choice) {
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
