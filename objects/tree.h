//
// Created by Даниил Лесь on 06.01.2022.
//

#ifndef CSA_HW1_TREE_H
#define CSA_HW1_TREE_H

#include <cstdio>

/*
 * Структура растения типа дерево.
 */
struct Tree {
    long long age;
};

/*
 * Чтение полей дерева из входного файла.
 * @param: tree - указатель на объект Tree, который будет заполнен из входного файла.
 * @param: input_file - указатель на входной файл
 * @returns: 1 - если при чтении произошла ошибка, 0 - ОК.
*/
int ReadInput(Tree* tree, FILE* input_file);

/*
 * Вывод полей дерева в выходной файл.
 * @param: tree - указатель на объект Tree, поля которого будут выведены в выходной файл.
 * @param: output_file - указатель на входной файл
*/
void Out(const Tree* tree, FILE* output_file);

/*
 * Генерация рандомных полей дерева для записи в контейнер.
 * @param: tree - указатель на объект Tree, поля которого будут рандомно сгенерированы.
*/
void RandomInput(Tree* tree);

#endif //CSA_HW1_TREE_H
