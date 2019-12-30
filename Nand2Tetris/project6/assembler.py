comps = {
    "0": "0101010",
    "1": "0111111",
    "-1": "0111010",
    "D": "0001100",
    "A": "0110000",
    "!D": "0001101",
    "!A": "0110001",
    "-D": "0001111",
    "-A": "0110011",
    "D+1": "0011111",
    "A+1": "0110111",
    "D-1": "0001110",
    "A-1": "0110010",
    "D+A": "0000010",
    "D-A": "0010011",
    "A-D": "0000111",
    "D&A": "0000000",
    "D|A": "0010101",
    "M": "1110000",
    "!M": "1110001",
    "-M": "1110011",
    "M+1": "1110111",
    "M-1": "1110010",
    "D+M": "1000010",
    "D-M": "1010011",
    "M-D": "1000111",
    "D&M": "1000000",
    "D|M": "1010101"
}

dests = {
    "null": "000",
    "M": "001",
    "D": "010",
    "MD": "011",
    "A": "100",
    "AM": "101",
    "AD": "110",
    "AMD": "111"
}

jumps = {
    "null": "000",
    "JGT": "001",
    "JEQ": "010",
    "JGE": "011",
    "JLT": "100",
    "JNE": "101",
    "JLE": "110",
    "JMP": "111"
}


class SymbolTable:
    def __init__(self):
        self.address = 16
        self.label_dict = {"SP": 0,
                           "LCL": 1,
                           "ARG": 2,
                           "THIS": 3,
                           "THAT": 4,
                           "SCREEN": 16384,
                           "KBD": 24576}
        for i in range(16):
            label = "R" + str(i)
            self.label_dict[label] = i

    def add_label(self, label):
        self.label_dict[label] = self.address
        self.address += 1
        assert self.address < 16384


def parser(line):
    line = line.strip()
    if line == "":
        return "E", None
    line = line.replace(" ", "")
    if line[0] == "(":
        return "E", None
    codeline = line.split("//")[0]
    if codeline == "":
        return "E", None
    elif codeline[0] == "@":
        # A-instruction
        return "A", codeline[1:]
    else:
        # C-instruction
        if "=" in codeline:
            dest, comp = codeline.split("=")
            return "C", [comp, dest, "null"]
        else:
            # ";" in code
            comp, jump = codeline.split(";")
            return "C", [comp, "null", jump]


def code(symbol_table, line):
    inst_type, inst = parser(line)

    if inst_type == "A":
        try:
            n = int(inst)
        except:
            if inst not in symbol_table.label_dict:
                symbol_table.add_label(inst)
            n = symbol_table.label_dict[inst]
        value = '{:015b}'.format(n)
        binary = "0" + value
        assert len(binary) == 16
        return binary
    elif inst_type == "C":
        comp = comps[inst[0]]
        dest = dests[inst[1]]
        jump = jumps[inst[2]]
        binary = "111" + comp + dest + jump
        assert len(binary) == 16
        return binary
    else:
        return "empty"


def main(infile, outfile):
    symbol_table = SymbolTable()
    n = 0
    with open(infile) as f_in:
        for line in f_in:
            line = line.strip()
            if len(line) > 0 and line[0:2] != "//":
                if line[0] == "(":
                    symbol_table.label_dict[line[1:-1]] = n
                else:
                    n += 1
    with open(infile) as f_in:
        with open(outfile, 'w+') as f_out:
            for line in f_in:
                binary = code(symbol_table, line)
                if binary == "empty":
                    continue
                else:
                    f_out.write(binary + "\n")


if __name__ == '__main__':
    for name in ["Add", "Max", "Rect", "Pong"]:
        main(name + '.asm', name + '.hack')
