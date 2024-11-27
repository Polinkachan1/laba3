﻿#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>

using namespace std;


void print_matrix(int *matrix, int N) {
    int* end = matrix + (N * N) - 1;
    for (int *i = matrix; i <= end; ++i) {
        if ((i - matrix) % N == 0) {
            cout << "\n";
        }
        cout << *i << " ";
    }
}
// Функция для отображения матрицы с использованием каретки
void printMatrix(int matrix[10][10], int n, int helper) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD destCoord;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            destCoord.X = j * 4 + 50;
            destCoord.Y = i + helper;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << matrix[i][j] << " ";
        }
    }
    cout << endl;
}


void idz() {
    int matrix[10][10], matrix1[10][10], matrix2[10][10] = { 0 }, N;
    cout << "Введите число для ИДЗ(от 2 до 10)" << endl;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(*(matrix + i) + j) = rand() % (N * N) + 1;
            *(*(matrix1 + i) + j) = rand() % (N * N) + 1;
        }
    }
    cout << "Первая матрица" << endl;
    printMatrix(matrix, N, 0);
    cout << "Вторая матрица"<< endl;
    printMatrix(matrix1, N, N+1);
    cout << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(*(matrix2 + i) + j) = *(*(matrix + i) + j) + *(*(matrix1 + i) + j);
            printMatrix(matrix2, N, N + 12);
            Sleep(100);
        }
    }
    printMatrix(matrix2, N, N + 12);
}
void shaker_sort(int* matrix, int size) {
    bool swapped = true;
    int* start;
    int* end;

    while (swapped) {
        swapped = false;

        // Проход слева направо
        for (start = matrix; start < matrix + size - 1; ++start) {
            if (*start > *(start + 1)) {
                // Перестановка элементов
                int temp = *start;
                *start = *(start + 1);
                *(start + 1) = temp;
                swapped = true;
            }
        }

        // Если не было перестановок, выходим
        if (!swapped) {
            break;
        }

        swapped = false;

        // Проход справа налево
        for (end = matrix + size - 1; end > matrix; --end) {
            if (*end < *(end - 1)) {
                // Перестановка элементов
                int temp = *end;
                *end = *(end - 1);
                *(end - 1) = temp;
                swapped = true;
            }
        }
    }
}

void fillSpiral(int matrix[10][10], int n) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            *(*(matrix + top) + i) = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(100);
        }
        top++;

        // Заполнение правого столбца сверху вниз
        for (int i = top; i <= bottom; i++) {
            *(*(matrix + i) + right) = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(100);
        }
        right--;

        // Заполнение нижней строки справа налево
        for (int i = right; i >= left; i--) {
            *(*(matrix + bottom) + i) = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(100);
        }
        bottom--;

        // Заполнение левого столбца снизу вверх
        for (int i = bottom; i >= top; i--) {
            *(*(matrix + i) + left) = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(100);
        }
        left++;
    }
    printMatrix(matrix, n, 0);
}


void divide_each_element(int matrix[10][10], int N) {
    int divide_num;

    cout << "Введите число, на которое нужно разделить: ";
    cin >> divide_num;
    if (divide_num == 0) {
        cout << "Деление на ноль!" << endl;
        return;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(*(matrix + i) + j) /= divide_num;
        }
    }
    printMatrix(matrix, N, N + 10);
}

void multiply_each_element(int matrix[10][10], int N) {
    int multiply_num;

    cout << "Введите число, на которое нужно умножить: ";
    cin >> multiply_num;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(*(matrix + i) + j) *= multiply_num;
        }
    }
    printMatrix(matrix, N, N + 10);
}
void enlarge_each_element(int matrix[10][10], int N) {
    int enlarge_num;

    cout << "Введите число, которое нужно прибавить: ";
    cin >> enlarge_num;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(*(matrix + i) + j) += enlarge_num;
        }
    }
    printMatrix(matrix, N, N+10);
}

void reduce_each_element(int matrix[10][10], int N) {
    int reduce_num;

    cout << "Введите число, которое нужно отнять: ";
    cin >> reduce_num;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(*(matrix + i) + j) += reduce_num;
        }
    }
    printMatrix(matrix, N, N + 10);
}

void fillSnake(int matrix[10][10], int n) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Заполнение столбца сверху вниз
        for (int i = top; i <= bottom; i++) {
            *(*(matrix + i) + left) = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(400);
        }
        left++;
        // Заполнение столбца снизу вверх
        for (int i = bottom; i >= top; i--) {
            *(*(matrix + i) + left) = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(400);
        }
        left++;
    }

}
void swap_quarters_a(int matrix[10][10], int N) {
    int temp[10][10];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = *(*(matrix + i) + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < middle && j < middle) {
                *(*(matrix + i) + j + middle) = *(*(temp + i) + j);
            }
            else if (i < middle && j >= middle) {
                *(*(matrix + i + middle) + j) = *(*(temp + i) + j);
            }
            else if (i >= middle && j >= middle) {
                *(*(matrix + i) + j - middle) = *(*(temp + i) + j);
            }
            else {
                *(*(matrix + i - middle) + j) = *(*(temp + i) + j);
            }
        }
    }
    printMatrix(matrix, N, N+10);
}
void swap_quarters_b(int matrix[10][10], int N) {
    int temp[10][10];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = *(*(matrix + i) + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < middle && j < middle) {
                *(*(matrix + i + middle) + j + middle) = *(*(temp + i) + j);
            }
            else if (i < middle && j >= middle) {
                *(*(matrix + i + middle) + j - middle) = *(*(temp + i) + j);
            }
            else if (i >= middle && j >= middle) {
                *(*(matrix + i - middle) + j - middle) = *(*(temp + i) + j);
            }
            else {
                *(*(matrix + i - middle) + j + middle) = *(*(temp + i) + j);
            }
        }
    }
    printMatrix(matrix, N, N+10);
}
void swap_quarters_c(int matrix[10][10], int N) {
    int temp[10][10];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = *(*(matrix + i) + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < middle) {
                *(*(matrix + i + middle) + j) = *(*(temp + i) + j);
            }
            else {
                *(*(matrix + i - middle) + j) = *(*(temp + i) + j);
            }
        }
    }
    printMatrix(matrix, N, N + 10);
}

