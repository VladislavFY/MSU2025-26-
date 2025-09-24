#include "prototypes_22.h"
   /* 
   - читаем первые два числа в prevprev и prev;
   - затем в цикле читаем curr ;
   - если curr > prev (с учётом eps) — сдвигаем окно;
   - если найдено нарушение (curr - prev <= eps) — пытаемся одним изменением
     починить либо prev, либо curr. Для решения смотрим на следующий элемент (next):
       * если нет следующего элемента => можно исправить (поднять curr) => OK;
       * если есть следующий, проверяем можем ли поставить новое prev между prevprev и curr
         (условие curr - prevprev > eps) или можем ли поставить новое curr между prev и next
         (условие next - prev > eps);
       * если ни один вариант невозможен => одного изменения недостаточно => возвращаем -2.
   - возвращаем 0 при успехе, или коды ошибок -3 (пустой файл), -4 (только одно число).
*/

int function_of_check(FILE *f)
{
    double curr = 0 , prev = 0 , prevprev = 0 , next = 0 ;
    int violations = 0;
    int have_next = 0;   /* флаг: в 'next' есть ранее прочитанное значение */
    int read_done = 0;        /* флаг окончания чтения */
    if (fscanf(f, "%lf", &prevprev) != 1) {
        printf("File is empty");
        return -3;
    }
    if (fscanf(f, "%lf", &prev) != 1) {
        printf("File doesnt have two numbers!");
        return -4;
    }

    while (!done) {
        if (have_next) {
            curr = next;
            have_next = 0;
        } else {
            if (fscanf(f, "%lf", &curr)!= 1) {
                done = 1;
            }
        }

        if (!done) {
            if (curr - prev <= eps) {
                violations++;
                if (violations_typeC > 1) {
                    return -2;
                }

                /* Подглядываем следующий элемент, если он есть */
                if ( fscanf(f, "%lf", &next) == 1) {
                    have_next = 1;
                    // can_change_prev = (curr - prevprev > eps);
                    // can_change_curr = (next - prev > eps);
                    if (!(curr - prevprev > eps) && !(next - prev > eps)) {
                        return -2;
                    }

                    if ((curr - prevprev > eps)) {
                        /* Симуляция изменения prev: ставим prev чуть больше prevprev + eps */
                        prev = prevprev + eps;
                        /* Сдвигаем окно: prevprev <- prev (изменённый), prev <- curr */
                        prevprev = prev;
                        prev = curr;
                    } else {
                        /* Симуляция изменения curr: ставим curr чуть больше prev + eps */
                        curr = prev + eps;
                        /* Сдвигаем окно: prevprev <- prev, prev <- curr (изменённый) */
                        prevprev = prev;
                        prev = curr;
                    }
                    /* следующая итерация возьмёт в curr значение из have_next (next) */
                } else {
                    /* next отсутствует — curr был последним элементом;
                       можем поднять curr > prev — значит одной заменой можно исправить */
                    return 0;
                }
            } else {
                /* Нарушения нет — простое сдвижение окна */
                prevprev = prev;
                prev = curr;
            }
        }
    }

    return 0;
}
