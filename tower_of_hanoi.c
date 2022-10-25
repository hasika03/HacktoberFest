#include<stdio.h>
void function(int n,char from,char aux,char to )
{
    if(n==0)
        return;
    function(n-1,from,aux,to);
    printf("%d %c %c",n,from,to);
    function(n-1,aux,to,from);
}

int main()
{
    int n;
    printf("enter n");
    scanf("%d",&n);
    function(n,'A','B','C');

}