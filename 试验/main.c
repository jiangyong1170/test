#include <stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define U 30
struct users
{
	char a[30];
	char b[30];
	char c[30];
	char d[30];
	char auth[30];
};
typedef struct song_info//歌曲信息结构体 
{
	int   songnum;//歌曲信息 
	char  songname[15];//歌曲名称 
	char  songername[15];//歌手名称 
	char  ablumname[15];//专辑名称 
	char   type[10];//歌曲流派 
}SINFO;
struct users use[U];//结构体
SINFO *pso;	//定义歌曲全局变量 
void registerUser();//注册函数
void login();//登录函数
void quitSystem();//退出程序函数
void userview();
void querymusic();
void loginactionmenu();//登录成功展示菜单
int userroleauth();//用户角色权限校验
void inputPassword(char d[], int length);//隐藏密码函数
void choice(SINFO *pso);//选歌函数
void add(SINFO *pso);//增加歌曲函数 
void show(SINFO *pso);//展示所有信息函数 
void dele(SINFO *pso);//删除函数 
void out();	//退出函数 
void menuone();
void menutwo();
void menuthree();
void main()
{
	//********************欢迎界面********************//
	//小数点个数//
	int t = 1;
	for (int i = 1; i <= 100; i++)
	{
		//输出提示信息
		printf("\n\n\n\n\t\t\t欢迎使用青软KTV点歌系统\n\n");
		printf("\t\t\t正在进入页面，请稍等");
		for (int j = 1; j <= t; j++)
		{
			printf(".");
		}
		//最多显示10个，或者其他数字
		if (t == 10)
		{
			t = 1;
		}
		t++;
		//进度条
		printf("\n%d%%", i);
		//清屏函数
		system("cls");
		//等候
		for (int m = 0; m <= 50000; m++)
		{

		}
	}
	/*****************欢迎界面********************/
	/******************主界面********************/
	//接收用户信息
	char a;
	while (1)
	{
		printf("\n\n\n\n\t\t\t青软KTV点歌系统为您服务\n\n");
		printf("\n\n\t\t\t服务【A】:新用户注册\n");
		printf("\n\n\t\t\t服务【B】：用户登录\n");
		printf("\n\n\t\t\t服务【C】：退出系统\n");
		printf("\n\n\t\t\t请选择服务的种类：\n");
		break;
	}
	scanf("%c", &a);
	//读取键盘缓冲区的回车符  //尽然要做管理员跟普通用户权限校验，登录不需要，后面点歌的生活需要做用户角色判断
	getchar();
	switch (a)
	{
	case 'A':
	case 'a':
		registerUser();
		break;
	case 'B':
	case 'b':
		login();
		break;
	case 'C':
	case 'c':
		quitSystem();
		break;
	default:
		printf("\n\t\t\t您的输入有误，请重新输入！");
		break;
	}
	printf("按任意键继续");
	//不经过键盘缓冲区的字符输入函数，不回显
	getchar();
	system("cls");
}
//注册函数
void registerUser()
{
	char a[30];
	char b[30];
	char c[30];
	char d[30];
	char auth[30];
	int t = 0;
	printf("\n\t\t\t您正在执行的是注册账号\r\n");
	FILE *fp = fopen("E:\\user.txt", "a");
	if (fp == NULL)
	{
		//printf("没有账号信息....");
		//printf("\n");
		//return; 
	}
	printf("\n\n\n\t\t\t请输入用户名\n");
	scanf("%s", &a);
	printf("\n\n\n\t\t\t请输入用户角色\n 0:管理员 1:普通用户\n");
	scanf("%s", &d);
	if (atoi(d) == 0) {
		strcpy(use[t].auth, "admin");
	}
	else if (atoi(d) == 1) {
		strcpy(use[t].auth, "user");
	}
	else {
		printf("\n\t\t\t您的输入有误，请重新输入！");
	}
	printf("\n\n\n\t\t\t请输入密码\n");
	scanf("%s", &b);
	printf("\n\n\n\t\t\t请再次输入密码\n");
	scanf("%s", &c);
	strcpy(use[t].a, a);
	strcpy(use[t].b, b);
	strcpy(use[t].c, c);
	fprintf(fp, "%s%s%s\n", use[t].a, use[t].b, use[t].auth);
	fclose(fp);
	printf("\n\n\n\t\t\t注册成功");
	printf("\n");
	system("cls");
	main();
}
//退出函数
void quitSystem()
{
	int p = 1;
	for (int i = 1; i <= 100; i++)
	{
		//输出提示信息
		printf("\n\n\n\n\t\t\t青软KTV点歌系统正在为您服务\n\n");
		printf("\t\t\t正在退出系统，请稍后");
		for (int j = 1; j <= p; j++)
		{
			printf(".");
		}
		//最多显示10个，或者其他数字
		if (p == 10)
		{
			p = 1;
		}
		p++;
		//进度条
		printf("\n%d%%", i);
		//清屏函数
		system("cls");
		//等候
		for (int m = 0; m <= 50000; m++)
		{

		}
		//正常退出系统函数，0表示正常退出，1表示异常退出
		exit(0);
	}
}
//用户角色权限校验
int userroleauth(char*username) {
	char a[30];
	char b[30];
	char d[30];
	int q = 0;
	int flag = 0;
	FILE *fp= fopen("E:\\user.txt", "r");//读取文件操作
	while (!feof(fp))
	{
		fscanf(fp, "%s%s%sn", &use[q].a, &use[q].b, &use[q].d);
		if ((strcmp(*username, use[q].a) == 0))
		{
			if ((strcmp("admin", use[q].a) == 0)) {
				flag = 0;
			}
			else {
				flag = 1;
			}
			break;
		}
		q++;
	}
	return flag;

}
//登录账号
void login()
{
	char a[30];
	char b[30];
	char c[30];
	int q = 0;
	int flag = 0;
	printf("\t以下为登陆账号\n");
	printf("请输入账号：");
	scanf("%s", &a);
	printf("请输入密码：");
	scanf("%s", &b);
	FILE *fp;
	fp = fopen("E:\\user.txt", "r");//读取文件操作
	while (!feof(fp))
	{
		fscanf(fp, "%s%sn", &use[q].a, &use[q].b);
		if ((strcmp(a, use[q].a) == 0) && (strcmp(b, use[q].b) == 0))
		{
			flag = 1;
			fclose(fp);
			break;
		}
		q++;
	}
	if (flag == 1)
	{
		loginactionmenu(a);
		return;
	}
	else
	{
		printf("账号或密码错误！\n");
	}
}
//void userview()
//{
//	int q = 0;
//	printf("登录成功！");
//	system("pause");
//	FILE *fp;
//	fp = fopen("F:\\user", "r");//读取文件操作
//	while(fscanf(fp,"%s %sn",&use[q].a, &use[q].b)!=EOF)
//	{
//		printf("\t账号:%s密码：%s\n", use[q].a, use[q].b);
//		q++;
//	}
//	fclose(fp);
//}
void inputPassword(char d[], int length)
{
}
void loginactionmenu(char*username) {
	char a;
	int auth = userroleauth(*username);
	while (1)
	{
		printf("\n\n\n\n\t\t\t青软KTV点歌系统为您服务\n\n");
		printf("\n\n\t\t\t服务【A】:功能1\n");
		printf("\n\n\t\t\t服务【B】：功能2\n");
		printf("\n\n\t\t\t服务【C】：修改密码\n");
		printf("\n\n\t\t\t请选择服务的种类：\n");
		break;
	}
	scanf("%c", &a);
	//读取键盘缓冲区的回车符  //尽然要做管理员跟普通用户权限校验，登录不需要，后面点歌的生活需要做用户角色判断
	getchar();
	switch (a)
	{
	case 'A':
	case 'a':
		menuone();
		break;
	case 'B':
	case 'b':
		menutwo();
		break;
	case 'C':
	case 'c':
		if (auth == 0) {
			menuthree();
			break;
		}
		else
		{
			printf("\n\n\t\t\t您没有功能3权限\n");
			break;
		}
	default:
		printf("\n\t\t\t您的输入有误，请重新输入！");
		break;
	}
	printf("按任意键继续");
	//不经过键盘缓冲区的字符输入函数，不回显
	getchar();
	system("cls");
}

