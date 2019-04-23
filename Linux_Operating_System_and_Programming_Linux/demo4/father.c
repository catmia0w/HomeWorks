main()
{
static char string[] = "Parent is using pipe write." ;
int len;

		len = sizeof(string) ;
        write(l, string, len) ;			/* 将string中的内容写入管道中 */
        printf("parent, parent, parent \n \n \n") ;
        exit(0) ;
}
