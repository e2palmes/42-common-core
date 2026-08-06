#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int match_space(FILE *f)
{
    int c;
    while ((c=fgetc(f)) != EOF && isspace(c))
        ;
    if (c != EOF)
        ungetc(c, f);
    return (1);
}

int match_char(FILE *f, char expected)
{
    int c;

    c = fgetc(f);
    if (c == expected)
        return (1);
    if (c != EOF)
        ungetc(c, f);
    return (0);
}

int scan_char(FILE *f, va_list ap)
{
    char *c;
    int ch;

    c = va_arg(ap, char *);
    ch = fgetc(f);
    if (ch == EOF)
        return (-1);
    *c = (char)ch;
    return (1);
}

int scan_int(FILE *f, va_list ap)
{
    int *n;
    int ch;

    n = va_arg(ap, int *);
    *n = 0;
	while ((ch = fgetc(f)) != EOF && isspace(ch));
	if (ch == EOF)
		return (-1);
    if (!isdigit(ch))
    {
        ungetc(ch, f);
        return (0);
    }
    while (ch != EOF && isdigit(ch))
    {
        *n = *n * 10 + (ch - '0');
        ch = fgetc(f);
    }
    if  (ch != EOF)
        ungetc(ch, f);
    return (1);
}

int scan_string(FILE *f, va_list ap)
{
	char *s;
	int ch;
	int i;

	s = va_arg(ap, char *);
	i = 0;
	while ((ch = fgetc(f)) != EOF && isspace(ch));
	if (ch == EOF)
		return (-1);
	while (ch != EOF && !isspace(ch))
	{
		s[i] = (char)ch;
		ch = fgetc(f);
		i++;
	}
	if (ch != EOF)
		ungetc(ch, f);
	s[i] = '\0';
	return (1);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			return scan_int(f, ap);
		case 's':
			return scan_string(f, ap);
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int ret = ft_vfscanf(stdin, format, ap);
    va_end(ap);
    return ret;
}
