#include <stdio.h>
/*
Author: Gehan Essam Eid
*/
/*********  Project of Embedia Power Matrix Which is a Matrix with at Least 3 Rows By 3 Columns in This Matrix ,
              Each Eelement Should Equal The Number Below it Raised to The Power of The Number Above it, 
              The Numbers in Matrix Are Represented as Characters Enclosed in Single Quotation Marks *******************/

/**************************PROTOTYPE OF FUNCTIONS***************************/
int calculate_power(int base,int exponet);
int char_to_int(char *c);
int Embedia_power_matrix(char matrix[][3][15],int rows,int Columns);





int main()
{
	/****************	TEST CASE 1   *****************/
	char matrix1[3][3][15]={
		{"3","2","2"},
		{"8","9","25"},
		{"2","3","5"}
	};
	
	/****************	CHEACK MATRIX   *****************/
	if(Embedia_power_matrix(matrix1,3,3)){
	
	/*******************  IF AGIVEN MATRIX IS an EMBEDIA POWER MATRIX  *****************/
     printf("Test Case 1:\n Embedia Power Matrix\n");	
	} 
	
	else{
	/*******************  IF AGIVEN MATRIX IS NOT  an EMBEDIA POWER MATRIX  *****************/
	printf(" Test Case 1:\n Not an Embedia Power Matrix\n");
	}
	
	/****************	TEST CASE 2   *****************/
	char matrix2[3][3][15]={
		{"1","3","5"},
		{"3","7","11"},
		{"5","11","17"}
	};
	
	if(Embedia_power_matrix(matrix2,3,3)){
	
     printf("Test Case 2:\n Embedia Power Matrix\n");	
	} 
	
	else{
	
	printf("Test Case 2:\n Not an Embedia Power Matrix\n");
	}
	
	
	/****************	TEST CASE 3   *****************/
	char matrix3[3][3][15]={
		{"3","4","2"},
		{"512","256","49"},
		{"8","4","7"}
	};
	
	if(Embedia_power_matrix(matrix3,3,3)){
	
     printf("Test Case 3:\n Embedia Power Matrix\\n");	
	} 
	
	else{
	
	printf(" Test Case 3:\n Not an Embedia Power Matrix");
	}
	
	return 0;
} 



 /**************FUNCTION TO CALCULATE HTE POWER FOR GIVEN(BASE , EXPONENT)******************/
 int calculate_power(int base,int exponent)
{
	int result=1;
	for(int i=0;i<exponent;i++)
	{
		result *=base;
		
	}
	return result;
}

/*********************FUNCTION TO CONVERT CHARACTER TO INTEGER*************************/

  int char_to_int(char *c)
{ 
	int result=0;
	signed int sign=1;
	int i=0;
	
	
	/******************** cheack negative Sign***********************/
	if(c[0]=='-'){
		sign=-1;
		i=1;
	}
		while(c[i]!='\0'){
			int digit=c[i] - '0';
			result=result*10 + digit;
			i++;
			
			
		} 
		result*=sign;
		return result;
}
	

/*********************FUNCTION TO DETERMINE IF AGIVEN MATRIX IS an EMBEDIA POWER MATRIX********************/
int Embedia_power_matrix(char matrix[][3][15],int rows,int columns)
{
	
	/****************************  CREAT VARIABLE**************************/
	int count_1  ;
	int count_2  ; 
	int below  =0;
	int above  =0;
	int current=0;
	int expected=0;
	/*********************** FOR LOOP TO CHEACK MATRIX*********************/
	
	for (count_1=1;count_1<rows-1;count_1++)
	{
		for(count_2=0;count_2<columns;count_2++)
		{ 
	/********************** BELOW VALUE OF MATRIX  **************************/
			below=char_to_int(matrix[count_1 + 1][count_2]);
	/********************** ABOVE VALUE OF MATRIX  **************************/
			above=char_to_int(matrix[count_1 - 1][count_2]);
	/********************** CURRENT VALUE OF MATRIX **************************/
		    current=char_to_int(matrix[count_1]  [count_2]);
			/**********************REPRESENT EXPECTED VALUE TO FUNCTION OF CALCULAT POWER **************************/
			expected=calculate_power(below,above);
			
			/**********************CHEACK CURRENT VALUE IF NOT EQUAL EXPECTED VALUE**************************/
			if(current!=expected)
			{
			return 0;
			}
		}
	}
	return 1;
} 