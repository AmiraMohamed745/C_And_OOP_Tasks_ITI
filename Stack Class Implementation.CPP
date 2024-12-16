#include <iostream.h>
#include <conio.h>
#include <stdlib.h>


// Stack example

class Stack {

 private:

   int topOfStack;
   int size;
   int* stack;

   /*
	  Static attribute to keep track of how many objects created

		 - Incremented with each constructor called

		 - Decremented with each destructor
   */

   static int counter;


 public:




   Stack (Stack& stackPassCopy);





  // Function to push elements into stack
  void push(int numInput);


  // Function to pop elements off the stack
  int pop();



  // Public static function that control the static attr counter
  static int getCounter() {

	  return counter;
                                  
  }


  Stack (int numOfElements);


  ~Stack();


  friend void viewContent (Stack stackViewed);


  friend void viewContentByReference (Stack& stackViewed);


  /*
  // Overloading operator = with call by value
  void operator= (Stack stackPassEqual);*/



  // Overloading operator = with call by reference
  Stack& operator= (const Stack &stackPassEqual);
                                                 

};                                         



// If user doesn't pass a size/number of elements, initialize to 10
Stack::Stack (int numOfElements = 10) {

	   // Stack initialized to 0; empty
	   topOfStack = 0;

	   size = numOfElements;

	   // Initialization of stack dynamically
	   // will have to be deleted manually using delete
	   stack = new int[size];

	   cout << "This is constructor of stack object with size " << size << endl;

	   counter++;

	   cout << "This is stack object NO." << counter << endl;
	}




Stack::~Stack() {

	   // Deleting the array that represents the satck
	   delete[] stack;

	   cout << "This is the destructor" << endl;

	  // counter--;

	   cout << "Destroying stack object NO." << counter << endl;
	   counter--;

   }




// Copy constructor

Stack::Stack (Stack& stackPassCopy) {

	  int i;

	  topOfStack = stackPassCopy.topOfStack;

	  size = stackPassCopy.size;

	  stack = new int[size];

	  for (i = 0; i < topOfStack; i++) {

		  stack[i] = stackPassCopy.stack[i];

	  }

	  counter++;

  }


// Initializing the static counter to 0

int Stack::counter = 0;



void Stack::push(int numInput) {

	 /*
		If top of stack = size, we can't add elements

		- Top of stack: points to where there is free place

		  * If it points to size -1, then it's standing on the last element
			and hasn't yet exceeded size
	 */

	 if (topOfStack == size) {

		cout << "Stack is full" << endl;

	 }

	 /*
		If there is a place to add: add the number in index = topOfStack
	 */

	 else {

		stack[topOfStack] = numInput;
		topOfStack++;

	 }

}


int Stack::pop() {


	// The value to pe popped off
	int popValue;



	/*
	   If top of stack is 0, it means the first place to
	   add is free, which means every other place after it
	   is free and stack is empty. You can't pop something
	   that doesn't exist.

	*/

	if (topOfStack == 0) {

		cout << "Stack is empty" << endl;

		// If stack is empty, we can't return a value

		popValue = -1;

	}

	else {

		/*
		   Otherwise, if stack isn't empty and there is an element

			 1. Decrement top of stack
			 2. The popped value = the value where the top of
				stack is standing

		 -  Wouldn't decrementing top of stack get us the
			element after the one we want to pop off? No

			topOfStack == size and index starts from 0 till size - 1

		*/

		topOfStack--;

		popValue = stack[topOfStack];

	}

	return popValue;


}



// Friend function to view the content of the stack

/*
   Pass a Stack object to it as an argument

   Uses the object to access the attributes


*/

void viewContent (Stack stackViewed) {


	 int index = stackViewed.topOfStack;

	 /*
		Top of stack stands where ther is empty space
		if the empty space exists at index 0, then stack is empty
		and there is not content to view
	 */

	 while (index != 0) {

		cout << "Element #" << index+1 << " is " << stackViewed.stack[--index] << endl;

	 }

}


// View content by refernce


void viewContentByReference (Stack& stackViewed) {


	 int index = stackViewed.topOfStack;


	 while (index != 0) {

		cout << "Element #" << index+1 << " is " << stackViewed.stack[--index] << endl;

	 }

}


/*
// Overloading operator =
void Stack::operator= (Stack stackPassEqual) {

	 // Delete the stack the object copied into has
	 // so that we make a new one with =
	 delete[] this -> stack;

	 this -> topOfStack = stackPassEqual.topOfStack;

	 this -> size = stackPassEqual.size;

	 this -> stack = new int[size];

	 // Copy each element from the stackPassEqual into the
	 // caller
	 for (int i = 0; i < topOfStack; i++) {

		 this -> stack[i] = stackPassEqual.stack[i];

	 }



}*/



