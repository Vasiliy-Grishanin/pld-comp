int main() {

    int lettre = 65; // Valeur ASCII de 'A'



    while (lettre < 91) { // Valeur ASCII de 'Z'
        int a = putchar(lettre);
        lettre = lettre + 1;
    }



    return lettre;
}