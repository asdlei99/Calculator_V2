#include "..\head\calculator.h"
#include "..\calculator\calculator.c"
#include "stdlib.h"
#include "stdio.h" 
int main() 
{
    void ScreenShow();
    int CalcCore();
    ScreenShow(); 
    while(1){
	CalcCore();
	}
    return 0;
}
 
void ScreenShow(){
	printf("��ӭʹ���������������V2��\n");
	printf("***********************\n");
	printf("˵����\n(1)֧�ִ����ŵ�����ʽ�����ű�����Ӣ��״̬����������š�\n");
	printf("(2)ֻ֧�ֵ�һ����Ϊ�����������\n(3)��֧�ָ������㡣\n") ;
	printf("***********************\n");
	printf("����������ʽ��ע��Ӣ�����ţ�����Enter���㣺\n");
} 
