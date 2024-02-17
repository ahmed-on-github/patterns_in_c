#include <stdio.h>

int main() {
    unsigned int n, h, w,i=0,j=0;
    printf("Enter n,w,h : \n");
    scanf("%i %i %i",&n,&w,&h);
    /**Rectangles**/
    /*________Pattern 1 __________*/
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    /*________Pattern 2 __________*/
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if( i==0 || i==h-1 || j==0 || j==w-1 ){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    /**Half trianles**/
    /*________Pattern 3 __________*/
    for(i=0;i<n;i++){
        for(j=1;j<=i+1;j++){
            printf("*");
            /*
            if( i==0 || i==i+1 || j==0 || j==i+1 ){
                printf("*");
            }
            else{
                printf(" ");
            } */
        }
        printf("\n");
    }
    printf("\n");

    /*________Pattern 4 __________*/
    for(i=n;i>0;i--){
        for(j=i;j>=1;j--){
            printf("*");
            /*
            if( i==0 || i==i+1 || j==0 || j==i+1 ){
                printf("*");
            }
            else{
                printf(" ");
            } */
        }
        printf("\n");
    }
    printf("\n");
    /*________Pattern 5__________*/
    for(i=n;i>0;i--){
        for(j=i;j>=1;j--){
            if( i==n || i==1 || j==i || j==1 ){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    /**Triangles**/
    /*________Pattern 6: Full Pyramid ( Equilateral triangle)__________*/

    //unsigned int row=0;
    char last_printed = 0;
    for(i=0; i<n; i++){
        for(j=0; j<2*n-1; j++){
            if( j< n-1-i || j> n-1+i ){
                printf(" ");
                last_printed=' ';
            }
            else{
                if(last_printed == '*'){
                    printf(" ");
                    last_printed = ' ';
                }
                else{
                    printf("*");
                    last_printed = '*';
                }
            }
        }
        printf("\n");
    }
    printf("\n");
    /*________Pattern 7: Inverted Full Pyramid (Inverted Equilateral triangle)__________*/

    //unsigned int row=0;
    //last_printed= ' '; // As we start printing a '*' at 1st row, 1st col


    /*________Pattern 8: Hollow Full Pyramid (Hollow Equilateral triangle)__________*/
        //unsigned int row=0;
    for(i=0; i<n; i++){
        for(j=0; j<2*n-1; j++){
            if( j< n-1-i || j> n-1+i ){
                printf(" ");
            }
            else{
                if( /**Upper Triangle corners**/j == n-1 -i || j == n-1 +i  /**Or we are @ last row (Triangle's base)**/|| i== n-1){
                    printf( (i==n-1)?/** At Pyramid's base? print '*' if j is evn\
                           and print ' ' if j is odd **/(j%2==0?"*":" "):"*" );
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\n");

    /*________ Pattern 9: Palindrome Triangle (Numbers) __________*/
    unsigned int num=0, decrement_flag=0;
    for(i=1; i<=n; i++){
        num = 1;
        decrement_flag=0;
        for(j=0; j<2*i-1; j++){
           if(num<i && decrement_flag ==0){
               printf("%d ",num++ );
           }
           else{
               decrement_flag =1;
                (num>0)?printf("%d ",num--):printf(" ");
           }
        }
        printf("\n");
    }
    printf("\n");

    /*________ Pattern 10: Palindrome Triangle (Alphabetical) __________*/
    for(i=1; i <= n; i++){
        num = 1;
        decrement_flag=0;
        for(j=0; j < 2*i-1; j++){
            if(num<i && decrement_flag ==0){
                printf("%c ",(char)('A' -1 + num++) );
            }
            else{
                decrement_flag =1;
                (num > 0)?printf("%c ",(char)('A' -1 +num--) ):printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    /*________ Pattern 11 : Equilateral Triangle (Numerical) __________*/
    //char last_printed_char = ' ';
    for(i=1; i <=n; i++){
        num = 1;
        decrement_flag=0;
        for(j=0; j < 2*n-1; j++){
            if( j< n-1 -i || j > n-1 +i ){
                printf("  "); /** 2 spaces **/
            }
            else{
                if(num<i && decrement_flag ==0){
                    printf("%d ",num++);
                }
                else{
                    decrement_flag =1;
                    (num > 0)?printf("%d ",num-- ):printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\n");

    /*________ Pattern 12 : Equilateral Triangle 2 (Numerical) __________*/
    last_printed = 0 ;
    for(i=0; i < n; i++){
        for(j=0; j < 2*n-1; j++){
            if( j< n-1 -i || j > n-1 +i ){
                printf("*");
                last_printed='*';
            }
            else{
                if( last_printed == '*' ){
                    printf("%d",i+1);
                    last_printed = i+1;
                }
                else{
                    printf("*");
                    last_printed = '*';
                }
            }
        }
        printf("\n");
    }
    printf("\n");
    /**Diamonds**/
    /*________ Pattern 13 : Solid Diamond __________*/
    for(i = 0 ; i< 2*n ;i++){
        for( j= 0 ; j<2*n-1 ; j++){

            if(i<n){ //Upper half
                if( j< n-1 -i || j> n-1 +i){ //Prints spaces only
                    printf(" ");
                    last_printed = ' ';
                }
                else{
                    if( last_printed == '*' ){
                        printf(" ");
                        last_printed = ' ';
                    }
                    else{
                        printf("*");
                        last_printed = '*';
                    }
                }
                /* Update this for the lower reverted triangle to start printing a '*' */
                if( (i== n-1) && (j== 2*n-2) ){
                    last_printed =' ';
                }
            }
            else{//Lower half
                if( j< (i-n) || j> 2*n-2 -(i-n) ){ //Prints spaces only
                    printf(" ");
                    last_printed = ' ';
                }
                else{
                    if( last_printed == '*' ){
                        printf(" ");
                        last_printed = ' ';
                    }
                    else{
                        printf("*");
                        last_printed = '*';
                    }
                }
            }
        }
        printf("\n");
    }
    printf("\n");
    /*________ Pattern 14 : hollow Diamond __________*/
    for(i = 0 ; i< 2*n ;i++){ /** 2n rows **/
        for( j= 0 ; j<2*n-1 ; j++){ /** 2n-1 columns of either '*'s or spaces **/

            if(i<n){ //Upper half
                if( j< n-1 -i || j> n-1 +i){ //Prints spaces only
                    printf(" ");
                }
                else{
                    (j==n-1-i || j==n-1+i)?printf("*"):printf(" ");
                }
            }
            else{//Lower half
                if( j< (i-n) /**Left spaces**/|| j > 2*n-2 /**Not -1 bec. max of j = 2n-2**/ -(i-n ) /**Right space**/){ //Prints spaces only
                    printf(" ");
                }
                else{
                    (j==i-n || j==2*n-2 -(i-n))?printf("*"):printf(" ");
                }
            }
        }
        printf("\n");
    }
    /*________ Pattern 15 : Rigth half solid Diamond __________*/
    decrement_flag=0;
    for(i=0; i< 2*n- 1 ;i++){ /// 2n-1 rows
        if( i< n){
            for(j=0;j<i; j++){
                printf("*");
            }
            printf("\n");
        }
        else{
            for(j=2*n-2 /**This is the max value of i**/ -i ;j>0; j--){
                printf("*");
            }
            printf("\n");
        }
    }
    printf("\n");
    /**Rhombus**/
    /*________ Pattern 16 : solid Rhombus __________*/
    for(i= 0 ; i< n ;i++){ /** n rows **/
        for(j=0;j<2*n-1 -i;j++){ /** variable number of columns , from 2n-1 columns at 1st row to n columns at last row **/
            (j<n-1- i /**n-1 is max value of i**/ )?printf(" "):printf("*");
        }
        printf("\n");
    }
    printf("\n");

    /*________ Pattern 17 : Hollow Rhombus __________*/
    for(i= 0 ; i< n ;i++){ /** n rows **/
        for(j=0;j<2*n-1 -i;j++){ /** variable number of columns , from 2n-1 columns at 1st row to n columns at last row **/
            (j<n-1- i /**n-1 is max value of i**/ )?/**Spaces Before the rhombus**/printf(" "):( (i==0||i==n-1)?printf("*"):( (j== n-1 - i /**Start of rhombus**/|| j== 2*n-2 -i /**End of rhombus**/)?printf("*"):printf(" ") ) );
        }
        printf("\n");
    }
    printf("\n");

    /*________ Pattern 18 : Basic Floyd triangle __________*/
    unsigned int val = 0;
    for(i= 1 ; i<= n ;i++){ /** n rows **/
        for(j=0;j<i ;j++){
            printf("%u ",++val);
        }
        printf("\n");
    }
    printf("\n");

    /*________ Pattern 19 : Right Arrow __________*/
    for(i= 0 ; i< 2*n -1 ;i++){ /** 2n-1 rows **/
        if( i < n-1 ){ /**Upper Half **/
            if(i%2==0 /**Even rows have only 1(*) **/ ){
                for(j=0;j<n/2 +i/2 /**n/2 is the least column index to type a(*) **/;j++){
                    printf(" ");
                }
                printf("*\n");
            }
            else{ /**Odd rows -- only empty rows**/
                printf("\n");
            }
        }
        else if( i== n-1){ /**Horizontal arrow part**/
            for(j=0;j<n ;j++){
                printf("*");
            }
            printf("\n");
        }
        else{ /** i>n**/
            if(i%2==0 /**Even Columns**/ ){
                for(j=0;j< n/2+ (2*n-2-i  /**2n-2 is the max value of i**/)/2;j++){
                    printf(" ");
                }
                printf("*\n");
            }
            else{ /**Odd Columns**/
                printf("\n");
            }
        }
    }
    printf("\n");
    return 0;
}
