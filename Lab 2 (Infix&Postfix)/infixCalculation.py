# Implementation of algorithm to evaluate the given postfix expression.

def evaluate(expr):
    stack = []
    tokens = expr.split()

    for ch in tokens:
        if ch.isdigit():
            stack.append(int(ch))
        elif ch in '+-*/':
            b = stack.pop()
            a = stack.pop()
            if ch == '+':
                stack.append(a + b)
            elif ch == '-':
                stack.append(a - b)
            elif ch == '*':
                stack.append(a * b)
            elif ch == '/':
                if b != 0:
                    stack.append(a / b)
                else:
                    return "Division by zero error"
    
    if len(stack) == 1:
        return stack.pop()
    else:
        return "Invalid expression"

expr = input("Enter postfix expression: ").strip()
result = evaluate(expr)
print("Result:", result)