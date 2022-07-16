#include <stdio.h>

int matrix();

int main()
{
    int n,m;
    printf("Welcome ! \n");
    printf("Enter the order of your matrix: \n");
   
    printf("Enter n: \n");
    scanf("%d", &n);   
    printf("Enter m: \n");
    scanf("%d", &m);

    matrix(n,m);
    
}

/*Creating a function to take the input for the matrix and print it
followed by forming the transpose and printing it*/

int matrix(n, m)
int n,m;
{
    int i,j;
    int mat[n][m];
    int trans[m][n];
    printf("Enter the values in the matrix: \n");
    /*for input of the martirx*/
    for ( i = 0; i < n; i++)
   {
       for ( j = 0; j< m; j++)
       {
           printf("Value at %d x %d \n", i, j);
           scanf("%d", &mat[i][j]);

       }
   }

   /*for printing the matrix back*/
      printf("Your matrix is: \n");
   for(i=0; i<n; i++)
   {
       printf("\n");
       for(j=0; j<m; j++)
       {
           printf("%d  ", mat[i][j]);
       }
   }
   
   /*for transposing the matrix and printing it*/
   for(i=0; i<m; i++)
   {
       for(j=0; j<n; j++)
       {
           if (i==j)
           {
               trans[i][j] = mat[i][j];
           }
           else
           {
               trans[i][j] = mat[j][i];
           }
       }
   }
   
   printf("\n \nThe transpose of your matrix is:");
   for(i=0; i<m; i++)
   {
       printf("\n");
       for(j=0; j<n; j++)
       {
           printf("%d  ", trans[i][j]);
       }
   }

}

