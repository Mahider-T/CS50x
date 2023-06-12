#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // index = 0.0588 * L - 0.296 * S - 15.8
    // L = average number of letters per 100 words
    // S = average number of sentences per 100 words
    float l, s, index;
    int finalIndex;
    string text = get_string("Text: ");
    int numberOfLetters = count_letters(text);
    int numberOfWords = count_words(text);
    int numberOfSentences = count_sentences(text);
    l = (((float)numberOfLetters/(float)numberOfWords))*(float)100;
    s = (((float)numberOfSentences/(float)numberOfWords))*(float)100;
    index = (0.0588 * l) - (0.296 * s) - 15.8;
    finalIndex = round(index);

    if(index >= 16){
        printf("Grade 16+");
    }
    else if(index < 1){
        printf("Before Grade 1");
    }
    else{
        printf("Grade %i\n", finalIndex);
    }

    // printf("%i letters\n", numberOfLetters);
    // printf("%i words\n", numberOfWords);
    // printf("%i sentences\n", numberOfSentences);


}

int count_letters(string text){
    int lengthOfString = strlen(text);
    int count = 0;
    char character;

    for( int i= 0; i < lengthOfString; i++){
        character = toupper(text[i]);
        if(character < 65 || character > 90){
            continue;
        }
        else{
            count++;
        }
    }
    return count;
}

int count_words(string text){
    int count = 1;
    char spaceCheck;
    for( int i = 0; i < strlen(text); i++){
        spaceCheck = text[i];
        if(spaceCheck == ' '){
            count++;
        }
    }
    return count;
}

int count_sentences(string text){
    int count = 0;
    char sentenceCheck;
     for( int i = 0; i < strlen(text); i++){
        sentenceCheck = text[i];
        if(sentenceCheck == '.' || sentenceCheck == '?' || sentenceCheck == '!' ){
            count++;
        }
    }
    return count;

}