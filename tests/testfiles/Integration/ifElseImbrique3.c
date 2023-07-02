int main(){
    int a = 5;
    int b = 6;
    if(a < b){
        a = 7;
        if(a != b+1){
            a = 28;
        }
    }else{
        a = 6;
        if(a == b){
            a = 8;
        }else{
            a = 10;
        }
    }
    return a;
}