void swap_quarters_d(int matrix[10][10], int N) {
    int temp[10][10];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = *(*(matrix + i) + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j < middle) {
                *(*(matrix + i) + j + middle) = *(*(temp + i) + j);
            }
            else {
                *(*(matrix + i) + j - middle) = *(*(temp + i) + j);
            }
        }
    }
    printMatrix(matrix, N, N + 10);
}

void display_menu() {
    cout << "\nДоступные задания:" << endl;
    cout << "1. Задание 1. Заполняет квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до N*N согласно схемам" << endl;
    cout << "2. Задание 2. Получение новой матрицы, из матрицы п. 1, переставляя ее блоки в соответствии со схемами" << endl;
    cout << "3. Задание 3. Используя арифметику указателей, сортирует элементы любой сортировкой из списка ниже" << endl;
    cout << "4. Задание 4. Уменьшает, увеличивает, умножает или делит все элементы матрицы на введенное пользователем число" << endl;
    cout << "5. Задание 5. ИДЗ" << endl;
    cout << "6. Задание 6. Выход" << endl;
}

int main() {
    setlocale(0, "");
    srand(time(NULL));
    int N, identificator, num1, num2, num3, num4;
    int matrix[10][10];
    cout << "Введите размер матрицы (6, 8, 10): ";
    cin >> N;
    cout << endl;
    while (true) {
        display_menu();
        cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ: ";
        cin >> identificator;
        system("cls");  // Для Windows
        switch (identificator) {
        case 1:
            cout << "1. Массив спиралью" << endl;
            cout << "2. Массив змейкой" << endl;
            cin >> num1;
            switch (num1) {
            case 1:
                fillSpiral(matrix, N);
                break;
            case 2:
                fillSnake(matrix, N);
                break;
            }
            break;
        case 2:
            printMatrix(matrix, N, 0);
            cout << "Меняем четверти" << endl;
            cout << "1. по часовой стрелке" << endl;
            cout << "2. по диагонали " << endl;
            cout << "3. сверху вниз" << endl;
            cout << "4. справа налево" << endl;
            cin >> num2;
            cout << "Измененная матрица" << endl;
            switch (num2) {
            case 1:
                swap_quarters_a(matrix, N);
                break;
            case 2:
                swap_quarters_b(matrix, N);
                break;
            case 3:
                swap_quarters_c(matrix, N);
                break;
            case 4:
                swap_quarters_d(matrix, N);
                break;
            }
            break;
        case 3:
            printMatrix(matrix, N, 0);
            cout << "Введите сортировку:" << endl;
            cout << "1. Shaker sort" << endl;
            cout << "2. Comb sort" << endl;
            cout << "3. Insert sort" << endl;
            cout << "4. Quick sort" << endl;

            cin >> num3;
            switch (num3) {
            case 1:
                shaker_sort(*matrix, N);
                print_matrix(*matrix, N);
                break;
            case 2:
                //comb_sort(matrix, N);
                break;
            case 3:
                //insert_sort(matrix, N);
                break;
            case 4:
                //quick_sort(matrix, N);
                break;
            }
            cout << "Измененная матрица" << endl;
            break;

        case 4:
            printMatrix(matrix, N, 0);
            cout << "Введите номер операции с элементами массива:" << endl;
            cout << "1. Увеличить элементы массива" << endl;
            cout << "2. Уменьшить элементы массива " << endl;
            cout << "3. Умножить элементы массива" << endl;
            cout << "4. Разделить элементы массива" << endl;
            cout << "Измененная матрица" << endl;
            cin >> num4;
            switch (num4) {
            case 1:
                enlarge_each_element(matrix, N);
                break;
            case 2:
                reduce_each_element(matrix, N);
                break;
            case 3:
                multiply_each_element(matrix, N);
                break;
            case 4:
                divide_each_element(matrix, N);
                break;
            }
            break;

        case 5:
            cout << "ИДЗ" << endl;
            idz();
            break;

        case 6:
            cout << "Выход!" << endl;
            return 0;

        default:
            cout << "Некорректный номер задания." << endl;
            break;
        }
        cout << "Задание выполнено. Нажмите Enter, чтобы продолжить." << endl;
        cin.ignore();
        cin.get();
    }
    return 0;
}