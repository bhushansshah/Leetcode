int divisorSubstrings(int num, int k){
    int len = 0;
    int lower = 0, upper;
    int divisor = 0;
    int count = 0;
    int dup = num;
    while(dup){
        len++;
        dup = dup / 10;
       
    }
    upper = len - 1;
    if(k == len){
        return 1;
    }
    char *p = malloc((len + 1) * sizeof(char));
    p[len] = '\0';
    dup = num;
    while(dup){
        p[upper--] = '0' + dup % 10;
        dup = dup / 10;
    }
    upper = k - 1;
    while(upper < len){
        divisor = 0;
        for(int i = lower; i <= upper; i++){
            divisor = 10 * divisor + p[i] - '0';
        }
        if( divisor && !(num % divisor)){
            count++;
        }
        upper++;
        lower++;
    }
    free(p);
    p = NULL;
    return count;
}
