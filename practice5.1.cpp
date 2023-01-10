#include <iostream>
#include <numeric>


typedef int MyArr[5];

void f (MyArr a)                                    //Функция получает массив
 {                                                  //и обнуляет 5 член массива
  a[4] = 0;
 }

int sum(int *begin, int *end)                   //Функция получает 2 указателя
 {                                              //на начало и конец массива
  return std::accumulate(begin, end, 0);        //и суммирует все члены массива
 }

int main()
 {
  MyArr a = {1 , 2 , 3 , 4 , 5};                    //Инициализация и заполнение массива
  int *begin = std::begin(a);                           //Инициализация указателя на начало массива
  int *end = std::end(a);                               //Инициализация указателя на конец массива

  std :: cout << " Sum1 : " << sum(begin, end) << '\n'; //Сумма массива до обнуления 5 члена
  f(a);                                             //Обнуление 5 члена массива
  std :: cout << " Sum2: " << sum(begin, end) << '\n';  //Сумма массива после обнуления 5 члена
  
  return 0;
 }
