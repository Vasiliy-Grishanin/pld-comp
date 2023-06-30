int test(int arg1,int arg2,int arg3,int arg4,int arg5,int arg6) {
    int x = 3;
    int y = x+2 + (arg1+arg2+arg3+arg4+arg5+arg6);
    return y;
}

int main() {
    int a;
    a = 1;
    int b= test(a,2,3,4,5,6);
    return b;
}