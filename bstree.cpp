#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct BSTreeNode{
    ElementType data;           //关键字（数据域）
    struct BSTreeNode* lchild;  //左孩子
    struct BSTreeNode* rchild;  //右孩子
    struct BSTreeNode* parent;  //父结点
}Node, *BSTree;

/* 创建一颗二叉树 */
BSTree create_bstree(int* array, int num);

/* 向二叉树中插入新结点 */
bool insert(Node* root, int val);

/* 协助insert()例程以查找当前结点的父结点 */
bool search_bstree(BSTree root, int val, Node* parent, Node* node);

/* 先序遍历二叉树 */
void preorder_bstree(BSTree tree);

/* 中序遍历二叉树 */
void inorder_bstree(BSTree tree);

/* 后序遍历二叉树 */
void postorder_bstree(BSTree tree);

int main(){
    int num;
    BSTree root = NULL;
    printf("Please input the num of array, and the BSTree will build on it\n");
    scanf("%d", &num);
    int* array = (int*)calloc(num, sizeof(int));
    printf("Please input %d different elements: \n", num);
    for(int i=0; i<num; i++){
        scanf("%d", array+i);
    }

    printf("the elements you just input are below:\n");
    for(int i=0; i<num; i++){
        printf("%d ", *(array+i));
    }

    create_bstree(array, num);
}

BSTree create_bstree(int* array, int length){
    Node* root = NULL;
    for(int i=0; i<length; i++)
        insert(root, *(array+i));
    return root;
}

bool insert(Node* root, int val){
    Node* node;
    if(!search_bstree(root, val, NULL, node)){
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = val;
        new_node->lchild = new_node->rchild = NULL;

        if(!node)
            root = node;
        else if(val<node->data)
            node->lchild = new_node;
        else
            node->rchild = new_node;
        return true;
    }
    else
        return false;
    return false;
}

bool search_bstree(BSTree root, int val, Node* parent, Node* node){
    if(!root){
        node = parent;
        return false;
    }else{
        if(val == root->data){
            node = root;
            return true;
        }else if(val<root->data){
            return search_bstree(root->lchild, val, root, node);
        }else{
            return search_bstree(root->rchild, val, root, node);
        }
    }
}

