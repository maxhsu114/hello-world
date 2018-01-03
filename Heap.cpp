#include <stdio.h> 
#include <stdlib.h> 
#define LEN 10
#define OFFSET 1
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

void heapSort(int*, int len, int(*)(int, int));
void heapTree(int*, int, int(*)(int, int)); 
void selectFromHeap(int*, int, int(*)(int, int)); 

void bubbleLeaf(int*, int, int(*)(int, int));
int isBubbleable(int*, int, int, int(*)(int, int));

void bubbleRoot(int*, int, int(*)(int, int));
int idxFromChilds(int*, int, int, int(*)(int, int));
int isRightLeafSuitable(int*, int, int, int(*)(int, int));

void print(int*, int len);
int ascending(int, int);
int descending(int, int);

int x;

int main(void) {
 
 
    int num[LEN] = {10, 9, 1, 2, 5, 3, 8, 7, 12, 11};
    heapSort(num, LEN, descending); 
    print(num, LEN);
    
    
    
    int num1[LEN] = {10, 9, 1, 2, 5, 3, 8, 7, 12, 11};
    heapSort(num1, LEN, ascending); 
    print(num1, LEN);


    system("PAUSE");

    return 0; 
}

void heapSort(int* num, int len, int(*compar)(int, int)) 
{
    heapTree(num, len, compar);				//"插入" (Insert)，創建一個(最大OR最小)堆 
    selectFromHeap(num, len, compar); 		//"刪除" (Delete)，將第一個元素和最後一個元素交換，把最後一個元素視為"已排序" 排除在堆之外 
}

void heapTree(int* num, int len, int(*compar)(int, int)) 
{ 
    int i, end;
    for(i = 1, end = len + 1; i < end; i++) 
	{ 
		bubbleLeaf(num, i, compar); 
	}
}

void selectFromHeap(int* num, int len, int(*comp)(int, int)) 		 
{
    int end;
    for(end = len; end > OFFSET; end--) 
	{
        SWAP(num[1 - OFFSET], num[end - OFFSET]);				//根和最後一個元素交換
        bubbleRoot(num, end, comp);
    }
}

void bubbleLeaf(int* num, int eleIdx, int(*compar)(int, int)) 
{
    int childIdx, parentIdx;
    for(childIdx = eleIdx, parentIdx = eleIdx / 2;
        isBubbleable(num, childIdx, parentIdx, compar);		//判斷 
        childIdx = parentIdx, parentIdx = childIdx / 2) 	//往根判斷直到把剛加入的子截點加入倒符合最大或最小堆樹  註：原本子截點移向原本的父截點；原本的父截點在往根移動 
	{
        SWAP(num[parentIdx - OFFSET], num[childIdx - OFFSET]); 	//滿足判斷條件  父子截點值交換  註：因為是int型態所以在求步截點時不管是左或右子截點，右截點不用-1直接除取整數(int)值會相等 
//=========================MY_TEXT=============================================================================================================================	    
		
		if(num[parentIdx - OFFSET]<num[childIdx - OFFSET])			//最小堆要用排序
		{
			printf("1NO.%d	parentIdx %d:%d	childIdx %d:%d  UnSWAP\n",eleIdx,parentIdx,num[parentIdx - OFFSET],childIdx,num[childIdx - OFFSET]);	
		} 
		else			//最大堆要用排序
		{
			printf("2NO.%d	parentIdx %d:%d	childIdx %d:%d  UnSWAP\n",eleIdx,parentIdx,num[parentIdx - OFFSET],childIdx,num[childIdx - OFFSET]);	
		} 
		
//=========================MY_TEXT=============================================================================================================================		
	}
}

int isBubbleable(int* num, int childIdx,int parentIdx, int(*compar)(int, int))                
{
    return childIdx > OFFSET && compar(num[parentIdx - OFFSET], num[childIdx - OFFSET]) < 0;
	//判斷此次加入的子截點是否符合最大(小)堆的需求	
	//childIdx > OFFSET是為了避免在還沒有父截點和子截點的關西成立前進來 
}

void bubbleRoot(int* num, int end, int(*comp)(int, int)) 
{
    int parentIdx, childIdx;
    for(parentIdx = 0 + OFFSET, 
        childIdx = idxFromChilds(num, parentIdx, end, comp);
        childIdx < end && 
        comp(num[childIdx - OFFSET], num[parentIdx - OFFSET]) > 0; 
        parentIdx = childIdx, 
        childIdx = idxFromChilds(num, parentIdx, end, comp)) 
	{
        SWAP(num[parentIdx - OFFSET], num[childIdx - OFFSET]); 
    }    
}

int idxFromChilds(int* num, int parentIdx, int end, int(*comp)(int, int)) 
{
   int childIdx = parentIdx * 2;
   return isRightLeafSuitable(num, childIdx, end, comp) ? 
              childIdx + 1 : childIdx;
}

int isRightLeafSuitable(int* num, int childIdx, 
                        int end, int(*comp)(int, int)) 
{
    return childIdx < end - 1 && comp(num[childIdx + 1 - OFFSET], num[childIdx - OFFSET]) > 0;
}

void print(int* arr, int len) 
{
    int i;
    for(i = 0; i < len; i++) { printf("%d ", arr[i]); } 
    printf("\n");
}

int ascending(int a, int b) { return a - b; }				//會帶入compar使用 
int descending(int a, int b) { return -ascending(a, b); }	//-ascending=-(a-b)會帶入compar使用 
