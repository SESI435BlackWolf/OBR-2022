import os

if os.path.exists("./no_debug/") == False:
    os.mkdir("./no_debug/")

file = "./segue_linha/segue_linha.ino"
new_file = "./no_debug/no_debug.ino"

with open(file) as segue_linha_debug:
    with open(new_file, "w") as segue_linha:
        for line in segue_linha_debug:
            if "Serial." in line or "// debug" in line:
                continue
            else:
                segue_linha.write(line)

print("""
A versão sem de_bebug de 'segue_linha.ino' está pronta.

Você pode compilar o arquivo 'no_debug' no arduino como a versão final sem debug.
Use essa versão durante o campeonato!!! ---> 'no_debug.ino'
""")