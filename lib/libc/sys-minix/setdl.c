#include <sys/cdefs.h>
#include "namespace.h"
#include <lib.h>
#include <unistd.h>


int setdl(int ddl,int index){
  message m;
  m.m1_i1=ddl;
  m.m1_i2=index;
  return(_syscall(PM_PROC_NR, SETDL, &m));
}