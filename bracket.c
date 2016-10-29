#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int t,n;// t is no. of test cases 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        char stack[1000000];
        int top=-1;
        void push(int n)
        {
            top++;
            stack[top]=n;
        }
        void pop(void)
        {
          top--;
        }

        int isEmpty(void)
        {
            if(top==-1)
            return 1;
            return 0;
        }        
        char* s = (char *)malloc(10240 * sizeof(char));
        scanf("%s",s);
        n=strlen(s);
        for(int i=0;i<n;i++)
            {
                if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                {
                    push(s[i]);
                }
                else 
                {
                    if(s[i]==')' && stack[top]=='(')
                    {
                        pop();
                    }
                    else if(s[i]==']' && stack[top]=='[')
                    {
                        pop();
                    }
                    else if(s[i]=='}' && stack[top]=='{')
                    {
                        pop();
                    }
                    
                    else break;
                }
            }
    
        if(isEmpty())
            {
              printf("YES\n");
            }
        else printf("NO\n");
        
    }
   return 0; 
}
