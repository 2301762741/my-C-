#define N 200
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP 0x4800
#define ESC 0x011b
int i,key;
int score=0;/*得分*/
int gamespeed=50000;/*游戏速度自己调整*/
struct Food
{
   int x;/*食物的横坐标*/
   int y;/*食物的纵坐标*/
   int yes;/*判断是否要出现食物的变量*/
}food;/*食物的结构体*/
struct Snake
{
   int x[N];
   int y[N];
   int node;/*蛇的节数*/
   int direction;/*蛇移动方向*/
   int life;/* 蛇的生命,0活着,1死亡*/
}snake;
void Init(void);/*图形驱动*/
void Close(void);/*图形结束*/
void DrawK(void);/*开始画面*/
void GameOver(void);/*结束游戏*/
void GamePlay(void);/*玩游戏具体过程*/
void PrScore(void);/*输出成绩*/
/*主函数*/
void main(void)
{
   Init();/*图形驱动*/
   DrawK();/*开始画面*/
   GamePlay();/*玩游戏具体过程*/
   Close();/*图形结束*/
}
/*图形驱动*/
void Init(void)
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"c:\\tc");
   cleardevice();
}
/*开始画面，左上角坐标为（50，40），右下角坐标为（610，460）的围墙*/
void DrawK(void)
{
/*setbkcolor(LIGHTGREEN);*/
   setcolor(11);
   setlinestyle(SOLID_LINE,0,THICK_WIDTH);/*设置线型*/
   for(i=50;i<=600;i+=10)/*画围墙*/
   {
      rectangle(i,40,i+10,49); /*上边*/
      rectangle(i,451,i+10,460);/*下边*/
   }
  for(i=40;i<=450;i+=10)
  {
     rectangle(50,i,59,i+10); /*左边*/
     rectangle(601,i,610,i+10);/*右边*/
  }
}
/*玩游戏具体过程*/
void GamePlay(void)
{
   randomize();/*随机数发生器*/
   food.yes=1;/*1表示需要出现新食物,0表示已经存在食物*/
   snake.life=0;/*活着*/
   snake.direction=1;/*方向往右*/
   snake.x[0]=100;snake.y[0]=100;/*蛇头*/
   snake.x[1]=110;snake.y[1]=100;
   snake.node=2;/*节数*/
   PrScore();/*输出得分*/
   while(1)/*可以重复玩游戏,压ESC键结束*/
   {
      while(!kbhit())/*在没有按键的情况下,蛇自己移动身体*/
      {
  if(food.yes==1)/*需要出现新食物*/
  {
      food.x=rand()%400+60;
      food.y=rand()%350+60;
      while(food.x%10!=0)/*食物随机出现后必须让食物能够在整格内,这样才可以让蛇吃到*/
  food.x++;
      while(food.y%10!=0)
  food.y++;
  food.yes=0;/*画面上有食物了*/
  }
  if(food.yes==0)/*画面上有食物了就要显示*/
  {
              setcolor(GREEN);
              rectangle(food.x,food.y,food.x+10,food.y-10);
  }
         for(i=snake.node-1;i>0;i--)/*蛇的每个环节往前移动,也就是贪吃蛇的关键算法*/
         {
            snake.x[i]=snake.x[i-1];
     snake.y[i]=snake.y[i-1];
  }
       /*1,2,3,4表示右,左,上,下四个方向,通过这个判断来移动蛇头*/
  switch(snake.direction)
  {
     case 1:snake.x[0]+=10;break;
     case 2: snake.x[0]-=10;break;
     case 3: snake.y[0]-=10;break;
     case 4: snake.y[0]+=10;break;
  }
  for(i=3;i<snake.node;i++)/*从蛇的第四节开始判断是否撞到自己了，因为蛇头为两节，第三节不可能拐过来*/
  {
     if(snake.x[i]==snake.x[0]&&snake.y[i]==snake.y[0])
     {
               GameOver();/*显示失败*/
               snake.life=1;
               break;
     }
        }
 if(snake.x[0]<55||snake.x[0]>595||snake.y[0]<55||
    snake.y[0]>455)/*蛇是否撞到墙壁*/
 {
     GameOver();/*本次游戏结束*/
     snake.life=1; /*蛇死*/
 }
 if(snake.life==1)/*以上两种判断以后,如果蛇死就跳出内循环，重新开始*/
           break;
 if(snake.x[0]==food.x&&snake.y[0]==food.y)/*吃到食物以后*/
 {
           setcolor(0);/*把画面上的食物东西去掉*/
           rectangle(food.x,food.y,food.x+10,food.y-10);
    snake.x[snake.node]=-20;snake.y[snake.node]=-20;
          /*新的一节先放在看不见的位置,下次循环就取前一节的位置*/
    snake.node++;/*蛇的身体长一节*/
    food.yes=1;/*画面上需要出现新的食物*/
    score+=10;
    PrScore();/*输出新得分*/
 }
 setcolor(4);/*画出蛇*/
 for(i=0;i<snake.node;i++)
    rectangle(snake.x[i],snake.y[i],snake.x[i]+10,
               snake.y[i]-10);
 delay(gamespeed);
 setcolor(0);/*用黑色去除蛇的的最后一节*/
 rectangle(snake.x[snake.node-1],snake.y[snake.node-1],
 snake.x[snake.node-1]+10,snake.y[snake.node-1]-10);
     }  /*endwhile（！kbhit）*/
    if(snake.life==1)/*如果蛇死就跳出循环*/
        break;
    key=bioskey(0);/*接收按键*/
    if(key==ESC)/*按ESC键退出*/
       break;
    else
       if(key==UP&&snake.direction!=4)
/*判断是否往相反的方向移动*/
   snake.direction=3;
          else
   if(key==RIGHT&&snake.direction!=2)
      snake.direction=1;
   else
      if(key==LEFT&&snake.direction!=1)
  snake.direction=2;
      else
  if(key==DOWN&&snake.direction!=3)
     snake.direction=4;
   }/*endwhile(1)*/
}
/*游戏结束*/
void GameOver(void)
{
    cleardevice(); 
    PrScore();
   setcolor(RED);
   settextstyle(0,0,4);
   outtextxy(200,200,"GAME OVER");
   getch();
}
/*输出成绩*/
void PrScore(void)
{   
   char str[10];
   setfillstyle(SOLID_FILL,YELLOW);
   bar(50,15,220,35);
   setcolor(6);
   settextstyle(0,0,2);
   sprintf(str,"score:%d",score);
   outtextxy(55,20,str);
}
/*图形结束*/
void Close(void)
{   
    getch();
    closegraph();
}