/********************************************************************/
/* A Small Real Time System for the Real-Time laboratory            */
/* built by: A.Teitelbaum on an idea of H.G.Mendelbaum              */
/* Jerusalem College of Technology, 5759-64 (1999-03)               */
/* update  Tishrey   5777                                           */
/* APP77.CPP, an application to demonstrate SMARTS77  functioning   */
/********************************************************************/
#include "smarts77.h"
#define NUM_OF_LOOPS 5
#define INHERITANCE_FLAG 0
#define CYCLES 3

Mutex ioMutex(0);
Mutex cenMutex(INHERITANCE_FLAG), amiMutex(INHERITANCE_FLAG);
Event evCtoA, evCtoB, evFtoD, evFtoE;
FILE* file = fopen("withoutP.txt", "w");  //a  == append, w == write
//FILE* file = fopen("withP.txt", "w");  //a  == append, w == write
// user Functions
void a()
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   A Start    *********************\n";
	fprintf(file, "\n *************   A Start    *********************\n");
	ioMutex.release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "A";
		fprintf(file, "A");
		ioMutex.release();
	}
	
	ioMutex.acquire();
	cout << "\n *************   A wait event from C    *********************\n";
	fprintf(file, "\n *************   A wait event from C    *********************\n");
	ioMutex.release();

	char w;
	evCtoA.wait(w);

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "A";
		fprintf(file, "A");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   A acquire   *********************\n";
	fprintf(file, "\n *************   A acquire    *********************\n");
	ioMutex.release();

	cenMutex.acquire();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "A";
		fprintf(file, "A");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   A release   *********************\n";
	fprintf(file, "\n *************   A release    *********************\n");
	ioMutex.release();

	cenMutex.release();

	ioMutex.acquire();
	cout << "\n *************   A Finish   *********************\n";
	fprintf(file, "\n *************   A Finish    *********************\n");
	ioMutex.release();
}

void b()
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   B Start    *********************\n";
	fprintf(file, "\n *************   B Start    *********************\n");
	ioMutex.release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "B";
		fprintf(file, "B");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   B wait event from C    *********************\n";
	fprintf(file, "\n *************   B wait event from C    *********************\n");
	ioMutex.release();

	char w;
	evCtoB.wait(w);

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "B";
		fprintf(file, "B");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   B Finish   *********************\n";
	fprintf(file, "\n *************   B Finish    *********************\n");
	ioMutex.release();
}

void c()
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   C Start    *********************\n";
	fprintf(file, "\n *************   C Start    *********************\n");
	ioMutex.release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "C";
		fprintf(file, "C");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   C acquire   *********************\n";
	fprintf(file, "\n *************   C acquire    *********************\n");
	ioMutex.release();

	cenMutex.acquire();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "C";
		fprintf(file, "C");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   C send event to A    *********************\n";
	fprintf(file, "\n *************   C send event to A    *********************\n");
	ioMutex.release();

	char w;
	evCtoA.send('A', NULL, 0);

	ioMutex.acquire();
	cout << "\n *************   C send event to B    *********************\n";
	fprintf(file, "\n *************   C send event to B    *********************\n");
	ioMutex.release();

	evCtoB.send('B', NULL, 0);

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "C";
		fprintf(file, "C");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   C release   *********************\n";
	fprintf(file, "\n *************   C release    *********************\n");
	ioMutex.release();

	cenMutex.release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "C";
		fprintf(file, "C");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   C Finish   *********************\n";
	fprintf(file, "\n *************   C Finish    *********************\n");
	ioMutex.release();
}

void d()
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   D Start    *********************\n";
	fprintf(file, "\n *************   D Start    *********************\n");
	ioMutex.release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "D";
		fprintf(file, "D");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   D wait event from F    *********************\n";
	fprintf(file, "\n *************   D wait event from F    *********************\n");
	ioMutex.release();

	char w;
	evFtoD.wait(w);

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "D";
		fprintf(file, "D");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   D acquire   *********************\n";
	fprintf(file, "\n *************   D acquire    *********************\n");
	ioMutex.release();

	amiMutex.acquire();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "D";
		fprintf(file, "D");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   D release   *********************\n";
	fprintf(file, "\n *************   D release    *********************\n");
	ioMutex.release();

	amiMutex.release();

	ioMutex.acquire();
	cout << "\n *************   D Finish   *********************\n";
	fprintf(file, "\n *************   D Finish    *********************\n");
	ioMutex.release();
}

void e()
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   E Start    *********************\n";
	fprintf(file, "\n *************   E Start    *********************\n");
	ioMutex.release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "E";
		fprintf(file, "E");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   E wait event from F    *********************\n";
	fprintf(file, "\n *************   E wait event from f    *********************\n");
	ioMutex.release();

	char w;
	evFtoE.wait(w);

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "E";
		fprintf(file, "E");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   E Finish   *********************\n";
	fprintf(file, "\n *************   E Finish    *********************\n");
	ioMutex.release();
}

void f()
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   F Start    *********************\n";
	fprintf(file, "\n *************   F Start    *********************\n");
	ioMutex.release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "F";
		fprintf(file, "F");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   F acquire   *********************\n";
	fprintf(file, "\n *************   F acquire    *********************\n");
	ioMutex.release();

	amiMutex.acquire();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "F";
		fprintf(file, "F");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   F send event to D    *********************\n";
	fprintf(file, "\n *************   F send event to D    *********************\n");
	ioMutex.release();

	char w;
	evFtoD.send('D', NULL, 0);

	ioMutex.acquire();
	cout << "\n *************   F send event to E    *********************\n";
	fprintf(file, "\n *************   F send event to E    *********************\n");
	ioMutex.release();

	evFtoE.send('E', NULL, 0);

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "F";
		fprintf(file, "F");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   F release   *********************\n";
	fprintf(file, "\n *************   F release    *********************\n");
	ioMutex.release();

	amiMutex.release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "F";
		fprintf(file, "F");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   F Finish   *********************\n";
	fprintf(file, "\n *************   F Finish    *********************\n");
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
	SMARTS.declareTask(a, 'A', 400, CYCLES); //void far* code, char name, int cycleTime, int cycles
	SMARTS.declareTask(b, 'B', 401, CYCLES);
    SMARTS.declareTask(c, 'C', 402, CYCLES);

	SMARTS.declareTask(d, 'D', 403, CYCLES);
	SMARTS.declareTask(e, 'E', 404, CYCLES);
	SMARTS.declareTask(f, 'F', 405, CYCLES);

	SMARTS.runTheTasks();
	fclose(file);
	scanf("%d");
}

/*
5, 600,000 - EDF & RR
100, 600,000 - !EDF & !RR
10, 600,000 - EDF & !RR
Amiad Korman & Yechezkel Chen
*/

