#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//在画面尺寸范围内显示飞机
/*
int main()
{
	char input;
	while(1){
		
		scanf("%c",&input);
		getchar();
		switch(input) {
			case 'a':
				printf("right\n");
				break;
			case 's':
				printf("down\n");
				break;
			default:
				printf("defalut");
				break;
			case 'd':
				printf("right\n");
				break;
			case 'w':
				printf("up\n");
				break;
			
		}
	}
	return 0;
}
*/


/*************************************************************************************************************************/
/*
int width,height;

int plane_x,plane_y;
int enemy_x,enemy_y;
int bullet_x,bullet_y;

int score;
char game_over=1;

void gotoxy(int x,int y)//类似于清屏函数，光标移动到原点位置进行重画
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void init_game()
{
	width=40;
	height=20;
	plane_x=height-1;
	plane_y=width/2-1;
	enemy_x=0;
	enemy_y=plane_y;
	bullet_x=-1;
	bullet_y=plane_y;
	score=0;
}

void display()
{
	int i,j;
	
//	system("cls");
	
	int space_output=1;//如果用数组则不需要该变量,因为数组可以重复写入,
						//在数组中我们可以根据实际情况,调整各个对象写入的先后顺序; 
	
	if(game_over){
		
		gotoxy(0,0);
		for(i=0;i<height;i++)
		{
			for(j=0;j<width;j++)
			{
				
				
				if(i==plane_x && (j==plane_y-2 || j==plane_y || j==plane_y+2))
				{
					printf("*");
					space_output=0;
				}
				else if(i==plane_x-1 && (j==plane_y-1 || j==plane_y+1))
				{
					printf("*");
					space_output=0;
				}
				else if(i==plane_x-2 && j==plane_y)
				{
					printf("*");
					space_output=0;
				}
				else;
		
				
				if(i==enemy_x && j==enemy_y)
				{
					printf("#");
					space_output=0;
				}
				if(i==bullet_x && j==bullet_y) 
				{
					printf("|");
					space_output=0;
				}
				if(space_output)
				{
					printf(" ");
					space_output=1;
				}
				printf(" ");
				space_output=1;
			}
			printf("\n");
		}
		printf("score %d\n",score);
	}
	else
	printf("game over\n");//never can go here
}

//update logic
void input_relate_logic()
{
	char input;
	if(kbhit())
	{
		
		input=getch();
		switch(input) {
			case 'a':
				plane_y--;
				break;
				
			case 's':
				plane_x++;
				break;
			case 'd':
				plane_y++;
				break;
			case 'w':
				plane_x--;
				break;
			case ' ':
				bullet_x=plane_x;
				bullet_y=plane_y;
				break;
			default:
				break;
		}
	}
}


void input_unrelate_logic()
{
	static unsigned int speed=0;

	
	
	//update logic
	bullet_x--;
	speed++;
	//score(0,10) speed=20
	//score(11,20) speed=15
	//score(21,40) speed=10
	//score(41,60) speed=5
	if(score<11){
		if(speed>20){
		enemy_x++;//let enemy move downward
		speed=0;
	}
	}
	else if(score<21){
		if(speed>15){
		enemy_x++;//let enemy move downward
		speed=0;
	}
	}
	else if(score<41){
			if(speed>10){
		enemy_x++;//let enemy move downward
		speed=0;
	}
	}
	else{
		if(speed>5){
		enemy_x++;//let enemy move downward
		speed=0;
	}
	}

	
}

void judge_logic()
{
	//judge
	if(bullet_x==enemy_x && bullet_y==enemy_y ){//attack successful
		enemy_x=0;
		enemy_y=rand()%width;
		score++;
	}
	if (enemy_x>height){//enemy get out of region
		enemy_x=0;
		enemy_y=rand()%width;
		score--;
	}
	
	if(enemy_x==plane_x && (enemy_y==plane_y-2 ||enemy_y==plane_y ||enemy_y==plane_y+2)){
		game_over=0;
	}
	else if(enemy_x==plane_x-1 && (enemy_y==plane_y-1 || enemy_y==plane_y+1)){
		game_over=0;
	}
	else if(enemy_x==plane_x-2 &&  enemy_y==plane_y ){
		game_over=0;
	}
	else;
}
void logic_update()
{
	judge_logic();
	input_unrelate_logic();
	input_relate_logic();
	
}
int main(int argc, char *argv[]) {
	init_game();
	while(game_over){
		//first let the logic displayed;
		//second judge;
		//third let logic update;
		display();
		logic_update();
	}
	return 0;
}


*/
/***********************************************************************************************************************/


