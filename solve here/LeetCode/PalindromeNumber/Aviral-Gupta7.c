#include<stdio.h>

void isPalindrome(int x){

    if (x < 0)
    {
        printf("False");
        return;
    }

  int rev = 0,temp = x,rem;

  while (temp != 0)
  {
    rem = temp%10;
    rev = (rev * 10) + rem;
    temp/=10;
  }

  if (rev == x)
  {
    printf("True");
  }
  else{
    printf("False");
  }

}

int main()
{
    int x;
    printf("Enter a number : ");
    scanf("%d",&x);
    isPalindrome(x);
    return 0;
}
