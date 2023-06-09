#include <stdio.h>
#include<cs50.h>

int getNumber(void){
    int levels;
    do{
        levels = get_int("How many levels? ");
    }while(levels < 1 || levels > 8);
    return levels;
}

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
    drawPyramid(getNumber());

}