TEMPLATE_NAME = 'template.cpp'
BASE_NAME = 'kod.cpp'

LINES_TO_COMMENT = [
    '#include <sys/time.h>',
]

FUNCTIONS_TO_COMMENT = [
    # name of func   # replacing for
    ('current_ms', 'return 1;')
]

def find_closing_bracket(code, pos):
    open_brackets_cnt = 1
    while open_brackets_cnt > 0:
        open_brackets_cnt += int(code[pos] == '{')
        open_brackets_cnt -= int(code[pos] == '}')
        pos += 1
    return pos - 1


def replace_func(code, func_name, body):
    pos = code.find(func_name)
    pos = pos + code[pos:].find('{')
    beg, en = pos, find_closing_bracket(code, pos + 1)
    return code[:beg+1] + body + code[en:]


def replace_line(code, line):
    return '\n'.join([e for e in code.split('\n') if e != line])


if __name__ == '__main__':
    code = open(BASE_NAME).read()
    for arg in FUNCTIONS_TO_COMMENT:
        code = replace_func(code, *arg)
    for arg in LINES_TO_COMMENT:
        code = replace_line(code, arg)
    
    with open(TEMPLATE_NAME, 'w') as file_obj:
        file_obj.write(code)