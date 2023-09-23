#include <stdio.h>
#include <ctype.h>

int test_isalpha(){

    char c;
    int b;
    char d;

    c = 'Q';
    printf("\nResult when uppercase alphabet is passed: %d", isalpha(c));

    c = 'q';
    printf("\nResult when lowercase alphabet is passed: %d", isalpha(c));

    c='+';
    printf("\nResult when non-alphabetic character is passed: %d", isalpha(c));

    
    printf("\nResult when undefined character is passed: %d", isalpha(d));


    b=12;
    printf("\nResult when integer character is passed: %d", isalpha(b));

    printf("\nResult when multiple argument character is passed: %d", isalpha("h",12));

    return 0;

}

int main(){
    test_isalpha();


}

// int test()