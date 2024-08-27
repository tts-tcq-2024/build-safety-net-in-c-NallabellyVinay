#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void GenerateSoundex(const char* name, char* soundex);
char GetSoundexCode(char c);
void PadSoundex(char* soundex);

// Soundex code mappings
char soundexMap[26] = {
    '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5',
    '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
};

// Generates the Soundex code for a given name
void GenerateSoundex(const char* name, char* soundex) {
    if (name == NULL || strlen(name) == 0) {
        strcpy(soundex, "");
        return;
    }

    // Convert first character to uppercase and add to soundex
    soundex[0] = toupper(name[0]);
    int soundexIndex = 1;

    char prevCode = GetSoundexCode(toupper(name[0]));

    // Process the remaining characters
    for (int i = 1; name[i] != '\0' && soundexIndex < 4; i++) {
        char code = GetSoundexCode(toupper(name[i]));
        if (code != '0' && code != prevCode) {
            soundex[soundexIndex++] = code;
            prevCode = code;
        }
    }

    // Pad the Soundex code to ensure it is four characters long
    PadSoundex(soundex);
}

// Returns the Soundex code for a given character
char GetSoundexCode(char c) {
    if (isalpha(c)) {
        return soundexMap[c - 'A'];
    }
    return '0';
}

// Pads the Soundex code with zeros to ensure it is four characters long
void PadSoundex(char* soundex) {
    int length = strlen(soundex);
    for (int i = length; i < 4; i++) {
        soundex[i] = '0';
    }
    soundex[4] = '\0';
}

// Test the Soundex algorithm
int main() {
    char name[] = "Robert";
    char soundex[5]; // 4 characters + null terminator

    GenerateSoundex(name, soundex);
    printf("Soundex for %s: %s\n", name, soundex);

    return 0;
}
