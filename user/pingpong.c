#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
void pingpong()
{
	
	int p_[2];
	int p = pipe(p_);
	if (p < 0){
		exit();
	}
	
	char buf[10];
	char* ping = "ping\n";
	char* pong = "pong\n";
	int id = fork();
	if (id == 0){
		read(p_[0], buf, 6);
		fprintf(1, "Child pid: %d\n", getpid());
		fprintf(1, "child output: %s\n", buf);
		write(p_[1], pong, 6);
	}
	else{
		fprintf(1, "Parent pid: %d\n", getpid());
		write(p_[1], ping, 6);
		wait();
		read(p_[0], buf, 6);
		fprintf(1,  "parent output: %s\n", buf);
	}
	exit();	
}
