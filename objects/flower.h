//
// Created by Даниил Лесь on 06.01.2022.
//

#ifndef CSA_HW1_FLOWER_H
#define CSA_HW1_FLOWER_H

#include <cstdio>

/*
 * Структура растения типа цветок.
 */
struct Flower {
    enum Flower_type {
        Home = 1,
        Garden = 2,
        Wild = 3,
    } flower_type;
};

/*
 * Название типа цветка (из перечеслителя в строку).
 * @param: flowerType - конкретный тип цветка в перечеслители.
 * @returns: Строка - название месяца цветения куста
*/
const char* PrintFlowerType(Flower::Flower_type flowerType);

/*
 * Чтение полей цветка из входного файла.
 * @param: flower - указатель на объект Flower, который будет заполнен из входного файла.
 * @param: input_file - указатель на входной файл
 * @returns: 1 - если при чтении произошла ошибка, 0 - ОК.
*/
int ReadInput(Flower* flower, FILE* input_file);

/*
 * Вывод полей цветка в выходной файл.
 * @param: flower - указатель на объект Flower, поля которого будут выведены в выходной файл.
 * @param: output_file - указатель на входной файл
*/
void Out(const Flower* flower, FILE* output_file);

/*
 * Генерация рандомных полей цветка для записи в контейнер.
 * @param: flower - указатель на объект Flower, поля которого будут рандомно сгенерированы.
*/
void RandomInput(Flower* flower);

#endif //CSA_HW1_FLOWER_H
