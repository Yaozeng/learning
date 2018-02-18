#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
char sp1='w',sp2='s',sp3='a',sp4='d';
char mode[50]="普通模式";
int gamestart_x=35,gamestart_y=16;
struct Monsters //怪物的属性结构——数据结构
{
	char name[10];//怪物名字
	int blood;//怪物血量
	int exp;//死后的经验
	int attack;//怪物攻击
	int defense;//怪物的防御
	int money;//死后的钱
}M1={"野狼",20,5,4,4,10};

struct role
{
	char name[7];//人物名字
	int level;    //人物等级
	int exp;//人物经验
	int sex;
	int age;
	char *d_weapon;//当前的武器
	char *d_cloth;//当前的衣服
	int attack;//当前的攻击
	int defense;//当前的防御
	int h_med;//当前金创药的个数
	int m_med;//当前魔法药的个数
	int z_magic;//总魔法值
	int z_blood;//总血值
	int d_blood;//当前的血值
	int d_magic;//当前的魔法值
	int money;//当前的钱
}role1={"尧增",1,0,1,18,0,0,8,8,0,0,80,60,60,80,500};

void gotoxy(int x,int y)//指定显示位置，注意x，y的值应该是从1开始的，和坐标值差1。
{ 
	COORD c; 
	c.X=x-1; 
	c.Y=y-1; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c); 
} 
void press()
{
	char c;
	system("cls");
	gotoxy(20,9);
	printf("游戏制作：xxxx");
	gotoxy(20,11);
	printf("制作日期：x年x月x日");
	c=getch();	
}
void gamedifficult_show()//游戏难度选择
{
	
	int hang=0;
	char ch=1;
	//system("title游戏难度选择");
	system("color f1");
	system("cls");
		
	while(!(hang==9&&ch==13))
	{
		
		gotoxy(20,hang+8); 
		printf("%c%c",16,16);
		gotoxy(22,8);
		printf("困难模式");
		gotoxy(22,11);
		printf("普通模式");
		gotoxy(22,14);
		printf("一般模式");
		gotoxy(22,17);
		printf("返回");
		gotoxy(22,19);
		printf("你选择的难度是:");
		ch=getch();
	    if(ch=='s')
			{
				hang=hang+3;
				if(hang>9)hang=hang-3;
				gotoxy(20,5+hang);printf("  ");
				gotoxy(20,8+hang); printf("%c%c",16,16); 
		}
		else if(ch=='w')
		{
			hang=hang-3;
			if(hang<0)hang=hang+3;
			gotoxy(20,11+hang);printf("  ");
			gotoxy(20,8+hang); printf("%c%c",16,16); 
		}
		if(hang==0&&ch==13)
		{
		strcpy(mode,"困难模式");
		gotoxy(40,19);
		printf("%s",mode);}
		if(hang==3&&ch==13)
			{strcpy(mode,"普通模式");
		gotoxy(40,19);
		printf("%s",mode);}
		if(hang==6&&ch==13)
			{strcpy(mode,"一般模式");
		gotoxy(40,19);
		printf("%s",mode);}
	}
		//system("pause");
	}
