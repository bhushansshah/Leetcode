bool canConstruct(char * ransomNote, char * magazine){
    int p[30] = {0,};
    while(*magazine != '\0'){
        p[*magazine - 'a']++;
        magazine++;
    }
    while(*ransomNote != '\0'){
        if(p[*ransomNote - 'a'] == 0){
            return false;
        }
        p[*ransomNote - 'a']--;
        ransomNote++;
    }
    return true;    
}