//V1.0
//1.实现游戏结束的画面
//2.将流程改进为 a.display b.logic judge c.logic update
//3.数组实现



//
//display
//judge
//logic update
//{
//	input logic
//	no input logic
//	mark location
//}
//



#define HEIGHT 20
#define WIDTH 30

#define TOP 0
#define BOTTOM (HEIGHT-1)
#define RIGHT (WIDTH-1)
#define LEFT 0

#define ENEMY_NUM 5

#define CANVAS_MARK 0
#define PLANE_MARK 1
#define ENEMY_MARK 2
#define BULLET_MARK 3

#define BULLET_MAX_NUM 3
int canvas[HEIGHT][WIDTH];

int plane_x,plane_y;
int enemy_x[ENEMY_NUM],enemy_y[ENEMY_NUM];
int bullet_x[BULLET_MAX_NUM],bullet_y[BULLET_MAX_NUM];
int bullet_num;//取值限定为 1或3 实现了一列或三列子弹发射 

char game_over=0;
char game_over_flag=0;
char bullet_display_flag=0;

int score;

void location_mark();
void gotoxy(int x,int y)//类似于清屏函数，光标移动到原点位置进行重画
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}


void init_game()
{
	int i,j;
	plane_x=HEIGHT-1;
	plane_y=WIDTH-1;
	bullet_num=1;
	bullet_display_flag=0;
	game_over=0;
	score=0;
	for (i=0;i<ENEMY_NUM;i++){
		enemy_x[i]=0;
		enemy_y[i]=rand()%WIDTH;
	}	
	for (i=0;i<bullet_num;i++){
		bullet_x[i]=-1;
		if (i==0)
			bullet_y[i]=plane_y;
		else if (i==1){
			bullet_y[i]=plane_y-1;
		}
		else if (i==2){
			bullet_y[i]=plane_y+1;
		}
	}
	
	
	location_mark();
//	for (i=0;i<HEIGHT;i++)
//		for (j=0;j<WIDTH;j++){
//			canvas[i][j]=CANVAS_MARK;
//		}
//	canvas[plane_x][plane_y]=PLANE_MARK;//plane marked with integer 1
//	for (i=0;i<ENEMY_NUM;i++){
//		canvas[enemy_x[i]][enemy_y[i]]=ENEMY_MARK;//enemy marked with integer 2
//	}	
//	
//	for (i=0;i<bullet_num;i++){
//		canvas[bullet_x[i]][bullet_y[i]]=BULLET_MARK;
//	}
		
}

void display_end()
{
	printf("all score %d\n",score);	
	printf("Game over\n");	
}


void display()
{
	int i,j;
	
	gotoxy(0,0);
	for(i=0;i<HEIGHT;i++){
	
		for(j=0;j<WIDTH;j++){
			if(canvas[i][j]==CANVAS_MARK)
				printf(" ");
//			else if(canvas[i][j]==PLANE_MARK)
//				printf("*");
			else if(canvas[i][j]==ENEMY_MARK)
				printf("#");
			else if(canvas[i][j]==BULLET_MARK)
				if (bullet_display_flag)
					printf("|");
				else;
				//	printf("*");
			else if(canvas[i][j]==PLANE_MARK)
				printf("*");
		}
		printf("\n");
	}
	printf("current score %d",score);
	printf("   \n");//三个空格,最大4位数,解决由于gotoxy造成的图像遗留(-1 0 1)	
	
}

