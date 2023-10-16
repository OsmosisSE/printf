#ifndef PRINTF_H
#define PRINTF_H


/* header files */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


/* buffer */
#define BUFF_SIZE 1024


/* structure */
/**
* struct convert - defines a structure for symbols and functions
*
* @sym: The operator
* @f: The function associated
*/
struct convert
{
	char *sym;
	int (*f)(va_list);
};
/* strucute type definition */
typedef struct convert conver_t;

/*Main functions*/
int process(const char *format, conver_t func[], va_list args);
int _printf(const char *format, ...);
int _putchar(char c);


/* convertion specifier handlers */
/* task 0 */
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
/* task 1 */
int print_int(va_list);
int print_number(va_list);
/* task 3 */
int print_octa(va_list args);
int print_hexa(va_list args);
int print_heXa(va_list args);
int print_heXa(va_list list);
int hexa_check(int num, char x);

/* custom convertion specifier handlers */
int print_bin(va_list args);
int print_pointer(va_list);
int print_reversed(va_list);
int print_rot13(va_list);


/* print characters that are non-printable */
int print_non(va_list);

int unsigned_int(va_list);
int print_exclusive_string(const char *format, ...);
int print_unsigned_int(unsigned int);

/* helpers */
char *_memcpy(char *dest, char *src, unsigned int n);
unsigned int base_len(unsigned int, int);
void write_base(char *str);
int print_hex_helper(unsigned long int num);
char *rev_string(char *);

int create_hexa(char[], char, int);

#endif
