#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _zend_sring {
    // 指针都和操作系统有关，在32位是4个字节，在64位是8个字节
    // int都是4个字节,变化的是long
    size_t len;  // size_t 打印是lu
    char *val;   // *val和val[1] 两种形式，虽然都是指针，指向一个字符串，
                 // 但是val[1]内存空间已经预设了是1个内存，不能超；而
    //char val[1];
} zend_string;

#define ZVAL(zstr) zstr->val

#define Z_L(i) INT64_C(i)
int main() {
    printf("%llu\n", Z_L(10));

    size_t res = 3 >> 1;
    printf("%zu\n", res);

    // 指针可以是个串，可以是个数组,或者是&变量
    char *s = "hello world";
    // 打印出整个字符串
    printf("%s\n", s);
    // 
    printf("%c\n", *s);
    printf("%p\n", s);

    //char s2[1];
    char *s3 = "php";
    char *pointer;
    printf("%lu\n", sizeof(pointer));
    printf("%lu\n", sizeof(s3));
    printf("%lu\n", sizeof(zend_string));
    zend_string *s2 = (zend_string *)malloc(3);
    printf("%lu\n", sizeof(s2));
    s2->val = s3;
    //memcpy(s2->val, s3, 3);
    printf("%s\n", s2->val);

    
   // int test[1];
   // int test2[3] = {1,2,3};
    //val = {1,2,3};
   // memcpy(test,test2,3);
   // test[4] = '\0';

    int val[2] = {2,4};
    // 数组名是指针,指向第一个元素的地址
    printf("%p\n", val);
    printf("%p\n", val + 1);
    // val[i],c会转换成*(val + i) 
    // note : * 的优先级高于运算符
    printf("%d\n", *val + 1); // *val 是2 ，+1 = 3
    printf("%d\n", *(val + 1));
    printf("%d\n", *(val + 1));

    // 指针 -- right--
    int x = 1, y = 2;
    int *ip;

    ip = &x;
     *ip = 3;
     // &x是内存地址，变成了指针
     printf("%p\n", &x);
     // ip是内存地址 ,是指针，可以++
     printf("%p\n", ip); 
     // *ip是内存地址的内容
     printf("%d\n", *ip);
     printf("%d\n", x);
    // 指针 -- right--end---

    // char val[] 是字符串变量，可以初始化，可以重新赋值
    // char val[1] 是字符串常量，只可以初始化，不可以赋值
//    char val[] = "b";
//    val[0] = "a";
//    printf("%s\n", val);
    //int str[] = '0xA4000H';
    //printf("%d",str);
    //printf("%c", *str);


    //int *p[3] = {1,2,3};
    int a[3] = {1,12,13};
    int *p;

    p = a;
    *p = a[1];
    int *next = p + 1;
    printf("%p\n",next);
    printf("%d\n",*next);
    //int a = 1;
    // different gcc ,have a little difference,mac: %lu,linux: %d
    //printf("%lu", sizeof(a));
    printf("%d\n", *p + 1);
}
