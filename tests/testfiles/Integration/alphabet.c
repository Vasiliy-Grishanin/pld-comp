int main() {

    int lettre = 65; // Valeur ASCII de 'A'


    int b = lettre < 91;
    while (lettre < 91) { // Valeur ASCII de 'Z'
        int a = putchar(lettre);
        lettre = lettre + 1;
    }



    return lettre < 91;
}