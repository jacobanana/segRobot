"""
 * Adrien Fauconnet - 2018
 * Segment display experiments
 * ------
 * characters.h generator
 * ------
 * usage: python scripts/char.py > include/characters.h
"""

A = 1
B = 2
C = 4
D = 8
E = 16
F = 32
G = 64
DOT = 128

def pd(chr, val, prefix="CH"):
    print("#define {2}_{0} {1}".format(chr, val, prefix))

alphabet = {
    "0": 127-G,
    "1": B+C,
    "2": A+B+G+E+D,
    "3": A+B+C+D+G,
    "4": B+C+F+G,
    "5": A+F+G+C+D,
    "6": 127-B,
    "7": A+B+C,
    "8": 127,
    "9": 127-E,
    "A": 127-D,
    "B": 127-A-B,
    "C": 127-B-C-G,
    "D": B+C+D+E+G,
    "E": 127-B-C,
    "F": 127-B-C-D,
    "G": 127-E,
    "H": 127-A-D,
    "I": E+F,
    "J": B+C+D,
    "K": 127-A-D,
    "L": D+E+F,
    "M": A+C+E,
    "N": C+G+E,
    "O": 127-G,
    "P": 127-C-D,
    "Q": 127-D-E,
    "R": E+G,
    "S": A+F+G+C+D,
    "T": D+E+F+G,
    "U": 127-A-G,
    "V": C+D+E,
    "W": B+D+F,
    "X": 127-A-D,
    "Y": 127-A-E,
    "Z": 127-C-F,
    }

for k, v in alphabet.iteritems():
    pd(k, v)

segments = {
    "A": 1,
    "B": 2,
    "C": 4,
    "D": 8,
    "E": 16,
    "F": 32,
    "G": 64,
    "DOT": 128,
}

for k, v in segments.iteritems():
    pd(k, v, "SEG")
