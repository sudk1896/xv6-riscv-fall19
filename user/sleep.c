#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int main(int argc, char *argv[])
{
	int id = fork();
	if (id > 0){	
		if (argc != 2){
			printf("Error, Pass only two arguments.\n");
			exit();	
		}
		id = wait();
	}
	else if (id == 0){
		int x = atoi(argv[1]);
		sleep(x);
	}
	exit();
}
