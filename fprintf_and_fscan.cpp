#include<cstdio>

int main() {
	FILE *file;

//===============寫入============================
	
    file = fopen("test.txt", "w"); 
    fprintf(file, "%s\t%d\n", "Mike", 20);
    fprintf(file, "%s\t%d\n", "Tank", 28);  
    fclose(file);
     
//===============寫入============================ 

//===============讀取============================ 

    char name[20]; 
    int age; 
    
	file = fopen("test.txt", "r"); 
    while(fscanf(file, "%s\t%d", name, &age) != EOF){ 	//只要有資料迴圈 
        char *tempName = name;  		//依序得到姓名資料
        int tempAge = age;      		//依序得到年齡資料
        printf("%s \t %d \n", name, age);	//把從文檔讀取到的值印在電腦上 
    } 
    fclose(file);
    
//===============讀取============================ 
    return 0; 
}
