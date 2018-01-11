# VE482-Minix3-Scheduling
## Objectives
This project is aimed at designing two different scheduling schemes for MINIX 3.2.1 Operating system.
## Description
This new operating systems runs two different kind of scheduling process:
1. Lottery Scheduling 
2. Earliest Deadline scheduling
## (The compilaton instrctions is omitted, see minix3.org for details)
## How to activate them
### Lottery scheduling
When writing a program, you can use the system call nice(x) to activate lottery scheduling for certain program. The larger the x is, the lower the priority will be and the lower the chance it will be picked during the scheduling
### Earliest Deadline Scheduling
Use the systemcall setdl(x,y), where x is the deadline for certain program,and y is the pid of the process. That is, you can set deadline for other processes.
