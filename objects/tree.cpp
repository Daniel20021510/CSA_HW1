//
// Created by Даниил Лесь on 06.01.2022.
//

#include "tree.h"
#include "../functions/additional_functions .h"

int ReadInput(Tree* tree, FILE* input_file){
    long long age;

    int argc = fscanf(input_file, "%lld\n", &age);

    if (argc != 1){
        printf("Error: Could not read tree age.\n");
        return 1;
    }

    tree->age = age;

    return 0;
}

void Out(const Tree* tree, FILE* output_file){
    fprintf(output_file, "age - %lld.\n", tree->age);
}

void RandomInput(Tree* tree){
    tree->age = RandomInt(10000);
    printf("%d\n", tree->age);
}