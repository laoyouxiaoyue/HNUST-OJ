#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

typedef char TElemType;
//�������Ķ�������洢��ʾ
typedef struct BiTNode {
   TElemType data;                      //���������
   struct BiTNode *lchild, *rchild; //���Һ���ָ��
} BiTNode, *BiTree;

//������������pre[pre_low..pre_low+len-1]����������in[in_low..in_low+len-1]����t
void BuildTree(BiTree& t, char pre[], int pre_low, char in[], int in_low, int len)
{
    /****�ڴ�������ɴ���************/
    if(len==0)t=NULL;
	if(len!=0)
	{
		char ch=pre[pre_low];
		int i;
		for(i=in_low;i<len+in_low;i++)
		{
			if(in[i]==ch)break;
		}
		i-=in_low;
		t=new BiTNode;
		t->data=ch;
		BuildTree(t->lchild,pre,pre_low+1,in,in_low,i);
		BuildTree(t->rchild,pre,pre_low+i+1,in,in_low+i+1,len-i-1);
	}

   /*********************************/
}
// ��������ĵݹ��㷨
void PostOrderTraverse(BiTree t)
{
   /****�ڴ�������ɴ���************/
	if(t)
	{
		PostOrderTraverse(t->lchild);
				PostOrderTraverse(t->rchild);
		printf("%c",t->data);
	
	}

   /*********************************/
}

void DestroyBitree(BiTree& t)
{
   /****�ڴ�������ɴ���************/
	delete t;

   /*********************************/
}

int main()
{
   char pre[30], in[30];
   BiTree t = NULL;
   while(cin >> pre) {
      cin >> in;
      BuildTree(t, pre, 0, in, 0, strlen(in));
      PostOrderTraverse(t);
      DestroyBitree(t);
      cout << endl;
   }
}


