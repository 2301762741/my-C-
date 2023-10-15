#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    // 随机产生
    int left=0, right=0;
    left = rand() % 1000 + 1; // 1 - 1000
    right = rand() % 1000 + 1; // 1 - 1000

    char ops[] = "+-*/";
    int sel = rand() % 4;
    char op = ops[sel];

    printf("请计算: %d %c %d = ", left, op, right);
    
    // 读取用户的输入
    double input = 0;
    scanf("%lf", &input);

    // 正确的值是多少？
    double result = 0;
    switch(op)
    {
    case '+':
        result = left + right;
        break;
    case '-':
        result = left - right;
        break;
    case '*':
        result = left * right;
        break;
    case '/':
        result = (double)left / right;
        break;
    }

    // 检查用户输入的是否正确？
    double delta = result - input;
    if( delta > -0.01 && delta < 0.01)
    {
        printf("输入正确！好样的!\n");
    }
    else
    {
        printf("输入不正确!加油!\n");
    }
    return 0;
}