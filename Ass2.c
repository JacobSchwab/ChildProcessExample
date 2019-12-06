#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

//Jacob Schwab

int main()
{
	double total2 = 0;
    double reminder = 0;
    double remainder = 0;
    double total = 0;
    int count = 0;
    int count2 = 0;
	int r[100]; 
	for (int k = 0; k < 100; ++k) {
		r[k] = rand() % 10 + 1;
	}
	
	// create a child process
	int state = fork();
	// child process if state is 0
	if (state < 0)
	{
		printf("fork failed\n");
	}
	// child process if state is 0
	else if (state == 0)
	{
		sleep(1);
		printf("Hello, I'm the Child Process!\n");
		printf("child process, pid = %u\n", getppid());
        
        for (int j = 0 ; j < 100; j++) {
            remainder = r[j] % 2;
			if (remainder == 1){
				total2 = total2 + r[j];
                count2++;
            }
				
			else continue;
		}
		double num2 = total2/count2;
		printf("The average of the odd numbers is %lf\n" , num2);
	}
	// parent process if state > zero.
	else
	{
		printf("Hello, I'm the Parent Process!\n");
		printf("parent process, pid = %u\n", getppid());

		for (int i = 0 ; i < 100; i++) {
            reminder = r[i] % 2;
			if (reminder == 0){
				total = total + r[i];
                count ++;
            }
				
			else continue;
		}
        double num1 = total/count;
		printf("The average of the even numbers is %lf\n" , num1);

	}
	return 0;
}

