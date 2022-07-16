#include <stdio.h>
#include <string.h>
int Reverse_complement();
int Codon_match();
int GC_composition();


/*char *strrev(char *str)*/
/* Had to copy this function code because this website doesn't have a pre defined 'strrev' function 
which usually comes with the inclusion of <string.h>*/
/* So this part is not included in my submision of the assignment*/
/*{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}*/



        
/* Creating a script in C for finding i. reverse complement, ii. GC composition, iii. codon match  */

int main()
{
    char ch;
    int ln;
    char seq[1000];
    printf("Welcome to the program \n");
    printf("Choose what you want to do: \n");
    printf("Click 'R' for reverse complement, \nClick 'C' for GC composition, \nClick 'M' for codon match, \nClick 'A' to perform all the above task");
    scanf("%c", &ch );
    
    printf("Give your sequence:(max length of 1000 bases, all uppercase) \n");
    scanf("%s", seq );

    ln = strlen(seq);

/* Creating seperate modules for each task */
    if (ch=='R')
    {
        printf("\n \n \n \n");
        Reverse_complement(seq, ln);
    }
    else if (ch=='C')
    {
        printf("\n \n \n \n");
        GC_composition(seq, ln);
    }
    else if (ch=='M')
    {
        printf("\n \n \n \n");
        Codon_match(seq, ln);
    }
    else if (ch=='A')
    {
        printf("\n \n \n \n");
        Reverse_complement(seq, ln);
        printf("\n \n \n \n");
        Codon_match(seq, ln);
        printf("\n \n \n \n");
        GC_composition(seq, ln);
        
    }
    else if ((ch=!'A') || (ch=!'M') || (ch=!'C') || (ch=!'R'))
    {
        printf("Select any one from A,M,C or R");
    }
}


/*Script for R*/
int Reverse_complement(s, ln)
int ln;
char s[1000];
{
    int i;
    char copy[1000];
    printf("Welcome to Reverse_complement module \n");
    printf("Your sequence is %s \n", s );
    strcpy(copy,s);
    i=0;
    while ( i < ln )
    {
        if (copy[i] == 'G')
        {
            copy[i] = 'C';
        }

        else if (copy[i] == 'A')
        {
            copy[i] = 'T';
        }

        else if (copy[i] == 'T')
        {
            copy[i] = 'A';
        }

        else if (copy[i] == 'C')
        {
            copy[i] = 'G';
        }

        printf( "%c", copy[i] ) ;
        i++ ;
    }

    printf("\nThe reverse complement of your function is: %s \n", strrev(copy) );
}



/*Script for M*/
int Codon_match(s, ln)
int ln;
char s[1000];
{
    int i;
    int j;
    char codon[3];
    printf("Welcome to Codon_match module \n");
    printf("Your sequence is %s \n", s );
    printf("Enter the target codon: \n");
    scanf("%s", codon );
    j=0;

    for ( i = 0; i <= ln; i++)
    {
        if(codon[0] == s[i])
        {
            if(codon[1] == s[i+1])
            {
                if(codon[2] == s[i+2])
                {
                    printf("The codon is found in the DNA sequence \n");
                    printf("The codon is in %d position \n", i );
                    j++;
                }

            }
        }
        
    }

    if(j==0)
    {
        printf("The codon was not found in the DNA sequence \n");
    }
    else
    {
        printf("The number of codon match in the sequence was found to be: %d", j );
    }
    
}



/*Script for C*/
int GC_composition(s, ln)
int ln;
char s[1000];
{
    int i, sum;
    int gc;
    float gc_comp;
    int g_count;
    int c_count;
    printf("Welcome to GC_composition module \n");
    printf("Your sequence is %s \n", s );
    i=0;
    g_count = 0;
    c_count = 0;
    while ( i < ln )
    {
        if (s[i] == 'G')
        {
            g_count++;
            i++;
        }

        else if (s[i] == 'C')
        {
            c_count++;
            i++;
        }

        else
        {
            i++;
        }
        
    }
    printf("G count in your sequrnce is: %d \n", g_count );
    printf("C count in your sequrnce is: %d \n", c_count );

    sum = g_count + c_count;
    gc = sum*100;
    gc_comp = gc / ln;

    printf("The GC composition of your sequence is: %f \n", gc_comp );
}