void menuone() {
	printf("\n\n\t\t\t欢迎使用：功能1\n");
}
void menutwo() {
	printf("\n\n\t\t\t欢迎使用：功能1\n");
}
void menuthree() {
	printf("\n\n\t\t\t欢迎使用：修改密码\n");
}

void querymusic()
{
	printf("\n\n\n\t\t\t正在登录您的账号，请稍后！");
	int i, j, k;
	FILE *fp;
	struct song_info
	{
		int   songnum;
		char  songname[15];
		char  songername[15];
		char  ablumname[15];
		char   type[10];
	};
	typedef struct song_info SINFO;
	SINFO *pso;
	void choice(SINFO *pso);//查找歌曲
	{
		char a[15];
		int q, t;
		FILE *fp;
		printf("请输入要查看歌手的名字：");
		scanf("%s", a);
		fp = fopen("F:\\song.txt", "rt");
		if (fp == NULL)
		{
			printf("the file :song.txt not found!");
			exit(-1);
		}
		for (k = 0; (!feof(fp)); k++)
			fread(&pso[k], sizeof(SINFO), 1, fp);
		fclose(fp);
		t = 0;
		for (q = 0; q<k; q++)
		{
			if (!strcmp(a, pso[q].songername))
			{
				if (t == 0)
					printf("该歌手有以下歌曲：\n");
				t++;
				printf("%s\n", pso[q].songname);
			}
		}
		if (t == 0)
		{
			printf("本系统还无该歌手歌曲，请增添！\n");
		}
		fclose(fp);
	}
	void add(SINFO *pso)//增加歌曲
		; {
		FILE *fp;
		fp = fopen("F:\\song.txt", "a+");
		printf("请你输入要增添歌曲的数量：");
		scanf("%d", &j);
		fflush(stdin);
		for (i = 0; i<j; i++) {
			printf("这是要增添的第%d首歌的信息:\n", i + 1);
			printf("歌曲编号是：");
			scanf("%d", &pso[i].songnum);
			fflush(stdin);
			printf("歌曲名字是：");
			gets(pso[i].songname);
			fflush(stdin);
			printf("歌手名字是：");
			gets(pso[i].songername);
			fflush(stdin);
			printf("专辑的名字是：");
			gets(pso[i].ablumname);
			fflush(stdin);
			printf("歌曲流派是：");
			gets(pso[i].type);
			fflush(stdin);
			system("cls");
			fwrite(&pso[i], sizeof(SINFO), 1, fp);
		}
		fclose(fp);
		printf("歌曲增添成功！\n");
	}


	void show(SINFO *pso);
	{
		FILE *fp;
		fp = fopen("F:\\song.txt", "rt");
		if (fp == NULL)
		{
			printf("the file :song.txt not found!");
			exit(-1);
		}
		printf("所有歌曲信息如下：\n");
		for (k = 0; !feof(fp); k++)//是否读到文件尾
		{
			fread(&pso[k], sizeof(SINFO), 1, fp);
		}
		fclose(fp);
		printf("%s%15s%20s%15s%15s", "歌曲编号", "歌名", "歌手", "专辑", "歌曲流派");
		printf("\n");
		for (i = 0; i<k - 1; i++)
		{
			printf("%03d%20s%20s%15s%15s", pso[i].songnum, pso[i].songname, pso[i].songername, pso[i].ablumname, pso[i].type);
			printf("\n");
		}

	}
	void dele(SINFO *pso);//删减歌曲
	{
		char a[15];
		int q;
		FILE *fp;
		printf("请输入要删除歌曲的名字：");
		scanf("%s", a);
		fp = fopen("d:\\song.txt", "rt");
		if (fp == NULL)
		{
			printf("the file :song.txt not found!");
			exit(-1);
		}
		for (k = 0; (!feof(fp)); k++)
			fread(&pso[k], sizeof(SINFO), 1, fp);
		fclose(fp);
		for (q = 0; q<k; q++)
			if (!strcmp(a, pso[q].songname))
				memset(&pso[q], 0, sizeof(SINFO));
		fp = fopen("d:\\song.txt", "w+");
		for (k = 0; k<q; k++)
			fwrite(&pso[k], sizeof(SINFO), 1, fp);
		fclose(fp);
		printf("删除信息成功！\n");
	}
	void out();//退出系统
	{
		char a;
		printf("确认退出系统？(y/n)");
		scanf("%c", &a);
		if ('y' == a)
			exit(0);
	}

	main();//返回主界面
	{
		SINFO *pso;

		char a;
	loop:
		printf("\n\n\n\n\t\t\t青软KTV点歌系统为您服务\n\n");
		printf("\n\n\t\t\t服务【A】:新用户注册\n");
		printf("\n\n\t\t\t服务【B】：用户登录\n");
		printf("\n\n\t\t\t服务【C】：退出系统\n");
		printf("\n\n\t\t\t请选择服务的种类：\n");
		return;
		scanf("%c", &a);
		//读取键盘缓冲区的回车符
		getchar();
		switch (a)
		{
		case 'A':
		case 'a':
			registerUser();
			break;
		case 'B':
		case 'b':
			login();
			break;
		case 'C':
		case 'c':
			quitSystem();
			break;
		default:
			printf("\n\t\t\t您的输入有误，请重新输入！");
			break;
		}
	}
}
