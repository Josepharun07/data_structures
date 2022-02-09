#include<stdio.h>
struct polynomial
{
     int coeff, exp;

};

int main()
{
    struct polynomial p1[10], p2[10], p3[10], temp;
    int n1, n2, n3;
    printf("Enter the number of terms of the first polynomial\n");
    scanf("%d", &n1);
    printf("\nEnter the terms of the first polynomial\n");
    for(int i=0; i<n1; i++)
    {
        printf("Coefficent and exponent of term %d: ", i+1);
        scanf("%d %d", &p1[i].coeff, &p1[i].exp);
    }
    printf("\nPolynomial 1: ");
    for(int i=0; i<n1-1; i++)
    printf("%dx^%d+", p1[i].coeff, p1[i].exp);
    printf("%dx^%d", p1[n1-1].coeff, p1[n1-1].exp);



    printf("\nEnter the number of terms of the second polynomial\n");
    scanf("%d", &n2);
    printf("\nEnter the terms of the second polynomial\n");
    for(int i=0; i<n2; i++)
    {
        printf("Coefficent and exponent of term %d: ", i+1);
        scanf("%d %d", &p2[i].coeff, &p2[i].exp);
    }
    printf("\nPolynomial 2: ");
    for(int i=0; i<n2-1; i++)
    printf("%dx^%d+", p2[i].coeff, p2[i].exp);
    printf("%dx^%d", p2[n2-1].coeff, p2[n2-1].exp);


    n3=n1;
    for(int i=0; i<n3; i++)
    {
        p3[i].coeff = p1[i].coeff;
        p3[i].exp = p1[i].exp;
    }
    
    for(int i=0; i<n2; i++)
    {
        int flag = 0;
        for(int j=0; j<n3; j++)
        {
            if(p2[i].exp == p3[j].exp)
            {
                p3[j].coeff+=p2[i].coeff;
                flag = 1;
              break;
            }
        }
        if (flag==0)
        {
            p3[n3].coeff = p2[i].coeff;
            p3[n3].exp = p2[i].exp;
            n3++;
        }
    }

    for(int i=0; i<n3-1; i++)
    {
        for(int j=0; j<n3-1; j++)
        {
            if(p3[j].exp<p3[j+1].exp)
            {
                temp = p3[j];
                p3[j] = p3[j+1];
               p3[j+1] = temp; 
            }
        }
    }
printf("\nPolynomial sum: ");
for(int i=0; i<n3-1; i++)
if(p3[i].coeff!=0)
printf("%dx^%d+", p3[i].coeff, p3[i].exp);
printf("%dx^%d", p3[n3-1].coeff, p3[n3-1].exp);
}
