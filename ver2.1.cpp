//wirte by yuziming and jiangchen
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<conio.h>
#include<ctime>
#include<windows.h>
#include <conio.h>
using namespace std;
int screen[500][500];//[y][x]
struct man{
	int x;
	int y;
	int HP;
	int attack;
	int attime;
}man1,man2;
//80*80
//system("cls");
int input;

int attack1Time,attack2Time;

int welcome(){
	system("cls");
	printf("这是一个双人对打沙雕小游戏\n");
	printf("由yuziming 和 jiangchen开发\n\n"); 
	printf("玩家1按WASD进行移动，按J健攻击\n");
	printf("玩家2按方向键来移动，数字0攻击\n\n");
	printf("祝您玩的愉快！\n按任意键开始");
	_getch(); 
	system("cls");
}

int maninit(){
	
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=false;
	SetConsoleCursorInfo(hOut,&cci);
	
	for(int a=1;a<=50;a++){
		for(int b=1;b<=50;b++){
			screen[a][b]=0;
		}
	}
	
	man1.attack=10;
	man1.HP=100;
	man1.x=5;
	man1.y=5;
	man2.attack=10;
	man2.HP=100;
	man2.x=25;
	man2.y=5;
}

int getNowTime(){
	return clock();
}

int mancheck(){
	if(screen[man1.y][man1.x]==-2 && getNowTime()-man1.attime>250){
		man1.HP-=man2.attack;
		man1.attime=getNowTime();
	}
	if(screen[man2.y][man2.x]==-1 && getNowTime()-man2.attime>250){
		man2.HP-=man1.attack;
		man2.attime=getNowTime();
	}
	if(man1.HP<=0 || man2.HP<=0){
		return -1;
	}
}

int scankey(){
	if (_kbhit()){
		input=getch();
		if(input==224) input=getch();
		return input;
	}
	else{
		input=0;
		return 0;
	}
}

int ifattack(){
	if(input==106){
		attack1Time=getNowTime();
	}
	if(input==48){
		attack2Time=getNowTime();
	}
}

void cleanat1(){
	for(int a=man1.y-3;a<=man1.y+3;a++){
		for(int b=man1.x-3;b<=man1.x+3;b++){
			screen[a][b]=0;
		}
	}
}

void cleanat2(){
	for(int a=man2.y-3;a<=man2.y+3;a++){
		for(int b=man2.x-3;b<=man2.x+3;b++){
			screen[a][b]=0;
		}
	}
}

int showattack1(){
//	cleanat1();
	int d1=getNowTime()-attack1Time;
	if(d1>0 && d1<125){
		screen[man1.y-1][man1.x]=-1;
		screen[man1.y-2][man1.x]=-1;
		mancheck();
	}
	if(d1>125 && d1<250){
		screen[man1.y-1][man1.x+1]=-1;
		screen[man1.y-2][man1.x+2]=-1;
		mancheck();
	}
	if(d1>250 && d1<375){
		screen[man1.y][man1.x+1]=-1;
		screen[man1.y][man1.x+2]=-1;
		mancheck();
	}
	if(d1>375 && d1<500){
		screen[man1.y+1][man1.x+1]=-1;
		screen[man1.y+2][man1.x+2]=-1;
		mancheck();
	}
	if(d1>500 && d1<625){
		screen[man1.y+1][man1.x]=-1;
		screen[man1.y+2][man1.x]=-1;
		mancheck();
	}
	if(d1>625 && d1<750){
		screen[man1.y+1][man1.x-1]=-1;
		screen[man1.y+2][man1.x-2]=-1;
		mancheck();
	}
	if(d1>750 && d1<875){
		screen[man1.y][man1.x-1]=-1;
		screen[man1.y][man1.x-2]=-1;
		mancheck();
	}
	if(d1>875 && d1<1000){
		screen[man1.y-1][man1.x-1]=-1;
		screen[man1.y-2][man1.x-2]=-1;
		mancheck();
	}
//	else cleanat1();
}

