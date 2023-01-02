int calPoints(char ** operations, int operationsSize){
    int record[1000];
    int top = -1;
    char *opeItem;
    int score;
    int sum = 0;
    int flag = 0;
    for(int i = 0; i < operationsSize; i++){
        opeItem = operations[i];
        flag = 0;
        if((*opeItem >= '0' && *opeItem <= '9') || *opeItem == '-'){
            if(*opeItem == '-'){
                flag = 1;
                opeItem++;
            }
            score = 0;
            while(*opeItem != '\0'){
                score = 10 * score + *opeItem - '0';
                opeItem++;
            }
            if(flag){
                score *= -1;
            }
            record[++top] = score;
        }
        else{
            switch(*opeItem){
                case '+' : record[top + 1] = record[top] + record[top - 1];
                            top++;
                            break;
                case 'C' : top--;
                            break;
                case 'D' : record[top + 1] = 2 * record[top];
                            top++;
                            break;
            }
        }
    }
    for(int i = 0; i <= top; i++){
        sum += record[i];
    }
    return sum;
}
