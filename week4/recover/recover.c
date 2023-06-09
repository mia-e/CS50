#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8
bool is_start_new_jpg(BYTE buffer[]);
int main(int argc, char *argv[])
{
    // check that the user only types in one command line argument
    if (argc != 2)
    {
        printf("Usage: /recover image \n");
        return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    // make sure file opens
    if (infile == NULL)
    {
        // advise user that file doesnt open
        printf("file not found\n");
        return 1;
    }
    BYTE buffer[BLOCK_SIZE];
    int file_index = 0;
    bool have_found_first_jpg = false;
    FILE *outfile;
    while (fread(buffer, BLOCK_SIZE, 1, infile))
    {
        if (is_start_new_jpg(buffer))
        {
            if (!have_found_first_jpg)
            {
                have_found_first_jpg = true;
            }
            else
            {
                fclose(outfile);
            }
            char filename[FILE_NAME_SIZE];
            sprintf(filename, "%03i.jpg", file_index++);
            outfile = fopen(filename, "w");
            // if file cant open
            if (outfile == NULL)
            {
                return 1;
            }
            fwrite(buffer, BLOCK_SIZE, 1, outfile);

        }
        else if (have_found_first_jpg)
        {
            //keep on writting the previous file
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }
    // close both files
    fclose(outfile);
    fclose(infile);
}
bool is_start_new_jpg(BYTE buffer[])
{
    // check the beggining of each file
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}
