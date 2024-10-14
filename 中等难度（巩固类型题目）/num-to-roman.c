//12.整数转罗马数字: 2024.9.24 朱嘉祺

char* intToRoman(int num) {
    //不同字母代表的数字, 可以计算每个数字在每个位上的表示形式，整理成一张硬编码表
    const char* thousands[] = {"", "M", "MM", "MMM"};
    const char* hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const char* tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const char* ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    //硬编码表完成后，将需要得到的数字的千位，百位，十位，个位提取出来
    int thousand = num / 1000;
    num %= 1000;
    int hundred = num / 100;
    num %= 100;
    int ten = num /10;
    num %= 10;
    int one = num % 10;
    char* roman = (char*)malloc(sizeof(char) * 16);
    roman[0] = '\0';
    strcpy(roman + strlen(roman) , thousands[thousand]);
    strcpy(roman + strlen(roman) , hundreds[hundred]);
    strcpy(roman + strlen(roman) , tens[ten]);
    strcpy(roman + strlen(roman) , ones[one]);
    return roman;
}