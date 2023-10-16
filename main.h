#ifndef PRINTF_H
#define PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#define BUFF_SIZE 1024
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
typedef struct convert conver_t;

/*Main functions*/
int process(const char *format, conver_t func[], va_list args);
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_pointer(va_list);
int print_int(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reversed(va_list);
int print_rot13(va_list);
int unsigned_int(va_list);
int print_octal(va_list list);
int print_hex(va_list args);
int hex_check(int num, char x);
int print_heX(va_list list);
int print_exclusive_string(const char *format, ...);
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsigned_int(unsigned int);
int print_hex_helper(unsigned long int num);


#endif
