int longestValidParentheses(char * s){
    int max = 0;
    int len = 0;
    int top = -1;
    int size = strlen(s);
    int *stack = malloc(sizeof(int) * size);
    int i = 0;
    int compare = size, ele, flag = 0, eos = -1;
    while(s[i] != '\0'){
        if(s[i] == '(')
            stack[++top] = i;
        else if(top != eos){
            len += 2;
            top--;
        }
        else{
            if(len > max){
                max = len;
            }
            len = 0;
            stack[++top] = i;
            eos++;
        }
        i++;
    }
    if(top == -1)
        return len;
    else if(eos == top){
        if(len > max)
            max = len;
    }
    else{
        max = 0;
        while(top != -1){
            ele = stack[top--];
            if(compare - ele - 1 > max){
                max = compare - ele - 1;
            }
            compare = ele;
        }
        if(compare > max){
            max = compare;
        }
    }
    return max;
