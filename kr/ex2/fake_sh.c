#include <stdio.h>
/* tiny shell simulation */
main()
{
	int c;
	
	printf("Tiny fake shell\n");
	putchar('>');
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			putchar('>');
		else {
			/* parse command here!
			 * actually i should use getline() 
			 */
		}
	}
}
