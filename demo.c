#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//typedef struct _zend_string     zend_string;

typedef struct _zend_string {
        char              val[1];
} zend_string;
#define ZSTR_VAL(zstr)  (zstr)->val
#define offsetof __builtin_offsetof
#define XtOffsetOf(s_type, field) offsetof(s_type, field)
#define _ZSTR_HEADER_SIZE XtOffsetOf(zend_string, val)
#define _ZSTR_STRUCT_SIZE(len) (_ZSTR_HEADER_SIZE + len + 1)

zend_string *zend_string_alloc(size_t len)
{

     zend_string *ret = (zend_string *)malloc(_ZSTR_STRUCT_SIZE(len));                          

        return ret;                                                                                   
}
zend_string *zend_string_init(const char *str, size_t len){
        zend_string *ret = zend_string_alloc(len);
        memcpy(ZSTR_VAL(ret), str, len);
        ZSTR_VAL(ret)[len] = '\0';
        return ret;
}
int main(){
        zend_string* zs = zend_string_init("asd", 3);
        printf("%s\n",ZSTR_VAL(zs));
        return 0;

}
