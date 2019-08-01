#include<stdio.h>
void main()
{
	//1:打开
	FILE* fp=fopen("./a.data","rb");
	if(NULL==fp)
	{
		perror("open fail\n");
		return;
	}
	//2:操作
/*	char name[10]="yq";
	char sex='m';
	int id=2019001;
	float score=99.8;
	fprintf(fp,"%s %c %d %f\n",name,sex,id,score);
*/
//	int a=97;
//	int buf[]={97,98,99,100,101,102,103};
//	printf("%ld\n",fwrite(buf,sizeof(int),7,fp));
	int a;
	while(fread(&a,1,sizeof(int),fp)>0)
	{
		printf("当前位置:%ld\n",ftell(fp));
//		printf("读取的长度:%ld\n",fread(&a,1,sizeof(int),fp));
		printf("%d\n",a);
	}
	//3:关闭
	fclose(fp);
}
