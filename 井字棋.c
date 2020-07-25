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
		if(m<2) printf("\n———\n");
	}
	printf("\n");
}
int judge(char t[][N],char p)
{
	int x=0;
	int i=0,j=0;
	//横向判断
	j=1; 
	for(;i<N;i++)
		if(t[i][j]==p&&t[i][j-1]==t[i][j]&&t[i][j]==t[i][j+1])
		{
			x=1;break;
		}
	//纵向判断
	for(i=0;i<N;i++)
	 if(t[j][i]==p&&t[j-1][i]==t[j][i]&&t[j][i]==t[j+1][i])
		{
			x=1;break;
		}
	//对角线判断
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
	int t=0;			//下棋次数 
	int m=0,n=0;		//玩家下棋坐标 
	int i=0,j=0;		//电脑下棋坐标 
	int flagX,flagO;	//判断是否获胜 
	char goon;			//判断是否继续游戏 
	srand(time(NULL));
	printf("井字棋游戏\n");
	printf("玩家先手，使用X\n");
		for(;t<5;t++)
		{
			
			//玩家下棋 
			scanf("%d%d",&i,&j);
			tablet[i-1][j-1]='X';
			//显示棋面 	
			system("cls");
			display(tablet);
			//判断 
			flagX=judge(tablet,'X');
			flagO=judge(tablet,'O');
			if(flagX) {
				printf("\n恭喜你胜利了！");
				break;
			}
			if(!flagX&&flagO){
				printf("\n你输了");
			break;
			}
			//电脑下棋 
			do{
				m=rand()%N;
				n=rand()%N;
			}while(tablet[m][n]!='\0');
			tablet[m][n]='O';
			//显示棋面 	
			system("cls");
			display(tablet);
			
			//判断 
			flagX=judge(tablet,'X');
			flagO=judge(tablet,'O');
			if(flagX) {
				printf("\n恭喜你胜利了！");
				break;
			}
			if(!flagX&&flagO){
				printf("\n你输了");
			break;
			}
		}
		if(flagO==flagX) printf("\n平局");
		
	
	return 0;
 } 
