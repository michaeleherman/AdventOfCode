#  PseudoCode

1. parse opcode string into array
2. create array of amplifier combinations
    For each set of amplifier combinations 
        for each amplifier (pass current amp combo and codes)
            opcode value, pass to opcode computer
                if opcode = 3, pass input value (first amplifier, second thrust)
                if opcode = 4, expect thrust return
        add thrust value to thrust value for set
    insert thrust into array of thrusts
find greatest signal in array of thrusts



