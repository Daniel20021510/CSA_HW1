//
// Created by Даниил Лесь on 06.01.2022.
//

#ifndef CSA_HW1_PLANT_H
#define CSA_HW1_PLANT_H

#include "tree.h"
#include "bush.h"
#include "flower.h"

/*
 * Структура обобщенного растения.
 * name - название растения
 */
struct Plant {

    char *name;

    enum plant_type {
        TREE = 1,
        BUSH = 2,
        FLOWER = 3,
    } plant_type;

    union {
        Tree tree;
        Bush bush;
        Flower flower;
    };
};

/*
 * Чтение полей растения из входного файла.
 * @param: plant - указатель на объект Plant, который будет заполнен из входного файла.
 * @param: input_file - указатель на входной файл
 * @returns: 1 - если при чтении произошла ошибка, 0 - ОК.
*/
int ReadInput(Plant* plant, FILE* input_file);

/*
 * Вывод полей растения в выходной файл.
 * @param: plant - указатель на объект Plant, поля которого будут выведены в выходной файл.
 * @param: output_file - указатель на входной файл
*/
void Out(Plant* plant, FILE* output_file);

/*
 * Генерация рандомных полей растения для записи в контейнер.
 * @param: plant - указатель на объект Plant, поля которого будут рандомно сгенерированы.
*/
void RandomInput(Plant* plant);

/*
 * Частное от деления числа гласных букв в названии на общую длину названия
 * @param: name - название растения.
 * @returns: (double) Частное от деления числа гласных букв в названии на общую длину названия
 */
double VowelsPerSize(char name[]);

#endif //CSA_HW1_PLANT_H
