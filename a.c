#include <stdio.h>
int main()
{
int a,b,c,x1,x2,x3,x5;
scanf("%d %d %d",&a,&b,&c);
if (a>b){
    if(b>c){
        x1=a;
        x2=b;
        x3=c;
    }else if(a<c){
        x1=c;
        x2=a;
        x3=b;
    }else{
     x1=a;
        x2=c;
        x3=b;
    }
}else{
      if(a>c){
        x1=b;
        x2=a;
        x3=c;
    }else if(a<c){
        if(b>c){
             x1=b;
        x2=c;
        x3=a;
        }else{
        x1=c;
        x2=b;
        x3=a;
        }
    }
}
x5=x1*100+x2*10+x3;
printf("le plus grand nbre est %d\n",x5);
if (a<b){
    if(b<c){
        x1=a;
        x2=b;
        x3=c;
    }else if(a<c){
        x1=a;
        x2=c;
        x3=b;
    }else{
     x1=c;
     x2=a;
     x3=b;
    }
}else{
      if(b>c){
        x1=c;
        x2=b;
        x3=a;
    }else if(b<c){
        if(a>c){
             x1=b;
        x2=c;
        x3=a;
        }else{
        x1=b;
        x2=a;
        x3=c;
        }
    }
}
x5=x1*100+x2*10+x3;
printf("le plus petit nbre est %d",x5);
}




