void printStuff(const char source[14], int pos, int instruction, int val1, int val2, int val3);

int opcode1(int pos1, int pos1Mode, int pos2, int pos2Mode, int pos3, int *intCodes);

int opcode2(int pos1, int pos1Mode, int pos2, char pos2Mode, int pos3, int *intCodes);

int opcode3(int pos, int *intCodes);

int opcode4(int pos, int outputPos, int *intCodes);

int opcode5(int pos, int *intCodes);

int opcode6(int pos, int *intCodes);

int opcode7(int pos, int *intCodes);

int opcode8(int pos, int *intCodes);

int parameterMode(int pos, int *intCodes);

int switcher(int pos, int *intCodes);