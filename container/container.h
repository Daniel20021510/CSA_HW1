//
// Created by Даниил Лесь on 06.01.2022.
//

#ifndef CSA_HW1_CONTAINER_H
#define CSA_HW1_CONTAINER_H

#include "../objects/plant.h"

/*
 * Структура контейнера для хранения растений: дерево, куст и цветок.
 * максимальный размер хранения - 10000 элементов
 */
struct Container {
    int size;
    Plant* plants[10000];
};

/*
 * Конструктор контейнера.
 */
Container* Crete();

/*
 * Деструктор контейнера.
 */
void Clear(Container* container);

/*
 * Чтение элементов контейнера из входного файла.
 * @param: container - указатель на объект Container, который будет заполнен из входного файла.
 * @param: input_file - указатель на входной файл
 * @returns: 1 - если при чтении произошла ошибка, 0 - ОК.
*/
int ReadInput(Container* container, FILE* input_file);

/*
 * Генерация рандомных элементов контейнера.
 * @param: container - указатель на объект Container, элементы которого будут рандомно сгенерированы.
 * @param: size - кол-во элементов для рандомной генерации
*/
void RandomInput(Container* container, int size);

/*
 * Добавление элемента в контейнер
 * @param: container - указатель на объект Container, элементы которого будут рандомно сгенерированы.
 * @param: plant - указатель на объект Plant, элементы который будет помещен в контейнер.
*/
int Add(Container* container,const Plant* plant);

/*
 * Вывод элементов контейнера в выходной файл.
 * @param: container - указатель на объект Container, элементы которого будут выведены в выходной файл.
 * @param: output_file - указатель на выходной файл
*/
void Out(const Container* container, FILE* output_file);

/*
 * Сортировка элементов контейнера
 * @param: container - указатель на объект Container, элементы которого будут сортироваться.
*/
void StraightInsertion(Container* container);

#endif //CSA_HW1_CONTAINER_H