void logic_judge()
{
	int i,j;

//敌机跑出了边界范围	
	for (i=0;i<ENEMY_NUM;i++){
		if(enemy_x[i]>HEIGHT-1){
			enemy_x[i]=0;
			enemy_y[i]=rand()%WIDTH;
			score--;
		}	
	}
//子弹跑出上边界
	 for (i=0;i<bullet_num;i++){
	 	if (bullet_x[i] < 0){
	 		bullet_x[i]=-1;
	 		bullet_y[i]=plane_y;
	 		bullet_display_flag=0;
		 }
	 		
	 	else;
	 }
	 
//子弹与敌机碰撞
     for (i=0;i<ENEMY_NUM;i++)
     	for (j=0;j<bullet_num;j++){
     		if(enemy_x[i]==bullet_x[j] && enemy_y[i]==bullet_y[j]){
     			enemy_x[i]=0;
				enemy_y[i]=rand()%WIDTH;
				bullet_x[j]=-1;
				score++;
			 }
     			
		 }
		 
//子弹与飞机碰撞
 	for (i=0;i<ENEMY_NUM;i++){
     		if(enemy_x[i]==plane_x && enemy_y[i]==plane_y){
				game_over_flag=1;
			 }
		}
	
		
}


void logic_update_input()
{
	char input;
	int i;
	if(kbhit()){
		input=getch();
		switch(input) {
			case 'a':
				plane_y--;
				if(plane_y<LEFT)
					plane_y=0;
				break;
			case 's':
				plane_x++;
				if(plane_x>BOTTOM)
					plane_x=BOTTOM;
				break;
			case 'd':
				plane_y++;
				if(plane_y>RIGHT)
					plane_y=RIGHT;
				break;
			case 'w':
				plane_x--;
				if(plane_x<TOP)
					plane_x=TOP;
				break;
			case ' ':
					for (i=0;i<bullet_num;i++){
					bullet_x[i]=plane_x;
					if (i==0)
						bullet_y[i]=plane_y;
					else if (i==1){
						bullet_y[i]=plane_y-1;
					}
					else if (i==2){
						bullet_y[i]=plane_y+1;
					}
				}
				bullet_display_flag=1;
				break;
			default:
				break;
		
		}
	
	}
	
}

void logic_update_no_input()
{
	int i,j;
	static unsigned int speed;
	speed++;
	if(speed>20){
		speed=0;
		for (i=0;i<ENEMY_NUM;i++){
			enemy_x[i]++;
		}
	}

	for (i=0;i<bullet_num;i++){
		if (bullet_display_flag)
			bullet_x[i]--;
		else;
	}
	
	if(score>10) bullet_num=3;
	else bullet_num=1;
	
}

void location_mark()
{
	int i,j;
	//在该函数中必须执行下面的标记更新 
	for (i=0;i<HEIGHT;i++)
	for (j=0;j<WIDTH;j++){
		canvas[i][j]=CANVAS_MARK;
	}
//	canvas[plane_x][plane_y]=PLANE_MARK;//plane marked with integer 1
	for (i=0;i<ENEMY_NUM;i++){
		if(TOP<=enemy_x[i] && BOTTOM>=enemy_x[i])
		canvas[enemy_x[i]][enemy_y[i]]=ENEMY_MARK;//enemy marked with integer 2
	}
	
	for (i=0;i<bullet_num;i++){
		if(TOP<=bullet_x[i] && BOTTOM>=bullet_x[i])//子弹与飞机与敌机相比具有无效状态期,指在上次实效到没按空格发射之前; 
			canvas[bullet_x[i]][bullet_y[i]]=BULLET_MARK;
	}	
	canvas[plane_x][plane_y]=PLANE_MARK;//plane marked with integer 1
}
void logic_update()
{
	
	logic_update_input();
	logic_update_no_input();
	location_mark();
	
}

int main()
{
	unsigned int delay1,delay2;
	init_game();
	while(!game_over)
	{
		if(!game_over_flag){
			
		for (delay1=0;delay1<100;delay1++)
			for(delay2=0;delay2<65536;delay2++);
		display();
		logic_judge();
		logic_update();
		}
		else
		{
			game_over=1;
			display_end();
		}

	}
	return 0;
}
 


