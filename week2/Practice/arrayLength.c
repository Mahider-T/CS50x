#include <stdio.h>
#include <ctype.h>
#include <cs50.h>

int numberOfElements(char arr[]){
    int length = 0;
    for(int i = 0; arr[i] != '\0'; i++){
        length++;
    }
    return length;
}

int main(int argc, string argv[]){
    int length = numberOfElements(argv[1]);
    printf("%i", length);
    }

