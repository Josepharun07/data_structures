#include <stdio.h>
int main()
{
int ar[50],k,i,j,n,pos=-1;
printf("Enter the number of elements: ");
scanf("%d",&n);
printf("Enter the elements\n");
for(i=0;i<n;i++)
scanf("%d",&ar[i]);
printf("Enter the element to be searched: ");
scanf("%d",&k);
int ch;
printf("1. Linear search\n2. Binary search\n3. Exit\n");
do{
printf("Enter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
for(i=0;i<n;i++)
{
if(k==ar[i])
{
pos=i;
break;
}
}
if(pos==-1)
{
printf("Element not in the list\n");
}
else
{
printf("Element found at positional index %d\n",pos);
}
break;
}
case 2:
{
for(i=0;i<n;i++)
for(j=0;j<n-i-1;j++)
{
if(ar[j]>ar[j+1])
{
int temp=ar[j];
ar[j]=ar[j+1];
ar[j+1]=temp;
}
}

printf("Sorted list is \n");
for(i=0;i<n;i++)
printf("%d \t",ar[i]);

int mid,l,h;
l=0;
h=n-1;
while(l<=h)
{
mid=(l+h)/2;
if (ar[mid]==k)
{
pos=mid;
break;
}
else if(ar[mid]<k)
{
l=mid+1;
}
else
{
h=mid-1;
}
}
if(pos==-1)
{
printf("Element not in the list \n");
}
else
{
printf("\nElement found at positional index %d\n",pos);
}
break;
}
case 3:
{
printf("Exiting...");
break;
}
}
}while(ch!=3);
}