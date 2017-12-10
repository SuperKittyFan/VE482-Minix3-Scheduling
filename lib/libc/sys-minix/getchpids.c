#include <sys/cdefs.h>
#include "namespace.h"
#include <lib.h>
#include <unistd.h>


void getchpids(int n, pid_t * chpids){
	for (int i=0;i<n;i++){
		int chpid=getnchpid(i);
		if (chpid!=-1)
			*(chpids++)=chpid;
	}
}

int getnchpid(int n)
{
 message m;
 m.m1_i1=n;
 return( (int) _syscall(PM_PROC_NR, GET_CHPID, &m));
}
