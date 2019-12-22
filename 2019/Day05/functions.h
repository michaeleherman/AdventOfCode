void printStuff(const char source[14], int pos, int instruction, int val1, int val2, int val3);

void opcode1(int pos1, int pos1Mode, int pos2, int pos2Mode, int pos3, int *intCodes);

void opcode2(int pos1, int pos1Mode, int pos2, char pos2Mode, int pos3, int *intCodes);

void opcode3(int pos, int *intCodes);

void opcode4(int outputPos, int *intCodes);

int opcode5(int pos, int *intCodes);

int opcode6(int pos, int *intCodes);

void opcode7(int pos, int *intCodes);

void opcode8(int pos, int *intCodes);

void parameterMode(int pos, int *intCodes);

int switcher(int pos, int *intCodes);