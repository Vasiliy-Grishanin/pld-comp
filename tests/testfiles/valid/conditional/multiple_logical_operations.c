int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    if ((a == 1 && b == 2) || (a == 2 && c == 3)) {
        a = 4;
    } else {
        a = 5;
    }
    return a;
}
