#include <stdio.h>

#include <string.h>

#define STRSIZE 100



int *frequency(char *string);

int main( )

{

    char string[]= "Life is a journey, not the destination, but the scenery along the should be and the mood at the view.";

    int sum=strlen(string);//字符总数

    int *array = frequency(string);

    

    for (int i = 0; i < '~' - '!'; i++)

        if (array[i] != 0)

            printf("%c 出现%d 次, 频度 = %4.2lf%%\n", i + '!', array[i], ((double)array[i] / sum) * 100); 



    return 0;

}

//计算频度核心代码

int *frequency(char *string)

{

    static int array['~' - '!'] = {0}; //must be initialized, or the memory will full of rubbish value

    char ch;

    int i = 0;



    while (string[i]!='\0')     //请在此处补充代码
    {
        if (string[i] >= '!' && string[i] < '~')
        {
            array[string[i] - '!']++;
        }
        i++;
    }

    return array;

}