void hp()
{
	void map(int x,int y);
	char s;
	system("cls");
	gotoxy(22,6);
	printf("人物属性");
	gotoxy(20,8);
	printf("姓名:%s",role1.name);
    gotoxy(20,10);
	printf("武器:%s",role1.d_weapon);
	gotoxy(20,12);
	printf("性别:(1 man 0 woman)%d",role1.sex);
	gotoxy(20,14);
	printf("年龄:%d",role1.age);
	gotoxy(20,16);
	printf("血量:%d",role1.d_blood);
	gotoxy(20,18);
	printf("攻击力:%d",role1.attack);
	gotoxy(20,20);
	printf("防御力：%d",role1.defense);
	gotoxy(20,22);
	printf("等级：%d",role1.level);
	if((s=getch())==13)
	{
		map(gamestart_x,gamestart_y);
	}
}
void conversation()
{
	void map(int x,int y);
	char *a,*b,*c,*d;
	int i;
	system("cls");
	a="张小凡：你现在伤不了我，还是先下山历练一下吧！";
	b="尧增：君子报仇十年不晚，我先去江湖上闯荡一番！";
	c="张小凡：期待你的表现，我们就此定下十年之约！";
	d="尧增：好！十年之后我定会打败你！";
	i=1;
	while(*a!='\0')
	{
		gotoxy(i++,2);
	printf("%c",*a++);
	Sleep(100);
	}
	i=1;
	while(*b!='\0')
	{
	gotoxy(i++,4);
	printf("%c",*b++);
	Sleep(100);
	}
	i=1;
	while(*c!='\0')
	{
	gotoxy(i++,6);
	printf("%c",*c++);
	Sleep(100);
	}
	i=1;
	while(*d!='\0')
	{
	gotoxy(i++,8);
	printf("%c",*d++);
	Sleep(100);
	}
	Sleep(1000);
		map(35,16);
}
void weapon_buy()
{
	void map(int x,int y);
	char ch;
	int x=3,y=4;
	system("cls");
	gotoxy(1,2);
	printf("我这里的东西物美价廉，买一两件吧！");
	gotoxy(4,4);
	printf("1 麒麟弓(2000)");
	gotoxy(4,5);
	printf("2 青木弓(200)");
	gotoxy(4,6);
	printf("3 铁胎弓(100)");
	gotoxy(4,7);
	printf("离开");
	gotoxy(20,4);
	printf("武器：%s",role1.d_weapon);
	gotoxy(20,5);
	printf("金钱:%d",role1.money);
	gotoxy(20,6);
	printf("魔法药:%d",role1.m_med);
	gotoxy(20,7);
	printf("金疮药:%d",role1.h_med);
	gotoxy(20,7);
	printf("铠甲：%s",role1.d_cloth);
	gotoxy(x,y);
	printf("%c",16);
	ch=getch();
	while(!(x==3&&y==7&ch==13))
	{
			if(ch==sp1)
	{ 
		gotoxy(x,y);
		printf(" ");
		y=y-1; 
		if(y<4) 
		{
			y=y+1;
		}
		gotoxy(x,y);
		printf("%c",16);
	}
	if(ch==sp2)
	{
		gotoxy(x,y);
			printf(" ");
			y=y+1;
			if(y>7) y=y-1;
			gotoxy(x,y);
			printf("%c",16);
	}
	if(x==3&&y==4&&ch==13)
	{
		role1.money-=2000;
		if(role1.money<0)
		{
			role1.money+=2000;
			gotoxy(1,15);
			printf("你的金钱不足！");
			Sleep(1000);
			 weapon_buy();
		}
		else
		{
			role1.attack+=20;
			role1.d_weapon="麒麟弓";
			weapon_buy();
		}
	}
	if(x==3&&y==5&&ch==13)
	{
		role1.money-=200;
		if(role1.money<0)
		{
			role1.money+=200;
			gotoxy(1,15);
			printf("你的金钱不足！");
			Sleep(1000);
			weapon_buy();
		}
		else
		{
			role1.attack+=10;
			role1.d_weapon="青木弓";
			weapon_buy();
		}
	}
	if(x==3&&y==6&&ch==13)
	{
		role1.money-=100;
		if(role1.money<0)
		{
			role1.money+=100;
			gotoxy(1,15);
			printf("你的金钱不足！");
			Sleep(1000);
		  weapon_buy();
		}
		else
		{
			role1.attack+=5;
			role1.d_weapon="铁胎弓";
			weapon_buy();
		}
	}

	ch=getch();
	}
	if(x==3&&y==7&&ch==13)
		map(gamestart_x,gamestart_y);

}
void med_buy()
{
	void map(int x,int y);
	char ch;
	int x=3,y=4;
	system("cls");
	gotoxy(1,2);
	printf("我这里的药品包治百病，买一两瓶吧！");
	gotoxy(4,4);
	printf("1 魔法药（50）");
	gotoxy(4,5);
	printf("2 金疮药(50)");
	gotoxy(4,6);
	printf("离开");
	gotoxy(20,4);
	printf("武器：%s",role1.d_weapon);
	gotoxy(20,5);
	printf("金钱:%d",role1.money);
	gotoxy(20,6);
	printf("魔法药:%d",role1.m_med);
	gotoxy(20,7);
	printf("金疮药:%d",role1.h_med);
	gotoxy(20,8);
	printf("铠甲：%s",role1.d_cloth);
	gotoxy(x,y);
	printf("%c",16);
	ch=getch();
	while(!(x==3&&y==6&ch==13))
	{
			if(ch==sp1)
	{ 
		gotoxy(x,y);
		printf(" ");
		y=y-1; 
		if(y<4) 
		{
			y=y+1;
		}
		gotoxy(x,y);
		printf("%c",16);
	}
	if(ch==sp2)
	{
		gotoxy(x,y);
			printf(" ");
			y=y+1;
			if(y>6) y=y-1;
			gotoxy(x,y);
			printf("%c",16);
	}
	if(x==3&&y==4&&ch==13)
	{
		role1.money-=50;
		if(role1.money<0)
		{
			role1.money+=50;
			gotoxy(1,15);
			printf("你的金钱不足！");
			Sleep(1000);
			med_buy();
		}
		else
		{
			role1.m_med+=1;
			med_buy();
		}
	}
	if(x==3&&y==5&&ch==13)
	{
		role1.money-=50;
		if(role1.money<0)
		{
			role1.money+=50;
			gotoxy(1,15);
			printf("你的金钱不足！");
			Sleep(1000);
			med_buy();
		}
		else
		{
			role1.h_med+=1;
			med_buy();
		}
	}
	ch=getch();
	}
	if(x==3&&y==6&&ch==13)
		map(gamestart_x,gamestart_y);
}
void cloth_buy()
{
	void map(int x,int y);
	char ch;
	int x=3,y=4;
	system("cls");
	gotoxy(1,2);
	printf("我这里的东西物美价廉，买一两件吧！");
	gotoxy(4,4);
	printf("1 日炎斗篷(2000)");
	gotoxy(4,5);
	printf("2 振奋铠甲(200)");
	gotoxy(4,6);
	printf("3 兰顿铠甲(100)");
	gotoxy(4,7);
	printf("离开");
	gotoxy(20,4);
	printf("武器：%s",role1.d_weapon);
	gotoxy(20,5);
	printf("金钱:%d",role1.money);
	gotoxy(20,6);
	printf("魔法药:%d",role1.m_med);
	gotoxy(20,7);
	printf("金疮药:%d",role1.h_med);
	gotoxy(20,8);
	printf("铠甲：%s",role1.d_cloth);
	gotoxy(x,y);
	printf("%c",16);
	ch=getch();
	while(!(x==3&&y==7&ch==13))
	{
			if(ch==sp1)
	{ 
		gotoxy(x,y);
		printf(" ");
		y=y-1; 
		if(y<4) 
		{
			y=y+1;
		}
		gotoxy(x,y);
		printf("%c",16);
	}
	if(ch==sp2)
	{
		gotoxy(x,y);
			printf(" ");
			y=y+1;
			if(y>7) y=y-1;
			gotoxy(x,y);
			printf("%c",16);
	}
	if(x==3&&y==4&&ch==13)
	{
		role1.money-=2000;
		if(role1.money<0)
		{
			role1.money+=2000;
			gotoxy(1,15);
			printf("你的金钱不足！");
			Sleep(1000);
			cloth_buy();
		}
		else
		{
			role1.defense+=20;
			role1.d_cloth="日炎斗篷";
			cloth_buy();
		}
	}
	if(x==3&&y==5&&ch==13)
	{
		role1.money-=200;
		if(role1.money<0)
		{
			role1.money+=200;
			gotoxy(1,15);
			printf("你的金钱不足！");
			Sleep(1000);
			weapon_buy();
		}
		else
		{
			role1.defense+=10;
			role1.d_cloth="振奋铠甲";
			cloth_buy();
		}
	}
	if(x==3&&y==6&&ch==13)
	{
		role1.money-=100;
		if(role1.money<0)
		{
			role1.money+=100;
			gotoxy(1,15);
			printf("你的金钱不足！");
			Sleep(1000);
			cloth_buy();
		}
		else
		{
			role1.defense+=5;
			role1.d_cloth="兰顿铠甲";
			cloth_buy();
		}
	}

	ch=getch();
	}
	if(x==3&&y==7&&ch==13)
		map(gamestart_x,gamestart_y);

}
void _weapon()
{
	void map(int x,int y);
	char ch;
	int x=2,y=23;
	gotoxy(2,22);
    printf("我这里有上好的武器供你选择，少年，来和我做交易吧！");
	gotoxy(3,23);
	printf("买卖");
	gotoxy(3,24);
	printf("离开");
	gotoxy(2,23);
	printf("%c",16);
	ch=getch();
	while(!(x==2&&y==24&&ch==13))
	{
	
	if(ch==sp1)
	{ 
		gotoxy(x,y);
		printf(" ");
		y=y-1; 
		if(y<23) 
		{
			y=y+1;
		}
		gotoxy(x,y);
		printf("%c",16);
	}
	if(ch==sp2)
	{
		gotoxy(x,y);
			printf(" ");
			y=y+1;
			if(y>24) y=y-1;
			gotoxy(x,y);
			printf("%c",16);
	}
	ch=getch();
	if(x==2&&y==23&&ch==13)
		weapon_buy();
	}
    map(gamestart_x,gamestart_y);
}
void _med()
{
	void map(int x,int y);
	char ch;
	int x=2,y=23;
	gotoxy(2,22);
    printf("我这里有上好的药品供你选择，少年，来和我做交易吧！");
	gotoxy(3,23);
	printf("买卖");
	gotoxy(3,24);
	printf("离开");
	gotoxy(2,23);
	printf("%c",16);
	ch=getch();
	while(!(x==2&&y==24&&ch==13))
	{
	
	if(ch==sp1)
	{ 
		gotoxy(x,y);
		printf(" ");
		y=y-1; 
		if(y<23) 
		{
			y=y+1;
		}
		gotoxy(x,y);
		printf("%c",16);
	}
	if(ch==sp2)
	{
		gotoxy(x,y);
			printf(" ");
			y=y+1;
			if(y>24) y=y-1;
			gotoxy(x,y);
			printf("%c",16);
	}
	ch=getch();
	if(x==2&&y==23&&ch==13)
		med_buy();
	}
	map(gamestart_x,gamestart_y);
}
void _cloth()
{
	 void map(int x,int y);
	char ch;
	int x=2,y=23;
	gotoxy(2,22);
    printf("我这里有上好的铠甲供你选择，少年，来和我做交易吧！");
	gotoxy(3,23);
	printf("买卖");
	gotoxy(3,24);
	printf("离开");
	gotoxy(2,23);
	printf("%c",16);
	ch=getch();
	while(!(x==2&&y==24&&ch==13))
	{
	
	if(ch==sp1)
	{ 
		gotoxy(x,y);
		printf(" ");
		y=y-1; 
		if(y<23) 
		{
			y=y+1;
		}
		gotoxy(x,y);
		printf("%c",16);
	}
	if(ch==sp2)
	{
		gotoxy(x,y);
			printf(" ");
			y=y+1;
			if(y>24) y=y-1;
			gotoxy(x,y);
			printf("%c",16);
	}
	ch=getch();
	if(x==2&&y==23&&ch==13)
		cloth_buy();
	}
    map(gamestart_x,gamestart_y);
} 
void _mission()
{
	 void map(int x,int y);
	 char *e,*f,*g,*h;
	 e="传闻南疆的万里大山中隐藏着一个巨大的宝物，少年可有兴趣？";
	 f="男儿志在四方，我必要取得那宝物！";
	 g="往西南方向直走就可以了，少年！祝你好运！";
	 h="后会有期！";
	 gotoxy(1,23);
	 printf("隐者：%s",e);
	 Sleep(1000);
	 gotoxy(1,24);
	 printf("尧增：%s",f);
	 Sleep(1000);
	 gotoxy(1,23);
	 printf("                                                                    ");
	 gotoxy(1,23);
	 printf("隐者：%s",g);
	 Sleep(1000);
	 gotoxy(1,24);
	 printf("                                                                    ");
	 gotoxy(1,24);
	 printf("尧增：%s",h);
	 Sleep(1000);
	  map(gamestart_x,gamestart_y);
}
void enter() //开始进入攻击怪物i
{
	int j;
	system("cls");
	system("color f4");
	gotoxy(29,13);
	printf("进入战斗，请等待...");
	gotoxy(25,16);
	printf("______________________________");
	gotoxy(25,18);
	printf("———————————————");
	for(j=0;j<30;j++)
	{
		Sleep(50);
		gotoxy(25+j,17);
		printf(">");
	}
}
void image() //定义刷屏，更新人物和怪物的血值、魔法值等
{
	system("cls");
	gotoxy(12,2);
	printf("%s",role1.name);
	gotoxy(56,2);
	printf("%s",M1.name);
	gotoxy(11,4);
	printf("HP: %d / %d  ",role1.d_blood,role1.z_blood);
	gotoxy(11,6);
	printf("MP: %d / %d  ",role1.d_magic,role1.z_magic);
	gotoxy(55,5);
	printf("HP: %d  ",M1.blood);
	gotoxy(13,8);printf("%c",1);
	gotoxy(12,9);printf("|||%c",26);
	gotoxy(12,10);printf("%c %c",25,25);
	gotoxy(56,8);printf("%c",2);
	gotoxy(54,9);printf("%c|||",15);
	gotoxy(55,10);printf("%c %c",25,25);
}
void monsterattack()  //怪物攻击我，n为怪物的攻击能力
{
	void attack();
	int j;
   if(M1.blood<100&&1==rand()%2)//根据血值、随机决定人物血值的减少，而怪物的血值不变
	{
		for(j=36;j>-4;j--)
		{
			gotoxy(17+j,10);printf("%c",15);
			Sleep(50);
			gotoxy(17+j,10);printf(" ");
		}
		role1.d_blood-=4;
		image();
		gotoxy(5,9);printf("- 4");
	}
	else
	{
		for(j=36;j>-4;j--)
		{
			gotoxy(17+j,9);printf("%c",15);
			gotoxy(17+j,9);printf("%c",15);
			gotoxy(17+j,9);printf("%c",15);
			Sleep(50);
			gotoxy(17+j,9);printf(" ");
			gotoxy(17+j,9);printf(" ");
			gotoxy(17+j,9);printf(" ");
		}
		role1.d_blood-=4;
		image();
		gotoxy(5,9);printf("- 8");
	}
	Sleep(1000);	
	gotoxy(5,9);printf("    ");
	attack();
}
void skill_useattack()
{
	void monsterattack();
	char ch1;
	int n1=0,j,k1,k2;
	k1=role1.attack-M1.defense;//人物的攻击与怪物的防御差值，决定人物的攻击能力；
	if(k1<0)k1=0;
	k2=M1.attack-role1.defense;//怪物的攻击与人物的防御差值，决定怪物的攻击能力
	if(k2<0)k2=0;
	gotoxy(10,15);printf(" ");
	gotoxy(36,13);printf("%c",16);
	gotoxy(38,13);printf("1.连环双击(消耗魔法值20点)");
	gotoxy(38,15);printf("2.破空一击(消耗魔法值40点)");
	gotoxy(38,17);printf("3.万箭之矢(消耗魔法值80点)");
	ch1=getch();
	while(ch1!=13)
	{
		if(ch1==sp2)
		{
			n1=n1+2;
			if(n1>4)n1=n1-2;
			gotoxy(36,n1+11);printf(" ");
			gotoxy(36,13+n1);printf("%c",16); 
		}
		if(ch1==sp1)
		{
			n1=n1-2;
			if(n1<0)n1=n1+2;
			gotoxy(36,15+n1);printf(" ");
			gotoxy(36,13+n1);printf("%c",16);
		}
		ch1=getch();
	}
	if(n1==0)//连环双击                            //用第一个技能
	{
		if(role1.d_magic<20)//魔法值不足,不能使用该种方式攻击
		{
			gotoxy(35,23);printf("魔法值不足！");
			Sleep(1000);
			gotoxy(35,23);printf("              ");
			gotoxy(36,13);printf("                                  ");
			gotoxy(38,15);printf("                                   ");
			gotoxy(38,17);printf("                                   ");
		}
		else//和攻击类似
		{
			gotoxy(36,13);printf("                                  ");
			gotoxy(38,15);printf("                                   ");
			gotoxy(38,17);printf("                                   ");
			gotoxy(17,9);
			printf("%c",26);
			Sleep(50);
			for(j=0;j<37;j++)
			{
				gotoxy(17+j,9);printf("-->-->");
				Sleep(50);
				gotoxy(17+j,9);printf("      ");
			}
			role1.d_magic-=20;
			M1.blood-=k1+10;
			image();
			gotoxy(65,9);printf("- %d",k1+10);
			Sleep(1000);	

			gotoxy(65,9);printf("    ");
			monsterattack(); 
		}

	}
	if(n1==2)//                            
	{
		if(role1.d_magic<40)//魔法值不足,不能使用该种方式攻击
		{
			gotoxy(35,23);printf("魔法值不足！");
			Sleep(1000);
			gotoxy(35,23);printf("              ");
			gotoxy(36,13);printf("                                  ");
			gotoxy(38,15);printf("                                   ");
			gotoxy(38,17);printf("                                   ");
		}
		else//和攻击类似
		{
			gotoxy(36,13);printf("                                  ");
			gotoxy(38,15);printf("                                   ");
			gotoxy(38,17);printf("                                   ");
			gotoxy(17,9);
			printf("%c",26);
			Sleep(50);
			for(j=0;j<37;j++)
			{
				gotoxy(17+j,9);printf("-->-->");
				Sleep(50);
				gotoxy(17+j,9);printf("      ");
			}
			role1.d_magic-=40;
			M1.blood-=k1+20;
			image();
			gotoxy(65,9);printf("- %d",k1+20);
			Sleep(1000);	

			gotoxy(65,9);printf("    ");
			monsterattack(); 
		}

	}
	if(n1==4)
	{
		if(role1.d_magic<80)//魔法值不足,不能使用该种方式攻击
		{
			gotoxy(35,23);printf("魔法值不足！");
			Sleep(1000);
			gotoxy(35,23);printf("              ");
			gotoxy(36,13);printf("                                  ");
			gotoxy(38,15);printf("                                   ");
			gotoxy(38,17);printf("                                   ");
		}
		else//和攻击类似
		{
			gotoxy(36,13);printf("                                  ");
			gotoxy(38,15);printf("                                   ");
			gotoxy(38,17);printf("                                   ");
			gotoxy(17,9);
			printf("%c",26);
			Sleep(50);
			for(j=0;j<37;j++)
			{
				gotoxy(17+j,9);printf("-->-->");
				Sleep(50);
				gotoxy(17+j,9);printf("      ");
			}
			role1.d_magic-=80;
			M1.blood-=k1+30;
			image();
			gotoxy(65,9);printf("- %d",k1+30);
			Sleep(1000);	

			gotoxy(65,9);printf("    ");
			monsterattack(); 
		}

	}
}
void directattack()
{
	int j=0,k1,k2;
	k1=role1.attack-M1.defense;//人物的攻击与怪物的防御差值，决定人物的攻击能力；
	if(k1<0)k1=0;
	k2=M1.attack-role1.defense;//怪物的攻击与人物的防御差值，决定怪物的攻击能力
	if(k2<0)k2=0;
	image();
	gotoxy(10,13);printf(" ");
	gotoxy(17,9);
	printf("%c",26);
	Sleep(50);
	for(j=0;j<37;j++)
	{
		gotoxy(17+j,9);printf("-->");
		Sleep(50);
		gotoxy(17+j,9);printf("   ");
	}
	M1.blood-=k1;//怪物的血值减少
	
	gotoxy(65,9);printf("- %d",k1);
     Sleep(1000);	
	gotoxy(65,9);printf("    ");
	monsterattack(); //怪物攻击人物 
}
void usemed()
{
	void monsterattack();
	char ch1;
	int n1=0;
	gotoxy(10,17); 
	printf(" ");
	gotoxy(36,13);
	printf("%c",16);
	gotoxy(38,13);
	printf("1 魔法药");
	gotoxy(38,15);
	printf("2 金疮药");
	ch1=getch();
	while(ch1!=13)
	{
		if(ch1==sp2)
		{
			n1=n1+2;
			if(n1>2)n1=n1-2;
			gotoxy(36,n1+11);printf(" ");
			gotoxy(36,13+n1);printf("%c",16); 
		}
		if(ch1==sp1)
		{
			n1=n1-2;
			if(n1<0)n1=n1+2;
			gotoxy(36,15+n1);printf(" ");
			gotoxy(36,13+n1);printf("%c",16);
		}
		ch1=getch();
	}
	if(n1==0)
	{
		role1.d_magic+=20;
		if(role1.d_magic>role1.z_magic) role1.d_magic=role1.z_magic;
		monsterattack();
	}
	if(n1==2)
	{
		role1.d_blood+=20;
		if(role1.d_blood>role1.z_blood) role1.d_blood=role1.z_blood;
		monsterattack();
	}
}
int _level(int exp)
{
	int i;
	i=exp/5;
	switch(i)
	{
	case 0:return 1;
	case 1:return 2;
	case 2:return 3;
	case 3:return 4;
	case 4:return 5;
	case 5:return 6;
	case 6:return 7;
	case 7:return 8;
	case 8:return 9;
	case 9:return 10;
    default:return 10;
	}
}
void attack()
{
	char ch;
	int j,k1,k2,n=0,m;
	system("cls");
	//enter();
	//image();
	k1=role1.attack-M1.defense;//人物的攻击与怪物的防御差值，决定人物的攻击能力；
	if(k1<0)k1=0;
	k2=M1.attack-role1.defense;//怪物的攻击与人物的防御差值，决定怪物的攻击能力
	if(k2<0)k2=0;
	//system("cls");
	system("color fc");
	while(role1.d_blood>0&&M1.blood>0)//直到人物或者怪物的血值<=0
	{
		image();
		gotoxy(10,13);printf("%c",16);
		gotoxy(12,13);printf("1.攻击");
		gotoxy(12,15);printf("2.技能");
		gotoxy(12,17);printf("3.道具");
		ch=getch();
		while(ch!=13)
		{
			if(ch==sp2)
			{
				n=n+2;
				if(n>4)n=n-2;
				gotoxy(10,11+n);printf(" ");
				gotoxy(10,13+n);printf("%c",16);
			}
			if(ch==sp1)
			{
				n=n-2;
				if(n<0)n=n+2;
				gotoxy(10,15+n);printf(" ");
				gotoxy(10,13+n);printf("%c",16);
			}
			ch=getch();
		}
		if(n==0)                                      //选择直接攻击
		{
			directattack();
		}
		if(n==2)                                              //用技能攻击
		{
			skill_useattack();
		}
		if(n=4)
		{
			usemed();
		}
		n=0;
	}
	if(role1.d_blood<=0)//人物失败、死亡
	{
		system("cls");
		system("color fc");
		gotoxy(25,13);
		printf("出师未捷生先死，长使英雄泪满襟！");
		gotoxy(25,16);
		printf("______________________________");
		gotoxy(25,18);
		printf("———————————————");
	    for(j=0;j<30;j++)
		{
	    	Sleep(50);
			gotoxy(25+j,17);
			printf(">");
		}
		role1.d_blood=20;
		M1.blood=20;//当前血值变为20,下一次还可以战斗
		map(35,15); 
	}
	if(M1.blood<=0)//怪物死亡
	{
	    gotoxy(35,18);
		printf("你杀死了%s！",M1.name);
		Sleep(1000);
		gotoxy(35,18);
		printf("你得到了%d经验值！  ",M1.exp);
		role1.exp=role1.exp+M1.exp;//经验值增加
		Sleep(1000);
		gotoxy(35,18);
		printf("你得到了%d金钱！  ",M1.money);
		role1.money=role1.money+M1.money;//人物金钱增加
		m=_level(role1.exp);
		if(m>role1.level)
		{
			gotoxy(35,18);
			printf("恭喜你升级了!");
			role1.level=m;
			role1.attack+=1;
			role1.defense+=1;
			role1.z_blood+=1;
			role1.z_magic+=1;
		}
		M1.blood=20;

	}
	Sleep(1000);
	map(gamestart_x,gamestart_y);
}
void map(int x,int y)
{
    char a[20][70],forbid[20][70],ch;
	int i,j;
	char key_up=sp1,key_down=sp2,key_left=sp3,key_right=sp4;
	system("cls");
	system("color f3");
	srand(time(0));
	for(i=0;i<20;i++)
	{
		for(j=0;j<70;j++)
		{
			a[i][j]=' ';
			forbid[i][j]=' ';
		}
	}
	for(j=0;j<70;j++)
	{
		a[0][j]='#';
		a[19][j]='#';
	}
	for(i=0;i<20;i++)
	{
		a[i][0]='#';
		a[i][69]='#';
	}
	a[10][69]=' ';
	//buliding
	for(j=8;j<16;j++)
	{
		a[3][j]='#';
		a[4][j]='#';
		a[13][j]='#';
		a[14][j]='#';
	}
	for(j=54;j<62;j++)
	{
		a[3][j]='#';
		a[4][j]='#';
		a[13][j]='#';
		a[14][j]='#';
	}
	a[5][12]='@';
    a[5][58]='!';
	a[15][12]='$';
	a[15][58]='&';

	for(j=32;j<36;j++)
	{
		a[7][j]='*';
		a[9][j]='*';
	}
	a[8][32]=a[8][35]='*';
	for(i=6;i<11;i++)
	{
		for(j=31;j<37;j++)
		{
			forbid[i][j]='^';
		}
	}
	
	printf("%s          桃源村\n",mode);
	for(i=0;i<20;i++)
	{
		for(j=0;j<70;j++)
		{
			printf("%c",a[i][j]);
		}
	
	printf("\n");
	}
	i=y-2;
	j=x-1;
	gotoxy(x,y);
	printf("%c",1);
while(x<70)
{
	ch=getch();
	if(ch==key_up&&a[i-1][j]==' '&&forbid[i-1][j]==' ')
		{
			gotoxy(x,y);
			printf(" ");
			y=y-1;
			i=y-2;
			gotoxy(x,y);
			printf("%c",1);
			gamestart_x=x;
			gamestart_y=y;
	}
	if(ch==key_down&&a[i+1][j]==' '&&forbid[i+1][j]==' ')
		{
			gotoxy(x,y);
			printf(" ");
			y=y+1;
			i=y-2;
			gotoxy(x,y);
			printf("%c",1);
			gamestart_x=x;
			gamestart_y=y;
	}
	if(ch==key_left&&a[i][j-1]==' '&&forbid[i][j-1]==' ')
		{
			gotoxy(x,y);
			printf(" ");
			x=x-1;
			j=x-1;
			gotoxy(x,y);
			printf("%c",1);
			gamestart_x=x;
			gamestart_y=y;
	}
if(ch==key_right&&a[i][j+1]==' '&&forbid[i][j+1]==' ')
		{
			gotoxy(x,y);
			printf(" ");
			x=x+1;
			j=x-1;
			gotoxy(x,y);
			printf("%c",1);
			gamestart_x=x;
			gamestart_y=y;
	}
if(ch==32)
	hp();
if(x==12&&y==7&&ch==13||x==14&&y==7&&ch==13||x==13&&y==8&&ch==13)
	_weapon();
if(x==58&&y==7&&ch==13||x==60&&y==7&&ch==13||x==59&&y==8&&ch==13)
	_med();
if(x==12&&y==17&&ch==13||x==14&&y==17&&ch==13||x==13&&y==18&&ch==13)
	_cloth();
if(x==58&&y==17&&ch==13||x==60&&y==17&&ch==13||x==59&&y==18&&ch==13)
	_mission();
if(3==rand()%7)
	enter();
	attack();
}

//system("pause");
}
void keyset()
{
	char sp;
	system("cls");
	gotoxy(2,4);
	printf("上：");
	gotoxy(2,6);
	printf("下：");
	gotoxy(2,8);
	printf("左：");
	gotoxy(2,10);
	printf("右：");
	gotoxy(6,4);
	sp1=getch();
	printf("%c",sp1);
	
	gotoxy(6,6);
	sp2=getch();
	printf("%c",sp2);
   
	gotoxy(6,8);
	 sp3=getch();
    printf("%c",sp3);
	
	gotoxy(6,10);
	 sp4=getch();
	printf("%c",sp4);
	gotoxy(2,14);
	printf("你选择的按键是：上：%c 下：%c 左： %c 右： %c",sp1,sp2,sp3,sp4);
	sp=getch();
}
void main()//游戏主界面
{
	char ch=1;
	int hang=0;
	//system("title封魔录");
	system("color f1");
	while(!(hang==8&&ch==13))
	{
		system("cls");
		gotoxy(20,hang+8);//箭头
		printf("%c%c",16,16);
		gotoxy(22,8);
		printf("开始游戏");
		gotoxy(22,10);
		printf("按键设置");
		gotoxy(22,12);
		printf("难度设置");
		gotoxy(22,14);
		printf("游戏制作");
		gotoxy(22,16);
		printf("退出");
		
		
	ch=getch();
	if(ch=='s')
	{
		hang=hang+2;
		if(hang>8)hang=hang-2;
		gotoxy(20,hang+6);
		printf("  ");
		gotoxy(20,hang+8);
		printf("%c%c",16,16);
	}
	else if(ch=='w')
	{
		hang=hang-2;
		if(hang<0)hang=hang+2;
		gotoxy(20,10+hang);
		printf("  ");
		gotoxy(20,8+hang);
		printf("%c%c",16,16);
	}
	if(hang==4&&ch==13) gamedifficult_show();
	if(hang==0&&ch==13) conversation();
	if(hang==6&&ch==13) press();
	if(hang==2&&ch==13) keyset();
	}
}