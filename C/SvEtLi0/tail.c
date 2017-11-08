#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define ERR_BUFF_SIZE 256




int main(int argc, char *argv[]){

	int fd;
	int count;
	char buf[ERR_BUFF_SIZE];
	char symbol[1];
	int newline_counter=0;
	if(argc == 1){
		write(2, "tail: cannot oppen file for readiing. No file specified.\n", 58);
	}
//da se opravi ^^

	if(argc > 1){
		for(count = 0; count<=argc; count++){
			fd=open(argv[count], O_RDONLY);
			if(fd <= 0){
				int res = snprintf(buf, ERR_BUFF_SIZE,"tail: cannot open '%s' for reading: No such file or directory\n", argv[count]);
				write(2, buf, res);
			}
			
			
		}
	}
	printf("New lines are: %d", newline_counter);
	return 0;
}

