#include <stdio.h>
#include <Windows.h>

int KnR_Style() { // K&R Style
    printf("Most developers prefer K&R style, is the most widely-used standard of function design. \n");
}

int Allman_Style() // Allman Style
{
    printf("Allman style is widely used when writing Windows applications in C# \n");
}

int main() {
    KnR_Style();
    Allman_Style();
    printf("All in all, its just preference at the end of the day, and it depends on what standard you have to write in. \n");

    int true = 1;
    int false = 0;

    if (true ^ false) {
        if (true) {
            printf("its true!");
        } else {
            printf("its false");
        }
    }

    // printf("\nplease enter a int\t");
    // int myInt;
    // scanf("%d", &myInt);

    // for (int i = myInt; i > 0; i--) {
    //     printf("%d\t", i);
    //     Sleep(100);
    // }

    int myFirstArray [5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        printf("\n%d", myFirstArray[i]);
        Sleep(100);
    }
        
    return 0;
}