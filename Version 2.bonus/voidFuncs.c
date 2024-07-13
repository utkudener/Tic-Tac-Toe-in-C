#include <stdio.h>
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
    int available[9];
    int i, j = 0, choice;
    int ok=0;
    /** do while ok equal to o**/
    do
    {

        printf( "\n It is %c's turn.  Choose your move (", *playerPtr );
        /** for loop to write available numbers**/
        for( i = 0; i < 9; i++ )
        {
            available[i]=i;
            /**if number equal to x or o equalize to -1
            else if print**/
            if( (a[i] != 'X') && (a[i] != 'O')  )
            {

                printf( " %d", available[i]);
            }
            else
            {
                available[i]=-1;
            }
        }
        printf( " ): ");

        scanf( "%d", &choice);
        /** for loop to increase i counter**/
        for( i = 0; i < 9; i++ )
        {
            /**if choice equal to number add 1 to ok**/
            if( choice == available[i] )
            {
                ++ok;
            }
        }
        /** if ok is not equal to 0 order to give another number
        else if ok if equal to 0 equalize *playerPtr to a[choice]**/
        if(ok)
        {
            if( *playerPtr == 'X' )
                a[ choice ] = 'X';
            else if(*playerPtr == 'O')
                a[ choice ] = 'O';
            else if(*playerPtr == 'x')
                a[ choice ] = 'X';
            else if(*playerPtr == 'o')
                a[ choice ] = 'O';
        }
        else
        {
            printf("\n\n That square marked before. '%c' Please pick another number that available. \n\n", *playerPtr );
        }

    }
    while( !ok );

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
