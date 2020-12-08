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
int   main(int argc, char * argv[])
{

    FILE *fp;

    char ch;

    unsigned char chr1,chrh;

    unsigned int count=0,checksum=0,chr=0;

    unsigned long sum=0;

    if(argc!=2)
    {
        printf("please input command:可执行文件名+读取的文件名 ");
        return 0;
    }
//    文件指针名=fopen（文件名,使用文件方式）;
//    “文件指针名”必须是被声明为FILE 类型的指针变量；
//    “文件名”是被打开文件的文件名；
//    “使用文件方式”是指文件的类型和操作要求；
//    "r" = "rt"
//    打开一个文本文件，文件必须存在，只允许读
//    r(read): 只读
//    w(write): 只写
//    a(append): 追加
//    t(text): 文本文件，可省略不写
//    b(binary): 二进制文件


//    成功：它返回一个指向FILE结构的指针，该结构代表这个新创建的流
//            (文件顺利打开后，指向该流的文件指针就会被返回）
//    失败：它就会返回一个空指针，errno会提示问题的性质
//    （如果文件打开失败，则返回NULL，并把错误代码存在errno中）

//    ofstream outfile;
//    outfile.open(s, ios::out);
    if((fp=fopen(argv[1],"r"))==NULL)

    {

        printf("file cannot be opened!");

        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long inputFileLength = ftell(fp);
    printf("input file length: %ld\n", inputFileLength);
    fseek(fp, 0, SEEK_SET);

    printf("Output Type:data--sum\n");


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
    printf("\n============================");
    printf("\ncount:  %d",count);
    printf("\n============================");
    return 0;

}



//int main(){
//    char  a[]="/home/ckg/Desktop/testfile.txt";
////    char *b=a;
////    einterpret_cast<type-id> (expression)
////    type-id 必须是一个指针、引用、算术类型、函数指针或者成员指针。
////    它可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针（
////    先把一个指针转换成一个整数，再把该整数转换成原类型的指针，还可以得到原先的指针值）。
////    mychar= reinterpret_cast<char **>(a);
//    testmain(2,a);
//
//}