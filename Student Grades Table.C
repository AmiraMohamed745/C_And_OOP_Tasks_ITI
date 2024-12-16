#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Matrix 3*4 for students grades
// with the sum of rows and average of columns


/*
   Rows of 2-D array. Even though we have 3 students,
   the size is 4 to accommodate the extra white space
   where the left header of the table resides
*/
#define STUDENT 4

/*
  Columns of 2-D array. Even though we have 4 subjects,
  the size is 5 to accommodate the extra white space
  where the top header of the table resides
*/
#define SUBJECT 5

/*
   The number of entities in the top header of the table,
   there are 5 entities + white space
*/
#define TOP_TABLE 6

/*
  The number of entities in the left header of the table,
  there are 4 entities + white space

*/
#define LEFT_TABLE 5



void main (void){


	// Variables to control the interations of the loops
	int i, j;


	// The sum of all grades each student gets
	int sumPerStudent;


	// The sum of all students grades in each subject subject
	int sumPerSubject;


	// The average of grades in each subject.
	// avg = sumPerSubject / number of students
	int averagePerSubject;


	// 2-D array for students grades
	int studentsGrades[STUDENT][SUBJECT];


	// The entities in the top header of the table
	char topTable[TOP_TABLE][10] = {" ", "Subj#1", "Subj#2", "Subj#3", "Subj#4", "Sum"};


	// The entities in the left header of the table
	char leftTable[LEFT_TABLE][10] = {" ", "Stud#1", "Stud#2", "Stud#3", "Avg"};


	// Horizontal coordinates
	int xOffset;

	// Vertical coordinates
	int yOffset;


	system("cls");


	// Initializing the coordinates
	xOffset = (80 - (TOP_TABLE * 6)) / 2;
	yOffset = (25 - (TOP_TABLE * 2)) / 2;



	// Loop to set the top header

	for (i = 0; i < TOP_TABLE; i++) {

		gotoxy((i * 8) + xOffset, yOffset);

		printf("%s", topTable[i]);
	}



	// Loop to set the left header

	for (i = 0; i < LEFT_TABLE; i++) {

		/*
		   - X offset: same as top header without extra space
			 at the beginning

		   - Y offset: same as top header + extra space to
			 separate the rows from each other
		*/

		gotoxy(xOffset,yOffset + (i * 3));

		printf("%s", leftTable[i]);

	}



	/*
	   Loop to get the grades

		  - Loop starts from 1 as 0 is white space
		  - For each student, we get the grades for 4 subjects

	*/

	for (i = 1; i < STUDENT; i++) {

		for (j = 1; j < SUBJECT; j++) {

		/*
		   - X offset: determined by the columns (j)

			   * Same as top header + some extra space for aesthetics

		  - Y offset: same as top header

		*/

			gotoxy(((j * 8) + xOffset) + 2, (i*3) + yOffset);

			scanf("%d", &studentsGrades[i][j]);

		}

	}



	// Loop to calculate the sum of the grades for each student


	for (i = 1; i < STUDENT; i++) {

		// Sum is set to 0 initially
		sumPerStudent = 0;


		for (j = 1; j < SUBJECT; j++) {

			gotoxy(((j * 8) + xOffset) + 9, (i*3) + yOffset);

			// Sum calculated for each student
			sumPerStudent += studentsGrades[i][j];

		}
		printf("%d",sumPerStudent);

	}



	// Loop to calculate the average of grades in each subject

	/*
	   Unlike the loop for the grades and sum, the average
	   loop increments the student in each iteration, while
	   the subject remains fixed.

	   This is to get the grade of each of the 3 students
	   in one subject.

	*/

	for (i = 1; i < SUBJECT; i++) {

		sumPerSubject = 0;

		for (j = 1; j < STUDENT; j++) {

			gotoxy((i * 8) + xOffset + 2, ((j*3) + yOffset) + 3);
			sumPerSubject += studentsGrades[j][i];

		}

		/*
		   To calculate the avergae correctly:

			 - STUDENT - 1: there are only 3 students
							but the size is 4 as explained above

			 - Use ( ): to adhere to BODMAS
		*/

		averagePerSubject = sumPerSubject / (STUDENT - 1);
		printf("%d", averagePerSubject);

	}


	getch();

}






/*  The logic without using gotoxy() + no comments


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define STUDENT 3
#define SUBJECT 4

// Matrix 3*4 for students grades
// with the sum of rows and average of columns


void main (void){

	int i, j;

	int sumPerStudent;
	int sumPerSubject;
	int averagePerSubject;

	int studentsGrades[STUDENT][SUBJECT];

	system("cls");


	for (i = 0; i < STUDENT; i++) {

		printf("Enter the grades of student #%d:- \n", i+1);

		for (j = 0; j < SUBJECT; j++) {

			printf("Grade for subject #%d: ", j+1);
			scanf("%d", &studentsGrades[i][j]);

		}
		printf("\n");

	}



	for (i = 0; i < STUDENT; i++) {

		sumPerStudent = 0;


		for (j = 0; j < SUBJECT; j++) {


			sumPerStudent += studentsGrades[i][j];

		}
		printf("Sum of grades for student #%d is: %d\n", i+1, sumPerStudent);

	}


	printf("\n");


	for (i = 0; i < SUBJECT; i++) {

		sumPerSubject = 0;

		for (j = 0; j < STUDENT; j++) {
				sumPerSubject += studentsGrades[j][i];

		}

		averagePerSubject = sumPerSubject / STUDENT;
		printf("The average of subject #%d is: %d\n", i+1, averagePerSubject);

	}




	getch();

}



*/