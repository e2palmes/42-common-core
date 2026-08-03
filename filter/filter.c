#define _GNU_SOURCE

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

char *get_full_text(size_t *len)
{
    ssize_t bytes_read;
    char *buffer;
    char *text;

    *len = 0;
    text = NULL;

    buffer = malloc(BUFFER_SIZE);
    if (!buffer)
        return (NULL);

    while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
    {
        char *tmp = realloc(text, *len + bytes_read);
        if (!tmp)
        {
            perror("Error");
            free(text);
            free(buffer);
            return (NULL);
        }

        text = tmp;
        memmove(text + *len, buffer, bytes_read);
        *len += bytes_read;
    }

    free(buffer);

    if (bytes_read < 0)
    {
        perror("Error");
        free(text);
        return (NULL);
    }

    if (!text)
    {
        text = malloc(1);
        if (!text)
        {
            perror("Error");
            return (NULL);
        }
    }

    return (text);
}

int main(int argc, char **argv)
{
    if (argc != 2 || !*argv[1])
        return (1);
    size_t bytes_read;
    char *text;
    char *pattern = argv[1];
    size_t pattern_len = strlen(pattern);

    text = NULL;
    bytes_read = 0;
    text = get_full_text(&bytes_read);
    if (!text && bytes_read != 0)
        return (1);

    char *current = text;
    char *match;

    while ((match = memmem(current, text + bytes_read - current, pattern, pattern_len)))
    {
        write(1, current, match - current);

        size_t i = 0;
        while (i++ < pattern_len)
            write(1, "*", 1);

        current = match + pattern_len;
    }
    if (current < text + bytes_read)
        write(1, current, text + bytes_read - current);
    free(text);
    return (0);
}