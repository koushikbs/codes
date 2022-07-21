#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sanityCheck(char* s)
{
    int len = 0;
    // Valid input: I=1, V=5, X=10, L=50, C=100, D=500, M=1000
    if (!s)
    {
        printf("Invalid input string.\n");
        return -1;
    }
    len = strlen(s);
    while(*s != '\0')
    {
        if (*s == 'I' || *s == 'V' || *s == 'X' || *s == 'L' ||
            *s == 'C' || *s == 'D' || *s == 'M')
        {
            s++;
        }
        else
        {
            printf("Invalid input string.\n");
            return -1;
        }
    }
    return 0;
}

int convertToInteger(char* s, int* result)
{
    int value = 0;
    int prev = 0;
    
    if (!s)
    {
        printf("%s: Invalid input string.\n", __func__);
        return -1;
    }
    while(*s != '\0')
    {
        switch (*s)
        {
            case 'I':
                value += 1;
                prev = 1;
                break;
            case 'V':
                if (prev == 1) value = value + (5-2);
                else value += 5;
                prev = 5;
                break;
            case 'X':
                if (prev == 1) value = value + (10 - 2);
                else value += 10;    
                prev = 10;
                break;

            case 'L':
                if (prev == 10) value = value + (50-20);
                else value += 50;
                prev = 50;
                break;
            case 'C':
                if (prev == 10) value = value + (100-20);
                else value += 100;
                prev = 100;
                break;
            case 'D':
                if (prev == 100) value = value + (500-200);
                else value += 500;
                prev = 500;
                break;
            case 'M':
                if (prev == 100) value = value + (1000-200);
                else value += 1000;
                prev = 1000;
                break;
            default:
                printf("Invalid roman literal encounteres.\n");
                break;
        }
        s++;
    }
    *result = value;
    
    return value; 
}

int main(int argc, char* argv[])
{
    int ret = -1;
    int result = 0;

    if (argc != 2)
    {
        printf("Invalid input.\n");
        return -1;
    }
    if (!argv[0] || !argv[1])
    {
        printf("Invalid input.\n");
        return -1;
    }
    if (strlen(argv[1]) > 15)
    {
        printf("Invalid input.\n");
        return -1;
    }
    //printf("inp len = %d.\n", strlen(argv[1]));
    ret = sanityCheck(argv[1]); 
    if (ret != 0)
    {
        printf("Invalid input.\n");
        return -1;
    }
    ret = convertToInteger(argv[1], &result);
    printf("Result: %d.\n", result);
    return 0;
}
