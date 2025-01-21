#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#define ALPHABET_SIZE 26

void saveEntry(const char *filename, const char *encrypted, const char *key, int shift) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s, %s, %d\n", encrypted, key, shift);
    fclose(file);
    printf("Entry Saved\n");
}
int shiftChar(char c, int shift) {
    if (isalpha(c)) {
        char base = isupper(c) ? 'A' : 'a';
        return (c - base + shift + ALPHABET_SIZE) % ALPHABET_SIZE + base;
    }
    return c;
}

void keyGenerator(char *key) {
    char alphabets[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        alphabets[i] = 'A' + i;
    }
    for (int i = ALPHABET_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = alphabets[i];
        alphabets[i] = alphabets[j];
        alphabets[j] = temp;
    }

    memcpy(key, alphabets, ALPHABET_SIZE);
    key[ALPHABET_SIZE] = '\0';
}

void encrypt(const char *text, char *encrypted, const char *key, int shift) {
    int strLength = strlen(text);
    char map[256] = {0};

    for (int i = 0; i < 26; i++) {
        map['A' + i] = key[i];
        map['a' + i] = key[i] + 32;
    }

    for (int i = 0; i < strLength; i++) {
        char c = text[i];
        if (isalpha(c)) {
            char shifted = shiftChar(c, shift);
            encrypted[i] = map[shifted];
        } else {
            encrypted[i] = c;
        }
    }
    encrypted[strLength] = '\0';
}

void decrypt(const char *encrypted, char *decrypted, const char *key, int shift) {
    int encrLength = strlen(encrypted);
    char reverseMap[256] = {0};

    for (int i = 0; i < 26; i++) {
        reverseMap[key[i]] = 'A' + i;
        reverseMap[key[i] + 32] = 'a' + i;
    }
    for (int i = 0; i < encrLength; i++) {
        char c = encrypted[i];
        if (isalpha(c)) {
            char replacedChar = reverseMap[c];
            decrypted[i] = shiftChar(replacedChar, -shift);
        } else {
            decrypted[i] = c;
        }
    }
    decrypted[encrLength] = '\0';
}
void displayDictionary() {
    FILE *file = fopen("encryptions.csv", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char text[1024];
    printf("Entry:\n");
    while(fgets(text, sizeof(text), file)) {
        printf("%s", text);
    }
    fclose(file);
}

int main() {
    srand(time(NULL));
    char text[1024];
    const char *filename = "encryptions.csv";
    char key [ALPHABET_SIZE + 1];
    char encrypted[1024];
    char decrypted[1024];
    int shift;
    
    printf("Text: \n");
    fgets(text, sizeof(text), stdin);
    if(strcmp(text, "dictionary\n") == 0) {
        displayDictionary();
        return 0;
    }
    shift = rand() % ALPHABET_SIZE;
    keyGenerator(key);
    encrypt(text, encrypted, key, shift);

    saveEntry(filename, encrypted, key, shift);
    printf("Encrypted: %s\n", encrypted);
    
    return 0;
}