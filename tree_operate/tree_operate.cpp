#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int elemType;
typedef struct bNode{
	elemType data;
	struct bNode *lchild,*rchild;
}bNode,*bTree;
//建立二叉树
void creatTree(bTree *T,elemType a[],int len,int index){
	if(index >= len)
		return;
	*T = (bNode *)malloc(sizeof(bNode));
	if(*T == NULL){
		printf("空间分配失败.\n");
		exit(0);
	}
	if(a[index] == -1)
		*T = NULL;
	else{
		(*T)->data = a[index];
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		creatTree((&(*T)->lchild),a,len,2 * index + 1);
		creatTree(&((*T)->rchild),a,len,2 * index + 2);
	}
}
void preOrder(bNode *L){
	bNode *p = L;
	if(p){
		printf("%d ",p->data);
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
void inOrder(bNode *L){
	bNode *p = L;
	if(p){
		inOrder(p->lchild);
		printf("%d ",p->data);
		inOrder(p->rchild);
	}
}
void postOrder(bNode *L){
	bNode *p = L;
	if(p){
		postOrder(p->lchild);
		postOrder(p->rchild);
		printf("%d ",p->data);
	}
}
//交换左右子树
void swap(bTree *T){
	bNode *temp,*p;
	p = (*T);
	if(p){
		swap(&(p->lchild));
		swap(&(p->rchild));
		temp = p->lchild;
		p->lchild = p->rchild;
		p->rchild = temp;
	}
}
//递归求二叉树的高度
int BtDepth(bNode *T){
	int left,right;
	bNode *p = T;
	if(p == NULL)
		return 0;
	else{
		left = BtDepth(p->lchild);
		right  = BtDepth(p->rchild);
		return ((left > right ? left : right) + 1);
	}
}
//递归统计结点个数
int bTreeNode_count(bNode *T){
	int left,right;
	bNode *p = T;
	if(p == NULL)
		return 0;
	left = bTreeNode_count(p->lchild);
	right = bTreeNode_count(p->rchild);
	return (1 + left + right);
}
//递归统计叶子结点个数
int bt_leafCount(bNode *T){
	int left,right;
	bNode *p = T;
	if(p == NULL)
		return 0;
	if(p->lchild == NULL && p->rchild == NULL)
		return 1;
	left = bt_leafCount(p->lchild);
	right = bt_leafCount(p->rchild);
	return (left + right);
}
int main(){
	bTree T;
	elemType a[] = {1,2,3,4,5,6,7,-1,8,-1,-1,-1,9,-1,10};
	int len = sizeof(a)/sizeof(a[0]);
	creatTree(&T,a,len,0);
	printf("先序遍历为:\n");
	preOrder(T);
	//printf("\n");
	//printf("中序遍历为:\n");
	//inOrder(T);
	//printf("\n");
	//printf("后序遍历为:\n");
	//postOrder(T);
	printf("\n---------------------------\n");
	//swap(&T);
	//printf("先序遍历为:\n");
	//preOrder(T);
	int btDepth = BtDepth(T);
	printf("二叉树高度为  %d\n",btDepth);
	int btNode_count = bTreeNode_count(T);
	printf("二叉树结点个数为  %d\n",btNode_count);
	int bt_lCount = bt_leafCount(T);
	printf("二叉树叶结点个数为  %d\n",bt_lCount);
	system("pause");
	return 0;
}