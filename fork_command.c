/*
PROGRAM 1
WAP USING FORK() AND EXEC() COMMANDS WHERE PARENT AND CHILD EXECUTE SAME PROGRAM,SAME CODE
*/

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
	int pid;

	pid=fork();

	if(pid<0)

	{

		fprintf(stderr,"Fork failed");

		exit(1);

	}

	else

	{

		printf("Hello,my pid is %d \n",pid);

		exit(-1);

	}

}


/*

OUTPUT



Hello,my pid is 0

Hello,my pid is 64576



*/






/*

PROGRAM 1(b)



WAP USING FORK() AND EXEC() COMMANDS WHERE PARENT AND CHILD EXECUTE SAME PROGRAM,DIFFERENT CODE.

*/



#include<sys/wait.h>

#include<unistd.h>

#include<stdlib.h>

#include<stdio.h>

void main()

{

        int pid;

        pid=fork();

        if(pid<0)

        {

                fprintf(stderr,"Fork failed");

                exit(-1);

        }

        else if(pid>0)

        {

                printf("Hello,my pid is %d \n",pid);

        }

	   else 

	   {

			printf("hi,,,,my pid is %d \n",pid);

	   }

	   exit(0);

}
/*
OUTPUT

hi,,,,my pid is 0

Hello,my pid is 65408

*/






/*

PROGRAM 



WAP USING FORK() AND EXEC() COMMANDS WHERE PARENT AND CHILD EXECUTE DIFFERENT PROGRAMS BY SPECIFYING A PATH

*/



#include<stdlib.h>

#include<stdio.h>

#include<unistd.h>

void main()

{

	int pid;

	pid=fork();

	if(pid<0)

	{

	fprintf(stderr,"Fork Failed");

	exit(-1);

	}

	else if(pid==0)

	{

		execlp("/bin/ls","ls",NULL);

	}

	else

	{

		printf("CHILD COMPLETE");

		exit(0);

	}

}



/*

OUTPUT



CHILD COMPLETE$ Music.exe       q1_b.exe        q2_m.o          q3_f.o

Prac_neha.txt   q1_b.o          q3_a.c          q5_a.c

a.out           q1_c.c          q3_a.o          q5_a.o

fcfs.c          q1_c.o          q3_b.c          q5_b.c

fcfs.o          q1_d.c          q3_b.o          q5_b.o

fcfs_2          q1_d.o          q3_c.c          rr.c

fcfs_2.c        q1_e.c          q3_c.o          rr.o

fcfs_2.o        q1_e.o          q3_d.c          sq.c

file.c          q1_f.c          q3_d.o          sq.o

q1_a.c          q2.c            q3_e.c

q1_a.o          q2.o            q3_e.o

q1_b.c          q2_m.c          q3_f.c



*/





//PROGRAM 1(d)

/*WAP (using fork() and/or exec() commands) WHERE  PARENT AND CHILD EXECUTE : AND BEFORE TERMINATING, THE PARENT WAITS FOR THE CHILD TO FINISH ITS TASK.*/



#imclude<stdio.h>

#include<stdlib.h>

#include<unistd.h>

void main()

{

        int pid;

        pid=fork();

        if(pid<0)

        {

                fprintf(stderr,"Fork failed");

                exit(-1);

        }

        else if(pid==0)

        {

                printf("child pid is : %d\n",pid);

        }

        else

        {

                wait(NULL);

                printf("parent pid is : %d\n",pid);

                exit(0);

        }

}



/*

OUTPUT



$ cc Q1_e.c

$ ./a.out

child pid is : 0

parent pid is : 3268

*/


