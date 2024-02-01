#include "pushswap.h"

int main(int argc,char**argv)
{
    char *stack_a;
    char *stack_b; 

    int i=0;
    int j=0;
    stack_a= (char *)malloc((argc-1) * sizeof(char));
    stack_b= (char *)malloc((argc-1) * sizeof(char));

    // Check if memory allocation was successful
    if (stack_a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Return an error code
    }
    if (stack_b == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Return an error code
    }
    if (argv == NULL) {
        fprintf(stderr, "Memory allocation failed for argv\n");
        return 1; // Return an error code
    }

    while (i < argc)
    {
        stack_a[i] = (*argv[i]);
        printf("i of %d is %c\n",i,stack_a[i]);
    
        i++;
    }

        while (j < argc)
    {
        // stack_b[j] = ft_atoi(argv[j]);
        printf("j of %d is %d\n",j,stack_b[j]);
        j++;
    }
}