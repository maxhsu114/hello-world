#include<cstdio>

int main() {
	FILE *file;

//===============�g�J============================
	
    file = fopen("test.txt", "w"); 
    fprintf(file, "%s\t%d\n", "Mike", 20);
    fprintf(file, "%s\t%d\n", "Tank", 28);  
    fclose(file);
     
//===============�g�J============================ 

//===============Ū��============================ 

    char name[20]; 
    int age; 
    
	file = fopen("test.txt", "r"); 
    while(fscanf(file, "%s\t%d", name, &age) != EOF){ 	//�u�n����ưj�� 
        char *tempName = name;  		//�̧Ǳo��m�W���
        int tempAge = age;      		//�̧Ǳo��~�ָ��
        printf("%s \t %d \n", name, age);	//��q����Ū���쪺�ȦL�b�q���W 
    } 
    fclose(file);
    
//===============Ū��============================ 
    return 0; 
}
