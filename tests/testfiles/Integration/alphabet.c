int main() {

    int lettre = 65; // Valeur ASCII de 'A'

    int a = 0;

    while (lettre < 91) { // Valeur ASCII de 'Z'
        a = putchar(lettre);
        lettre = lettre + 1;
    }



    return lettre;
}