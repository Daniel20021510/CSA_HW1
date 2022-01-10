//
// Created by Даниил Лесь on 06.01.2022.
//

#include <cstdlib>
#include <string.h>
#include "plant.h"
#include "../functions/additional_functions .h"
#include "../functions/vowels_functions.h"

int ReadInput(Plant* plant, FILE* input_file){
    int plant_type = -1;
    char name[255];
    int argc = fscanf(input_file, "%d %s ", &plant_type, &name);

    if (argc != 2){
        printf("Error: Could not read plant type of plant name.\n");
        return 1;
    }

    plant->name = (char *) malloc(255);
    strcpy(plant->name, name);

    switch (plant_type) {
        case Plant::TREE:
            plant->plant_type = Plant::TREE;
            return ReadInput(&plant->tree, input_file);
        case Plant::BUSH:
            plant->plant_type = Plant::BUSH;
            return ReadInput(&plant->bush, input_file);
        case Plant::FLOWER:
            plant->plant_type = Plant::FLOWER;
            return ReadInput(&plant->flower, input_file);
        default:
            printf("Incorrect plant type.\n");
            return 1;
    }
}

void RandomInput(Plant* plant) {
    plant->name = (char *) malloc(255);
    char* name = RandomString();
    strcpy(plant->name, name);
    int plant_type = RandomInt(4);
    printf("%d %s ", plant_type, name);

    switch (plant_type) {
        case Plant::TREE:
            plant->plant_type = Plant::TREE;
            return RandomInput(&plant->tree);
        case Plant::BUSH:
            plant->plant_type = Plant::BUSH;
            return RandomInput(&plant->bush);
        case Plant::FLOWER:
            plant->plant_type = Plant::FLOWER;
            return RandomInput(&plant->flower);
    }
}

void Out(Plant* plant, FILE* output_file){
    switch (plant->plant_type) {
        case Plant::TREE:
            fprintf(output_file, "Tree: name - %s, vowels per length = %f, ", plant->name, VowelsPerSize(plant->name));
            return Out(&plant->tree, output_file);
        case Plant::BUSH:
            fprintf(output_file, "Bush: name - %s, vowels per length = %f, ", plant->name, VowelsPerSize(plant->name));
            return Out(&plant->bush, output_file);
        case Plant::FLOWER:
            fprintf(output_file, "Flower: name - %s, vowels per length = %f, ", plant->name, VowelsPerSize(plant->name));
            return Out(&plant->flower, output_file);
    }
}

double VowelsPerSize(char name[]){
    return (CountVowels(name) * 1.0) / StringSize(name);
}
