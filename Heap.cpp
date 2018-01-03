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
    heapTree(num, len, compar);				//"���J" (Insert)�A�Ыؤ@��(�̤jOR�̤p)�� 
    selectFromHeap(num, len, compar); 		//"�R��" (Delete)�A�N�Ĥ@�Ӥ����M�̫�@�Ӥ����洫�A��̫�@�Ӥ�������"�w�Ƨ�" �ư��b�蠟�~ 
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
        SWAP(num[1 - OFFSET], num[end - OFFSET]);				//�کM�̫�@�Ӥ����洫
        bubbleRoot(num, end, comp);
    }
}

void bubbleLeaf(int* num, int eleIdx, int(*compar)(int, int)) 
{
    int childIdx, parentIdx;
    for(childIdx = eleIdx, parentIdx = eleIdx / 2;
        isBubbleable(num, childIdx, parentIdx, compar);		//�P�_ 
        childIdx = parentIdx, parentIdx = childIdx / 2) 	//���ڧP�_������[�J���l�I�I�[�J�˲ŦX�̤j�γ̤p���  ���G�쥻�l�I�I���V�쥻�����I�I�F�쥻�����I�I�b���ڲ��� 
	{
        SWAP(num[parentIdx - OFFSET], num[childIdx - OFFSET]); 	//�����P�_����  ���l�I�I�ȥ洫  ���G�]���Oint���A�ҥH�b�D�B�I�I�ɤ��ެO���Υk�l�I�I�A�k�I�I����-1�����������(int)�ȷ|�۵� 
//=========================MY_TEXT=============================================================================================================================	    
		
		if(num[parentIdx - OFFSET]<num[childIdx - OFFSET])			//�̤p��n�αƧ�
		{
			printf("1NO.%d	parentIdx %d:%d	childIdx %d:%d  UnSWAP\n",eleIdx,parentIdx,num[parentIdx - OFFSET],childIdx,num[childIdx - OFFSET]);	
		} 
		else			//�̤j��n�αƧ�
		{
			printf("2NO.%d	parentIdx %d:%d	childIdx %d:%d  UnSWAP\n",eleIdx,parentIdx,num[parentIdx - OFFSET],childIdx,num[childIdx - OFFSET]);	
		} 
		
//=========================MY_TEXT=============================================================================================================================		
	}
}

int isBubbleable(int* num, int childIdx,int parentIdx, int(*compar)(int, int))                
{
    return childIdx > OFFSET && compar(num[parentIdx - OFFSET], num[childIdx - OFFSET]) < 0;
	//�P�_�����[�J���l�I�I�O�_�ŦX�̤j(�p)�諸�ݨD	
	//childIdx > OFFSET�O���F�קK�b�٨S�����I�I�M�l�I�I�����覨�߫e�i�� 
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

int ascending(int a, int b) { return a - b; }				//�|�a�Jcompar�ϥ� 
int descending(int a, int b) { return -ascending(a, b); }	//-ascending=-(a-b)�|�a�Jcompar�ϥ� 
