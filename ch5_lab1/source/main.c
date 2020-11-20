#include <stdio.h>
#include <stdlib.h>

#define student 3
#define exams 4

void minimum(int grades[][exams], int p, int texts);
void maximum(int grades[][exams], int p, int texts);
void average(int grades[][exams], int p, int texts);
void printarray(int grades[][exams], int p, int texts);
void printmenu();

int main(void)
{
	int studentgrades[student][exams] = { {77,68,86,73},
								  {96,87,89,78},
								  {70,90,86,81} };

	void(*processgrages[4])(int[student][exams], int, int)
		= { printarray,minimum,maximum,average };

	int choice = 0;
	while (choice != 4)
	{
		do {
			printmenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4)
		{
			(*processgrages[choice])(studentgrades, student, exams);
		}
		else
		{
			printf("\tProgram Ended. \n");
		}
	}
	system("pause");
	return 0;
}

void minimum(int grades[][exams], int p, int texts)
{
	int i, j;
	int lowgrade = 100;

	for (i = 0; i < p; i++) 
	{
		for (j = 0; j < texts; j++) 
		{
			if (grades[i][j]<lowgrade) 
			{
				lowgrade = grades[i][j];
			}
		}
	}
	printf("\n\tThe lowest grade is %d", lowgrade);
	printf("\n");
}

void maximum(int grades[][exams], int p, int texts)
{
	int i, j;
	int highrade = 0;

	for (i = 0; i < p; i++)
	{
		for (j = 0; j < texts; j++)
		{
			if (grades[i][j] > highrade)
			{
				highrade = grades[i][j];
			}
		}
	}
	printf("\n\tThe hightest grade is %d", highrade);
	printf("\n");
}

void average(int grades[][exams], int p, int texts)
{
	int i, j, total;

	for (i = 0; i < p; i++)
	{
		total = 0;
		for (j = 0; j < texts; j++)
		{
			total += grades[i][j];
		}
		printf("\n\tThe average grade for student %d is %.1f", i + 1, (double)total / texts);
	}
	printf("\n");
}

void printarray(int grades[][exams], int p, int texts)
{
	int i, j;

	printf("\n\t\t[0]    [1]    [2]    [3]");
	for(i=0;i<p;i++)
	{
		printf("\nstudentgrades[%d]", i);
		for(j=0;j<texts;j++)
		{
			printf("%-7d", grades[i][j]);
		}
	}
	printf("\n");
}

void printmenu() 
{
	printf("\n");
	printf("\tEnter a choice:\n");
	printf("\t0 Print the array of grades\n");
	printf("\t1 Find the minimum grade\n");
	printf("\t2 Find the maximum grade\n");
	printf("\t3 Print the average on all texts for each student\n");
	printf("\t4 End program\n");
	printf("Choice:");
}