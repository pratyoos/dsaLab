#Q No 2: Implement an algorithm to convert the given infix expression to postfix expression.

def get_precedence(op):
    if op in ('+', '-'):
        return 1
    if op in ('*', '/'):
        return 2
    if op == '^':
        return 3
    return 0

def check_operator(ch):
    return ch in ('+', '-', '*', '/', '^')

def validate_parentheses(exp):
    stack = []
    for char in exp:
        if char == '(':
            stack.append(char)
        elif char == ')':
            if not stack or stack.pop() != '(':
                return False
    return not stack

def to_postfix(expr):
    if not validate_parentheses(expr):
        return "Unbalanced parentheses"

    temp_stack = []
    result = []

    for char in expr:
        if char.isspace():
            continue

        if char.isalnum():
            result.append(char)

        elif char == '(':
            temp_stack.append(char)

        elif char == ')':
            while temp_stack and temp_stack[-1] != '(':
                result.append(temp_stack.pop())
            temp_stack.pop()
            
        elif check_operator(char):
            while temp_stack and get_precedence(temp_stack[-1]) >= get_precedence(char):
                result.append(temp_stack.pop())
            temp_stack.append(char)

    while temp_stack:
        result.append(temp_stack.pop())

    return ''.join(result)

infix = input("Enter an expression: ").strip()
postfix_expr = to_postfix(infix)
print("Postfix:", postfix_expr)