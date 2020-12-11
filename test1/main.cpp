#include <iostream>
using namespace std;

//
//char **argv 与char *argv[]
//1、char **argv
//
//分析：argv是一个指针变量，argv的指向（*argv）是char *，也就是argv指向的也是一个指针 ；
//
//*argv的指向（**argv）是char。
//
//
//
//2、char *argv[]
//
//分析：首先argv是一个数组，数组里面的元素是指针变量（char *），数组里元素指向的是char
//在实际的代码运行中　　char *argv[]代表的是除了　可执行的程序名字之外的参数个数　　
// 每一个argv[1],argv[2].....一个就是一个ｃｈａｒ数组，可以理解为一个字符串　
// 比如　　　./a.out  xxx.txt yy.txt   xxx.txt yyy.txt 就是包含在char *argv[]里面

//argc代表程序参数的个数　　　比如执行命令　./a.out   "test.txt"　这里面包含有两个参数
int   testmain(int argc, char * argv)
{

    FILE *fp;

    char ch;

    unsigned char chr1,chrh;

    unsigned int count=0,checksum=0,chr=0;

    unsigned long sum=0;

    cout << "writen by   :陈国蓉和陈凯歌\n";
    cout << "purpose for :数据校验和\n";
    cout << "Now start data verifying program!!!\n";
    cout <<"=============================\n";

    if((fp=fopen(argv,"r"))==NULL)

    {
        printf("file cannot be opened!(文件不能被打开或者文件地址有误或者文件内容为空)");

        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long inputFileLength = ftell(fp);//ｆｔｅｌｌ统计当前指针位置距离文件的首个字符的巨鹿
    printf("input file length: %ld\n", inputFileLength);
    fseek(fp, 0, SEEK_SET);

    while(1)

    {

        long inputFileLength = ftell(fp);

        if((ch=fgetc(fp))!=EOF)

        {
            count++;


            if(ch!=' ')

            {

                if(ch>='0'&&ch<='9')

                    ch-='0';

                else

                {

                    if(ch>='a'&&ch<='f')

                        ch=ch-'a'+10;

                    else

                    {

                        if(ch>='A'&&ch<='F')

                            ch=ch-'A'+10;

                    }

                }

                if(count%2==1)

                    chrh=ch<<4;

                else

                {

                    chr1=ch&0x0f;

                    chr=chrh|chr1;

                    if(count%4==2)

                        sum+=chr<<8;

                    else

                    {

                        if(count%4==0)

                            sum+=chr;

                    }

                    printf("%x--%1x    ",chr,sum);

                }

            }

            else

                count--;

        }

        else break;


    }

    if(sum>>16)

        checksum=~(long(sum>>16)+long(sum&0x0000ffff));

    checksum=checksum&0x0000ffff;

    printf("\nCheckSum:  %x",checksum);

    fclose(fp);
    return 0;

}



int main(){
    char  a[]="/home/ckg/Desktop/xxx.txt";
    testmain(2, a);

}
//jintian laoshi zhen sb