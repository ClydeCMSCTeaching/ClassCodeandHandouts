
#include <stdio.h>
#include <stdio.h>

int main() {

  int userInput;
  int exit_code;
  
  do {
    printf("Enter a number [0, 15]: ");
    exit_code = scanf("%d", &userInput); // 0 => failure, 1=> correctly parsed and stored the value
    printf("this is the exit code %d\n", exit_code);
  } while (exit_code == 1 && (userInput > 15) || (userInput < 0)); // while the exit_code implies the data type was right
  
 
  return(0);
}
