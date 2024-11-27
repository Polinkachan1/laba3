#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>

using namespace std;
void print_matrix(int* matrix, int N) {
    int* end = matrix + (N * N) - 1;
    for (int* i = matrix; i <= end; ++i) {
        if ((i - matrix) % N == 0) {
            cout << "\n";
        }
        cout << *i << " ";
    }
}
void printMatrix(int* matrix, int n, int helper) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD destCoord;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            destCoord.X = j * 4 + 50;
            destCoord.Y = i + helper; 
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(matrix + i * n + j) << " "; 
        }
        cout << endl;
    }
}
void idz() {
    int N;
    cout << "Введите число для ИДЗ(от 2 до 10)" << endl;
    cin >> N;
    int* matrix1 = new int[N * N]; 
    int* matrix2 = new int[N * N];
    int* matrix3 = new int[N * N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix1 + i * N + j) = rand() % (N * N) + 1;
            *(matrix2 + i * N + j) = rand() % (N * N) + 1;
            *(matrix3 + i * N + j) = 1;
        }
    }
    cout << "Первая матрица" << endl;
    printMatrix(matrix1, N, 0);
    cout << "Вторая матрица" << endl;
    printMatrix(matrix2, N, N + 1);
    cout << endl;
    int top = 0, bottom = N - 1, left = 0, right = N - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            int * num = matrix3 + i + top*N;
            *num = *(matrix1 + i + top*N) + *(matrix2 + i+ top*N);
            printMatrix(matrix3, N, N + 12);
            Sleep(50);
        }
        top++;
    }
    printMatrix(matrix3, N, N + 12);
}
void shaker_sort(int *matrix, int N) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int * i = matrix + 1, *end = matrix + N * N - 1; i <= end; i++) {
            if (*(i - 1) > *i) {
                int temp = *(i - 1);
                *(i - 1) = *i;
                *i = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        for (int* i = matrix + N*N - 2; i >= matrix; i--) {
            if (*(i - 1) > *i) {
                int temp = *(i - 1);
                *(i - 1) = *i;
                *i = temp;
                swapped = true;
            }
        }
    } 
}
void comb_sort(int* matrix, int N) {
    int temp;
    float k = 1.247, S = N - 1;
    int count = 0;
    while (S >= 1)
    {
        for (int i = 0; i + S < N; i++)
        {
            if (*(matrix+i) > *(matrix+int(i + S)))
            {
                temp = *(matrix+int(i + S));
                *(matrix+int(i + S)) = *(matrix+i);
                *(matrix+i) = temp;
            }
        }
        S /= k;
    }

    while (true)
    {
        for (int i = 0; i < N - 1; i++)
        {
            if (*(matrix+i) > *(matrix+i + 1))
            {
                temp = *(matrix+i + 1);
                *(matrix+i + 1) = *(matrix+i);
                *(matrix+i) = temp;
            }
            else count++;
        }
        if (count == N - 1)
            break;
        else
            count = 0;
    }
}
void quick_sort(int* matrix, int* begin, int* end) {
    int* f = begin;
    int* l = end;
    int mid = *(begin + (end - begin) / 2);

    while (f <= l) {
        while (*f < mid) f++; 
        while (*l > mid) l--; 

        if (f <= l) {
            swap(*f, *l);
            f++;
            l--;
        }
    }
    if (begin < l) quick_sort(matrix, begin, l);
    if (f < end) quick_sort(matrix, f, end);
}
void insert_sort(int* matrix, int N) {
    for (int i = 1; i < N*N; i++) {
        int key = *(matrix + i);
        int j = i - 1;
        while (j >= 0 && *(matrix + j) > key) {
            *(matrix + j + 1) = *(matrix + j);
            j--;
        }
        *(matrix + j + 1) = key;
    }
}
void fillSnake(int* matrix, int n) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = top; i <= bottom; i++) {
            int* num = matrix + i * n + left;
            *num = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(400);
        }
        left++;

        for (int i = bottom; i >= top; i--) {
            int* num = matrix + i * n + left;
            *num = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0); 
            Sleep(400);
        }
        left++;
    }
}
void fillSpiral(int *matrix, int n) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            *(matrix + top * n + i)= rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(100);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            *(matrix + i* n + right) = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(100);
        }
        right--;


        for (int i = right; i >= left; i--) {
            *(matrix + bottom * n + i) = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(100);
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            *(matrix + i*n + left) = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(100);
        }
        left++;
    }
    printMatrix(matrix, n, 0);
}
void swap_quarters_a(int *matrix, int N) {
    int *temp = new int[N*N];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(temp + i*N + j) = *(matrix + i*N + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < middle && j < middle) {
                *(matrix + i*N + j + middle) = *(temp + i*N + j);
            }
            else if (i < middle && j >= middle) {
                *(matrix + (i+ middle)*N + j) = *(temp + i*N + j);
            }
            else if (i >= middle && j >= middle) {
                *(matrix + i*N + (j - middle)) = *(temp + i*N + j);
            }
            else {
                *(matrix + (i - middle)*N + j) = *(temp + i*N + j);
            }
        }
    }
    printMatrix(matrix, N, N + 10);
}
void swap_quarters_b(int *matrix, int N) {
    int* temp = new int[N * N];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(temp+i*N+j) = *(matrix + i * N + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < middle && j < middle) {
                *(matrix + (i + middle)*N + j + middle) = *(temp + i*N + j);
            }
            else if (i < middle && j >= middle) {
                *(matrix + (i + middle)*N + j - middle) = *(temp + i*N + j);
            }
            else if (i >= middle && j >= middle) {
                *(matrix + (i - middle)*N + j - middle) = *(temp + i*N + j);
            }
            else {
                *(matrix + (i - middle) * N + j + middle) = *(temp + i * N + j);
            }
        }
    }
    printMatrix(matrix, N, N + 10);
}
void swap_quarters_c(int *matrix, int N) {
    int* temp = new int[N * N];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(temp + i * N + j) = *(matrix + i * N + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < middle) {
                *(matrix + (i + middle)*N + j) = *(temp + i*N + j);
            }
            else {
                *(matrix + (i - middle)*N + j) = *(temp + i*N + j);
            }
        }
    }
    printMatrix(matrix, N, N + 10);
}

