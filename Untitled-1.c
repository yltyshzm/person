#include <stdio.h>
#include <stdlib.h>

// 函数声明
double perform_calculation(double result, double num, char operation);

int main() {
    char operation;
    double num, result;
    int first_input = 1;

    // 提示用户选择操作符
    printf("请选择操作符 (+, -, *, /): ");
    scanf(" %c", &operation);

    printf("请输入数字（输入 '=' 结束输入）:\n");

    while (1) {
        char input[20];
        // 读取用户输入
        scanf("%s", input);

        // 检查用户是否输入结束标志
        if (input[0] == '=' && input[1] == '\0') {
            break;
        }

        // 将输入的字符串转换为数字
        num = atof(input);

        if (first_input) {
            result = num;  // 第一个数字作为初始值
            first_input = 0;
        } else {
            // 进行累积计算
            result = perform_calculation(result, num, operation);
        }
    }

    // 输出计算结果
    printf("计算结果: %.2lf\n", result);

    return 0;
}

// 执行计算的函数
double perform_calculation(double result, double num, char operation) {
    switch (operation) {
        case '+':
            return result + num;
        case '-':
            return result - num;
        case '*':
            return result * num;
        case '/':
            if (num != 0) {
                return result / num;
            } else {
                printf("错误: 除数不能为零\n");
                exit(1);
            }
        default:
            printf("错误: 未知的操作符\n");
            exit(1);
    }
    return 0; // 这行代码理论上不会被执行
}
