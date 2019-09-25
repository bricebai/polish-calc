#include <stdio.h>
#include<ctype.h>
#include <stdlib.h> /* for atof() */

#define MAX 512

struct stack
{
    int stk[MAX];
    int top;
};
typedef struct stack STACK;
STACK s;
 
void push(double);
int  pop(void);
void display(void);

/*  Function to add an element to the stack */
void push (double num) {
    if (s.top == (MAX - 1)) {
        printf ("Stack is Full\n");
        return;
    }
    else {
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    return;
}

/*  Function to delete an element from the stack */
int pop () {
    int num;
    if (s.top == -1) {
        printf ("Stack is Empty\n");
        return (s.top);
    }
    else {
        num = s.stk[s.top];
        s.top = s.top - 1;
    }
    return(num);
}

/*  Function to print each element of the current stack */
void printStack() {
	printf("Current Stack:\n");
	int index = 0;
	while (index <= s.top) {
		printf("%d\n", s.stk[index]);
		index++;
	}
	printf("\n");
	return;
}

/* Converting a string to an integer */
int stringtoint (char *str) {
	int currentCharNum;
	int resultNum = 0;
	while (*str != '\0') {
		currentCharNum = *str - '0';
		resultNum = (resultNum * 10) + currentCharNum;
		str++;
	}

	return resultNum;
}

int main(int argc, char *argv[])
{
	//initialize stack
	s.top = -1;
	int index = 0;
	int i = 0;
	char word[256];
	int op1, op2; //used for subtraction and division
	char ch;
	int result;
  
	
	printf("Please input a series of numbers and operators:\n");
	while ((ch  = getchar()) != '\n')
	{
	   if (!isspace(ch) && isdigit(ch)) {
	   	word[i] = ch;
	   	i++;
	   }
	   else if (isspace(ch)) {
	       word[i] = '\0';
	       
	       if (word[0] == '\0') {
	       		continue;
	       }
	       else {
	       		push(stringtoint(word));
	       }
	       
	       printStack();
	       i = 0;
	       continue;
	   } 
		else {
			switch (ch) {
      
			case '+':
				//printf("You have reached the + case.\n");
				op1 = pop(); op2 = pop();
				result = op1 + op2;
				push(result);
				continue;
			case '*':
				//printf("You have reached the * case.\n");
				op1 = pop(); op2 = pop();
				result = op1 * op2;
				push(result);
				continue;
			case '-':
				//printf("You have reached the - case.\n");
				op1 = pop(); op2 = pop();
				result = op1 - op2;
				push(result);
				continue;
			case '/':
				//printf("You have reached the / case.\n");
				op1 = pop(); op2 = pop();
				if (op2 == 0.0)
					printf("Error: Cannot divide by zero\n");
				else {
					result = op1/op2;
					push(result);
				}
				continue;
			default:
				printf("Not a number or operation\n");
				break;
			}
		}
	   
	}

	printf("Final result: %d\n", pop());
	return 0;
}


/* ------------------------------------------------------
TEST CASES TO POTENTIALLY BREAK THIS CODE:

- 1 2 3 4
- + * - /
- 1 2 + 4 5
- 1+ 3 2 * *
- + + 1 2 3
- 1 2 3 ++ -
- extra spaces
- 1 3 5 +

All pass! :)
*/
