//
// Created by Даниил Лесь on 06.01.2022.
//

#include <cstdlib>
#include "container.h"
#include "../functions/additional_functions .h"

Container* Crete(){
    Container* container = (Container*) malloc(sizeof(Container));
    container->size = 0;
    for(int i =0; i < 10000; ++i){
        container->plants[i] = NULL;
    }
    return container;
}

void Clear(Container* container){
    for (int i = 0; i < container->size; ++i) {
        delete container->plants[i];
    }
    container->size = 0;
    delete container;
}

int Add(Container* container, Plant* plant){
    if (container->size + 1 < 10100){
        container->plants[container->size] = (Plant*) malloc(sizeof(Plant));
        container->plants[container->size]->plant_type = plant->plant_type;

        container->plants[container->size]->name = plant->name;
        container->plants[container->size]->tree = plant->tree;
        container->plants[container->size]->bush = plant->bush;
        container->plants[container->size]->flower = plant->flower;

        container->size++;
        return 0;
    }else{
        printf("Error: container is full.\n");
        return 1;
    }
}

int ReadInput(Container* container, FILE* input_file){
    int plants_number;
    int argc = fscanf(input_file, "%d\n", &plants_number);
    if (argc != 1){
        printf("Error: Could not read plants number.\n");
        return 1;
    }

    if (plants_number > 10000){
        printf("Error: Plants number too big. More then 10000.\n");
        return 1;
    }

    if (plants_number <= 0){
        printf("Error: Plants number cannot be less then 1.\n");
        return 1;
    }

    for(int i = 0; i < plants_number; ++i){
        Plant plant{};
        int status = ReadInput(&plant, input_file);
        if (status){
            printf("%d plant resulted in error.\n", i + 1);
            return status;
        }
        Add(container, &plant);
    }
    return 0;
}

void RandomInput(Container* container, int size){
    if (size > 10000){
        printf("Error: Plants number too big. More then 10000.\n");
        return;
    }

    if (size <= 0){
        printf("Error: Plants number cannot be less then 1.\n");
        return;
    }

    printf("%d\n", size);
    for(int i = 0; i < size; ++i) {
        Plant plant{};
        RandomInput(&plant);
        Add(container, &plant);
    }
}

void Out(const Container* container, FILE* output_file){
    for(int i = 0; i < container->size; ++i){
        fprintf(output_file, "[%d] ", i);
        Out(container->plants[i], output_file);
    }
}

void StraightInsertion(Container* container)
{
    for(int i = 0; i < container->size; ++i){
        Plant* plant = container->plants[i];
        int j = i;
        while(j > 0 && VowelsPerSize(container->plants[j-1]->name) > VowelsPerSize(plant->name)){
            container->plants[j] = container->plants[j-1];
            j--;
        }
        container->plants[j] = plant;
    }
}
