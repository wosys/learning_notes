#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100//顺序表可能达到的最大长度

typedef int Elemtype;
typedef int Status;

typedef struct list{
	Elemtype *elem;
	int len;
	int listsize;
}List;

void list_init(List *L){
	L->elem = (Elemtype *)malloc(MAXSIZE * sizeof(Elemtype));//开辟空间
	if (L->elem == NULL){//判断空间是否开辟成功
		printf("储存分配失败退出\n");
		exit(0);
	}
	L->len = 0;	//初始化数据有效数据为0
	L->listsize = MAXSIZE;	//初始化数组长度为MAXSIZE
}

Status list_insert(List *L, int i, Elemtype data){
	Elemtype *base, *insert, *p;
	if ((i<1) || (i>L->len + 1) || (L == NULL)){//i值不合法
		printf("位置输入错误\n");
		return 0;
	}
	if (L->len > L->listsize){//当表长达到预设的最大空间时，需要动态扩充
		base = (Elemtype *)realloc(L->elem, (L->listsize + MAXSIZE) * sizeof(Elemtype));
		L->elem = base;
		L->listsize += MAXSIZE;
	}
	insert = &(L->elem[i - 1]);//目标指针指向要插入的目标地址
							   //指向最后一个元素的地址
	for (p = L->elem + L->len - 1; p >= insert; p--){
		*(p + 1) = *p;//插入位置及之后的元素后移
	}
	*insert = data;//data值放在第i个位置
	++L->len;//表长加1
	return 1;
}

Status list_delete(List *L, int i){
	Elemtype *aim, *p;
	if ((i<1) || (i>L->len)){//i值不合法
		printf("位置输入错误\n");
		return 0;
	}
	aim = &(L->elem[i-1]);//目标指针指向要删除的目标地址
	p = (L->elem + L->len - 1); //指向最后一个元素的地址
	for (aim = aim + 1; aim <= p; ++aim){ 
		*(aim - 1) = *aim;//被删除元素之后的元素前移
	}
	--L->len;//表长减1
	return 1;
}

Status list_search(List L, Elemtype e) {
	int m;
	for (m = 0; m < L.len; m++) {
		if (L.elem[m] == e)
			break;
	}
	printf("%d\n", m + 1);
	if (m + 1 > L.len) printf("由于超出顺序表最后数据位置，故未找到%d\n",e);
	return 0;
}

void show_list(List *L){
	int i;
	for (i = 0; i<L->len; i++){
		printf("elem[%d]=%d\n", i+1 , L->elem[i]);
	}
	printf("\n");
}
int main(){
	int i;
	list L;
	list_init(&L);
	for (i = 0; i<10; i++){
		list_insert(&L, i + 1, i + 1);
	}
	printf("插入前的顺序表\n");
	show_list(&L);

	printf("插入后的顺序表  在5位置插入99\n");
	list_insert(&L, 5, 99);
	show_list(&L);

	printf("删除后的顺序表  把4位置删除\n");
	list_delete(&L, 4);
	show_list(&L);

	printf("查找顺序表中值为9的位置:");
	list_search(L, 9);
	printf("查找顺序表中值为18的位置:");
	list_search(L, 18);
	return 0;
}
