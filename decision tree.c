/*
의사결정트리 프로그램 
작성날짜 : 2008년 4월 26일 토요일
수정날짜 : 2008년 5월 22일 목요일
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>

//사용될 함수
int callDataNo(); // 데이터의 갯수를 리턴하는 함수
int scoreFunc();  // 성적에 대한 엔트로피와 옵션을 설정해주는 함수
int licenseFunc();  // 자격증에 대한 엔트로피와 옵션을 설정해주는 함수
int toeicFunc();  // 토익점수에 대한 엔트로피와 옵션을 설정해주는 함수
int graduateFunc();  // 졸업성적에 대한 엔트로피와 옵션을 설정해주는 함수
int patriotFunc();  // 국가유공자유무에 대한 엔트로피와 옵션을 설정해주는 함수
int internFunc();  // 인턴경험에 대한 엔트로피와 옵션을 설정해주는 함수
int armyFunc();  // 군필에 대한 엔트로피와 옵션을 설정해주는 함수
void maketree();  // 트리를 만들때 필요한 옵션들을 불러와서 연산하는 함수
void userInterface();  // 유저 인터페이스 함수
int Tree();  // 트리를 만드는 함수
int Decision_Node();  // 의사 결정에 대한 함수

//샘플데이터 에서 읽어올 데이터들이 저장되는 변수 선언
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

//의사결정트리에 사용될 구조체
typedef struct tree1{
	char title[20];
	int number;
	struct tree1 *nextlevel_1;
	struct tree1 *nextlevel_2;
	struct tree1 *nextlevel_3;
	struct tree1 *nextlevel_4;
	struct tree1 *nextlevel_5;
}TREEST;

//평가 데이터에 대한 구조체
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
	//변수 선언
	int tree[7]={0}; 
	int tree_2[7]={0};
	int noUse[7]={0}; // 노드로 뽑히면 읽어오지 않음을 설정하는 변수
	int decision[5]={0}; //의사를 결정하는 변수
	int level_1=0;
	int level_2=0;
	TEMP temp;
	TLINK root=NULL;
	
	//비교 데이터 생성
	strcpy(temp.scoreA,"상");
	strcpy(temp.scoreB,"중상");
	strcpy(temp.scoreC,"중");
	strcpy(temp.scoreD,"중하");
	strcpy(temp.scoreE,"하");
	strcpy(temp.scoreY1,"Y");
	strcpy(temp.scoreY2,"y");
	strcpy(temp.scoreN1,"N");
	strcpy(temp.scoreN2,"n");

	Tree(tree,tree_2,noUse,decision,temp,root,&level_1,&level_2); //트리 생성 함수 호출

}

//의사 결정 함수
int Decision_Node(TLINK templink,int *level_2,int decision[],TLINK tCurrent){
	
	TLINK tData=NULL;
	
	if( *level_2 > 4 ) //모든 노드의 결정이 끝나면 종료
		return 0;
	
	if( strcmp(tCurrent->title,"예") != 0 && strcmp(tCurrent->title,"아니오") != 0 ){
		
		tData = (TLINK)malloc(sizeof(TREEST));
		
		if( *level_2 < 2 ){
			
			if( decision[*level_2] == 1){
				if( *level_2 == 0 )
					templink->nextlevel_1 = tData;
				else if ( *level_2 == 1 )
					templink->nextlevel_2 = tData;
				strcpy(tData->title,"예");			
			}
			else if (decision[*level_2] == 2){
				if( *level_2 == 0 )
					templink->nextlevel_1 = tData;
				else if ( *level_2 == 1 )
					templink->nextlevel_2 = tData;
				strcpy(tData->title,"아니오");			
			}			
		}
		
		if( *level_2 == 2 ){
			if( decision[*level_2] == 1 && tCurrent->number >= 3){
				templink->nextlevel_3 = tData;
				strcpy(tData->title,"예");
			}
			else if (decision[*level_2] == 2 && tCurrent->number >= 3){	
				templink->nextlevel_3= tData;
				strcpy(tData->title,"아니오");
			}			
		}
		
		if(*level_2 > 2){
			
			if( decision[*level_2] == 1 && tCurrent->number > 3){
				if( *level_2 == 3 )
					templink->nextlevel_4 = tData;
				else if ( *level_2 == 4 )
					templink->nextlevel_5 = tData;
				strcpy(tData->title,"예");
			}
			else if (decision[*level_2] == 2 && tCurrent->number > 3){
				if( *level_2 == 3 )
					templink->nextlevel_4 = tData;
				else if ( *level_2 == 4 )
					templink->nextlevel_5 = tData;
				strcpy(tData->title,"아니오");
			}
		}	
	}
	(*level_2)++;

	//재귀 호출
	return Decision_Node(templink,level_2,decision,tCurrent);

}

//트리생성함수

int Tree(int tree[],int tree_2[],int noUse[],int decision[],TEMP temp,TLINK root,int *level_1,int *level_2){
	
	TLINK tData=NULL;
	TLINK tCurrent=NULL;
	TLINK templink=NULL;
	//모든 노드의 생성이 끝나면 의사를 결정 인터페이스 호출
	if( *level_1 > 4 ){
		userInterface(root); //유저인터페이스로
		return 0;
	}
	
	tData = (TLINK)malloc(sizeof(TREEST));
	tData->nextlevel_1 = NULL;
	tData->nextlevel_2 = NULL;
	tData->nextlevel_3 = NULL;
	tData->nextlevel_4 = NULL;
	tData->nextlevel_5 = NULL;
	
	if( root == NULL ){ //루트 노드가 0일때 
		
		root = tData;
		maketree(tData,temp,temp.scoreA,&noUse[0],&tree[0],&tree_2[0],&decision[0]);
		printf("root : %s\n",tData->title);
		tData->nextlevel_1 = NULL;
		tData->nextlevel_2 = NULL;
		tData->nextlevel_3 = NULL;
		tData->nextlevel_4 = NULL;
		tData->nextlevel_5 = NULL;
		
		return Tree(tree,tree_2,noUse,decision,temp,root,level_1,level_2); //루트노드 설정 후 재귀 호출
		
	}
	
	if(tree[*level_1] != 0){ //레벨1의 노드들에 따른 설정
		
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
			maketree(tData,temp,temp.scoreA,&noUse[0],&tree_2[0],&tree[0],&decision[0]); //트리 비교 생성 함수
		}
		else if (tree[*level_1] == 1)
			strcpy(tData->title,"예");
		else if (tree[*level_1] == 2)
			strcpy(tData->title,"아니오");
		
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
		//의사 결정 함수 호출
		Decision_Node(templink,level_2,decision,tCurrent);
		
		printf("\n%s %s %s %s %s",templink->nextlevel_1,templink->nextlevel_2,templink->nextlevel_3,templink->nextlevel_4,templink->nextlevel_5);
	}
	(*level_1)++;
	
	//재귀 호출
	return Tree(tree,tree_2,noUse,decision,temp,root,level_1,level_2);	
}

//트리 연산 함수

void maketree(TLINK tData,TEMP temp,char temp1[], int *noUse,int *tree,int *tree_2,int *decision){
	
	double value=0; //엔트로피 비교값
	double scoreEntro=0,licenseEntro=0,toeicEntro=0,graduateEntro=0,patriotEntro=0,internEntro=0,armyEntro=0; //엔트로피
	int max,i;	

	//데이터 파일에서 읽어들일 구조체를 생성 연결리스트를 사용하여 읽어들임

	LINK head=NULL;
	LINK data=NULL;
	LINK current=NULL;	
	FILE *fp;
	if( (fp = fopen("test.txt","r")) == NULL){
		fprintf(stderr,"파일없다.");
		exit(1);
	}
	max = callDataNo();
	//헤드인지 연결리스트인지를 판단하여 파일에서 데이터를 읽어들임
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
	//루트를 제외한 잎노드들간의 게인을 구하기 위한 연결리스트를 새로 생성
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
	//게인을 구하여 가장 게인이 큰 데이터를 결정하기위한 함수들과 결정된 데이터는 사용하지 않도록 하기위한 변수
	//인포메이션 - 게인을 구할필요 없이 엔트로피값이 가장 작은것을 선택하게 함.
	if(*(noUse+6) != 1){
		scoreFunc(head,data,current,&scoreEntro,temp.scoreA,tree+5);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreB,tree+5);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreC,tree+5);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreD,tree+5);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreE,tree+5);
		
		if(value == 0 ){
			strcpy(tData->title,"성적");
			tData->number = 5;
			value = scoreEntro;
		}
	}
	
	if(*(noUse) != 1){		
		licenseFunc(head,data,current,&licenseEntro,temp.scoreY1,temp.scoreY2,tree+5);
		licenseFunc(head,data,current,&licenseEntro,temp.scoreN1,temp.scoreN2,tree+5);
		if(value == 0 || value > licenseEntro){
			tData->number = 2;
			strcpy(tData->title,"기사자격증");
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
			strcpy(tData->title,"토익");
			value = toeicEntro;
		}		
	}	
	if(*(noUse+2) != 1){		
		graduateFunc(head,data,current,&graduateEntro,temp.scoreA,tree+5);
		graduateFunc(head,data,current,&graduateEntro,temp.scoreC,tree+5);
		graduateFunc(head,data,current,&graduateEntro,temp.scoreE,tree+5);		
		if(value == 0 || graduateEntro<value){
			strcpy(tData->title,"졸업실험성적");
			tData->number = 3;
			value = graduateEntro;
		}
	}
	if(*(noUse+3) != 1){
		patriotFunc(head,data,current,&patriotEntro,temp.scoreY1,temp.scoreY2,tree+5);
		patriotFunc(head,data,current,&patriotEntro,temp.scoreN1,temp.scoreN2,tree+5);		
		if(value == 0 || patriotEntro<value){
			strcpy(tData->title,"국가유공자");
			tData->number = 2;
			value = patriotEntro;
		}		
	}
	if(*(noUse+4) != 1){
		internFunc(head,data,current,&internEntro,temp.scoreY1,temp.scoreY2,tree+5);
		internFunc(head,data,current,&internEntro,temp.scoreN1,temp.scoreN2,tree+5);	
		if(value == 0 || internEntro<value){
			strcpy(tData->title,"인턴경험");
			tData->number = 2;
			value = internEntro;
		}	
	}
	if(*(noUse+5) != 1){
		armyFunc(head,data,current,&armyEntro,temp.scoreY1,temp.scoreY2,tree+5);
		armyFunc(head,data,current,&armyEntro,temp.scoreN1,temp.scoreN2,tree+5);	
		if(value == 0 || armyEntro<value){
			strcpy(tData->title,"군필");
			tData->number = 2;
		}	
	}
	
	//노드로 선택되었을 시 불러오기 안함 설정 
	
	if(strcmp(tData->title,"기사자격증") == 0){
		licenseFunc(head,data,current,&licenseEntro,temp.scoreY1,temp.scoreY2,tree,decision);
		licenseFunc(head,data,current,&licenseEntro,temp.scoreN1,temp.scoreN2,tree+1,decision+1);
		
		*(tree+2) = 0;
		*(tree+3) = 0;
		*(tree+4) = 0;
		*noUse = 1;
	}
	
	
	
	else if(strcmp(tData->title,"토익") == 0){
		toeicFunc(head,data,current,&toeicEntro,temp.scoreA,tree,decision);
		toeicFunc(head,data,current,&toeicEntro,temp.scoreB,tree+1,decision+1);
		toeicFunc(head,data,current,&toeicEntro,temp.scoreC,tree+2,decision+2);
		toeicFunc(head,data,current,&toeicEntro,temp.scoreD,tree+3,decision+3);
		toeicFunc(head,data,current,&toeicEntro,temp.scoreE,tree+4,decision+4);
		
		*(noUse+1) = 1;
	}
	else if(strcmp(tData->title,"졸업실험성적") == 0){
		graduateFunc(head,data,current,&graduateEntro,temp.scoreA,tree,decision);
		graduateFunc(head,data,current,&graduateEntro,temp.scoreC,tree+1,decision+1);
		graduateFunc(head,data,current,&graduateEntro,temp.scoreE,tree+2,decision+2);
		
		*(tree+3) = 0;
		*(tree+4) = 0;
		*(noUse+2) = 1;
	}
	else if(strcmp(tData->title,"국가유공자") == 0){
		patriotFunc(head,data,current,&patriotEntro,temp.scoreY1,temp.scoreY2,tree,decision);
		patriotFunc(head,data,current,&patriotEntro,temp.scoreN1,temp.scoreN2,tree+1,decision+1);
		
		*(tree+2) = 0;
		*(tree+3) = 0;
		*(tree+4) = 0;
		*(noUse+3) = 1;
	}
	else if(strcmp(tData->title,"인턴경험") == 0){
		internFunc(head,data,current,&internEntro,temp.scoreY1,temp.scoreY2,tree,decision);
		internFunc(head,data,current,&internEntro,temp.scoreN1,temp.scoreN2,tree+1,decision+1);
		
		*(tree+2) = 0;
		*(tree+3) = 0;
		*(tree+4) = 0;
		*(noUse+4) = 1;
	}
	else if(strcmp(tData->title,"군필") == 0){
		armyFunc(head,data,current,&armyEntro,temp.scoreY1,temp.scoreY2,tree);
		armyFunc(head,data,current,&armyEntro,temp.scoreN1,temp.scoreN2,tree+1,decision+1);
		
		*(tree+2) = 0;
		*(tree+3) = 0;
		*(tree+4) = 0;
		*(noUse+5) = 1;
	}
	else if(strcmp(tData->title,"성적") == 0){
		scoreFunc(head,data,current,&scoreEntro,temp.scoreA,tree,decision);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreB,tree+1,decision+1);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreC,tree+2,decision+2);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreD,tree+3,decision+3);
		scoreFunc(head,data,current,&scoreEntro,temp.scoreE,tree+4,decision+4);
		
		*(noUse+6) = 1;	
	}
}
//데이터 갯수를 구하기 위한 함수
int callDataNo(){
	int outchar, max=1 ; 
	FILE *fp;
	fp = fopen("test.txt","r"); // 파일 포인터에 파일 읽어들임
	while((outchar=getc(fp))!=EOF) //끝을 만나면 멈추는 반복문 사용
	{
		if(outchar == '\n') //개행문자를 만나면 라인이 1씩 증가
			max++;
	}

	if(max <= 1){
		printf("데이터가 없습니다\n");
		exit(1);
	}

	return max;
	fclose(fp); //파일 닫음
}
//전체 인포메이션을 구하기 위한 함수
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
//성적 게인을 구하기 위한 함수
int scoreFunc(LINK head,LINK data,LINK current, double *scoreEntro, char temp[],int *tree,int *decision){
	
	double s1=0,max=0,total=0;
	current = head;
	while( current != NULL ){
		//게인을 구하기 위한 데이터의 갯수를 연산
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
	//트리 결정 여부를 연산
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
		//엔트로피를 구함
		*scoreEntro = *scoreEntro + (max / total) * (-(s1/max) * log10(s1/max) / log10(2) - ((max-s1)/max) * log10((max-s1)/max) / log10(2));
		*tree = 3;
		if( max-s1 < s1)
			*decision = 1;
		
		else
			*decision = 2;
	}
	return 0;
}
//자격증 유무의 게인을 구하기 위한 함수
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
//토익 게인을 구하기 위한 함수
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

//졸업실험 성적을 구하기 위한 함수
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
//국가유공자 유무를 구하기 위한 함수
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
//인턴 경험 유무게인을 구하기 위한 함수
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
//군필유무의 게인을 구하기 위함 함수
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
//유저 인터페이스
void userInterface(TLINK root){
	
	char sellect;
	int key=1;
	LINK user=NULL;
	TLINK tCurrent=NULL;

	//메뉴
	while(sellect != '2'){
		
		printf("\n\n\t\t M E N U");
		printf("\n\n\t\t 1 : 의 사 결 정 ");
		printf("\n\n\t\t 2 : 종       료 ");
		printf("\n\n\t\t\t 선       택 : ");
		
		scanf("%s",&sellect);
		
		switch(sellect){
			
		case '1':
			
			tCurrent = root;
			key=1;
			
			user = (LINK)malloc(sizeof(STUDENT));
			//의사결정 판단할 데이터를 입력받음
			while( key != 0 ){
				printf("\n\n성적입력(상,중상,중,중하,하) : ");
				scanf("%s",&user->score);
				if( strcmp ( user->score,"상") == 0 || strcmp ( user->score,"중상") == 0 || strcmp ( user->score,"중") == 0 || strcmp ( user->score,"중하") == 0 || strcmp ( user->score,"하") == 0 ){
					key = 0;
				}
				else{
					printf("잘못된 키입력\n");
					key = 1;
				}
			}
			while( key != 1){
				printf("자격증 유무 입력(Y,N) : ");
			scanf("%s", &user->license);
				if( strcmp ( user->license,"Y") == 0 || strcmp (user->license,"y") == 0 || strcmp (user->license,"N") == 0 ||strcmp ( user->license,"n") == 0 ){
					key = 1;
				}
				else{
					printf("잘못된 키입력\n");
					key = 0;
				}
			}
			while( key != 0 ){
				printf("토익 성적 입력(상,중상,중,중하,하) : ");
				scanf("%s", &user->toeic);
				if( strcmp ( user->toeic,"상") == 0 || strcmp (user->toeic,"중상") == 0 || strcmp (user->toeic,"중") == 0 || strcmp (user->toeic,"중하") == 0 || strcmp (user->toeic,"하") == 0 ){
					key = 0;
				}
				else{
					printf("잘못된 키입력\n");
					key = 1;
				}
			}
			while( key != 1 ){
				printf("졸업실험 성적 입력(상,중,하) : ");
				scanf("%s", &user->graduate);
				if( strcmp ( user->graduate,"상") == 0 || strcmp (user->graduate,"중") == 0 || strcmp (user->graduate,"하") == 0 ){
					key = 1;
				}
				else{
					printf("잘못된 키입력\n");
					key = 0;
				}
			}
			while( key != 0 ){
				printf("국가 유공자 유무 입력(Y,N) : ");
			scanf("%s", &user->patriot);
				if( strcmp ( user->patriot,"Y") == 0 || strcmp (user->patriot,"y") == 0 || strcmp (user->patriot,"N") == 0 || strcmp (user->patriot,"n") == 0 ){
					key = 0;
				}
				else{
					printf("잘못된 키입력\n");
					key = 1;
				}
			}
			while( key != 1 ){
				printf("인턴 경험 입력(Y,N) : ");
			scanf("%s", &user->intern);
				if( strcmp ( user->intern,"Y") == 0 || strcmp (user->intern,"y") == 0 || strcmp (user->intern,"N") == 0 ||strcmp ( user->intern,"n") == 0 ){
					key = 1;
				}
				else{
					printf("잘못된 키입력\n");
					key = 0;
				}
			}
			while(key != 0){
				printf("군필 입력 (Y,N) :");
			scanf("%s", &user->army);
				if( strcmp ( user->army,"Y") == 0 || strcmp (user->army,"y") == 0 || strcmp (user->army,"N") == 0 ||strcmp ( user->army,"n") == 0 ){
					key = 0;
				}
				else{
					printf("잘못된 키입력\n");
					key = 1;
				}
			}
			
			
			//입력받은 데이터를 비교하여 트리를 따라 가게 함.
			
			if( strcmp(root->title,"성적") ==0){
				if( strcmp(user->score,"상") ==0){
					tCurrent = root->nextlevel_1;
				}
				else if( strcmp(user->score,"중상") ==0){
					tCurrent = root->nextlevel_2;
				}
				else if( strcmp(user->score,"중") ==0){
					tCurrent = root->nextlevel_3;
				}
				else if( strcmp(user->score,"중하") ==0){
					tCurrent = root->nextlevel_4;
				}
				else if( strcmp(user->score,"하") ==0){
					tCurrent = root->nextlevel_5;
				}
			}
			
			if( strcmp(root->title,"기사자격증") ==0){
				if( strcmp(user->license,"y") ==0|| strcmp(user->license,"Y") ==0){
					
					tCurrent = root->nextlevel_1;
				}
				else if(  strcmp(user->license,"n") ==0|| strcmp(user->license,"N") ==0){
					
					tCurrent = root->nextlevel_2;
				}	
			}
			
			if( strcmp(root->title,"토익") ==0){
				if( strcmp(user->toeic,"상") ==0){
					tCurrent = root->nextlevel_1;
				}
				else if( strcmp(user->toeic,"중상")==0 ){
					tCurrent = root->nextlevel_2;
				}
				else if( strcmp(user->toeic,"중") ==0){
					tCurrent = root->nextlevel_3;
				}
				else if( strcmp(user->toeic,"중하")==0 ){
					tCurrent = root->nextlevel_4;
				}
				else if( strcmp(user->toeic,"하")==0){
					tCurrent = root->nextlevel_5;
				}
			}
			if( strcmp(root->title,"졸업실험성적") ==0){
				if( strcmp(user->graduate,"상") ){
					tCurrent = root->nextlevel_1;
				}
				else if( strcmp(user->graduate,"중")==0 ){
					tCurrent = root->nextlevel_2;
				}
				else if( strcmp(user->graduate,"하")==0 ){
					tCurrent = root->nextlevel_3;
				}
			}
			if( strcmp(root->title,"국가유공자") ==0){
				if( strcmp(user->patriot,"y")==0|| strcmp(user->patriot,"Y") ==0){
					
					tCurrent = root->nextlevel_1;
				}
				else if(  strcmp(user->patriot,"n") ==0|| strcmp(user->patriot,"N")==0 ){
					
					tCurrent = root->nextlevel_2;
				}	
			}
			if( strcmp(root->title,"인턴경험") ==0){
				if( strcmp(user->intern,"y") ==0|| strcmp(user->intern,"Y")==0 ){
					
					tCurrent = root->nextlevel_1;
				}
				else if(  strcmp(user->intern,"n")==0 || strcmp(user->intern,"N")==0 ){
					
					tCurrent = root->nextlevel_2;
				}	
			}
			
			if( strcmp(root->title,"군필") ==0){
				if( strcmp(user->army,"y") || strcmp(user->army,"Y") ){
					
					tCurrent = root->nextlevel_1;
				}
				else if(  strcmp(user->army,"n") ==0|| strcmp(user->army,"N") ==0){
					
					tCurrent = root->nextlevel_2;
				}	
			}

//트리 가 예 아니오 로 설정 되어 있으면 이미 결정되었으므로 들어가지 않는다.

			if( strcmp(tCurrent->title,"예") != 0 || strcmp(tCurrent->title,"아니오") != 0 ){
				
				if( strcmp(root->title,"성적")==0 ){
					if( strcmp(user->score,"상") ){
						tCurrent = root->nextlevel_1;
					}
					else if( strcmp(user->score,"중상") ==0){
						tCurrent = root->nextlevel_2;
					}
					else if( strcmp(user->score,"중")==0 ){
						tCurrent = root->nextlevel_3;
					}
					else if( strcmp(user->score,"중하")==0 ){
						tCurrent = root->nextlevel_4;
					}
					else if( strcmp(user->score,"하")==0 ){
						tCurrent = root->nextlevel_5;
					}
				}
				
				if( strcmp(root->title,"기사자격증") == 0){
					if( strcmp(user->license,"y") ==0|| strcmp(user->license,"Y") ==0){
						
						tCurrent = root->nextlevel_1;
					}
					else if(  strcmp(user->license,"n")==0 || strcmp(user->license,"N")==0 ){
						
						tCurrent = root->nextlevel_2;
					}	
				}
				if( strcmp(tCurrent->title,"토익") == 0){

					if( strcmp(user->toeic,"상")==0 ){
						tCurrent = tCurrent->nextlevel_1;
					}
					else if( strcmp(user->toeic,"중상") ==0){
						tCurrent = tCurrent->nextlevel_2;
					}
					else if( strcmp(user->toeic,"중")==0 ){
						tCurrent = tCurrent->nextlevel_3;
					}
					else if( strcmp(user->toeic,"중하") ==0){
						tCurrent = tCurrent->nextlevel_4;
					}
					else if( strcmp(user->toeic,"하")==0 ){
						tCurrent = tCurrent->nextlevel_5;
					}
					
				}
				if( strcmp(tCurrent->title,"졸업실험성적") == 0){
					if( strcmp(user->graduate,"상") ==0){
						tCurrent = tCurrent->nextlevel_1;
					}
					else if( strcmp(user->graduate,"중")==0 ){
						tCurrent = tCurrent->nextlevel_2;
					}
					else if( strcmp(user->graduate,"하")==0 ){
						tCurrent = tCurrent->nextlevel_3;
					}
				}
				if( strcmp(tCurrent->title,"국가유공자") == 0 ){
					if( strcmp(user->patriot,"y") ==0|| strcmp(user->patriot,"Y") ==0){
						
						tCurrent = tCurrent->nextlevel_1;
					}
					else if(  strcmp(user->patriot,"n") ==0|| strcmp(user->patriot,"N") ==0){
						
						tCurrent = tCurrent->nextlevel_2;
					}	
				}
				if( strcmp(tCurrent->title,"인턴경험") == 0){
					if( strcmp(user->intern,"y")==0 || strcmp(user->intern,"Y") ==0){
						
						tCurrent = tCurrent->nextlevel_1;
					}
					else if(  strcmp(user->intern,"n") ==0|| strcmp(user->intern,"N") ==0){
						
						tCurrent = tCurrent->nextlevel_2;
					}	
				}				
				if( strcmp(tCurrent->title,"군필") == 0){
					if( strcmp(user->army,"y") ==0|| strcmp(user->army,"Y") ==0){
						
						tCurrent = tCurrent->nextlevel_1;
					}
					else if(  strcmp(user->army,"n")==0 || strcmp(user->army,"N")==0 ){
						
						tCurrent = tCurrent->nextlevel_2;
					}	
				}	
			}	printf("\n\n취업여부 : %s\n\n",tCurrent->title); //취업여부 결정		
			break;					
		case '2':
			printf("\t\t\n\n종료합니다.\n");
			break;	
		default:
			printf("\t\t\n\n잘못 누르셨습니다.\n\n");			
		}
	}
}