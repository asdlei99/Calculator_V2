#include "../head/calculator.h"
#include "stdlib.h"
#include "stdio.h" 
#define MAX 100 

//��ʼ���������ջ
void stack_num(int *stack,int *top)
{
	int i;
	for(i = 0;i < MAX;i ++)
	{
		stack[i] = 0;
	}
	*top = -1;
}

//��ʼ������������ջ 
void stack_operator(char *stack,int *top)
{
	int i;
	for(i = 0;i < MAX;i ++)
	{
		stack[i] = 0;
	}
	*top = -1;
}

 //���ջ�ǲ�����
int check_full(int *top)
{
	if(*top == MAX - 1)
	{
		return STACK_FULL;
	}
	return STACK_RIGHT;
}

//���ջ�ǲ��ǿ�
int check_empty(int *top)
{
	if(*top == -1)
	{
		return STACK_EMPTY;
	}
	return STACK_RIGHT;
}

//�ж�����������ȼ�
int priority(char c)
{
	switch(c)
	{
		//�Ӽ�ͬ���ȼ� 
		case '+': 
		case '-':
		{
			return 1;
			break;
		}
		//�˳�ͬ���ȼ� 
		case '*':
		case '/':
		{
			return 2;
			break;
		}
		default:
		{
			return 0;
		}
	}
	return 0;
}

//�Ƚ���������ȼ� 
int compare_priority(char *str,char *stack2,int *top2,int *stack1,int *top1)
{
	int num,num1,total;
	char c;
	if(*str == '\0')
	{
		return SUCCESS;
	}
	if(check_full(top2) == STACK_FULL)
	{
		return STACK_FULL;
	}
	else if(check_empty(top2) == STACK_EMPTY||*str == '(')
	{
		
		push_operator(stack2,str,top2);
	}
	else if(*str == ')')
	{
		c = pop_operator(stack2,top2); //��ջ��ȡ��һ�������
		while(c != '(')
		{
			num = pop_num(stack1,top1); //ȡ��һ��������
			num1 = pop_num(stack1,top1);
			total = calculate(num1,num,c); //����
			push_num(stack1,&total,top1); //����������ջ
			c = pop_operator(stack2,top2);
		}
	}
	else
	{
		c = pop_operator(stack2,top2);
		if(c == '(') 
		{
			push_operator(stack2,&c,top2);//�������ջ
			push_operator(stack2,str,top2);
			return SUCCESS;
		}
		num = priority(c);
		num1 = priority(*str);
		if(num1 > num)//��������ȼ�����ջ�����ȼ�
		{
			push_operator(stack2,&c,top2); //�������ջ 
			push_operator(stack2,str,top2);
		}
		else
		{
			num = pop_num(stack1,top1);//ȡ��ջ��������Ͳ�����ջջ������������������
			num1 = pop_num(stack1,top1);
			total = calculate(num1,num,c);//���� 
			push_num(stack1,&total,top1);//�������ջ 
			compare_priority(str,stack2,top2,stack1,top1);//�����Ƚϸ��������ջ������������ȼ� 
		}
	}
	return SUCCESS;
}

//����ִ���������� 
int calculate(int num1,int num2,char c) 
{
	switch(c)
	{
		case '+':
		{
			return num1 + num2;
		}
		case '-':
		{
			return num1 - num2;
		}
		case '*':
		{
			return num1 * num2;
		}
		case '/':
		{
			return num1 / num2;
		}
		
	}
}

//����ջ
int push_num(int *stack,int *num,int *top)
{
	if(check_full(top) == STACK_FULL)
	{
		return STACK_FULL;
	}
	(*top) ++;
	stack[*top] = *num;
	return PUSH_SUCCESS;
}

//�������ջ 
int push_operator(char *stack,char *c,int *top)
{
	if(check_full(top) == STACK_FULL)
	{
		return STACK_FULL;
	}
	(*top) ++;
	stack[*top] = *c;
	return PUSH_SUCCESS;
}

//����ջ 
int pop_num(int *stack,int *top)
{
	int num;
	if(check_empty(top) == STACK_EMPTY)
	{
		return STACK_EMPTY;
	}
	num = stack[*top];
	(*top) --;
	return num;
}

//�������ջ 
char pop_operator(char *stack,int *top)
{
	char c;
	if(check_empty(top) == STACK_EMPTY)
	{
		return STACK_EMPTY;
	}
	c = stack[*top];
	(*top) --;
	return c;
}

//��������ͺ��ļ��� 
int CalcCore()
{
	int num,num1;
	int total;
	char c;
	//����ռ�
	char *dest = (char *)malloc(sizeof(100)); 
	char *temp = dest;//�׵�ַ
	char *str = (char *)malloc(sizeof(100));	
	//��ջ	
	int stack1[MAX];					
	int top1;
	stack_num(stack1,&top1);
	//�����ջ		
	char stack2[MAX];					
	int top2;
	stack_operator(stack2,&top2);
	//���� 
	scanf("%s",str);
	char *ptr = str;	
    if(*str == '-') //�����һ�����Ǹ������������ 
	{num = 0;
	push_num(stack1,&num,&top1);
	}
	while(*str != '\0')
	{   
		if(*str >= '0'&&*str <= '9')//���� 
		{
			while(*str >= '0'&&*str <= '9')
			{
				*temp = *str;
				str ++;
				temp ++;
		        
			}
			*temp = '\0';
			temp = dest;		
			num = atoi(dest);//�ַ���ת����
			push_num(stack1,&num,&top1);
		}		
		compare_priority(str,stack2,&top2,stack1,&top1);		//�Ƚ�����������ȼ� 

		if(*str == ' '||(*str >= 'a' && *str <= 'z')||(*str >= 'A' && *str <= 'Z')) //�ܿ��������� 
		{
			printf("����ʽ�к�����ĸ���������");
			break;
		}
		if(*str == '\0')
		{break;
		}
		str ++;
	}
    //ȡ������ 
	while(top2 != -1)
	{
		num = pop_num(stack1,&top1);
		num1 = pop_num(stack1,&top1);
		c = pop_operator(stack2,&top2);
		total = calculate(num1,num,c);
		push_num(stack1,&total,&top1);
	}
	printf(" = %d\n",total);	
	return 0;
}
