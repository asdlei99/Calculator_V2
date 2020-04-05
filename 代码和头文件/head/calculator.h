/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef CAL_CORE_H_INCLUDED
#define CAL_CORE_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1
#define MAX 100 

/**************************************************************
*	Struct Define Section
**************************************************************/
enum usu
{
	STACK_FULL = -10,
	STACK_RIGHT,
	STACK_EMPTY,
	SUCCESS,
	PUSH_SUCCESS
};
 
/**************************************************************
*	Prototype Declare Section
**************************************************************/
//��ʼ���������ջ
void stack_num(int *stack,int *top);

//��ʼ������������ջ 
void stack_operator(char *stack,int *top);

//���ջ�ǲ�����
int check_full(int *top);

//���ջ�ǲ��ǿ�
int check_empty(int *top);

//�ж�����������ȼ�
int priority(char c);

//�Ƚ���������ȼ� 
int compare_priority(char *str,char *stack2,int *top2,int *stack1,int *top1);

//����ִ���������� 
int calculate(int num1,int num2,char c) ;

//����ջ
int push_num(int *stack,int *num,int *top);

//�������ջ 
int push_operator(char *stack,char *c,int *top);

//����ջ 
int pop_num(int *stack,int *top);

//�������ջ 
char pop_operator(char *stack,int *top);

//����ͺ��ļ��� 
int CalcCore();

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
 
 