// Overloading operator =
// Should return a value
Stack& Stack::operator= (const Stack& stackPassEqual) {

	 // Delete the stack the object copied into has
	 // so that we make a new one with =
	 delete[] this -> stack;

	 this -> topOfStack = stackPassEqual.topOfStack;

	 this -> size = stackPassEqual.size;

	 this -> stack = new int[size];

	 // Copy each element from the stackPassEqual into the
	 // caller
	 for (int i = 0; i < topOfStack; i++) {

		 this -> stack[i] = stackPassEqual.stack[i];

	 }


	return *this;
}




int main() {


	system ("cls");




	cout << "Creating a stack of size 5...." << endl;

	Stack stack1(5);



	cout << "Calling push for the first time on stack1..." << endl;
	stack1.push(100);



	cout << "Calling push for the second time on stack1..." << endl;
	stack1.push(200);



	cout << "Calling push for the third time on stack1..." << endl;
	stack1.push(300);



	cout << "Calling push for the fourth time on stack1..." << endl;
	stack1.push(400);



	cout << "Calling push for the fifth time on stack1..." << endl;
	stack1.push(500);


	cout << "Number of objects created: " << Stack::getCounter() << endl;



	cout << "Calling viewContent() on stack1...." << endl;
	viewContent(stack1);



	cout << "Number of objects created: " << Stack::getCounter() << endl;



	cout << "Calling viewContentByReference() on stack1..." << endl;
	viewContentByReference(stack1);



	cout << "Number of objects created: " << Stack::getCounter() << endl;




	cout << "Calling the copy constructor..." << endl;
	Stack stackCopy (stack1);



	cout << "Number of objects created: " << Stack::getCounter() << endl;




	cout << "Calling viewContent() on copied stack...." << endl;
	viewContent(stackCopy);



	cout << "Number of objects created: " << Stack::getCounter() << endl;



	cout << "Calling viewContentByReference on copied stack..." << endl;
	viewContentByReference(stackCopy);



	cout << "Number of objects created: " << Stack::getCounter() << endl;




	cout << "Calling pop() on stack1 for first time..." << endl;

	stack1.pop();



	cout << "Calling pop() on stack1 for the second time..." << endl;
	stack1.pop();



	cout << "Number of objects created: " << Stack::getCounter() << endl;




	cout << "Calling viewContent() after popping 2 time for stack1..." << endl;
	viewContent(stack1);



	cout << "Number of objects created: " << Stack::getCounter() << endl;



	cout << "Calling viewContentByReference() after popping 2 time for stack1..." << endl;
	viewContentByReference(stack1);



	cout << "Number of objects created: " << Stack::getCounter() << endl;



	cout << "Creating object stack2 without entering size..." << endl;

	Stack stack2;



	cout << "Number of objects created: " << Stack::getCounter() << endl;



	cout << "Calling push for the first time on stack2..." << endl;
	stack2.push(10);



	cout << "Calling push for the second time on stack2..." << endl;
	stack2.push(20);



	cout << "Number of objects created: " << Stack::getCounter() << endl;



	cout << "Calling viewContent() on stack2 after pushing 2 times..." << endl;
	viewContent(stack2);



	cout << "Number of objects created: " << Stack::getCounter() << endl;



	cout << "Calling viewContentByReference() on stack2 after pushing 2 times..." << endl;
	viewContentByReference(stack2);



	cout << "Number of objects created: " << Stack::getCounter() << endl;


	cout << "Calling copy constructor on stack2...." << endl;
	Stack stackCopy2(stack2);


	cout << "Number of objects created: " << Stack::getCounter() << endl;


  // cout << "Printing stack1 = stack2 before overloading =...." << endl;
	cout << "Printing stack1 = stack2 after overloading =...." << endl;
	stack1 = stack2;


	cout << "Number of objects created: " << Stack::getCounter() << endl;


	cout << "Popping from stack2...." << endl;
	stack2.pop();


	cout << "Number of objects created: " << Stack::getCounter() << endl;


	cout << "Pushing into stack1...." << endl;
	stack1.push(1000);


	cout << "Number of objects created: " << Stack::getCounter() << endl;



   //cout << "Calling viewContentByReference before overloading..." << endl;
	cout << "Calling viewContentByReference after overloading..." << endl;
	cout << "Stack1...." << endl;
	viewContentByReference(stack1);



	cout << "Number of objects created: " << Stack::getCounter() << endl;



	cout << "Stack2...." << endl;
	viewContentByReference(stack2);


	cout << "Number of objects created: " << Stack::getCounter() << endl;



	getch();



	return 0;
}