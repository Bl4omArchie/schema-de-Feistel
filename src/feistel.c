/* Schéma de Feistel
Comment sont représentés les données ?

-> On peut les représenter sous différentes formes: caractère, entier, binaire ou hexadécimal.
Et on les manipule sous forme de nombres (uint) ou de chaîne de caractère.

Le but premier ici est de trouver sous quelle forme représenter les données manipuler afin d'implémenter les opérations arithmétique (ex: xor)
Comme en C il est moins aisé de manipuler les types, contrairement à python, ce travail est important.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define ROUNDS 5


void cipher(uint64_t *ciphertext, uint64_t plaintext, uint32_t key) {
    uint64_t left_block = plaintext << 32;
    uint64_t right_block = plaintext & 0xFFFFFFFF;
    uint64_t tmp;

    printf ("%lx, %lx", left_block, right_block);

    for (int r=0; r<ROUNDS; r++) {
        tmp = left_block;
        right_block = right_block ^ key;
        left_block = left_block ^ right_block;

        right_block = left_block;
        left_block = tmp;
    }
    printf ("%ld%ld", left_block, right_block);
}

int decipher(char *plaintext, char ciphertext, char key) {

}

int main() {
    uint64_t message = 0b10100101000101; 
    uint32_t key = 0b11100101010;

    uint64_t ciphertext;
    uint64_t *ptr_ct = &ciphertext;

    cipher(ptr_ct, message, key);

    return 1;
}