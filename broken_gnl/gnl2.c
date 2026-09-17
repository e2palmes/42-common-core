#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    static ssize_t pos = 0;
    static ssize_t bytes_read = 0;
    char *ret;
    char *tmp;
    size_t capacity = 1024;
    size_t i = 0;
    size_t j;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    ret = malloc(capacity);
    if (!ret)
        return NULL;
    while (1)
    {
        // Relire seulement quand le buffer est consommé.
        if (pos == bytes_read)
        {
            pos = 0;
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            if (bytes_read <= 0)
                break;
        }
        // Garder une place pour le '\0'.
        if (i == capacity - 1)
        {
            tmp = malloc(capacity * 2);
            if (!tmp)
            {
                free(ret);
                pos = 0;
                bytes_read = 0;
                return NULL;
            }
            j = 0;
            while (j < i)
            {
                tmp[j] = ret[j];
                j++;
            }
            free(ret);
            ret = tmp;
            capacity *= 2;
        }
        ret[i++] = buffer[pos++];
        if (ret[i - 1] == '\n')
            break;
    }
    if (i == 0 || bytes_read < 0)
    {
        free(ret);
        pos = 0;
        bytes_read = 0;
        return NULL;
    }
    ret[i] = '\0';
    return ret;
}
