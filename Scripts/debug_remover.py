import os
import sys
import re


if os.path.exists("./no_debug/") == False:
    os.mkdir("./no_debug/")

file = "./segue_linha/segue_linha.ino"
new_file = "./no_debug/no_debug.ino"

giro = False
pattern = "(?P<debug>.Serial|// ?[dD]ebug)"
if len(sys.argv) == 2 and sys.argv[1] == "-giro":
    pattern += "|(?P<giro>/* @Giroscopio)"
    giro = True

pattern = re.compile(pattern)

print(" Lines Removed ".center(70, "="))
with open(file) as segue_linha_debug:
    with open(new_file, "w") as segue_linha:
        toprint = False
        for line in segue_linha_debug:
            match = pattern.search(line)
            if match:
                print(" -", line, end="")
                if giro and match.group("giro"): toprint = True
            elif toprint:
                match = re.search("\*/", line)
                if match: toprint = False

                print(f" {'-' if match else '+'}", line, end="")
            if match == None: segue_linha.write(line)

print("""

A versão sem de_bebug de 'segue_linha.ino' está pronta.

Você pode compilar o arquivo 'no_debug' no arduino como a versão final sem debug.
Use essa versão durante o campeonato!!! ---> 'no_debug.ino'
""")
