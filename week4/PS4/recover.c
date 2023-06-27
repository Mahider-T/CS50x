#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
     typedef uint8_t BYTE;
    BYTE block[512];

    if( argc != 2){
        printf("usage ./recover image\n");
        return 1;
    }

    // char *photo = argv[1];
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }


        int count = 0;
        int started = 0;
        FILE *fileWrite;
    while (fread(block, 1, 512, file) == 512)
    {
        if(block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff /*&& (block[3] & 0xf0) == 0xe0*/){
            // printf("%i ", count);
            // count++;
            started = 1;
            count++;
            char fileNow[9];
            sprintf(fileNow, "%03i.jpg",count-1);
            if(count != 1 && count != 0){
                // char fileBefore[9];
                // sprintf(fileBefore, "%03i.jpg",count-2);
                fclose(fileWrite);
            }
            fileWrite = fopen(fileNow, "w");
            fwrite(block, 1, 512, fileWrite);

            printf("Start of an Image %i\n", count);//Debug


        }
        else{
            if(started == 1){
                printf("Remaining of the image %i\n ", count);
                 char fileNow[9];
                 sprintf(fileNow, "%03i.jpg",count-1);
                //  FILE *fileWrite = fopen(fileNow, "a");
                 fwrite(block, 1, 512, fileWrite);
            }
        }

    }
}