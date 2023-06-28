int main() {
    int a = 1;
    int b = 1;
    if (a == b) {
        if (a == 1) {
            a = 3;
        } else {
            a = 4;
        }
    } else {
        if (b == 2) {
            a = 5;
        } else {
            a = 6;
        }
    }
    return a;
}