/*
�ǻ����Ʈ�� ���α׷� 
�ۼ���¥ : 2008�� 4�� 26�� �����
������¥ : 2008�� 5�� 22�� �����
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>

//���� �Լ�
int callDataNo(); // �������� ������ �����ϴ� �Լ�
int scoreFunc();  // ������ ���� ��Ʈ���ǿ� �ɼ��� �������ִ� �Լ�
int licenseFunc();  // �ڰ����� ���� ��Ʈ���ǿ� �ɼ��� �������ִ� �Լ�
int toeicFunc();  // ���������� ���� ��Ʈ���ǿ� �ɼ��� �������ִ� �Լ�
int graduateFunc();  // ���������� ���� ��Ʈ���ǿ� �ɼ��� �������ִ� �Լ�
int patriotFunc();  // ���������������� ���� ��Ʈ���ǿ� �ɼ��� �������ִ� �Լ�
int internFunc();  // ���ϰ��迡 ���� ��Ʈ���ǿ� �ɼ��� �������ִ� �Լ�
int armyFunc();  // ���ʿ� ���� ��Ʈ���ǿ� �ɼ��� �������ִ� �Լ�
void maketree();  // Ʈ���� ���鶧 �ʿ��� �ɼǵ��� �ҷ��ͼ� �����ϴ� �Լ�
void userInterface();  // ���� �������̽� �Լ�
int Tree();  // Ʈ���� ����� �Լ�
int Decision_Node();  // �ǻ� ������ ���� �Լ�

//���õ����� ���� �о�� �����͵��� ����Ǵ� ���� ����
typedef struct data1{
	char score[20];
	char license[20];
	char toeic[20];
	char graduate[20];
	char patriot[20];
	char intern[20];
	char army[20];
	char result[20];
	struct data1 *next;
}STUDENT;

//�ǻ����Ʈ���� ���� ����ü
typedef struct tree1{
	char title[20];
	int number;
	struct tree1 *nextlevel_1;
	struct tree1 *nextlevel_2;
	struct tree1 *nextlevel_3;
	struct tree1 *nextlevel_4;
	struct tree1 *nextlevel_5;
}TREEST;

//�� �����Ϳ� ���� ����ü
typedef struct tempexp{
	char scoreA[3];
	char scoreB[5];
	char scoreC[3];
	char scoreD[5];
	char scoreE[3];
	char scoreY1[2];
	char scoreY2[2];
	char scoreN1[2];
	char scoreN2[2];
}TEMP;

typedef STUDENT *LINK;
typedef TREEST *TLINK;

void main(){
	//���� ����
	int tree[7]={0}; 
	int tree_2[7]={0};
	int noUse[7]={0}; // ���� ������ �о���� ������ �����ϴ� ����
	int decision[5]={0}; //�ǻ縦 �����ϴ� ����
	int level_1=0;
	int level_2=0;
	TEMP temp;
	TLINK root=NULL;
	
	//�� ������ ����
	strcpy(temp.scoreA,"��");
	strcpy(temp.scoreB,"�߻�");
	strcpy(temp.scoreC,"��");
	strcpy(temp.scoreD,"����");
	strcpy(temp.scoreE,"��");
	strcpy(temp.scoreY1,"Y");
	strcpy(temp.scoreY2,"y");
	strcpy(temp.scoreN1,"N");
	strcpy(temp.scoreN2,"n");

	Tree(tree,tree_2,noUse,decision,temp,root,&level_1,&level_2); //Ʈ�� ���� �Լ� ȣ��

}

//�ǻ� ���� �Լ�
int Decision_Node(TLINK templink,int *level_2,int decision[],TLINK tCurrent){
	
	TLINK tData=NULL;
	
	if( *level_2 > 4 ) //��� ����� ������ ������ ����
		return 0;
	
	if( strcmp(tCurrent->title,"��") != 0 && strcmp(tCurrent->title,"�ƴϿ�") != 0 ){
		
		tData = (TLINK)malloc(sizeof(TREEST));
		
		if( *level_2 < 2 ){
			
			if( decision[*level_2] == 1){
				if( *level_2 == 0 )
					templink->nextlevel_1 = tData;
				else if ( *level_2 == 1 )
					templink->nextlevel_2 = tData;
				strcpy(tData->title,"��");			
			}
			else if (decision[*level_2] == 2){
				if( *level_2 == 0 )
					templink->nextlevel_1 = tData;
				else if ( *level_2 == 1 )
					templink->nextlevel_2 = tData;
				strcpy(tData->title,"�ƴϿ�");			
			}			
		}
		
		if( *level_2 == 2 ){
			if( decision[*level_2] == 1 && tCurrent->number >= 3){
				templink->nextlevel_3 = tData;
				strcpy(tData->title,"��");
			}
			else if (decision[*level_2] == 2 && tCurrent->number >= 3){	
				templink->nextlevel_3= tData;
				strcpy(tData->title,"�ƴϿ�");
			}			
		}
		
		if(*level_2 > 2){
			
			if( decision[*level_2] == 1 && tCurrent->number > 3){
				if( *level_2 == 3 )
					templink->nextlevel_4 = tData;
				else if ( *level_2 == 4 )
					templink->nextlevel_5 = tData;
				strcpy(tData->title,"��");
			}
			else if (decision[*level_2] == 2 && tCurrent->number > 3){
				if( *level_2 == 3 )
					templink->nextlevel_4 = tData;
				else if ( *level_2 == 4 )
					templink->nextlevel_5 = tData;
				strcpy(tData->title,"�ƴϿ�");
			}
		}	
	}
	(*level_2)++;

	//��� ȣ��
	return Decision_Node(templink,level_2,decision,tCurrent);

}

//Ʈ�������Լ�

int Tree(int tree[],int tree_2[],int noUse[],int decision[],TEMP temp,TLINK root,int *level_1,int *level_2){
	
	TLINK tData=NULL;
	TLINK tCurrent=NULL;
	TLINK templink=NULL;
	//��� ����� ������ ������ �ǻ縦 ���� �������̽� ȣ��
	if( *level_1 > 4 ){
		userInterface(root); //�����������̽���
		return 0;
	}
	
	tData = (TLINK)malloc(sizeof(TREEST));
	tData->nextlevel_1 = NULL;
	tData->nextlevel_2 = NULL;
	tData->nextlevel_3 = NULL;
	tData->nextlevel_4 = NULL;
	tData->nextlevel_5 = NULL;
	
	if( root == NULL ){ //��Ʈ ��尡 0�϶� 
		
		root = tData;
		maketree(tData,temp,temp.scoreA,&noUse[0],&tree[0],&tree_2[0],&decision[0]);
		printf("root : %s\n",tData->title);
		tData->nextlevel_1 = NULL;
		tData->nextlevel_2 = NULL;
		tData->nextlevel_3 = NULL;
		tData->nextlevel_4 = NULL;
		tData->nextlevel_5 = NULL;
		
		return Tree(tree,tree_2,noUse,decision,temp,root,level_1,level_2); //��Ʈ��� ���� �� ��� ȣ��
		
	}
	
	if(tree[*level_1] != 0){ //����1�� ���鿡 ���� ����
		
		if( *level_1 == 0 ){
			root->nextlevel_1 = tData;
		}
		if( *level_1 == 1 ){
			root->nextlevel_2 = tData;
		}
		if( *level_1 == 2 ){
			root->nextlevel_3 = tData;
		}
		if( *level_1 == 3 ){
			root->nextlevel_4 = tData;
		}
		if( *level_1 == 4 ){
			root->nextlevel_5 = tData;
		}		
		if (tree[*level_1] == 3){
			maketree(tData,temp,temp.scoreA,&noUse[0],&tree_2[0],&tree[0],&decision[0]); //Ʈ�� �� ���� �Լ�
		}
		else if (tree[*level_1] == 1)
			strcpy(tData->title,"��");
		else if (tree[*level_1] == 2)
			strcpy(tData->title,"�ƴϿ�");
		
		if( *level_1 == 0 ){
			printf("lv2-1 %s",tData->title);
		}
		if( *level_1 == 1 ){
			printf("\nlv2-2 %s",tData->title);
		}
		if( *level_1 == 2 ){
			printf("\nlv2-3 %s",tData->title);
		}
		if( *level_1 == 3 ){
			printf("\nlv2-4 %s",tData->title);
		}
		if( *level_1 == 4 ){
			printf("\nlv2-5 %s",tData->title);
		}
		
		tData->nextlevel_1 = NULL;
		tData->nextlevel_2 = NULL;
		tData->nextlevel_3 = NULL;
		tData->nextlevel_4 = NULL;
		tData->nextlevel_5 = NULL;
		
		templink = tData;
		tCurrent = tData;
		
		*level_2=0;
		//�ǻ� ���� �Լ� ȣ��
		Decision_Node(templink,level_2,decision,tCurrent);
		
		printf("\n%s %s %s %s %s",templink->nextlevel_1,templink->nextlevel_2,templink->nextlevel_3,templink->nextlevel_4,templink->nextlevel_5);
	}
	(*level_1)++;
	
	//��� ȣ��
	return Tree(tree,tree_2,noUse,decision,temp,root,level_1,level_2);	
}

//Ʈ�� ���� �Լ�

void maketree(TLINK tData,TEMP temp,char temp1[], int *noUse,int *tree,int *tree_2,int *decision){
	
	double value=0; //��Ʈ���� �񱳰�
	double scoreEntro=0,licenseEntro=0,toeicEntro=0,graduateEntro=0,patriotEntro=0,internEntro=0,armyEntro=0; //��Ʈ����
	int max,i;	

	//������ ���Ͽ��� �о���� ����ü�� ���� ���Ḯ��Ʈ�� ����Ͽ� �о����

	LINK head=NULL;
	LINK data=NULL;
	LINK current=NULL;	
	FILE *fp;
	if( (fp = fopen("test.txt","r")) == NULL){
		fprintf(stderr,"���Ͼ���.");
		exit(1);
	}
	max = callDataNo();
	//������� ���Ḯ��Ʈ������ �Ǵ��Ͽ� ���Ͽ��� �����͸� �о����
	for(i=1 ; i<max ; i++) 
	{
		if(head == NULL){
			data = (LINK)malloc(sizeof(STUDENT));
			data->next = head;
			head = data;
		}
		else{
			data = (LINK)malloc(sizeof(STUDENT));
			current = head;
			
			while(current->next != NULL){
				current = current->next;
			}
			current->next = data;
			data->next = NULL;
		}	
		fscanf(fp,"%s", &data->score);
		fscanf(fp,"%s", &data->license);
		fscanf(fp,"%s", &data->toeic);
		fscanf(fp,"%s", &data->graduate);
		fscanf(fp,"%s", &data->patriot);
		fscanf(fp,"%s", &data->intern);
		fscanf(fp,"%s", &data->army);
		fscanf(fp,"%s", &data->result);		
	}
	fclose(fp);
	//��Ʈ�� ������ �ٳ��鰣�� ������ ���ϱ� ���� ���Ḯ��Ʈ�� ���� ����
	for( i=0 ; i<7 ;i++){
		if( *(noUse+i) != 0 ){	
			current = head;
			while( current != NULL ){			
				if( strcmp( head->score , temp1 ) == -1){
					head = head->next;
				}
				else if( strcmp( current->score , temp1 ) == -1){
					current = current->next;
				}	
				else
					current = current->next;
			}
		}
	}
	//������ ���Ͽ� ���� ������ ū �����͸� �����ϱ����� �Լ���� ������ �����ʹ� ������� �ʵ��� �ϱ����� ����
	//�������̼� - ������ �����ʿ� ���� ��Ʈ���ǰ��� ���� �������� �����ϰ� ��.
	if(*(noUse+6) != 1){
		scoreFunc(head,data,current,&scoreEntro,temp.scoreA,tree+5);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreB,tree+5);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreC,tree+5);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreD,tree+5);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreE,tree+5);
		
		if(value == 0 ){
			strcpy(tData->title,"����");
			tData->number = 5;
			value = scoreEntro;
		}
	}
	
	if(*(noUse) != 1){		
		licenseFunc(head,data,current,&licenseEntro,temp.scoreY1,temp.scoreY2,tree+5);
		licenseFunc(head,data,current,&licenseEntro,temp.scoreN1,temp.scoreN2,tree+5);
		if(value == 0 || value > licenseEntro){
			tData->number = 2;
			strcpy(tData->title,"����ڰ���");
			value = licenseEntro;
		}
	}	
	if(*(noUse+1) != 1){
		toeicFunc(head,data,current,&toeicEntro,temp.scoreA,tree+5);
		toeicFunc(head,data,current,&toeicEntro,temp.scoreB,tree+5);
		toeicFunc(head,data,current,&toeicEntro,temp.scoreC,tree+5);
		toeicFunc(head,data,current,&toeicEntro,temp.scoreD,tree+5);
		toeicFunc(head,data,current,&toeicEntro,temp.scoreE,tree+5);
		if(value == 0 || toeicEntro<value){
			tData->number = 5;
			strcpy(tData->title,"����");
			value = toeicEntro;
		}		
	}	
	if(*(noUse+2) != 1){		
		graduateFunc(head,data,current,&graduateEntro,temp.scoreA,tree+5);
		graduateFunc(head,data,current,&graduateEntro,temp.scoreC,tree+5);
		graduateFunc(head,data,current,&graduateEntro,temp.scoreE,tree+5);		
		if(value == 0 || graduateEntro<value){
			strcpy(tData->title,"�������輺��");
			tData->number = 3;
			value = graduateEntro;
		}
	}
	if(*(noUse+3) != 1){
		patriotFunc(head,data,current,&patriotEntro,temp.scoreY1,temp.scoreY2,tree+5);
		patriotFunc(head,data,current,&patriotEntro,temp.scoreN1,temp.scoreN2,tree+5);		
		if(value == 0 || patriotEntro<value){
			strcpy(tData->title,"����������");
			tData->number = 2;
			value = patriotEntro;
		}		
	}
	if(*(noUse+4) != 1){
		internFunc(head,data,current,&internEntro,temp.scoreY1,temp.scoreY2,tree+5);
		internFunc(head,data,current,&internEntro,temp.scoreN1,temp.scoreN2,tree+5);	
		if(value == 0 || internEntro<value){
			strcpy(tData->title,"���ϰ���");
			tData->number = 2;
			value = internEntro;
		}	
	}
	if(*(noUse+5) != 1){
		armyFunc(head,data,current,&armyEntro,temp.scoreY1,temp.scoreY2,tree+5);
		armyFunc(head,data,current,&armyEntro,temp.scoreN1,temp.scoreN2,tree+5);	
		if(value == 0 || armyEntro<value){
			strcpy(tData->title,"����");
			tData->number = 2;
		}	
	}
	
	//���� ���õǾ��� �� �ҷ����� ���� ���� 
	
	if(strcmp(tData->title,"����ڰ���") == 0){
		licenseFunc(head,data,current,&licenseEntro,temp.scoreY1,temp.scoreY2,tree,decision);
		licenseFunc(head,data,current,&licenseEntro,temp.scoreN1,temp.scoreN2,tree+1,decision+1);
		
		*(tree+2) = 0;
		*(tree+3) = 0;
		*(tree+4) = 0;
		*noUse = 1;
	}
	
	
	
	else if(strcmp(tData->title,"����") == 0){
		toeicFunc(head,data,current,&toeicEntro,temp.scoreA,tree,decision);
		toeicFunc(head,data,current,&toeicEntro,temp.scoreB,tree+1,decision+1);
		toeicFunc(head,data,current,&toeicEntro,temp.scoreC,tree+2,decision+2);
		toeicFunc(head,data,current,&toeicEntro,temp.scoreD,tree+3,decision+3);
		toeicFunc(head,data,current,&toeicEntro,temp.scoreE,tree+4,decision+4);
		
		*(noUse+1) = 1;
	}
	else if(strcmp(tData->title,"�������輺��") == 0){
		graduateFunc(head,data,current,&graduateEntro,temp.scoreA,tree,decision);
		graduateFunc(head,data,current,&graduateEntro,temp.scoreC,tree+1,decision+1);
		graduateFunc(head,data,current,&graduateEntro,temp.scoreE,tree+2,decision+2);
		
		*(tree+3) = 0;
		*(tree+4) = 0;
		*(noUse+2) = 1;
	}
	else if(strcmp(tData->title,"����������") == 0){
		patriotFunc(head,data,current,&patriotEntro,temp.scoreY1,temp.scoreY2,tree,decision);
		patriotFunc(head,data,current,&patriotEntro,temp.scoreN1,temp.scoreN2,tree+1,decision+1);
		
		*(tree+2) = 0;
		*(tree+3) = 0;
		*(tree+4) = 0;
		*(noUse+3) = 1;
	}
	else if(strcmp(tData->title,"���ϰ���") == 0){
		internFunc(head,data,current,&internEntro,temp.scoreY1,temp.scoreY2,tree,decision);
		internFunc(head,data,current,&internEntro,temp.scoreN1,temp.scoreN2,tree+1,decision+1);
		
		*(tree+2) = 0;
		*(tree+3) = 0;
		*(tree+4) = 0;
		*(noUse+4) = 1;
	}
	else if(strcmp(tData->title,"����") == 0){
		armyFunc(head,data,current,&armyEntro,temp.scoreY1,temp.scoreY2,tree);
		armyFunc(head,data,current,&armyEntro,temp.scoreN1,temp.scoreN2,tree+1,decision+1);
		
		*(tree+2) = 0;
		*(tree+3) = 0;
		*(tree+4) = 0;
		*(noUse+5) = 1;
	}
	else if(strcmp(tData->title,"����") == 0){
		scoreFunc(head,data,current,&scoreEntro,temp.scoreA,tree,decision);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreB,tree+1,decision+1);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreC,tree+2,decision+2);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreD,tree+3,decision+3);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreE,tree+4,decision+4);
		
		*(noUse+6) = 1;	
	}
}
//������ ������ ���ϱ� ���� �Լ�
int callDataNo(){
	int outchar, max=1 ; 
	FILE *fp;
	fp = fopen("test.txt","r"); // ���� �����Ϳ� ���� �о����
	while((outchar=getc(fp))!=EOF) //���� ������ ���ߴ� �ݺ��� ���
	{
		if(outchar == '\n') //���๮�ڸ� ������ ������ 1�� ����
			max++;
	}

	if(max <= 1){
		printf("�����Ͱ� �����ϴ�\n");
		exit(1);
	}

	return max;
	fclose(fp); //���� ����
}
//��ü �������̼��� ���ϱ� ���� �Լ�
double infoFunc(LINK head,LINK data,LINK current){
	
	double s1=0,max=0;
	current = head;
	while( current != NULL ){
		if( strcmp( current->result,"y") == 0 ||  strcmp( current->result,"Y") == 0 ){
			s1++;
			max++;
		}
		else
			max++;
		current = current->next;
	}	
	return -(s1/max) * log10(s1/max) / log10(2) - ((max-s1)/max) * log10((max-s1)/max) / log10(2);
}
//���� ������ ���ϱ� ���� �Լ�
int scoreFunc(LINK head,LINK data,LINK current, double *scoreEntro, char temp[],int *tree,int *decision){
	
	double s1=0,max=0,total=0;
	current = head;
	while( current != NULL ){
		//������ ���ϱ� ���� �������� ������ ����
		if( strcmp( current->score,temp) == 0 && ( strcmp( current->result,"y") == 0 ||  strcmp( current->result,"Y") == 0 )){
			s1++;
			max++;
			total++;
		}
		else if( strcmp( current->score,temp) == 0 && ( strcmp( current->result,"n") == 0 ||  strcmp( current->result,"N") == 0 )){
			max++;
			total++;
		}
		else
			total++;
		current = current->next;
	}
	//Ʈ�� ���� ���θ� ����
	if( s1 == 0 ){
		*tree = 2;
		*decision = 2;
		return 0;
	}
	else if( max == s1 ){
		*tree = 1;
		*decision = 1;
		return 0;
	}
	else{
		//��Ʈ���Ǹ� ����
		*scoreEntro = *scoreEntro + (max / total) * (-(s1/max) * log10(s1/max) / log10(2) - ((max-s1)/max) * log10((max-s1)/max) / log10(2));
		*tree = 3;
		if( max-s1 < s1)
			*decision = 1;
		
		else
			*decision = 2;
	}
	return 0;
}
//�ڰ��� ������ ������ ���ϱ� ���� �Լ�
int licenseFunc(LINK head,LINK data,LINK current, double *scoreEntro, char temp1[],char temp2[],int *tree,int *decision){
	
	double s1=0,max=0,total=0;
	current = head;
	while( current != NULL ){
		if( (strcmp(current->license,temp1) == 0 || strcmp( current->license,temp2) == 0 ) && ( strcmp( current->result,"y") == 0 ||  strcmp( current->result,"Y") == 0 )){
			s1++;
			max++;
			total++;
		}
		else if( (strcmp(current->license,temp1) == 0 || strcmp( current->license,temp2) == 0 ) && ( strcmp( current->result,"n") == 0 ||  strcmp( current->result,"N") == 0 )){
			max++;
			total++;
		}
		else
			total++;
		current = current->next;
	}
	if( s1 == 0 ){
		*tree = 2;
		*decision = 2;
		return 0;
	}
	else if( max == s1 ){
		*tree = 1;
		*decision = 1;
		return 0;
	}
	else{
		*scoreEntro = *scoreEntro + (max / total) * (-(s1/max) * log10(s1/max) / log10(2) - ((max-s1)/max) * log10((max-s1)/max) / log10(2));
		*tree = 3;
		if( max-s1 < s1)
			*decision = 1;
		
		else
			*decision = 2;
	}
	return 0;
}
//���� ������ ���ϱ� ���� �Լ�
int toeicFunc(LINK head,LINK data,LINK current, double *scoreEntro, char temp[],int *tree,int *decision){
	
	double s1=0,max=0,total=0;
	current = head;
	while( current != NULL ){
		if( strcmp( current->toeic,temp) == 0 && ( strcmp( current->result,"y") == 0 ||  strcmp( current->result,"Y") == 0 )){
			s1++;
			max++;
			total++;
		}
		else if( strcmp( current->toeic,temp) == 0 && ( strcmp( current->result,"n") == 0 ||  strcmp( current->result,"N") == 0 )){
			max++;
			total++;
		}
		else
			total++;
		current = current->next;
	}
	if( s1 == 0 ){
		*tree = 2;
		*decision = 2;
		return 0;
	}
	else if( max == s1 ){
		*tree = 1;
		*decision = 1;
		return 0;
	}
	else{
		*scoreEntro = *scoreEntro + (max / total) * (-(s1/max) * log10(s1/max) / log10(2) - ((max-s1)/max) * log10((max-s1)/max) / log10(2));
		*tree = 3;
		if( max-s1 < s1)
			*decision = 1;
		
		else
			*decision = 2;
	}
	return 0;
}

//�������� ������ ���ϱ� ���� �Լ�
int graduateFunc(LINK head,LINK data,LINK current, double *scoreEntro, char temp[],int *tree,int *decision){
	
	double s1=0,max=0,total=0;
	current = head;
	while( current != NULL ){
		if( strcmp( current->graduate,temp) == 0 && ( strcmp( current->result,"y") == 0 ||  strcmp( current->result,"Y") == 0 )){
			s1++;
			max++;
			total++;
		}
		else if( strcmp( current->graduate,temp) == 0 && ( strcmp( current->result,"n") == 0 ||  strcmp( current->result,"N") == 0 )){
			max++;
			total++;
		}
		else
			total++;
		current = current->next;
	}
	if( s1 == 0 ){
		*tree = 2;
		*decision = 2;
		return 0;
	}
	else if( max == s1 ){
		*tree = 1;
		*decision = 1;
		return 0;
	}
	else{
		*scoreEntro = *scoreEntro + (max / total) * (-(s1/max) * log10(s1/max) / log10(2) - ((max-s1)/max) * log10((max-s1)/max) / log10(2));
		*tree = 3;
		if( max-s1 < s1)
			*decision = 1;
		
		else
			*decision = 2;
	}
	return 0;
}
//���������� ������ ���ϱ� ���� �Լ�
int patriotFunc(LINK head,LINK data,LINK current, double *scoreEntro, char temp1[],char temp2[],int *tree,int *decision){
	
	double s1=0,max=0,total=0;
	current = head;
	while( current != NULL ){
		if( (strcmp(current->patriot,temp1) == 0 || strcmp( current->patriot,temp2) == 0 ) && ( strcmp( current->result,"y") == 0 ||  strcmp( current->result,"Y") == 0 )){
			s1++;
			max++;
			total++;
		}
		else if( (strcmp(current->patriot,temp1) == 0 || strcmp( current->patriot,temp2) == 0 ) && ( strcmp( current->result,"n") == 0 ||  strcmp( current->result,"N") == 0 )){
			max++;
			total++;
		}
		else
			total++;
		current = current->next;
	}
	if( s1 == 0 ){
		*tree = 2;
		*decision = 2;
		return 0;
	}
	else if( max == s1 ){
		*tree = 1;
		*decision = 1;
		return 0;
	}
	else{
		*scoreEntro = *scoreEntro + (max / total) * (-(s1/max) * log10(s1/max) / log10(2) - ((max-s1)/max) * log10((max-s1)/max) / log10(2));
		*tree = 3;
		if( max-s1 < s1)
			*decision = 1;
		
		else
			*decision = 2;
	}
	return 0;
}
//���� ���� ���������� ���ϱ� ���� �Լ�
int internFunc(LINK head,LINK data,LINK current, double *scoreEntro, char temp1[],char temp2[],int *tree,int *decision){
	
	double s1=0,max=0,total=0;
	current = head;
	while( current != NULL ){
		if( (strcmp(current->intern,temp1) == 0 || strcmp( current->intern,temp2) == 0 ) && ( strcmp( current->result,"y") == 0 ||  strcmp( current->result,"Y") == 0 )){
			s1++;
			max++;
			total++;
		}
		else if( (strcmp(current->intern,temp1) == 0 || strcmp( current->intern,temp2) == 0 ) && ( strcmp( current->result,"n") == 0 ||  strcmp( current->result,"N") == 0 )){
			max++;
			total++;
		}
		else
			total++;
		current = current->next;
	}
	if( s1 == 0 ){
		*tree = 2;
		*decision = 2;
		return 0;
	}
	else if( max == s1 ){
		*tree = 1;
		*decision = 1;
		return 0;
	}
	else{
		*scoreEntro = *scoreEntro + (max / total) * (-(s1/max) * log10(s1/max) / log10(2) - ((max-s1)/max) * log10((max-s1)/max) / log10(2));
		*tree = 3;
		if( max-s1 < s1)
			*decision = 1;
		
		else
			*decision = 2;
	}
	return 0;
}
//���������� ������ ���ϱ� ���� �Լ�
int armyFunc(LINK head,LINK data,LINK current, double *scoreEntro, char temp1[],char temp2[],int *tree,int *decision){
	
	double s1=0,max=0,total=0;
	current = head;
	while( current != NULL ){
		if( (strcmp(current->army,temp1) == 0 || strcmp( current->army,temp2) == 0 ) && ( strcmp( current->result,"y") == 0 ||  strcmp( current->result,"Y") == 0 )){
			s1++;
			max++;
			total++;
		}
		else if( (strcmp(current->army,temp1) == 0 || strcmp( current->army,temp2) == 0 ) && ( strcmp( current->result,"n") == 0 ||  strcmp( current->result,"N") == 0 )){
			max++;
			total++;
		}
		else
			total++;
		current = current->next;
	}
	if( s1 == 0 ){
		*tree = 2;
		*decision = 2;
		return 0;
	}
	else if( max == s1 ){
		*tree = 1;
		*decision = 1;
		return 0;
	}
	else{
		*scoreEntro = *scoreEntro + (max / total) * (-(s1/max) * log10(s1/max) / log10(2) - ((max-s1)/max) * log10((max-s1)/max) / log10(2));
		*tree = 3;
		if( max-s1 < s1)
			*decision = 1;
		
		else
			*decision = 2;
	}
	return 0;
}
//���� �������̽�
void userInterface(TLINK root){
	
	char sellect;
	int key=1;
	LINK user=NULL;
	TLINK tCurrent=NULL;

	//�޴�
	while(sellect != '2'){
		
		printf("\n\n\t\t M E N U");
		printf("\n\n\t\t 1 : �� �� �� �� ");
		printf("\n\n\t\t 2 : ��       �� ");
		printf("\n\n\t\t\t ��       �� : ");
		
		scanf("%s",&sellect);
		
		switch(sellect){
			
		case '1':
			
			tCurrent = root;
			key=1;
			
			user = (LINK)malloc(sizeof(STUDENT));
			//�ǻ���� �Ǵ��� �����͸� �Է¹���
			while( key != 0 ){
				printf("\n\n�����Է�(��,�߻�,��,����,��) : ");
				scanf("%s",&user->score);
				if( strcmp ( user->score,"��") == 0 || strcmp ( user->score,"�߻�") == 0 || strcmp ( user->score,"��") == 0 || strcmp ( user->score,"����") == 0 || strcmp ( user->score,"��") == 0 ){
					key = 0;
				}
				else{
					printf("�߸��� Ű�Է�\n");
					key = 1;
				}
			}
			while( key != 1){
				printf("�ڰ��� ���� �Է�(Y,N) : ");
			scanf("%s", &user->license);
				if( strcmp ( user->license,"Y") == 0 || strcmp (user->license,"y") == 0 || strcmp (user->license,"N") == 0 ||strcmp ( user->license,"n") == 0 ){
					key = 1;
				}
				else{
					printf("�߸��� Ű�Է�\n");
					key = 0;
				}
			}
			while( key != 0 ){
				printf("���� ���� �Է�(��,�߻�,��,����,��) : ");
				scanf("%s", &user->toeic);
				if( strcmp ( user->toeic,"��") == 0 || strcmp (user->toeic,"�߻�") == 0 || strcmp (user->toeic,"��") == 0 || strcmp (user->toeic,"����") == 0 || strcmp (user->toeic,"��") == 0 ){
					key = 0;
				}
				else{
					printf("�߸��� Ű�Է�\n");
					key = 1;
				}
			}
			while( key != 1 ){
				printf("�������� ���� �Է�(��,��,��) : ");
				scanf("%s", &user->graduate);
				if( strcmp ( user->graduate,"��") == 0 || strcmp (user->graduate,"��") == 0 || strcmp (user->graduate,"��") == 0 ){
					key = 1;
				}
				else{
					printf("�߸��� Ű�Է�\n");
					key = 0;
				}
			}
			while( key != 0 ){
				printf("���� ������ ���� �Է�(Y,N) : ");
			scanf("%s", &user->patriot);
				if( strcmp ( user->patriot,"Y") == 0 || strcmp (user->patriot,"y") == 0 || strcmp (user->patriot,"N") == 0 || strcmp (user->patriot,"n") == 0 ){
					key = 0;
				}
				else{
					printf("�߸��� Ű�Է�\n");
					key = 1;
				}
			}
			while( key != 1 ){
				printf("���� ���� �Է�(Y,N) : ");
			scanf("%s", &user->intern);
				if( strcmp ( user->intern,"Y") == 0 || strcmp (user->intern,"y") == 0 || strcmp (user->intern,"N") == 0 ||strcmp ( user->intern,"n") == 0 ){
					key = 1;
				}
				else{
					printf("�߸��� Ű�Է�\n");
					key = 0;
				}
			}
			while(key != 0){
				printf("���� �Է� (Y,N) :");
			scanf("%s", &user->army);
				if( strcmp ( user->army,"Y") == 0 || strcmp (user->army,"y") == 0 || strcmp (user->army,"N") == 0 ||strcmp ( user->army,"n") == 0 ){
					key = 0;
				}
				else{
					printf("�߸��� Ű�Է�\n");
					key = 1;
				}
			}
			
			
			//�Է¹��� �����͸� ���Ͽ� Ʈ���� ���� ���� ��.
			
			if( strcmp(root->title,"����") ==0){
				if( strcmp(user->score,"��") ==0){
					tCurrent = root->nextlevel_1;
				}
				else if( strcmp(user->score,"�߻�") ==0){
					tCurrent = root->nextlevel_2;
				}
				else if( strcmp(user->score,"��") ==0){
					tCurrent = root->nextlevel_3;
				}
				else if( strcmp(user->score,"����") ==0){
					tCurrent = root->nextlevel_4;
				}
				else if( strcmp(user->score,"��") ==0){
					tCurrent = root->nextlevel_5;
				}
			}
			
			if( strcmp(root->title,"����ڰ���") ==0){
				if( strcmp(user->license,"y") ==0|| strcmp(user->license,"Y") ==0){
					
					tCurrent = root->nextlevel_1;
				}
				else if(  strcmp(user->license,"n") ==0|| strcmp(user->license,"N") ==0){
					
					tCurrent = root->nextlevel_2;
				}	
			}
			
			if( strcmp(root->title,"����") ==0){
				if( strcmp(user->toeic,"��") ==0){
					tCurrent = root->nextlevel_1;
				}
				else if( strcmp(user->toeic,"�߻�")==0 ){
					tCurrent = root->nextlevel_2;
				}
				else if( strcmp(user->toeic,"��") ==0){
					tCurrent = root->nextlevel_3;
				}
				else if( strcmp(user->toeic,"����")==0 ){
					tCurrent = root->nextlevel_4;
				}
				else if( strcmp(user->toeic,"��")==0){
					tCurrent = root->nextlevel_5;
				}
			}
			if( strcmp(root->title,"�������輺��") ==0){
				if( strcmp(user->graduate,"��") ){
					tCurrent = root->nextlevel_1;
				}
				else if( strcmp(user->graduate,"��")==0 ){
					tCurrent = root->nextlevel_2;
				}
				else if( strcmp(user->graduate,"��")==0 ){
					tCurrent = root->nextlevel_3;
				}
			}
			if( strcmp(root->title,"����������") ==0){
				if( strcmp(user->patriot,"y")==0|| strcmp(user->patriot,"Y") ==0){
					
					tCurrent = root->nextlevel_1;
				}
				else if(  strcmp(user->patriot,"n") ==0|| strcmp(user->patriot,"N")==0 ){
					
					tCurrent = root->nextlevel_2;
				}	
			}
			if( strcmp(root->title,"���ϰ���") ==0){
				if( strcmp(user->intern,"y") ==0|| strcmp(user->intern,"Y")==0 ){
					
					tCurrent = root->nextlevel_1;
				}
				else if(  strcmp(user->intern,"n")==0 || strcmp(user->intern,"N")==0 ){
					
					tCurrent = root->nextlevel_2;
				}	
			}
			
			if( strcmp(root->title,"����") ==0){
				if( strcmp(user->army,"y") || strcmp(user->army,"Y") ){
					
					tCurrent = root->nextlevel_1;
				}
				else if(  strcmp(user->army,"n") ==0|| strcmp(user->army,"N") ==0){
					
					tCurrent = root->nextlevel_2;
				}	
			}

//Ʈ�� �� �� �ƴϿ� �� ���� �Ǿ� ������ �̹� �����Ǿ����Ƿ� ���� �ʴ´�.

			if( strcmp(tCurrent->title,"��") != 0 || strcmp(tCurrent->title,"�ƴϿ�") != 0 ){
				
				if( strcmp(root->title,"����")==0 ){
					if( strcmp(user->score,"��") ){
						tCurrent = root->nextlevel_1;
					}
					else if( strcmp(user->score,"�߻�") ==0){
						tCurrent = root->nextlevel_2;
					}
					else if( strcmp(user->score,"��")==0 ){
						tCurrent = root->nextlevel_3;
					}
					else if( strcmp(user->score,"����")==0 ){
						tCurrent = root->nextlevel_4;
					}
					else if( strcmp(user->score,"��")==0 ){
						tCurrent = root->nextlevel_5;
					}
				}
				
				if( strcmp(root->title,"����ڰ���") == 0){
					if( strcmp(user->license,"y") ==0|| strcmp(user->license,"Y") ==0){
						
						tCurrent = root->nextlevel_1;
					}
					else if(  strcmp(user->license,"n")==0 || strcmp(user->license,"N")==0 ){
						
						tCurrent = root->nextlevel_2;
					}	
				}
				if( strcmp(tCurrent->title,"����") == 0){

					if( strcmp(user->toeic,"��")==0 ){
						tCurrent = tCurrent->nextlevel_1;
					}
					else if( strcmp(user->toeic,"�߻�") ==0){
						tCurrent = tCurrent->nextlevel_2;
					}
					else if( strcmp(user->toeic,"��")==0 ){
						tCurrent = tCurrent->nextlevel_3;
					}
					else if( strcmp(user->toeic,"����") ==0){
						tCurrent = tCurrent->nextlevel_4;
					}
					else if( strcmp(user->toeic,"��")==0 ){
						tCurrent = tCurrent->nextlevel_5;
					}
					
				}
				if( strcmp(tCurrent->title,"�������輺��") == 0){
					if( strcmp(user->graduate,"��") ==0){
						tCurrent = tCurrent->nextlevel_1;
					}
					else if( strcmp(user->graduate,"��")==0 ){
						tCurrent = tCurrent->nextlevel_2;
					}
					else if( strcmp(user->graduate,"��")==0 ){
						tCurrent = tCurrent->nextlevel_3;
					}
				}
				if( strcmp(tCurrent->title,"����������") == 0 ){
					if( strcmp(user->patriot,"y") ==0|| strcmp(user->patriot,"Y") ==0){
						
						tCurrent = tCurrent->nextlevel_1;
					}
					else if(  strcmp(user->patriot,"n") ==0|| strcmp(user->patriot,"N") ==0){
						
						tCurrent = tCurrent->nextlevel_2;
					}	
				}
				if( strcmp(tCurrent->title,"���ϰ���") == 0){
					if( strcmp(user->intern,"y")==0 || strcmp(user->intern,"Y") ==0){
						
						tCurrent = tCurrent->nextlevel_1;
					}
					else if(  strcmp(user->intern,"n") ==0|| strcmp(user->intern,"N") ==0){
						
						tCurrent = tCurrent->nextlevel_2;
					}	
				}				
				if( strcmp(tCurrent->title,"����") == 0){
					if( strcmp(user->army,"y") ==0|| strcmp(user->army,"Y") ==0){
						
						tCurrent = tCurrent->nextlevel_1;
					}
					else if(  strcmp(user->army,"n")==0 || strcmp(user->army,"N")==0 ){
						
						tCurrent = tCurrent->nextlevel_2;
					}	
				}	
			}	printf("\n\n������� : %s\n\n",tCurrent->title); //������� ����		
			break;					
		case '2':
			printf("\t\t\n\n�����մϴ�.\n");
			break;	
		default:
			printf("\t\t\n\n�߸� �����̽��ϴ�.\n\n");			
		}
	}
}