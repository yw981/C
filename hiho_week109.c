#include <stdio.h>
#include <stdlib.h>

int cost;

struct Tree {
	int p;
	int q;
	struct Tree * left;
	struct Tree * right;
};

void traversal(struct Tree * tree){	
	if(tree!=NULL) {
		cost -= tree->p;
		printf("p %d q %d\n",tree->p,tree->q);		
		if(tree->left!=NULL) traversal(tree->left);
		cost += tree->q;
		if(tree->right!=NULL) traversal(tree->right);
	}
	
}

/*
4
2 1
4 3
2 1
2 1
1 2
1 3
3 4
*/

int main()
{
	FILE * fp = fopen("h109.txt","r");
	struct Tree * tree;
	int n,i,from,to;
	cost=0;
	fscanf(fp,"%d",&n);
	tree = (struct Tree *) malloc(n*sizeof(struct Tree));
	for(i=0;i<n;i++){
		fscanf(fp,"%d%d",&tree[i].p,&tree[i].q);
		tree[i].left=tree[i].right=NULL;
	}
	for(i=0;i<n-1;i++){
		fscanf(fp,"%d%d",&from,&to);
		from--;
		to--;
		if(tree[from].left==NULL) tree[from].left=&tree[to];
		else tree[from].right=&tree[to];
	}
	//printf("tree node %d\n",tree->left->val);
    traversal(tree);
	//for(i=0;i<n;i++){
	//	printf("tree : %d %d\n",tree[i].p,tree[i].q);
	//}
	return 0;
}