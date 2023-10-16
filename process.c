#include "main.h"
/**
 * process - recieves input with arguments and print formatted string
 * @format: designation format
 * @func: list of possible functions
 * @args: list of arguments
 *
 * Return: total count of character printed
 */
int process(const char *format, conver_t func[], va_list args)
{
	int a, b, value, p_result;

	p_result = 0;
	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] == '%')
		{
			for (b = 0; func[b].sym != NULL; b++)
			{
				if (format[a + 1] == func[b].sym[0])
				{
					value = func[b].f(args);
					if (value == -1)
						return (-1);
					p_result += value;
					break;
				}
			}
			if (func[b].sym == NULL && format[a + 1] != ' ')
			{
				if (format[a + 1] != '\0')
				{
					_putchar(format[a]);
					_putchar(format[a + 1]);
					p_result = p_result + 2;
				}
				else
					return (-1);
			}
			a = a + 1;
		}
		else
		{
			_putchar(format[a]);
			p_result++;
		}
	}
	return (p_result);
}
