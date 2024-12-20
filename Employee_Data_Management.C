#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


// Struct with employees data

struct Employee {

	   int code;
	   char* name;  // get the name dynamically from user
	   int salary; // changed salary to int so scanf() and fgets() work
};



// Function prototypes
struct Employee* readEmpData(int size);

void writeEmpData(struct Employee* employees, int size);

char* getEmpName(void);



void main (void) {


	 int i; // for loop that frees memory of dynamic names


	 int size; // User will determine it


	 // Array of employee structs dynamically allocated to store
	 // the return of the getEmpData()
	 struct Employee* resultEmp;


	 system("cls");


	 // Prompting the user to enter the size of the array
	 printf("Enter the number of employees you will insert their data: ");
	 scanf("%d", &size);
	 printf("\n");



	 // Assigning the return of getEmpData() to resultEmp
	 /*
		No nned to dynamically allocate resultEmp in main() as
		it is already assigned to the return of readEmpData which
		already returns a dynamically allocated array of structs

	  */
	 resultEmp = readEmpData(size);


	 printf("\n");


	 // Printing the data user enters
	 writeEmpData(resultEmp, size);



	 // Freeing the memory for the dynamically allocated names
	 for (i = 0; i < size; i++) {

		 free(resultEmp[i].name);
	 }



	 // Freeing the memory
	 free(resultEmp);


	 getch();

}



// Function to read data of employees

// Returns a pointer to an array of structs and takes size as param

struct Employee* readEmpData(int size) {

	   int i;


	   // Creating an array of employee structs and
	   /// dynamically allocating it
	   struct Employee* employees = (struct Employee*)malloc(size * sizeof(struct Employee));



	   // Looping through the array and entering values for
	   // the attributes

	   /*
		  Be careful: You compare employees against NULL not the i
					  to check the success of the dynamic allcation
	   */

	   for (i = 0; employees != NULL && i < size; i++) {


		   printf("Enter the data of employee #%d:-\n", i+1);


		   printf("Enter employee code: ");
		   scanf("%d", &employees[i].code);

		   /*
			  To clear the new lines left over by scanf()

			  - Not recommended anymore and gives undefined behavior
				in most compilers

			  - There is while ((getchar()) != '\n');

			  - There is fgetc(stdin) used in OD03L04
		   */
		   fflush(stdin);



		   printf("Enter employee name: ");

		   /*
			  fegts() is more recommended with strings than gets()

				 * it checks the size

			  scanf() only scans the first word

		   */
		  // fgets(employees[i].name, sizeof(employees[i].name), stdin);

		   // Assign return of getEmpData() to employees[i].name
		   employees[i].name = getEmpName();
		   fflush(stdin);



		   printf("Enter employee salary: ");
		   scanf("%d", &employees[i].salary);
		   fflush(stdin);

		   printf("\n");
	   }


	   // Returning the array of employee structs
	   return employees;

}





// Function to print the data of the employees

/*
	- Return type is void as it simply prints data

	- Takes an array of employee structs + size as param
*/

void writeEmpData(struct Employee* employees, int size) {

	 int i;

	 // Loop through the array of employee structs
	 // to print the data entered by user
	 printf("The data of employees you entered: \n");


	 for (i = 0; i < size; i++) {


		 printf("Employee #%d's code: %d\n", i+1, employees[i].code);

		 printf("Employee #%d's name: %s\n", i+1, employees[i].name);

		 printf("Employee #%d's salary: %d\n", i+1, employees[i].salary);

		 printf("\n");

	 }

}




// Function to get employee name dynamically
// Comments in OD04L05
char* getEmpName() {


	  int i = 0;


	  char* name;


	  char charachter;


	  name = (char*)malloc(sizeof(char));


	  while ((charachter = getc(stdin)) != '\n') {


		 if (name == NULL) {

			 printf("Memory allocation failed!\n");
			 exit(1);

		  }

		 name[i] = charachter;


		 // Increment then realloc() so first time realloc() allocates
		 // memory, it is 1 byte. It cannot start with 0 byte

		 i++;


		 /*
			- Explanation not in OD04L05:

				* realloc(void *ptr, size_t size)

				* realloc() deallocates the old object pointed to by
				  the pointer and returns a new object that has the
				  specified size
		 */

		 realloc(name, i * sizeof(char));

		 }


	  name[i] = '\0';

	  return name;


}





