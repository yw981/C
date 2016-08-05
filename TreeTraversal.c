#include <stdio.h>
#include <stdlib.h>

struct Tree {
	int val;
	struct Tree * left;
	struct Tree * right;
};

void pre_order_traversal(struct Tree * tree){	
	if(tree!=NULL) {
		printf("visit %d\n",tree->val);		
		if(tree->left!=NULL) pre_order_traversal(tree->left);
		if(tree->right!=NULL) pre_order_traversal(tree->right);
	}
	
}

void in_order_traversal(struct Tree * tree){
	if(tree!=NULL) {			
		if(tree->left!=NULL) in_order_traversal(tree->left);
		printf("visit %d\n",tree->val);	
		if(tree->right!=NULL) in_order_traversal(tree->right);
	}
}

void post_order_traversal(struct Tree * tree){
	if(tree!=NULL) {			
		if(tree->left!=NULL) post_order_traversal(tree->left);		
		if(tree->right!=NULL) post_order_traversal(tree->right);
		printf("visit %d\n",tree->val);	
	}
}

int main()
{
	FILE * fp = fopen("tree.txt","r");
	struct Tree * tree;
	int n,i,from,to;
	fscanf(fp,"%d",&n);
	tree = (struct Tree *) malloc(n*sizeof(struct Tree));
	for(i=0;i<n;i++){
		tree[i].val=i+1;
		tree[i].left=tree[i].right=NULL;
	}
	for(i=0;i<n-1;i++){
		fscanf(fp,"%d%d",&from,&to);
		from--;
		to--;
		if(tree[from].left==NULL) tree[from].left=&tree[to];
		else tree[from].right=&tree[to];
	}

	pre_order_traversal(tree);
	//in_order_traversal(tree);
	//post_order_traversal(tree);
	//for(i=0;i<n;i++){
	//	printf("tree : %d %d\n",tree[i].p,tree[i].q);
	//}
	return 0;
}