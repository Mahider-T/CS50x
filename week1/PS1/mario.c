#include <stdio.h>
#include<cs50.h>

void drawPyramid(int numberOfLevels){
    for(int i = 1; i<= numberOfLevels; i++){
        for(int j = numberOfLevels; j>= 1; j--){
            if(i>=j){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("  ");
        for(int j = 1; j <= numberOfLevels; j++){
            if(i>=j){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

}

int main(void){
    int levels = get_int("How many levels? ");
    drawPyramid(levels);

}