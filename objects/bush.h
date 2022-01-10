//
// Created by Даниил Лесь on 06.01.2022.
//

#ifndef CSA_HW1_BUSH_H
#define CSA_HW1_BUSH_H

#include <cstdio>

/*
 * Структура растения типа куст.
 */
struct Bush {
    enum Flowering_month {
        Jan = 1,
        Feb = 2,
        Mar = 3,
        Apr = 4,
        May = 5,
        Jun = 6,
        Jul = 7,
        Aug = 8,
        Sep = 9,
        Oct = 10,
        Nov = 11,
        Dec = 12,
    } flowering_month;
};

/*
 * Название месяца цветения (из перечеслителя в строку).
 * @param: flowering_month - конкретный месяц цветения куста в перечеслители.
 * @returns: Строка - название месяца цветения куста
*/
const char* PrintFloweringMonth(Bush::Flowering_month flowering_month);

/*
 * Чтение полей куста из входного файла.
 * @param: bush - указатель на объект Bush, который будет заполнен из входного файла.
 * @param: input_file - указатель на входной файл
 * @returns: 1 - если при чтении произошла ошибка, 0 - ОК.
*/
int ReadInput(Bush* bush, FILE* input_file);

/*
 * Вывод полей куста в выходной файл.
 * @param: bush - указатель на объект Bush, поля которого будут выведены в выходной файл.
 * @param: output_file - указатель на входной файл
*/
void Out(const Bush* bush, FILE* output_file);

/*
 * Генерация рандомных полей куста для записи в контейнер.
 * @param: bush - указатель на объект Bush, поля которого будут рандомно сгенерированы.
*/
void RandomInput(Bush* bush);

#endif //CSA_HW1_BUSH_H
