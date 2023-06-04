/********************************************************************/
/* A Small Real Time System for the Real-Time laboratory            */
/* built by: A.Teitelbaum on an idea of H.G.Mendelbaum              */
/* Jerusalem College of Technology, 5759-64 (1999-03)               */
/* update  Tishrey   5777                                           */
/* APP77.CPP, an application to demonstrate SMARTS77  functioning   */
/********************************************************************/
#include "smarts77.h"
#define NUM_OF_LOOPS 5
#define INHERITANCE_FLAG 1

Mutex ioMutex(INHERITANCE_FLAG);
Mutex cenMutex(INHERITANCE_FLAG), amiMutex(INHERITANCE_FLAG);
Event evCtoA, evCtoB;
//FILE* f = fopen("withoutpriorityinheritance.txt", "w");  //a  == append, w == write
FILE* f = fopen("withpriorityinheritance.txt", "w");  //a  == append, w == write
// user Functions
void a()
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   A Start    *********************\n";
	fprintf(f, "\n *************   A Start    *********************\n");
	ioMutex.release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "A";
		fprintf(f, "A");
		ioMutex.release();
	}
	
	ioMutex.acquire();
	cout << "\n *************   A wait event from C    *********************\n";
	fprintf(f, "\n *************   A wait event from C    *********************\n");
	ioMutex.release();

	char w;
	evCtoA.wait(w);

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "A";
		fprintf(f, "A");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   A acquire   *********************\n";
	fprintf(f, "\n *************   A acquire    *********************\n");
	ioMutex.release();

	cenMutex.acquire();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "A";
		fprintf(f, "A");
		ioMutex.release();
	}

	// ???????????????????????????????????????????????????????????????????
	ioMutex.acquire();
	cout << "\n *************   A release   *********************\n";
	fprintf(f, "\n *************   A release    *********************\n");
	ioMutex.release();

	cenMutex.release();
	// ???????????????????????????????????????????????????????????????????

	ioMutex.acquire();
	cout << "\n *************   A Finish   *********************\n";
	fprintf(f, "\n *************   A Finish    *********************\n");
	ioMutex.release();
}

void b()
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   B Start    *********************\n";
	fprintf(f, "\n *************   B Start    *********************\n");
	ioMutex.release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "B";
		fprintf(f, "B");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   B wait event from C    *********************\n";
	fprintf(f, "\n *************   B wait event from C    *********************\n");
	ioMutex.release();

	char w;
	evCtoB.wait(w);

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "B";
		fprintf(f, "B");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   B Finish   *********************\n";
	fprintf(f, "\n *************   B Finish    *********************\n");
	ioMutex.release();
}

void c()
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   C Start    *********************\n";
	fprintf(f, "\n *************   C Start    *********************\n");
	ioMutex.release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "C";
		fprintf(f, "C");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   C acquire   *********************\n";
	fprintf(f, "\n *************   C acquire    *********************\n");
	ioMutex.release();

	cenMutex.acquire();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "C";
		fprintf(f, "C");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   C send event to A    *********************\n";
	fprintf(f, "\n *************   C send event to A    *********************\n");
	ioMutex.release();

	char w;
	evCtoA.send('A', NULL, 0);

	ioMutex.acquire();
	cout << "\n *************   C send event to B    *********************\n";
	fprintf(f, "\n *************   C send event to B    *********************\n");
	ioMutex.release();

	evCtoB.send('B', NULL, 0);

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "C";
		fprintf(f, "C");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   C release   *********************\n";
	fprintf(f, "\n *************   C release    *********************\n");
	ioMutex.release();

	cenMutex.release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "C";
		fprintf(f, "C");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   C Finish   *********************\n";
	fprintf(f, "\n *************   C Finish    *********************\n");
	ioMutex.release();
}

void main()
{
	clrscr();
	// RR
	//SMARTS.externalFunctions(timerInterruptHandler, scheduler, myTaskEnd, roundRobin);
	// EDF
	//SMARTS.externalFunctions(timerInterruptHandler, scheduler, myTaskEnd, EDF);
	// RMS
	SMARTS.externalFunctions(timerInterruptHandler, scheduler, myTaskEnd, RMS);
	SMARTS.declareTask(a, 'A', 400, 3); //void far* code, char name, int cycleTime, int cycles
	SMARTS.declareTask(b, 'B', 401, 3);
	SMARTS.declareTask(c, 'C', 402, 3);
	SMARTS.runTheTasks();
	fclose(f);
	scanf("%d");
}

/*
5, 600,000 - EDF & RR
100, 600,000 - !EDF & !RR
10, 600,000 - EDF & !RR
Amiad Korman & Yechezkel Chen
*/

