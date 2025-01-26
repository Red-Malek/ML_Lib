#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>
#define PAS 0.01
#define MAX_SIZE 5



typedef struct {
    double slope;
    double intercept;
}linear_regression;



long double SSE(float a ,float b,double *x,double *y,int n)
{
    long double res=0;
    for(int i=0;i<n;i++)
    {
        res+=pow(y[i]-a*x[i]-b,2);
    }
    return res/(float)n;
}



float derivee_prprt_a(float a,float b,double *x,double *y,int n)
{
    float d=0;
    for (int i=0;i<n;i++)
    {
        d+=x[i]*(y[i]-a*x[i]-b);
    }
    return (((-1/(float)n)*d));
}



float derivee_prprt_b(float a,float b,double *x,double *y,int n)
{
    float d=0;
    for (int i=0;i<n;i++)
    {
        d+=(y[i]-a*x[i]-b);
    }
    return (((-1/(float)n)*d));
}



void Linear_regression(double *x,double *y,linear_regression *reg,int n)
{
    srand(time(0)); 
    double a= ((double)rand() / RAND_MAX)*200-101; 
    double b = ((double)rand() / RAND_MAX) *200-101;
    
   float derivee_a=derivee_prprt_a(a,b,x,y,n);
   float derivee_b=derivee_prprt_b(a,b,x,y,n);

   float temp1=derivee_a;
   float temp2=derivee_b;
   
   while (temp1*derivee_a>0 ||  temp2*derivee_b>0)
   { 
        a-=PAS*derivee_a;
        b-=PAS*derivee_b;
         derivee_a=derivee_prprt_a(a,b,x,y,n);
         derivee_b=derivee_prprt_b(a,b,x,y,n);
   }

   reg->intercept=b;
   reg->slope=a;
}



void free_memory(double *x,double*y)
{
    free(x);
    x=NULL;
    free(y);
    y=NULL;
}



int read_data(const char *filename, double *X, double *y, int max_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        puts("Error opening file");
        return -1;  
    }

    int count = 0;
    while (count < max_size && fscanf(file, "%lf,%lf", &X[count], &y[count]) == 2) {
        count++;
    }

    fclose(file);  
    return count;  
}



int main()
{
    /*float  x[10]={2,4,2,5,6.5,8,5,8,4,7};
    float  y[10]={5,4,7,2,5,6,5.2,8.2,6.1,10.2};*/
    
    double *x;
    double *y;
    x=(double*)malloc(sizeof(double)*MAX_SIZE);
    y=(double*)malloc(sizeof(double)*MAX_SIZE);
    linear_regression reg;
    int data_size=read_data("data_example1.txt",x,y,MAX_SIZE);
    if(data_size<=0)
    {
        return -1;
    }
    Linear_regression(x,y,&reg,data_size);
    printf("%f  %f",reg.slope,reg.intercept);
    free_memory(x,y);
 return 0;
}


