 #include<stdio.h>
void Function1();
void Function2();
void Function3();

int main()
{
  Function1();
  Function2();
  Function3();
  return(0);
}

void Function1()
{int a;
 int b;
 printf("Give two integers:");
 scanf("%d%d",&a,&b);
 printf(" You entered %d and %d, their sum is: %d\n",a,b,a+b);
}
void Function2()
{
  float a,b;
  printf("Give two floats:");
  scanf("%f%f",&a,&b);
   printf(" You entered %f and %f, their product is: %f\n",a,b,a*b);
}void Function3()
{
  char a[4];
 printf("Give a word:");
 scanf("%s",a);
 printf(" %s %s\n",a,a);
}
