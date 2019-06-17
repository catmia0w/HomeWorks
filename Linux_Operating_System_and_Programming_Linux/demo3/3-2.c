//程序清单 3-2
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    
    char c; 
    int in, out; 
    int nread;

    in = open("file.in", O_RDONLY); 
    out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
//将注释打开，并将两条语句的后一句注释掉，重新编译执行。
    char block[1024]; 
    while((nread = read(in,block,sizeof(block))) > 0)
        write(out,block,nread);
//    while((nread = read(in,&c,sizeof(c))) > 0)
  //      write(out,&c,nread);

}