/* **************************************************************** */


// Impl before making the name dynamic

/*
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


// Struct with employees data

struct Employee {
                               
	   int code;
	   char name[15];
	   int salary; // changed salary to int so scanf() and fgets() work
};



// Function prototypes
struct Employee* readEmpData(int size);

void writeEmpData(struct Employee* employees, int size);



void main (void) {


	 int size; // User will determine it

	 // Array of employee structs dynamically allocated to store
	 // the return of the getEmpData()
	 struct Employee* resultEmp;


	 system("cls");

	 // Prompting the user to enter the size of the array
	 printf("Enter the number of employees you will insert their data: ");
	 scanf("%d", &size);
	 printf("\n");



	 // Assigning the return of getEmpData() to resultEmp
	 /*
		No nned to dynamically allocate resultEmp in main() as
		it is already assigned to the return of readEmpData which
		already returns a dynamically allocated array of structs

	  */
/*	 resultEmp = readEmpData(size);


	 printf("\n");


	 // Printing the data user enters
	 writeEmpData(resultEmp, size);


	 // Freeing the memory
	 free(resultEmp);


	 getch();  */

//}



// Function to read data of employees

// Returns a pointer to an array of structs and takes size as param

/* struct Employee* readEmpData(int size) {

	   int i;


	   // Creating an array of employee structs and
	   /// dynamically allocating it
	   struct Employee* employees = (struct Employee*)malloc(size * sizeof(struct Employee));



	   // Looping through the array and entering values for
	   // the attributes

	   /*
		  Be careful: You compare employees against NULL not the i
					  to check the success of the dynamic allcation
	   */

 /*	   for (i = 0; employees != NULL && i < size; i++) {

		   printf("Enter the data of employee #%d:-\n", i+1);


		   printf("Enter employee code: ");
		   scanf("%d", &employees[i].code);

		   /*
			  To clear the new lines left over by scanf()

			  - Not recommended anymore and gives undefined behavior
				in most compilers

			  - There is while ((getchar()) != '\n');

			  - There is fgetc(stdin) used in OD03L04
		   */
/*		   fflush(stdin);



		   printf("Enter employee name: ");

		   /*
			  fegts() is more recommended with strings than gets()

				 * it checks the size

			  scanf() only scans the first word

		   */
/*		   fgets(employees[i].name, sizeof(employees[i].name), stdin);
		   fflush(stdin);



		   printf("Enter employee salary: ");
		   scanf("%d", &employees[i].salary);
		   fflush(stdin);

		   printf("\n");
	   }


	   // Returning the array of employee structs
	   return employees;

}





// Function to print the data of the employees

/*
	- Return type is void as it simply prints data

	- Takes an array of employee structs + size as param
*/

/*void writeEmpData(struct Employee* employees, int size) {

	 int i;

	 // Loop through the array of employee structs
	 // to print the data entered by user
	 printf("The data of employees you entered: \n");


	 for (i = 0; i < size; i++) {


		 printf("Employee #%d's code: %d\n", i+1, employees[i].code);

		 printf("Employee #%d's name: %s", i+1, employees[i].name);

		 printf("Employee #%d's salary: %d\n", i+1, employees[i].salary);

		 printf("\n");

	 }

}

*/





/* **************************************************************** */



/*
   The read function before


// Function to read data of employees

   The function returns an array of structs and takes size as param

struct Employee* readEmpData(int size) {

	   int i;
	   size_t len;


	   // Creating an array of employee structs and
	   /// dynamically allocating it
	   struct Employee* employees = (struct Employee*)malloc(size * sizeof(struct Employee));




	   // Looping through the array and entering values for
	   // the attributes
	   for (i = 0; employees != NULL && i < size; i++) {

		   printf("Enter the data of employee #%d:-\n", i+1);


		   printf("Enter employee code: ");
		   scanf("%d", &employees[i].code);
		   fgetc(stdin);


		   printf("Enter employee name: ");
		   fgets(employees[i].name, sizeof(employees[i].name), stdin);
		   len = strlen(employees[i].name);

		   if (len > 0 && employees[i].name[len - 1] == '\n') {
			  employees[i].name[len - 1] = '\0';
		   }


		   printf("Enter employee salary: ");
		   scanf("%lf", &employees[i].salary);
		   fgetc(stdin);

	   }


	   // Returning the array of employee structs
	   return employees;

}

*/









