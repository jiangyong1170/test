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
typedef struct song_info//������Ϣ�ṹ�� 
{
	int   songnum;//������Ϣ 
	char  songname[15];//�������� 
	char  songername[15];//�������� 
	char  ablumname[15];//ר������ 
	char   type[10];//�������� 
}SINFO;
struct users use[U];//�ṹ��
SINFO *pso;	//�������ȫ�ֱ��� 
void registerUser();//ע�ắ��
void login();//��¼����
void quitSystem();//�˳�������
void userview();
void querymusic();
void loginactionmenu();//��¼�ɹ�չʾ�˵�
int userroleauth();//�û���ɫȨ��У��
void inputPassword(char d[], int length);//�������뺯��
void choice(SINFO *pso);//ѡ�躯��
void add(SINFO *pso);//���Ӹ������� 
void show(SINFO *pso);//չʾ������Ϣ���� 
void dele(SINFO *pso);//ɾ������ 
void out();	//�˳����� 
void menuone();
void menutwo();
void menuthree();
void main()
{
	//********************��ӭ����********************//
	//С�������//
	int t = 1;
	for (int i = 1; i <= 100; i++)
	{
		//�����ʾ��Ϣ
		printf("\n\n\n\n\t\t\t��ӭʹ������KTV���ϵͳ\n\n");
		printf("\t\t\t���ڽ���ҳ�棬���Ե�");
		for (int j = 1; j <= t; j++)
		{
			printf(".");
		}
		//�����ʾ10����������������
		if (t == 10)
		{
			t = 1;
		}
		t++;
		//������
		printf("\n%d%%", i);
		//��������
		system("cls");
		//�Ⱥ�
		for (int m = 0; m <= 50000; m++)
		{

		}
	}
	/*****************��ӭ����********************/
	/******************������********************/
	//�����û���Ϣ
	char a;
	while (1)
	{
		printf("\n\n\n\n\t\t\t����KTV���ϵͳΪ������\n\n");
		printf("\n\n\t\t\t����A��:���û�ע��\n");
		printf("\n\n\t\t\t����B�����û���¼\n");
		printf("\n\n\t\t\t����C�����˳�ϵͳ\n");
		printf("\n\n\t\t\t��ѡ���������ࣺ\n");
		break;
	}
	scanf("%c", &a);
	//��ȡ���̻������Ļس���  //��ȻҪ������Ա����ͨ�û�Ȩ��У�飬��¼����Ҫ���������������Ҫ���û���ɫ�ж�
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
		printf("\n\t\t\t���������������������룡");
		break;
	}
	printf("�����������");
	//���������̻��������ַ����뺯����������
	getchar();
	system("cls");
}
//ע�ắ��
void registerUser()
{
	char a[30];
	char b[30];
	char c[30];
	char d[30];
	char auth[30];
	int t = 0;
	printf("\n\t\t\t������ִ�е���ע���˺�\r\n");
	FILE *fp = fopen("E:\\user.txt", "a");
	if (fp == NULL)
	{
		//printf("û���˺���Ϣ....");
		//printf("\n");
		//return; 
	}
	printf("\n\n\n\t\t\t�������û���\n");
	scanf("%s", &a);
	printf("\n\n\n\t\t\t�������û���ɫ\n 0:����Ա 1:��ͨ�û�\n");
	scanf("%s", &d);
	if (atoi(d) == 0) {
		strcpy(use[t].auth, "admin");
	}
	else if (atoi(d) == 1) {
		strcpy(use[t].auth, "user");
	}
	else {
		printf("\n\t\t\t���������������������룡");
	}
	printf("\n\n\n\t\t\t����������\n");
	scanf("%s", &b);
	printf("\n\n\n\t\t\t���ٴ���������\n");
	scanf("%s", &c);
	strcpy(use[t].a, a);
	strcpy(use[t].b, b);
	strcpy(use[t].c, c);
	fprintf(fp, "%s%s%s\n", use[t].a, use[t].b, use[t].auth);
	fclose(fp);
	printf("\n\n\n\t\t\tע��ɹ�");
	printf("\n");
	system("cls");
	main();
}
//�˳�����
void quitSystem()
{
	int p = 1;
	for (int i = 1; i <= 100; i++)
	{
		//�����ʾ��Ϣ
		printf("\n\n\n\n\t\t\t����KTV���ϵͳ����Ϊ������\n\n");
		printf("\t\t\t�����˳�ϵͳ�����Ժ�");
		for (int j = 1; j <= p; j++)
		{
			printf(".");
		}
		//�����ʾ10����������������
		if (p == 10)
		{
			p = 1;
		}
		p++;
		//������
		printf("\n%d%%", i);
		//��������
		system("cls");
		//�Ⱥ�
		for (int m = 0; m <= 50000; m++)
		{

		}
		//�����˳�ϵͳ������0��ʾ�����˳���1��ʾ�쳣�˳�
		exit(0);
	}
}
//�û���ɫȨ��У��
int userroleauth(char*username) {
	char a[30];
	char b[30];
	char d[30];
	int q = 0;
	int flag = 0;
	FILE *fp= fopen("E:\\user.txt", "r");//��ȡ�ļ�����
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
//��¼�˺�
void login()
{
	char a[30];
	char b[30];
	char c[30];
	int q = 0;
	int flag = 0;
	printf("\t����Ϊ��½�˺�\n");
	printf("�������˺ţ�");
	scanf("%s", &a);
	printf("���������룺");
	scanf("%s", &b);
	FILE *fp;
	fp = fopen("E:\\user.txt", "r");//��ȡ�ļ�����
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
		printf("�˺Ż��������\n");
	}
}
//void userview()
//{
//	int q = 0;
//	printf("��¼�ɹ���");
//	system("pause");
//	FILE *fp;
//	fp = fopen("F:\\user", "r");//��ȡ�ļ�����
//	while(fscanf(fp,"%s %sn",&use[q].a, &use[q].b)!=EOF)
//	{
//		printf("\t�˺�:%s���룺%s\n", use[q].a, use[q].b);
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
		printf("\n\n\n\n\t\t\t����KTV���ϵͳΪ������\n\n");
		printf("\n\n\t\t\t����A��:����1\n");
		printf("\n\n\t\t\t����B��������2\n");
		printf("\n\n\t\t\t����C�����޸�����\n");
		printf("\n\n\t\t\t��ѡ���������ࣺ\n");
		break;
	}
	scanf("%c", &a);
	//��ȡ���̻������Ļس���  //��ȻҪ������Ա����ͨ�û�Ȩ��У�飬��¼����Ҫ���������������Ҫ���û���ɫ�ж�
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
			printf("\n\n\t\t\t��û�й���3Ȩ��\n");
			break;
		}
	default:
		printf("\n\t\t\t���������������������룡");
		break;
	}
	printf("�����������");
	//���������̻��������ַ����뺯����������
	getchar();
	system("cls");
}

