
#include<bits/stdc++.h>
using namespace std;

int main(){
    printf("\n                                              Prefix code to Assembly code");
	stack<char>stack1;
	stack<int>stack2;
	char input[100], str[100],str2[100];
	printf("\nEnter a Prefix code:\n");
	int i,j,len,len2;
    scanf("%s",input);
    len=strlen(input);
    for(i=0;i<len;i++)
    {
        stack1.push(input[i]);
    }
    printf("\nOpcode Operand Comment\n");
    printf("------ ------- -------\n");
    int temp_number=1,flag=0,temp_flag=0,flag2=0;
    while(!stack1.empty())
    {
        int x=0;
        char c=stack1.top();
        while(1)
        {
            if(c=='*'|| c=='/' || c=='+' || c=='-'){break;}
            str[x]=stack1.top();
            x++;
            stack1.pop();
            if(stack1.empty()){break;}
            c=stack1.top();
        }
        str[x]='\0';
        char sign=stack1.top();
        stack1.pop();
        strcpy(str2,strrev(str));
        if(x==2)
        {
            if(flag!=0)
            {
                printf("STOR    Temp%d    Temp%d<-AC\n",temp_number,temp_number);
                stack2.push(temp_number);
                temp_number++;
            }
            flag=1;
            printf("LOAD    %c        AC<-%c\n",str2[0],str2[0]);
            if(sign=='*')
            {
                 printf("MPY     %c        AC<-AC%c%c\n",str2[1],sign,str2[1]);
            }
            else if(sign=='/')
            {
                 printf("DIV     %c        AC<-AC%c%c\n",str2[1],sign,str2[1]);
            }
            else if(sign=='+')
            {
                 printf("ADD     %c        AC<-AC%c%c\n",str2[1],sign,str2[1]);
            }
            else if(sign=='-')
            {
                 printf("SUB     %c        AC<-AC%c%c\n",str2[1],sign,str2[1]);
            }
        }
        else if(x==1)
        {
            if(sign=='*')
            {
                 printf("MPY     %c        AC<-AC%c%c\n",str2[0],sign,str2[0]);
            }
            else if(sign=='/')
            {
                 printf("DIV     %c        AC<-AC%c%c\n",str2[0],sign,str2[0]);
            }
            else if(sign=='+')
            {
                 printf("ADD     %c        AC<-AC%c%c\n",str2[0],sign,str2[0]);
            }
            else if(sign=='-')
            {
                 printf("SUB     %c        AC<-AC%c%c\n",str2[0],sign,str2[0]);
            }
        }
        else if(x==0)
        {
            {
                if(sign=='*')
                {
                     printf("MPY     Temp%d    AC<-AC%cTemp%d\n",stack2.top(),sign,stack2.top());
                }
                else if(sign=='/')
                {
                     printf("DIV     Temp%d    AC<-AC%cTemp%d\n",stack2.top(),sign,stack2.top());
                }
                else if(sign=='+')
                {
                     printf("ADD     Temp%d    AC<-AC%cTemp%d\n",stack2.top(),sign,stack2.top());
                }
                else if(sign=='-')
                {
                     printf("SUB     Temp%d    AC<-AC%cTemp%d\n",stack2.top(),sign,stack2.top());
                }
                stack2.pop();
                temp_number--;
            }
      }
    }
    printf("STOR    Temp%d    Temp%d<-AC\n",temp_number,temp_number);
}

