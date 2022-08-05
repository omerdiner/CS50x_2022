#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Usage: ./recover");
        return 1;
    }

    FILE * file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Couldn't open the file! ");
        return 2;
    }

    BYTE buffer[512];

    int imageCount = 0;

    FILE * output = NULL;

    char * fileName = malloc(sizeof(char) * 8);

    while (fread(buffer, sizeof(char), 512, file)) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
        	if (imageCount != 0)
                {
                    fclose(output);
                }
            sprintf(fileName, "%03d.jpg", imageCount);

            output = fopen(fileName, "w");

            imageCount++;

            if (output != NULL) {
                fwrite(&buffer, sizeof(char), 512, output);
            }
        }
    }

    free(fileName);
    fclose(output);
    fclose(file);

    return 0;

}
