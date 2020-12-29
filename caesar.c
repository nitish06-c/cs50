#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(int argc , string argv[])
{
    if (argc != 2)
    {
        printf ("Usage: ./caesar key");
        return 1;
    }
    int key = atoi(argv[1]);
    if (key < 0)
    {
    printf ("Usage: ./caesar key");
    return 1;
    }
    else
    {
        string plaintext= get_string("plaintext: ");
        printf("ciphertext: ");

           for (int i = 0; i < strlen(plaintext); i++)
        {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue; 
        }

        int ascii_offset= isupper(plaintext[i]) ? 65 : 97;
        int pi = plaintext[i] - ascii_offset;
        int ci = (pi + key) % 26;

        printf("%c", ci + ascii_offset);
    }

    printf("\n");
    return 0;
    }
}
}