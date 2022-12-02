#include "iniparser.h"
#include "dictionary.h"
#include "ini_parser.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>



static const struct option long_options[] =
{
	{.name = "help",			.has_arg = 0,	.val = 'h'},
	{.name = "cmd",				.has_arg = 1,	.val = 'c'},
	{.name = "first_title",			.has_arg = 1,	.val = 'a'},
	{.name = "second_title", 		.has_arg = 1,	.val = 'b'},
	{.name = "filename",			.has_arg = 1,	.val = 'f'},
	{.name = "data",			.has_arg = 1,	.val = 'd'},
	{0}
};

static const char options[] = "hc:a:b:f:d:";

/**
 *	usage-打印工具支持的命令及使用方法
 * */
void usage(void)
{
	printf("帮助:\n"
		"配置文件结构:\n"
		"**********************************\n"
		"[score]\n"
		"s1 = 100\n"
		"s2 = 200\n"
		"**********************************\n"
		"参数说明:\n"
		"-c:	选择进行解析或修改; 0->解析;	1->修改.\n"
		"-a:	表示一级目录,如配置文件结构中的 name \n"
		"-b:	表示二级目录,如配置文件结构中的 s1 \n"
		"-f:	表示配置文件路径 \n"
		"-d:	表示配置文件将要修改的内容 \n"
		"例:\n"
		"解析配置:		./process_ini -c 0 -a client -b ip -f ./conf.ini  \n"
		"修改配置:		./process_ini -c 1 -a client -b ip -f ./conf.ini -d 160.0.0.100  \n"
		"删除配置:		./process_ini -c 2 -a client -b mac -f ./conf.ini   \n"
		"添加配置:		./process_ini -c 3 -a client -b mac -f ./conf.ini -d 00:50:90:00:00:01\n"		

		);
	exit(1);/* 返回退出 */
}



int main(int argc, char *const argv[])
{
	int ret = 0;
	int opt = 0;
	int cmd = -1;
	char * first_title;
	char * second_title;
    char * filename;
	char * data;
	char buff[100];

	if (argc == 1) {
		usage();
	}

	while (1) {
		opt = getopt_long(argc, argv, options, long_options, NULL);
		if (opt == -1) {
			break;
		}
		switch (opt) {
			case 'h':
				usage();
				break;
			case 'c':
				cmd = strtol(optarg, (char **)NULL, 0);
				printf("cmd: %d\n", cmd);
				break;
			case 'a':
				first_title = optarg;
				printf("first_title: %s\n", first_title);
				break;
			case 'b':
				second_title = optarg;
				printf("second_title: %s\n", second_title);
				break;
			case 'f':
				filename = optarg;
				printf("filename: %s\n", filename);
				break;
			case 'd':
				data = optarg;
				printf("data: %s\n", data);
				break;

			default:
				break;

		}
	}

		if(cmd == 1){
			printf("配置文件修改\n");
			ret = set_parser(first_title, second_title, data, filename);
			if(ret!=0){
				printf("修改配置文件失败!!!\n");
			}else{
				printf("修改配置文件成功!!!\n");
			}
		}else if (cmd == 0){
			printf("配置文件解析\n");
			ret = get_parser(first_title, second_title, filename);
			if(ret!=0){
				printf("解析失败!!!ret = %d\n",ret);
			}else{
				printf("解析成功!!!ret = %d\n",ret);
			}
			
		}else if(cmd == 2){
			printf("配置文件删除！！！\n");
			ret = delete_parser(first_title, second_title, filename);
			if(ret!=0){
				printf("批量配置失败!!!\n");
			}else{
				printf("批量配置成功!!!n");
			}
		}else if(cmd == 3){
			printf("配置文件增加！！！\n");
			ret = add_parser(first_title, second_title, data, filename);
		}else{
			printf("请重新输入！！！\n");
		}
	return ret;
}





