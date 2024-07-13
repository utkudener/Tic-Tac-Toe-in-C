#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

/**  drawGrid     Draws the current state of the tic-tac-toe grid    **/
void drawGrid( char a[] )
{
    printf( "\n" );
    printf( " %c | %c | %c \n", a[0], a[1], a[2] );
    printf( "---|---|---\n");
    printf( " %c | %c | %c \n", a[3], a[4], a[5] );
    printf( "---|---|---\n");
    printf( " %c | %c | %c \n", a[6], a[7], a[8] );
    printf("\n");
}

/**  takeTurn     Orders to play when play with cpu **/
void takeTurn( char a[], char *playerPtr  )
{
    int available[8];
    int i, j = 0, choice, random;
    /** for loop to increase i**/
    for(i = 0; i < 9; i++ )
        /**eger a'nin i. degeri x veya o ya esit degilse a'nin j.degeri i'ye esittir **/
        if( (a[i] != 'X') && (a[i] != 'O')  )
            available[ j++ ] = i;

    srand(time(NULL));
    random=rand()%8;

    printf( "\n It is %c's turn.  Choose your move (", *playerPtr );
    /**for loop to increase i**/
    for( i = 0; i < j; i++ )
        printf( " %d", available[i]);
    printf( " ): ");
    /**eger playerPtr'in degeri x'e esitse a dizisinin random'un verdigi degerin yerindeki degeri x'e esitler
    o'ya esitse a dizisinin random'un verdigi degerin yerindeki degeri o'ya esitler**/
    if (*playerPtr == 'X')
    {
        a[ random ] = 'X', printf("%d", random);
    }
    else
    {
        scanf("%d", &choice);
        a[ choice ] = 'O';
    }

    printf("\n");
}
/**  takeTurn     Orders to play when play with human**/
void takeTurnHuman( char a[], char *playerPtr  )
{
    int available[8];
    int i, j = 0, choice;
    /**That for loop allows to create available number array **/
    for(i = 0; i < 9; i++ )
        /**That if structure help to create available number array **/
        if( (a[i] != 'X') && (a[i] != 'O')  )
            available[ j++ ] = i;

    printf( "\n It is %c's turn.  Choose your move (", *playerPtr );
    /**That for loop allows to print available array **/
    for( i = 0; i < j; i++ )
        printf( " %d", available[i]);
    printf( " ): ");
    scanf( "%d", &choice);
    /**These if else statement marks the x or o to the chosen location.**/
    if( *playerPtr == 'X' )
        a[ choice ] = 'X';
    else if(*playerPtr == 'O')
        a[ choice ] = 'O';
    else if(*playerPtr == 'x')
        a[ choice ] = 'x';
    else if(*playerPtr == 'o')
        a[ choice ] = 'o';

}
/** swapPlayer    Chooses the player  **/
void swapPlayer( char *playerPtr )
{
    /**These if else statements allows the turn to pass to the other player**/
    if( *playerPtr == 'X' )
        *playerPtr = 'O';
    else if(*playerPtr == 'O')
        *playerPtr = 'X';
    else if(*playerPtr == 'o')
        *playerPtr = 'x';
    else if(*playerPtr == 'x')
        *playerPtr = 'o';

}
