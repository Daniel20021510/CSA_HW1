//
// Created by Даниил Лесь on 06.01.2022.
//

#include "flower.h"
#include "../functions/additional_functions .h"

const char *types[3] = {"home", "garden", "wild"};

int ReadInput(Flower* bush, FILE* input_file){
    int flowering_type;

    int argc = fscanf(input_file, "%d\n", &flowering_type);

    if (argc != 1){
        printf("Error: Could not read flower type.\n");
        return 1;
    }

    if (flowering_type < 1 || flowering_type > 3){
        printf("Error: Incorrect flower type.\n");
        return 1;
    }

    bush->flower_type = (Flower::Flower_type) flowering_type;

    return 0;
}

void Out(const Flower* flower, FILE* output_file){
    fprintf(output_file, "flower type - %s.\n", PrintFlowerType(flower->flower_type));
}

void RandomInput(Flower* flower){
    flower->flower_type = (Flower::Flower_type) RandomInt(4);
    printf("%d\n", flower->flower_type);
}

const char* PrintFlowerType(Flower::Flower_type flowerType) {
    switch (flowerType) {
        case Flower::Home:
            return types[0];
        case Flower::Garden:
            return types[1];
        case Flower::Wild:
            return types[2];
    }
}