void swap_quarters_d(int *matrix, int N) {
    int* temp = new int[N * N];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(temp + i * N + j) = *(matrix + i * N + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j < middle) {
                *(matrix + i*N + j + middle) = *(temp + i*N + j);
            }
            else {
                *(matrix + i*N + j - middle) = *(temp + i*N + j);
            }
        }
    }
    printMatrix(matrix, N, N + 10);
}
void enlarge_each_element(int *matrix, int N) {
    int enlarge_num;

    cout << "Введите число, которое нужно прибавить: ";
    cin >> enlarge_num;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix + i*N + j) += enlarge_num;
        }
    }
    printMatrix(matrix, N, N + 10);
}
void reduce_each_element(int *matrix, int N) {
    int reduce_num;

    cout << "Введите число, которое нужно отнять: ";
    cin >> reduce_num;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix + i*N + j) -= reduce_num;
        }
    }
    printMatrix(matrix, N, N + 10);
}
void divide_each_element(int *matrix, int N) {
    int divide_num;

    cout << "Введите число, на которое нужно разделить: ";
    cin >> divide_num;
    if (divide_num == 0) {
        cout << "Деление на ноль!" << endl;
        return;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix + i*N + j) /= divide_num;
        }
    }
    printMatrix(matrix, N, N + 10);
}

void multiply_each_element(int *matrix, int N) {
    int multiply_num;

    cout << "Введите число, на которое нужно умножить: ";
    cin >> multiply_num;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix + i*N + j) *= multiply_num;
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
void start(int* matrix, int N) {
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            *(matrix + i * N + j) = 1;
        }
    }
}
int main() {
    setlocale(0, "");
    srand(time(NULL));
    int N, identificator, num1, num2, num3, num4;
    cout << "Введите размер матрицы (6, 8, 10): ";
    cin >> N;
    int* matrix = new int[N * N];

    while (true) {
        display_menu();
        cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ: ";
        cin >> identificator;
        system("cls");  // Для Windows
        switch (identificator) {
        case 1:
            start(matrix, N);
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
                shaker_sort(matrix, N);
                printMatrix(matrix, N, N+10);
                break;
            case 2:
                comb_sort(matrix, N);
                printMatrix(matrix, N, N + 10);
                break;
            case 3:
                insert_sort(matrix, N);
                printMatrix(matrix, N, N + 10);
                break;
            case 4:
                quick_sort(matrix, matrix, matrix + N * N - 1);
                printMatrix(matrix, N, N + 10);
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