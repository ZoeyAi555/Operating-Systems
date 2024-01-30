//memory alloc
char str1[] = {'c','h','i','n','a'}; //chinayrhhgshehbn x00
char str2[]= "china"; // china x00
char* str3="china"; //read only
char* s = (char*)malloc(7)
memcpy(s,"hello",5);
s[5]=0;//'\0'
// hello

s[5] = '0';
//helloa


// typedef

int add();
void test(){
    printf("sss\n");
    add();
}
int add(){
    return 10;
}

typedef void* (*task_fun_t)();

int main{
    task_fun_t pp = (task_fun_t)test;
    pp();
}


//pointer

int i = 10;
int* p = (int*)10;

i+=1;//11
p+=1;//14 加一个步长(short*** -> short**) p+1*4 = 14 ptr=4B

int pp = (int)p;
pp+=1;//11

int ppp = (int)((char*)p+1);//11
ppp+=1;//12 

// point & char/int...

int* p = malloc(1000);
//move 10 Bytes
char* c = (char*)((int)p+10);