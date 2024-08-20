#include <stdio.h>
#include <stdlib.h>

// ��������
double perform_calculation(double result, double num, char operation);

int main() {
    char operation;
    double num, result;
    int first_input = 1;

    // ��ʾ�û�ѡ�������
    printf("��ѡ������� (+, -, *, /): ");
    scanf(" %c", &operation);

    printf("���������֣����� '=' �������룩:\n");

    while (1) {
        char input[20];
        // ��ȡ�û�����
        scanf("%s", input);

        // ����û��Ƿ����������־
        if (input[0] == '=' && input[1] == '\0') {
            break;
        }

        // ��������ַ���ת��Ϊ����
        num = atof(input);

        if (first_input) {
            result = num;  // ��һ��������Ϊ��ʼֵ
            first_input = 0;
        } else {
            // �����ۻ�����
            result = perform_calculation(result, num, operation);
        }
    }

    // ���������
    printf("������: %.2lf\n", result);

    return 0;
}

// ִ�м���ĺ���
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
                printf("����: ��������Ϊ��\n");
                exit(1);
            }
        default:
            printf("����: δ֪�Ĳ�����\n");
            exit(1);
    }
    return 0; // ���д��������ϲ��ᱻִ��
}