int showattack2(){
//	cleanat2();
	int d2=getNowTime()-attack2Time;
	if(d2>0 && d2<125){
		screen[man2.y-1][man2.x]=-2;
		screen[man2.y-2][man2.x]=-2;
		mancheck();
	}
	if(d2>125 && d2<250){
		screen[man2.y-1][man2.x+1]=-2;
		screen[man2.y-2][man2.x+2]=-2;
		mancheck();
	}
	if(d2>250 && d2<375){
		screen[man2.y][man2.x+1]=-2;
		screen[man2.y][man2.x+2]=-2;
		mancheck();
	}
	if(d2>375 && d2<500){
		screen[man2.y+1][man2.x+1]=-2;
		screen[man2.y+2][man2.x+2]=-2;
		mancheck();
	}
	if(d2>500 && d2<625){
		screen[man2.y+1][man2.x]=-2;
		screen[man2.y+2][man2.x]=-2;
		mancheck();
	}
	if(d2>625 && d2<750){
		screen[man2.y+1][man2.x-1]=-2;
		screen[man2.y+2][man2.x-2]=-2;
		mancheck();
	}
	if(d2>750 && d2<875){
		screen[man2.y][man2.x-1]=-2;
		screen[man2.y][man2.x-2]=-2;
		mancheck();
	}
	if(d2>875 && d2<1000){
		screen[man2.y-1][man2.x-1]=-2;
		screen[man2.y-2][man2.x-2]=-2;
		mancheck();
	}
//	else cleanat2();
}

void manmove(){
//		int a,b;
//		a = getch();			//w 119 a 97 s 115 d 100
		if(input == 119 && man1.y > 3)
			man1.y--;
		if(input == 97 && man1.x > 1)
			man1.x--;
		if(input == 115 && man1.y < 20)
			man1.y++;
		if(input == 100 && man1.x < 30)
			man1.x++;
//		if(input == 119 || a == 97 || a == 115 || a == 100)
//			return;
//		b = getch();			//w 72 s 80 a 75 d 77
		if(input == 72 && man2.y > 3)
			man2.y--;
		if(input == 75 && man2.x > 1)
			man2.x--;
		if(input == 80 && man2.y < 20)
			man2.y++;
		if(input == 77 && man2.x < 30)
			man2.x++;
}

int print_scr(){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=1;
	pos.Y=1;
	SetConsoleCursorPosition(hOut,pos);
//	system("cls");
	for(int a=1;a<=20;a++){
		for(int b=1;b<=30;b++){
			if(man1.x==b && man1.y==a){
				printf("①"); //
				b+=1;
				continue;
			}
			if(man2.x==b && man2.y==a){
				printf("②"); //
				b+=1;
				continue;
			}
			if(screen[a][b]==-1){
				printf("+");
				continue;
			}
			if(screen[a][b]==-2){
				printf("+");
			}
			else printf(" ");
		}
		printf("\n");
	}
	printf("player1 HP %d ",man1.HP);
	if(getNowTime()-man1.attime<=250)printf("    NB ! ! !");
	else printf("            ");
	printf("\n");
	printf("player2 HP %d ",man2.HP);
	if(getNowTime()-man2.attime<=250)printf("    NB ! ! !");
	else printf("            ");
	printf("\n");
}

void gameover(){
	if(man1.HP<=0)
		printf("man2 win\n");
	else
		if(man2.HP<=0)
			printf("man1 win\n");
	printf("press 'r' to restart.");
}


int main(){
	welcome();
	maninit();
	while(1)
	{
		scankey();
		manmove();
		ifattack();
		showattack1();
		showattack2();
		print_scr();
		if(mancheck()==-1) break;
		cleanat1();
		cleanat2();
	}
	gameover();
	Sleep(500);
	char ch;
	while(ch!='r'){
		ch = _getch();
//		if(ch==27) return 0;
	}
	system("cls");
	main();
//	system("pause");
	return 0;
}







