#include "helper.h"


int my_strcmp(char *str, char *dup)
{
    while(*str && *dup)
    {
        if(*str != *dup)
        {
            return 1;
        }

        str++;
        dup++;
    }

    if(*str != '\0' || *dup != '\0')
    {
        return 1;
    }

    return 0;
}

int my_strchr(char *str, char find)
{
    while(*str)
    {
        if(*str == find) return 1;
        str++;
    }

    return 0;
}

char* my_strok(char *str, const char *delim)
{
    static char *next;

    if(str != NULL) next = str;

    if(next == NULL) return NULL;


    while(*next != '\0' && *next == *delim)
    {
        next++;
    }

    if(*next == '\0')
    {
        next = NULL;
        return NULL;
    }

    char *token = next;

    while(*next != '\0' && *next != *delim)
    {
        next++;
    }

    if(*next != '\0')
    {
        *next = '\0';
         next++;
    }
    else
    {
        next = NULL;
    }

    return token;
}

int my_strcspn(const char *str1, const char *str2)
{
    int count = 0;

    while(*str1)
    {
        int j = 0;

        while(str2[j])
        {
            if(*str1 == str2[j]) return count;
            j++;
        } 
        
        count++;
        str1++;
    }
}