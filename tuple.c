#include<stdio.h>
#include<stdlib.h>
struct tuple{
    int r;
    int c;
    int v;
};
int a[100][100], b[100][100], r1, r2, c1, c2,nz1 = 0, nz2 = 0;
struct tuple t1[100],t2[100],tt1[100],tt2[100],tr[100];
void printmatrix(int p[100][100], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%i\t", p[i][j]);

        }
        printf("\n");
    }
}

void convert(int p[100][100], int r, int c, int nz,struct tuple t[100]) {
    printf("%i\t",r);
    printf("%i\t",c);
    printf("%i\t",nz);
    printf("\n");
    int k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (p[i][j] != 0) {
                t[k].r=i;
                t[k].c=j;
                t[k].v=p[i][j];
                k++;
            }

        }
    }
    for (int i = 0; i < nz; i++) {
        printf("%i\t", t[i].r);
        printf("%i\t", t[i].c);
        printf("%i\t", t[i].v);
        printf("\n");

    }
}
void transpose(struct tuple p[100], int nz,int r,int c,struct tuple tt[100]){


    for (int i = 0; i < nz; i++) {
        tt[i].r = p[i].c;
        tt[i].c = p[i].r;
        tt[i].v = p[i].v;
    }
    for (int i = 0; i < nz-1; i++) {
        for (int j = 0; j < nz - i - 1; j++) {
            if (tt[j].r > tt[j + 1].r) {
                struct tuple temp;
                temp=tt[j];
                tt[j]=tt[j+1];
                tt[j+1]=temp;

            }

        }
    }
    printf("%i\t",c);
    printf("%i\t",r);
    printf("%i\t",nz);
    printf("\n");
    for (int i = 0; i < nz; i++) {
        printf("%i\t",tt[i].r);
        printf("%i\t",tt[i].c);

        printf("%i\t",tt[i].v);
        printf("\n");
    }

}
void normal(struct tuple p[100],int nz,int r,int c){
    int out[100][100]={0};
    for( int k=0;k<nz;k++){
        out[p[k].r][p[k].c]=p[k].v;
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            printf("%i\t",out[i][j]);
        }
       printf("\n");
    }
}
void addition(struct tuple p1[100],struct tuple p2[100],int nz1, int nz2,int r,int c){
    int out[100][100]={0};
    int nz=0;
    for( int k=0;k<nz1;k++){
        out[p1[k].r][p1[k].c]+=p1[k].v;
    }
    for( int j=0;j<nz2;j++){
        out[p2[j].r][p2[j].c]+=p2[j].v;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            
            if(out[i][j]!=0){
                nz++;
            }
        }

    }
    convert(out,r,c,nz,tr);

}
int main() {

    printf("Enter the size of first matrix \n");
    scanf("%i%i", &r1, &c1);
    printf("'Enter the elements of the array\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%i", &a[i][j]);
            if (a[i][j] != 0)
                nz1++;

        }
    }
    printf("Enter the size of Second matrix \n");
    scanf("%i%i", &r2, &c2);
    printf("'Enter the elements of the array\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%i", &b[i][j]);
            if (b[i][j] != 0)
                nz2++;

        }
    }


    int ch = 0;


    do {
        printf("1: Display the entered matrix\n");
        printf("2: Display the tuple form of entered matrix\n");
        printf("3: Display the transpose tuple form of entered matrix\n");
        printf("4: Display the normal form of transpose tuple form\n");
        printf("5: Display the sum of in tuple form \n");
        printf("0: Exit \n");
        printf("Enter the option");
        scanf("%i", &ch);
        if (ch == 1) {
            printf("Entered matrix are \n");
            printf("The first matrix is \n");
            printmatrix(a,r1,c1);
            printf("The second matrix \n");
            printmatrix(b,r2,c2);

        }
        else if(ch==2){
            printf(" Tuple matrix are \n");
            printf("The first tuple matrix is \n");
            convert(a,r1,c1,nz1,t1);
            printf("The second tuple matrix \n");
            convert(b,r2,c2,nz2,t2);
        }
        else if(ch==3){
            printf(" Tuple transpose matrix are \n");
            printf("The first tuple transpose matrix is \n");
            transpose(t1,nz1,r1,c1,tt1);

            printf("The second tuple transpose matrix \n");
            transpose(t2,nz2,r2,c2,tt2);

        }
        else if(ch==4){
            printf("Transpose \n");
            printf("The first transpose\n");
            normal(tt1,nz1,r1,c1);
            printf("The second transpose\n");
            normal(tt2,nz2,r2,c2);

        }
        else if(ch==5){
            if(r1==r2 && c1==c2) {
                printf("The sum of th matrix in tuple form is\n");
                addition(t1,t2,nz1,nz2,r1,c2);
            }
            else{
                printf("Size not matching \n");
            }
        }
        else if(ch==0){
            exit(0);
        }
    } while (ch != 0);

}