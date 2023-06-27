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
    while (fread(block, 1, 512, file) == 512)
    {
        if(block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff /*&& (block[3] & 0xf0) == 0xe0*/){
            // printf("%i ", count);
            // count++;
            started = 1;
            count++;
            printf("Start of an Image %i\n", count);
            
        }
        else{
            if(started == 1){
                printf("Remaining of the image %i\n ", count);
            }
        }

    }
}