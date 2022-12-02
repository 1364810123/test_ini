#include <stdio.h>
#include <stdlib.h>
#include "iniparser.h"
#include "dictionary.h"
#include <unistd.h>
#include <getopt.h>

/* 
 * 函数名：         get_parser 
 * 入口参数：       title 
 *                      配置文件中一级目录标识 
 *                  key 
 *                      配置文件中二级目录标识  
 *                  filename 
 *                      要读取的文件路径 
 * 返回值：         找到需要查的值则返回0 
 *                 否则返回-1 
 */  
int get_parser(char *title, char *key, char *filename);

/* 
 * 函数名：         set_parser 
 * 入口参数：       title 
 *                      配置文件中一级目录标识 
 *                  key 
 *                      配置文件中二级目录标识  
 *                  filename 
 *                      要读取的文件路径
 *		    		val
 *						变更后的值
 * 返回值：         找到需要查的值则返回0 
 *                 否则返回-1 
 */  

int set_parser(char *title, char *key, char *val, char *filename);



/* 
 * 函数名：         delete_parser 
 * 入口参数：       title 
 *                      配置文件中一级目录标识 
 *                  key 
 *                      配置文件中二级目录标识  
 *                  filename 
 *                      要读取的文件路径 
 * 返回值：         找到需要查的值则返回0 
 *                 否则返回-1 
 */  
int delete_parser(char *title, char *key, char *filename);

/* 
 * 函数名：         set_parser 
 * 入口参数：       title 
 *                      配置文件中一级目录标识 
 *                  key 
 *                      配置文件中二级目录标识  
 *                  filename 
 *                      要读取的文件路径
 *		    		val
 *						增加的值
 * 返回值：         找到需要查的值则返回0 
 *                 否则返回-1 
 */  

int add_parser(char *title, char *key, char *val, char *filename);




