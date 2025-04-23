#include <cmath>
#include <cstdio>

// Класс для решения квадратного уравнения вида ax² + bx + c = 0
class QuadraticEquationSolver {
private:
  
    double a, b, c;        // Коэффициенты уравнения
    double discriminant;    // Дискриминант 
    double x1, x2;         // Корни уравнения (если существуют)
    int rootsCount;         // Количество корней (0, 1 или 2)

public:
    // Конструктор 
    QuadraticEquationSolver() : a(0), b(0), c(0), discriminant(0), x1(0), x2(0), rootsCount(0) {}

    // Метод для ввода коэффициентов уравнения с клавиатуры
    void inputCoefficients() {
        printf("Введите коэффициенты квадратного уравнения (a, b, c): ");
        scanf("%lf %lf %lf", &a, &b, &c);
    }

    // Метод для решения квадратного уравнения
    void solve() {
        // Вычисляем дискриминант по формуле D = b² - 4ac
        discriminant = b * b - 4 * a * c;

        // Анализируем дискриминант
        if (discriminant > 0) {
            // D > 0: два различных корня
            rootsCount = 2;
            x1 = (-b + sqrt(discriminant)) / (2 * a);  // Первый корень
            x2 = (-b - sqrt(discriminant)) / (2 * a);  // Второй корень
        } else if (discriminant == 0) {
            // D = 0: один корень
            rootsCount = 1;
            x1 = -b / (2 * a);  // Единственный корень
        } else {
            // D < 0: Корней нет
            rootsCount = 0;
        }
    }

    // Метод для вывода результатов на экран
    void printResults() {
        // Выводим само уравнение
        printf("Уравнение: %.2fx² + %.2fx + %.2f = 0\n", a, b, c);
        // Выводим дискриминант
        printf("Дискриминант: %.2f\n", discriminant);

        // Выводим корни в зависимости от их количества
        switch (rootsCount) {
            case 2:
                printf("Два действительных корня:\n");
                printf("x1 = %.2f\n", x1);
                printf("x2 = %.2f\n", x2);
                break;
            case 1:
                printf("Один действительный корень:\n");
                printf("x = %.2f\n", x1);
                break;
            case 0:
                printf("Действительных корней нет\n");
                break;
            default:
                printf("Ошибка: неизвестное количество корней\n");
                break;
        }
    }
};

// Главная функция программы
int main() {
    // Создаем объект-решатель квадратных уравнений
    QuadraticEquationSolver solver;
    // Вводим коэффициенты
    solver.inputCoefficients();
    // Решаем уравнение
    solver.solve();
    // Выводим результаты
    solver.printResults();

    return 0;
}