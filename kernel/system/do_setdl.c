#include "kernel/system.h"
#include <minix/endpoint.h>

void reach_deadline(timer_t * tp);

/*===========================================================================*
  *                                do_setdl                                 *
  *===========================================================================*/
int do_setdl(struct proc *caller_ptr, message *m_ptr)
{
	
	struct proc *rp;
  	timer_t *tp;

/* 1.get the process*/
  	rp = proc_addr(m_ptr->m1_i2);
/* 2.change the priority*/
  	RTS_SET(rp, RTS_NO_QUANTUM);
/* 3.check whether to reset the deadline*/
  	if (rp->p_deadline.tmr_exp_time!=0){
    	reset_timer(&rp->p_deadline); 
    	rp->p_deadline.tmr_exp_time = 0;
  	}
  	if (m_ptr->m1_i1!=0){
/* 4.set the alarm clock*/
  		tp = &rp->p_deadline;
  		tp->tmr_arg.ta_int = rp->p_nr;
  		tp->tmr_exp_time = m_ptr->m1_i1*60+get_uptime();
  		tp->tmr_func = reach_deadline; 	
  		printf("Process %d set timer, deadline=%d \n",tp->tmr_arg.ta_int,tp->tmr_exp_time);
  		set_timer(tp,tp->tmr_exp_time,tp->tmr_func);
  	}
/* 5. enqueue the process*/
	RTS_UNSET(rp, RTS_NO_QUANTUM);
  	return(OK);

}

void reach_deadline(timer_t *tp)
{
  printf("Process %d reach deadline...\n",tp->tmr_arg.ta_int);
/*provide a signal to teminate the process*/
  cause_sig(tp->tmr_arg.ta_int,SIGTERM);
  return;
}
