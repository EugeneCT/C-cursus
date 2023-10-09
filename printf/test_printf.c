
#include <stdarg.h>
#include <stdio.h>
#include "printf.h"

	// int main()
	// {
	// 	int a = 12;
    //     // char c[] = "hello";
	// 	int b = 9;
    //     unsigned int u = 100;
    //     int *p = &a;
    //     float d = 3.14256789;
	// 	// int u = -17;
	// 	int x = 17;
	// 	char str[] = "This is Great";
    //     char c = 's';
    //     printf("I am testing %i %% %i",a,b);
	// 	// func(str, a,c, b);
	// }


/// test case -    printf("I am testing %05.3d",a) ->  I am testing   012
// c
// 0,precision,+,space,# cant use with c speicifier - will ignore
// only will habdle -,width

// s
// 0,+,space,# cant use with c speicifier - will ignore
// for precision - number of maximum characters to be prnted
// if width less then str len, nth will happen
// Will handle -,width,precision

// p
// 0,+,space,# cant use with c speicifier - will ignore
// if width less then address len, nth will happen
// if spaced is used, will act as space
// Will handle -,space,width

// d and i
// ignore #
// for precision - number of maximum characters to be prnted
// will habdle -,+,space,0,width,precision


// u
// ignore #,space,+
// for precision - number of maximum characters to be prnted, but would not truncate orignal width, extra 1 will add 0 in front
// 0 ignore when used with precision, 
// will habdle -,0,width,precision

// x and X
// ignore #,space,+
// for precision - number of maximum characters to be prnted, but would not truncate orignal width, extra 1 will add 0 in front
// 0 ignore when used with precision, 
// will habdle -,0,width,precision