void menuone() {
	printf("\n\n\t\t\t��ӭʹ�ã�����1\n");
}
void menutwo() {
	printf("\n\n\t\t\t��ӭʹ�ã�����1\n");
}
void menuthree() {
	printf("\n\n\t\t\t��ӭʹ�ã��޸�����\n");
}

void querymusic()
{
	printf("\n\n\n\t\t\t���ڵ�¼�����˺ţ����Ժ�");
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
	void choice(SINFO *pso);//���Ҹ���
	{
		char a[15];
		int q, t;
		FILE *fp;
		printf("������Ҫ�鿴���ֵ����֣�");
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
					printf("�ø��������¸�����\n");
				t++;
				printf("%s\n", pso[q].songname);
			}
		}
		if (t == 0)
		{
			printf("��ϵͳ���޸ø��ָ�����������\n");
		}
		fclose(fp);
	}
	void add(SINFO *pso)//���Ӹ���
		; {
		FILE *fp;
		fp = fopen("F:\\song.txt", "a+");
		printf("��������Ҫ���������������");
		scanf("%d", &j);
		fflush(stdin);
		for (i = 0; i<j; i++) {
			printf("����Ҫ����ĵ�%d�׸����Ϣ:\n", i + 1);
			printf("��������ǣ�");
			scanf("%d", &pso[i].songnum);
			fflush(stdin);
			printf("���������ǣ�");
			gets(pso[i].songname);
			fflush(stdin);
			printf("���������ǣ�");
			gets(pso[i].songername);
			fflush(stdin);
			printf("ר���������ǣ�");
			gets(pso[i].ablumname);
			fflush(stdin);
			printf("���������ǣ�");
			gets(pso[i].type);
			fflush(stdin);
			system("cls");
			fwrite(&pso[i], sizeof(SINFO), 1, fp);
		}
		fclose(fp);
		printf("��������ɹ���\n");
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
		printf("���и�����Ϣ���£�\n");
		for (k = 0; !feof(fp); k++)//�Ƿ�����ļ�β
		{
			fread(&pso[k], sizeof(SINFO), 1, fp);
		}
		fclose(fp);
		printf("%s%15s%20s%15s%15s", "�������", "����", "����", "ר��", "��������");
		printf("\n");
		for (i = 0; i<k - 1; i++)
		{
			printf("%03d%20s%20s%15s%15s", pso[i].songnum, pso[i].songname, pso[i].songername, pso[i].ablumname, pso[i].type);
			printf("\n");
		}

	}
	void dele(SINFO *pso);//ɾ������
	{
		char a[15];
		int q;
		FILE *fp;
		printf("������Ҫɾ�����������֣�");
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
		printf("ɾ����Ϣ�ɹ���\n");
	}
	void out();//�˳�ϵͳ
	{
		char a;
		printf("ȷ���˳�ϵͳ��(y/n)");
		scanf("%c", &a);
		if ('y' == a)
			exit(0);
	}

	main();//����������
	{
		SINFO *pso;

		char a;
	loop:
		printf("\n\n\n\n\t\t\t����KTV���ϵͳΪ������\n\n");
		printf("\n\n\t\t\t����A��:���û�ע��\n");
		printf("\n\n\t\t\t����B�����û���¼\n");
		printf("\n\n\t\t\t����C�����˳�ϵͳ\n");
		printf("\n\n\t\t\t��ѡ���������ࣺ\n");
		return;
		scanf("%c", &a);
		//��ȡ���̻������Ļس���
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
			printf("\n\t\t\t���������������������룡");
			break;
		}
	}
}
