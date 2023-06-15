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
#define RECURSIA_FLAG 1
#define CYCLES 3

Mutex ioMutex(0, 0);
/*
//Mutex cenMutex(INHERITANCE_FLAG, RECURSIA_FLAG), amiMutex(INHERITANCE_FLAG, RECURSIA_FLAG);
//Event evCtoA, evCtoB, evFtoD, evFtoE;
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
*/

//Mutex mutexA(INHERITANCE_FLAG, RECURSIA_FLAG), mutexB(INHERITANCE_FLAG, RECURSIA_FLAG), mutexC(INHERITANCE_FLAG, RECURSIA_FLAG), mutexD(INHERITANCE_FLAG, RECURSIA_FLAG);
Event evEtoD, evDtoC, evCtoB, evBtoA;
FILE* file = fopen("withRec.txt", "w");
//FILE* file = fopen("withoutR.txt", "w");

void A() 
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   A Start    *********************\n";
	fprintf(file, "\n *************   A Start    *********************\n");
	ioMutex.release();

	ioMutex.acquire();
	cout << "\n *************   A wait event from B    *********************\n";
	fprintf(file, "\n *************   A wait event from B    *********************\n");
	ioMutex.release();

	char w;
	evBtoA.wait(w);

	ioMutex.acquire();
	cout << "\n *************   A acquire mutexA  *********************\n";
	fprintf(file, "\n *************   A acquire mutexA   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[0].acquire();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "A";
		fprintf(file, "A");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   A release mutexA  *********************\n";
	fprintf(file, "\n *************   A release mutexA   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[0].release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "A";
		fprintf(file, "A");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   A Finish   *********************\n";
	fprintf(file, "\n *************   A Finish    *********************\n");
	ioMutex.release();
}

void B()
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   B Start    *********************\n";
	fprintf(file, "\n *************   B Start    *********************\n");
	ioMutex.release();

	ioMutex.acquire();
	cout << "\n *************   B wait event from C    *********************\n";
	fprintf(file, "\n *************   B wait event from C    *********************\n");
	ioMutex.release();

	char w;
	evCtoB.wait(w);

	ioMutex.acquire();
	cout << "\n *************   B acquire mutexA  *********************\n";
	fprintf(file, "\n *************   B acquire mutexA   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[0].acquire();

	ioMutex.acquire();
	cout << "\n *************   B acquire mutexB  *********************\n";
	fprintf(file, "\n *************   B acquire mutexB   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[1].acquire();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "B";
		fprintf(file, "B");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   B send event to A    *********************\n";
	fprintf(file, "\n *************   B send event to A    *********************\n");
	ioMutex.release();

	evBtoA.send('A', NULL, 0);

	ioMutex.acquire();
	cout << "\n *************   B release mutexB  *********************\n";
	fprintf(file, "\n *************   B release mutexB   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[1].release();

	ioMutex.acquire();
	cout << "\n *************   B release mutexA  *********************\n";
	fprintf(file, "\n *************   B release mutexA   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[0].release();

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

void C()
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   C Start    *********************\n";
	fprintf(file, "\n *************   C Start    *********************\n");
	ioMutex.release();

	ioMutex.acquire();
	cout << "\n *************   C wait event from D    *********************\n";
	fprintf(file, "\n *************   C wait event from D    *********************\n");
	ioMutex.release();

	char w;
	evDtoC.wait(w);

	ioMutex.acquire();
	cout << "\n *************   C acquire mutexB  *********************\n";
	fprintf(file, "\n *************   C acquire mutexB   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[1].acquire();

	ioMutex.acquire();
	cout << "\n *************   C acquire mutexC  *********************\n";
	fprintf(file, "\n *************   C acquire mutexC   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[2].acquire();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "C";
		fprintf(file, "C");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   C send event to B    *********************\n";
	fprintf(file, "\n *************   C send event to B    *********************\n");
	ioMutex.release();

	evCtoB.send('B', NULL, 0);

	ioMutex.acquire();
	cout << "\n *************   C release mutexC  *********************\n";
	fprintf(file, "\n *************   C release mutexC   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[2].release();

	ioMutex.acquire();
	cout << "\n *************   C release mutexB  *********************\n";
	fprintf(file, "\n *************   C release mutexB   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[1].release();

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

void D()
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   D Start    *********************\n";
	fprintf(file, "\n *************   D Start    *********************\n");
	ioMutex.release();

	ioMutex.acquire();
	cout << "\n *************   D wait event from E    *********************\n";
	fprintf(file, "\n *************   D wait event from E    *********************\n");
	ioMutex.release();

	char w;
	evEtoD.wait(w);

	ioMutex.acquire();
	cout << "\n *************   D acquire mutexC  *********************\n";
	fprintf(file, "\n *************   D acquire mutexC   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[2].acquire();

	ioMutex.acquire();
	cout << "\n *************   D acquire mutexD  *********************\n";
	fprintf(file, "\n *************   D acquire mutexD   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[3].acquire();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "D";
		fprintf(file, "D");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   D send event to C    *********************\n";
	fprintf(file, "\n *************   D send event to C    *********************\n");
	ioMutex.release();

	evDtoC.send('C', NULL, 0);

	ioMutex.acquire();
	cout << "\n *************   D release mutexD  *********************\n";
	fprintf(file, "\n *************   D release mutexD   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[3].release();

	ioMutex.acquire();
	cout << "\n *************   D release mutexC  *********************\n";
	fprintf(file, "\n *************   D release mutexC   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[2].release();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "D";
		fprintf(file, "D");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   D Finish   *********************\n";
	fprintf(file, "\n *************   D Finish    *********************\n");
	ioMutex.release();
}

void E() 
{
	int j;
	ioMutex.acquire();
	cout << "\n *************   E Start    *********************\n";
	fprintf(file, "\n *************   E Start    *********************\n");
	ioMutex.release();

	ioMutex.acquire();
	cout << "\n *************   E acquire mutexD  *********************\n";
	fprintf(file, "\n *************   E acquire mutexD   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[3].acquire();

	for (j = 0; j < NUM_OF_LOOPS; j++)
	{
		for (long i = 0; i < 600000; i++);
		ioMutex.acquire();
		cout << "E";
		fprintf(file, "E");
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   E send event to D    *********************\n";
	fprintf(file, "\n *************   E send event to D    *********************\n");
	ioMutex.release();

	evEtoD.send('D', NULL, 0);

	ioMutex.acquire();
	cout << "\n *************   E release mutexD  *********************\n";
	fprintf(file, "\n *************   E release mutexD   *********************\n");
	ioMutex.release();

	SMARTS.mutexes[3].release();

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

void main()
{
	clrscr();
	// RR
	//SMARTS.externalFunctions(timerInterruptHandler, scheduler, myTaskEnd, roundRobin);
	// EDF
	//SMARTS.externalFunctions(timerInterruptHandler, scheduler, myTaskEnd, EDF);
	// RMS
	SMARTS.externalFunctions(timerInterruptHandler, scheduler, myTaskEnd, RMS);
	//SMARTS.declareTask(a, 'A', 400, CYCLES); //void far* code, char name, int cycleTime, int cycles
	//SMARTS.declareTask(b, 'B', 401, CYCLES);
	//SMARTS.declareTask(c, 'C', 402, CYCLES);

	//SMARTS.declareTask(d, 'D', 403, CYCLES);
	//SMARTS.declareTask(e, 'E', 404, CYCLES);
	//SMARTS.declareTask(f, 'F', 405, CYCLES);

	SMARTS.declareTask(A, 'A', 400, CYCLES); //void far* code, char name, int cycleTime, int cycles
	SMARTS.declareTask(B, 'B', 401, CYCLES);
	SMARTS.declareTask(C, 'C', 402, CYCLES);

	SMARTS.declareTask(D, 'D', 403, CYCLES);
	SMARTS.declareTask(E, 'E', 404, CYCLES);

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

