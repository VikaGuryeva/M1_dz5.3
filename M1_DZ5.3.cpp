#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    // Динамическое выделение памяти для массива точек
    pair<int, bool>* points = new pair<int, bool>[2 * N];

    // Считываем отрезки и добавляем их концы в массив
    for (int i = 0; i < N; ++i) {
        int left, right;
        cin >> left >> right;
        points[2 * i] = make_pair(left, true);  // Левый конец отрезка
        points[2 * i + 1] = make_pair(right, false); // Правый конец отрезка
    }

    // Сортируем все точки по координате
    sort(points, points + 2 * N);

    int painted_length = 0;
    int depth = 0;
    int prev_x = 0;

    // Проходим по всем точкам
    for (int i = 0; i < 2 * N; ++i) {
        int x = points[i].first;
        bool is_left = points[i].second;

        // Добавляем длину окрашенной части, если depth не равно нулю и это не первая точка
        if (depth != 0 && x != prev_x) {
            painted_length += x - prev_x;
        }

        // Обновляем значение depth в зависимости от того, является ли точка началом или концом отрезка
        if (is_left) {
            depth++;
        }
        else {
            depth--;
        }

        // Обновляем предыдущую координату
        prev_x = x;
    }

    // Выводим результат
    cout << painted_length << endl;

    // Освобождаем выделенную память
    delete[] points;

    return 0;
}
