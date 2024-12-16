#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// Magic Box algorithim

void main(void) {

	int size;
	int totalSize;
	int num;
	int row;
	int column;
	int i;
	int xOffset;
	int yOffset;


	system("cls");

	printf("Enter the size of the magic box: ");
	scanf("%d",&size);


	/* Used a while loop for prompting the user re-enter
	   a size in case they eneter an even number

	   - Why a while loop and not if?
	   Because while will keep executing till the condition becomes
	   false by enetering an odd number

		 * if statement will only check for the condiiton 1 time
		   so, on the second try if the user eneter an even number,
		   it will be accepted.

	*/

	while (size % 2 == 0) {
		printf("You cannot enter an even number. Try again: ");
		scanf("%d", &size);
	}


	// Calculating the total size after having taken the size from user

	totalSize = size * size;


	/*
	 - 80: A console consists of 80 columns/characters in width
	 - size * 6: each cell in the box has size * 6 characters
	 - 80 - (size * 6): remaining space after the box is considered
	 - /2: to center the output
	 - (80 - (3*6)) / 2 = (80 - 18) / 2 = 31
	*/
	xOffset = (80 - (size * 6)) / 2;


	/*
	  - 25: A console has 25 lines in height
	  - size * 2: each cell has a height of size * 2
	  - /2: to center the output
	  - (25 - (3*2)) / 2 = (25 - 6) / 2 = 9.5
	*/
	yOffset = (25 - (size * 2)) / 2;



	// Intializing the row and column to the position where 1 should
	// be placed
	row = 0;
	column = size / 2;


	// Inform user to enter 1 first so it will be placed
	// in the intialized positions of row and column
	printf("Enter the numbers sequentially from 1 to %d", totalSize);



	/* The for loop itself should have the logic to check if:

	   - A number entered is less than 1
	   - A number entered is more than totalSize
	   - A number entered is a duplicate
	   - A number enetered is placed where 1 should be placed

	*/


	for (i = 1; i <= totalSize; i++) {


		// The gotoxy() should be placed before any scanf() or
		// printf() so that any typing appears exactly in the
		// center
		gotoxy((column*6) + xOffset,(row*2) + yOffset);

		// Used scanf() only without printf(), as printf()
		// prints the number on the left side or top left
		// in addition to having them printed in the center
		scanf("%d", &num);


		/*
		   This logic handles the positioning of the numbers
		   If the position, determined by i; is dividible by size,
		   this means Row is full, so we move downward to the next row
		   but the column remains the same, meaning, the next number
		   gets placed in the same column position but in the next row
		*/
		if(i % size == 0) {
			row++;

		}


		/*
		  If the positioning is not divisible by size, we move
		  diagonally up and left
		*/
		else {
			row--;
			column--;
		}

		// If row is negative, circulate to the last row
		if (row < 0) { row = size - 1; }

		// If column is negative, circulate to last column
		if (column < 0) { column = size - 1; }

		// If row is less than or equal to size, circulate
		// to the first row
		if (row >= size) { row = 0; }

		// If column is less than or equal to size, circulate
		// to the first column
		if (column >= size) {column = 0; }


	}

	getch();

}