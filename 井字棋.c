#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 3
void display(char tablet[][N])
{
	int m=0,n=0;
	for(;m<N;m++)
	{
		for(n=0;n<N;n++)
			{
				printf("%c",tablet[m][n]);
				if(n<2) printf("|");
			}
		if(m<2) printf("\n������\n");
	}
	printf("\n");
}
int judge(char t[][N],char p)
{
	int x=0;
	int i=0,j=0;
	//�����ж�
	j=1; 
	for(;i<N;i++)
		if(t[i][j]==p&&t[i][j-1]==t[i][j]&&t[i][j]==t[i][j+1])
		{
			x=1;break;
		}
	//�����ж�
	for(i=0;i<N;i++)
	 if(t[j][i]==p&&t[j-1][i]==t[j][i]&&t[j][i]==t[j+1][i])
		{
			x=1;break;
		}
	//�Խ����ж�
	i=j=1;
	if (t[i][j]==p&&t[i-1][j-1]==t[i][j]&&t[i][j]==t[i+1][j+1] )
		x=1;
	if (t[i][j]==p&&t[i-1][j+1]==t[i][j]&&t[i][j]==t[i+1][j-1] )
		x=1;
	return x;	
}
int main()
{
	char tablet[N][N]={'\0'};
	int t=0;			//������� 
	int m=0,n=0;		//����������� 
	int i=0,j=0;		//������������ 
	int flagX,flagO;	//�ж��Ƿ��ʤ 
	char goon;			//�ж��Ƿ������Ϸ 
	srand(time(NULL));
	printf("��������Ϸ\n");
	printf("������֣�ʹ��X\n");
		for(;t<5;t++)
		{
			
			//������� 
			scanf("%d%d",&i,&j);
			tablet[i-1][j-1]='X';
			//��ʾ���� 	
			system("cls");
			display(tablet);
			//�ж� 
			flagX=judge(tablet,'X');
			flagO=judge(tablet,'O');
			if(flagX) {
				printf("\n��ϲ��ʤ���ˣ�");
				break;
			}
			if(!flagX&&flagO){
				printf("\n������");
			break;
			}
			//�������� 
			do{
				m=rand()%N;
				n=rand()%N;
			}while(tablet[m][n]!='\0');
			tablet[m][n]='O';
			//��ʾ���� 	
			system("cls");
			display(tablet);
			
			//�ж� 
			flagX=judge(tablet,'X');
			flagO=judge(tablet,'O');
			if(flagX) {
				printf("\n��ϲ��ʤ���ˣ�");
				break;
			}
			if(!flagX&&flagO){
				printf("\n������");
			break;
			}
		}
		if(flagO==flagX) printf("\nƽ��");
		
	
	return 0;
 } 
