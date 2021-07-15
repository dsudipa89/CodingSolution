/*Problem - The Kauravas challenge the Pandavas to break a circular battle formation known as the Chakravyuha. The Pandavas accept the challenge since they know that the knowledge of how to defeat such a formation is known to Krishna and Arjuna. However, on that day, Krishna and Arjuna are dragged into fighting a war on another front with the Samsaptakas. Since the Pandavas have accepted the challenge already, Abhimanyu decided to attempt the challenge. Abhimanyu used his skills to successfully break into the formation. Abhimanyu fights valiantly single-handedly slaying several warriors who come his way including Duryodhana's son Laxman. Upon witnessing the death of his beloved son, Duryodhana is incensed and orders the entire Kaurava force to attack Abhimanyu. Drona suggests that Abhimanyu could only be killed through illicit means His comments are met with agreement, Salya snaps Abhimanyu's bow while Dushasana and Kripa kill Abhimanyu's horses and charioteers. Dronacharya,Aswathama and Karna forms a formation to kill Abhimanu. As Abhimanu is a highly skilled warrior this formation will work only if Abhimanu lies within or on the UNIQUE CIRCLE formed by these warriors. All four individuals, i.e. Dronacharya,Aswathama, Karna and Abhimanyu stands on different position in the formation.
There may be several ways in which this formation can be made. You may assume that the all Kauravas are indistinguishable, while considering how many ways can everyone be placed. Any one of these ways now, is equiprobable.
What is the probability that Abhimanyu can be killed by Kauravas in Chakravyuha.

Input
The first line of the input contains an integer T, the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N, the number of positions in chakravyuha formation.
The next N lines consist of 2 space separated integers each, where the i'th line specifies the X and Y co-ordinates of the i'th position in chakravyuha.
Output
For each test case, output a single line containing the probability that Abhimanyu is killed in Chakravyuha.
Your answer should be round up to 6 decimal places.

Constraints
1 <= T <= 10
4 <= N <= 30
-50 <= X, Y <= 50
All (X,Y) in a test case are unique. 
*/

/*===========================================================  SOLUTION BY SUDIPA GHOSH - Roll - 16900119008 - CSE2 ===============================================*/

#include<stdio.h>
int isDivby11(int);

int main(){

    int n;
    scanf("%d",&n);

    //check contraint
    if(n<=0 || n>100){
        return 0;
    }

    int a[100][100]; // matrix to store number
    int b[20][20];   // Matrix for power point
    int counter=1;  // store the number in rectangular spiral

    int i,j,x = 1; //incices of arrays

    int w;   // w - window 

    int size=n-1; // size - size of window
    
    int no_div = (n*n)/11 + 1 ; // no of divisibles by 11

    for( w = 0 ; w < n / 2 ; w++){
        i = w;
        j = w;

        //move right
        for( j = j ; j < size + w ; j++){
        	        
            a[ i ][ j ] = counter;
            counter++;
            
            if(isDivby11( a[i][j] )){
                b[x][0]=i;
                b[x][1]=j;
                x++;
            }
        }

        //move down
        for( i = i ; i < size + w ; i++){
        				        	
            a[ i ][ j ] = counter;
            counter++;
            
            if(isDivby11( a[i][j] )){
                b[x][0]=i;
                b[x][1]=j;
                x++;
            }
        }

        //move left
        for( j = j ; j > w ; j--){
            a[ i ][ j ] = counter;
            counter++;
            
            if(isDivby11( a[i][j] )){
                b[x][0]=i;
                b[x][1]=j;
                x++;
            }
        }

        //move up
        for( i = i ; i > w ; i--){
        	          
            a[ i ][ j ] = counter;
            counter++;
            
            	if(isDivby11( a[i][j] )){
                b[x][0]=i;
                b[x][1]=j;
                x++;
            }
        }
        size = size-2;
    }
    
    // if value of n is odd
    if( n % 2 != 0){
        a[w][w] = counter;      
    }

    //print number in rectangular spiral (Chakarvyuha)
    for( i = 0 ; i < n ; i++){
        for( j = 0 ; j < n ; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    
    printf("Total Power points : %d\n",no_div);

    printf("(0,0)\n");
    int k;
    for (k=1; k<x; k++)
	{
		printf("(%d,%d)\n", b[k][0], b[k][1]);
	 } 
    return 0;
}

int isDivby11(int z){
    if( z % 11 == 0 ){
        return 1;
    }
    else{
        return 0;
    }
}



