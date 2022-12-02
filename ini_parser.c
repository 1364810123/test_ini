#include <stdio.h>
#include <stdlib.h>
#include "iniparser.h"
#include "dictionary.h"
#include <unistd.h>
#include <getopt.h>


int get_parser(char *title, char *key, char *filename){
	printf("查询信息！！！\n");
	int ret = 0;
	dictionary      *ini = NULL;
	const char *str;
	char input_file[100];
    ini = iniparser_load(filename); //打开INI文件，解析dictionary对象并返回(分配内存)dictionary对象

    if( ini == NULL ){
        return -1; 
	}
	sprintf(input_file, "%s:%s", title, key);
	//printf("输入的元素：%s\n",input_file);
	//printf("查询的结果为 : %s \n", dictionary_get(ini, input_file, "NULL"));  
	str = dictionary_get(ini, input_file, "NULL");
	printf("查询的结果为 : %s \n", str);
	ret = strcmp(str, "NULL");
	//printf("ret = %d",ret);
	if(ret == -1){
		return 0;
	}else{
		return -1;
	}
	

}


int set_parser(char *title, char *key, char *val, char *filename){
	printf("修改信息！！！\n");
	int ret = 0;
	FILE            *fp = NULL; 
	dictionary      *ini = NULL;
	//char *input_file;
	char input_file[100];
    ini = iniparser_load(filename); //打开INI文件，解析dictionary对象并返回(分配内存)dictionary对象

    if( ini == NULL ){
        return -1; 
	}
	sprintf(input_file, "%s:%s", title, key);
	printf("输入的元素：%s\n",input_file);
	ret = dictionary_set(ini, input_file, val); 

	fp              = fopen(filename, "w");
    iniparser_dump_ini(ini, fp);// 保存到文件中
    fclose(fp);
	if(ret == 0){
		return 0;
	}else{
		return -1;
	}
}

int add_parser(char *title, char *key, char *val, char *filename){
	printf("增加信息！！！\n");
	int ret = 0;
	FILE            *fp = NULL; 
	dictionary      *ini = NULL;
	//char *input_file;
	char input_file[100];
    ini = iniparser_load(filename); //打开INI文件，解析dictionary对象并返回(分配内存)dictionary对象

    if( ini == NULL ){
        return -1; 
	}
	sprintf(input_file, "%s:%s", title, key);
	//printf("输入的元素：%s\n",input_file);
	iniparser_set(ini, input_file, val); 

	fp              = fopen(filename, "w");
    iniparser_dump_ini(ini, fp);// 保存到文件中
    fclose(fp);
	if(ret == 0){
		return 0;
	}else{
		return -1;
	}
}


int delete_parser(char *title, char *key, char *filename){
	printf("删除信息！！！\n");
	int ret = 0;
	FILE            *fp = NULL; 
	dictionary      *ini = NULL;
	//char *input_file;
	char input_file[100];
    ini = iniparser_load(filename); //打开INI文件，解析dictionary对象并返回(分配内存)dictionary对象

    if( ini == NULL ){
        return -1; 
	}
	sprintf(input_file, "%s:%s", title, key);
	printf("输入的元素：%s\n",input_file);
	iniparser_unset(ini, input_file); 
	fp              = fopen(filename, "w");
    iniparser_dump_ini(ini, fp);// 保存到文件中
    fclose(fp);
	if(ret == 0){
		return 0;
	}else{
		return -1;
	}
}