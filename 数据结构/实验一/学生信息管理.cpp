#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {
	int num;
	int grade;
	char name[20];
	struct student *next;
}student;
student *head;
int length;

void creat() {
	student *p1, *p2;
	length = 0;
	int number = 0;
	p1 = (student *)malloc(sizeof(student));
	p1->num = -1;

	if (head == NULL)
		head = p1;
	printf("请输入学生学号、姓名、成绩：\n");
	while (number <= 5) {
		p2= (student *)malloc(sizeof(student));
		scanf("%d %s %d", &p2->num, p2->name, &p2->grade);
		if (p2->num == 0) {
			printf("学生信息建立完成！\n");
			break;
		}
		length++;
		p1->next = p2;
		p2->next = NULL;
		p1 = p1->next;
		number++;
	}

}

void show() {
	student *p = head->next;
	printf("表中学生信息如下：\n");
	while (p != NULL) {
		printf("%d %s %d\n", p->num, p->name, p->grade);
		p = p->next;
	}

}

void numsearch() {
	int xuehao;
	student *p = head->next;
	printf("请输入需要查找的学生的学号\n");
	scanf("%d", &xuehao);
	while (p != NULL) {
		if (p->num == xuehao) {
			printf("你要的学生信息如下：\n");
			printf("%d %s %d\n", p->num, p->name, p->grade);
			return;
		}
		p = p->next;
	}
	if (p == NULL)
		printf("找不到该学号的学生\n");
	return;
}

void insert(){
	int num_, i;
	student *p, *q;
	p = head;
	printf("请输入你要插入位置: ");
	scanf("%d", &num_);
	if (num_>length){
		printf("找不到要插入的位置\n");
		return;
	}
	else{
		printf("请输入你要插入的学生的学号、姓名、成绩：\n");
		q = (student *)malloc(sizeof(student));
		scanf("%d %s %d", &q->num, q->name, &q->grade);
		while (p != NULL){
			if (p->num == q->num){
            printf("该学号已经存在，无法插入信息！\n");
			return;
}
p = p->next;
}
p = head;
for (i = 0; i<num_; i++)
p = p->next;
q->next = p->next;
p->next = q;
length++;
printf("插入学生信息成功！\n");
return;}

}

void Delete(){
	int num_;
	student *p, *q;
	q = head, p = head->next;
	printf("请输入要删除的学生的学号:\n");
	scanf("%d", &num_);
	while (p != NULL){
		if (p->num == num_){
			q->next = p->next;
			free(p);
			length--;
			printf("删除成功！\n");
			return;
		}
		p = p->next;
		q = q->next;
	}
	if (p == NULL){
		printf("找不到要删除的学号！\n");
		return;
	}
}

void menu() {
	printf("***************************************************************\n");
	printf("| 1、 添加学生信息 |\n");
	printf("| 2、 显示学生信息 |\n");
	printf("| 3、 查找某个学生信息 |\n");
	printf("| 4、 删除指定学号的学生 |\n");
	printf("| 5、 指定的位置上插入学生信息 |\n");
	printf("****************************************************************\n");
}
int main(void) {
	int a;
	menu();
	while (1) {
		printf("请选择你要的功能:");
		scanf("%d", &a);
		switch (a){
		case 0:return 0;
		case 1:
			creat();
			menu();
			break;
		case 2:
			if (head)
			{
				show();
				menu();
			}
			else
			{
				printf("学生信息为空，请先建立学生信息！\n");
				menu();
			}
			break;
		case 3:
			if (head) {
				numsearch();
				menu();
			}
			else
			{
				printf("学生信息为空，请先建立学生信息！\n");
				menu();
			}
			break;
		case 4:
			if (head)
			{
				Delete();
				menu();

			}
			else
			{
				printf("学生信息为空，请先建立学生信息！\n");
				menu();
			}
		break;
		case 5:
			if (head)
			{
				insert();
				menu();
			}
			else
			{
				printf("学生信息为空，请先建立学生信息！\n");
				menu();
			}
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}