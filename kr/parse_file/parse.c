/*
 * File: parse.c
 * Description:
 *	Parse origin.src file which contain many source files
 *	that concatenated one by one.
 * History:
 *	Jan 24, 2016	Daniel Ni	Create
 */
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BUF	(1000)

/*TODO 
 * get ralative path, using like command pwd somehow.
 */
char FILENAME[] = "/home/tgni/workspace/c/parse_file/origin.src";
char PATH[128] = "/home/tgni/workspace/c/parse_file/out/";
char HDR[] = "/* File: ";
char TAIL[] = " */"; 

int parse(const char *path)
{
	FILE *fp, *new = NULL;
	char *line = NULL;
	char *p, *e;
	char filename[128];
	char name[32];
	size_t len = 0;
	int read = 0;

	fp = fopen(path, "rb");
	if (!fp) {
		printf("error open file:%s\n", path);
		return -1;
	}

	while ((read = getline(&line, &len, fp)) != -1) {
		if (strncmp(line, HDR, strlen(HDR)) == 0) {
			if (new) {
				fflush(new);
				fclose(new);
			}
			p = line + strlen(HDR);
			e = strstr(p, TAIL);
			if (!e) {
				printf("error invalid header:%s\n", line);
				break;
			}
			strncpy(name, p, e - p);
			name[e - p] = '\0';
			strcpy(filename, PATH);
			strcat(filename, name);
			
			printf("create: %s\n", filename);
			new = fopen(filename, "w+");
			if (!new) {
				printf("error create %s\n",filename);	
				return -1;
			}
			//fputs(line, new);
			/* TODO 
			 * Manybe a new formatted Header can add here
			 */
		} else {
			fputs(line, new);	
		}
	}

	free(line);
	fclose(fp);

	return 0;
}

main()
{
	parse(FILENAME);
}
