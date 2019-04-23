# define STD_INPUT 0					// 定义标准输入设备描述符
# define STD_OUTPUT 1				// 定义标准输出设备描述符

int fd[2];
main()
{
static char process1[]="father",process2[]="child";
	 	  
		pipe(fd);						// 定义管道
	    pipeline(process1,process2);		// 调用自定义函数pipeline()
	    exit(1);						// 程序结束
}

pipeline(char* process1,char* process2)
{
int i;

		if ((i=fork())==-1) 					// 创建进程，失败退出
 		{
			perror("process fork error!");	
			exit(1);
		}
		if (i)
	    {
		      close(fd[0]);					// 关闭管道输入描述符
		      close(STD_OUTPUT);		// 关闭标准输出描述符1
		      dup(fd[1]);					// 指定标准输出描述符1为管道写指针
		      close(fd[1]);					// 关闭原始管道写指针
			  execl(process1, process1, 0);	// 用程序father覆盖当前程序
		      printf(" father failed.\n");		// execl()执行失败
	      }
	      else
	      {
		      close(fd[1]);					// 关闭管道输出描述符
		      close(STD_INPUT);			// 关闭标准输入描述符0
		      dup(fd[0]);					// 指定标准输入描述符0为管道读指针
		      close(fd[0]);					// 关闭原始管道读指针
		      execl(process2,process2,0);	// 用程序child覆盖当前程序
		      printf("child failed.\n");		// execl()执行失败
	      }
	      exit(2);						// 程序结束
}
