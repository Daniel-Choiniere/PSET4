// Declares a dictionary's functionality

// these lines just ensure that, even though dictionary.c and speller.c (which you’ll see in a moment) #include this file, clang will only compile it once.
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
// notice our use of #define, a "preprocessor directive" that defines a "constant" called LENGTH that has a value of 45. It’s a constant in the sense that you can’t (accidentally) change it in your own code. In fact, clang will replace any mentions of LENGTH in your own code with, literally, 45. In other words, it’s not a variable, just a find-and-replace trick.
#define LENGTH 45

// Prototypes
bool load(const char *dictionary);
unsigned int size(void);
bool check(const char *word);
bool unload(void);

#endif // DICTIONARY_H
