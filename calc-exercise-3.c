#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
double peek(void);

/* Add support for 10 more variables named A-J in addition 
   to the M variable in exercise 2, we are trying to build
   off of this idea to be able to set values of variables 
   and use them to our advantage. */
main()
{
  int type; /* is it an operator or an operand */
  double op2; /* for subtraction */
  char s[MAXOP]; /* hold operands (i.e., numbers) */
  int M = 0; /* new variable to store values, should be initialized to zero */
  int memory[10] = { 0 }; /* memory array to store the variable names, with all entries initialized to 0 */
  int nextOp; /* used after assignment operator to see what variable to assign value to */
  
  while((type = getop(s)) != EOF){
    switch(type){
    case NUMBER:
      push(atof(s));
      break;
	case 'A'...'J': /* replace variable by its value */
		push(memory[type - 'A']);
		break;
	case '>': // assign a value to the following variable
		op2 = peek();// last value seen is going to be assigned to the variable
		// need to figure out what variable immediately follows assignment operator
		nextOp = getop(s); 
		//now store value into the variable
		memory[nextOp - 'A'] = op2;
		break;
    case '+':
	  M = pop() + pop();
      push(M);
      break;
	case '*':
		M = pop() * pop();
		push(M);
		break;
    case '-':
      op2 = pop();
	  M = pop() - op2;
      push(M);
      break;
	case '/':
		op2 = pop();
		if(op2 != 0){
			M = pop() / op2;
			push(M);
		} else {
			printf("Illegal division by zero attempted\n");
		}
		break;
	case '%':
		op2 = pop();
		int op1 = pop();
		int op2asint = op2;
		if (op2 != 0.0){
			// note that mod requires integer values
			M = op1 % op2asint;
			push(M);
		} else {
			printf("Illegal division by zero attempted\n");
		}
		break;
	case 'M':
		//treat M as a number and push its value on the stack
		push(M); // push M onto the stack
		break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* Push a value onto the stack */
void push (double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, cant push %g\n",f);
}

/* pop the first value off of the stack and return it */
double pop(void)
{
  if(sp > 0)
    return val[--sp];
  else
    {
      printf("error: stack empty \n");
      return 0.0;
    }
}

/* return the top value of the stack without popping the value off */
double peek(void) {
	if(sp > 0){
		return val[sp -1];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getch(void);
void ungetch(int);

/* Get next operator or numeric operand*/
int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if(!isdigit(c) && c != '.') {
	if(c == '>'){
		return '>';
	} 
	return c; /* not a number */
  }
  i = 0;
  if (isdigit(c)) /* collect integer part */
    while(isdigit(s[++i] = c = getch()))
      ;
  if(c=='.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
  return(bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if(bufp >= BUFSIZE){
    printf("ungetch: too many characters\n");
  }
  else
    {
      buf[bufp++] = c;
    }
}