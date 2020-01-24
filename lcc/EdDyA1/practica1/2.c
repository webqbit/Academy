#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int string_len(char* str){
	int i = 0;
	for(; str[i] != '\0' ; i++);
	return i;
}

void string_reverse(char* str){
	int j = string_len(str)-1;
	int i = 0;
	for(; i < j ; i++, j--){
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}

}

int string_concat(char* str1, char* str2, int max){
	int ind = string_len(str1);
	int i;

	for(i = 0 ; ind + i < max ; i++){
		str1[i+ind] = str2[i];
		if(str2[i] == '\0')
			return i;
	}
	return i;
}

int max(int a, int b){
	return (a > b) ? a : b;
}
int string_compare(char* str1, char*str2){
	int i = 0;
	int a = max(string_len(str1), string_len(str2));
	for(; i < a ; i++){
	 	if(str1[i] < str2[i])
	 		return -1;
	 	if(str1[i] > str2[i])
	 		return 1;
	 }
	return 0;
}

int string_compare2(char* str1, char* str2){
	int max = string_len(str2);
	int i = 0;
	for(; i < max ; i++)
		if(str1[i] != str2[i])
			return 0;
	return 1;
}
int string_subcadena(char* str1, char*str2){
	int max1 = string_len(str1);
	int i = 0;

	for(; i < max1 ; i++)
		if(str1[i] == str2[0] && string_compare2(str1+i, str2))
			return i;
	return -1;
}

void string_concat2(char* str1, char* str2){
	int i = 0;
	int max = string_len(str1);
	for(; str2[i] != '\0' ; i++)
		str1[max + i] = str2[i];
	str1[max + i] = str2[i];
}

void string_unir(char* arregloStrings[], int capacidad, char* sep, char* res){
	int i = 0;

	for(; i < capacidad ; i++){
		string_concat2(res, arregloStrings[i]);
		string_concat2(res, sep);
	}
	int max_res = string_len(res);
	int max_sep = string_len(sep);
	res[max_res - max_sep] = '\0';
}


int main(){
	char* arr[] = {"hola", "bb", "ya", "que"};
	char sep[] = "---";
	char res[100];
	res[0] = '\0';

	string_unir(arr, 4, sep, res);
	printf("%s\n",res);

	return 0;
}
