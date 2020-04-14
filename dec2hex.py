import re

AddrPattern = re.compile(r"\((\d+)\,")
DataPattern = re.compile(r"\ (\d+)\)")

def AddrDecToHex(match):
    return str("(" + hex(int(match.group(1))).upper().replace('X', 'x') + ",")

def DataDecToHex(match):
    return str(" " + hex(int(match.group(1))).upper().replace('X', 'x') + ")")

with open('A:\Test.c', 'r') as fin:
    content = fin.read()
    
content_new = (AddrPattern.sub(AddrDecToHex, content))
content_new = (DataPattern.sub(DataDecToHex, content_new))      
#print(content_new)

with open("A:\TestOut.c", "wt") as fout:
    fout.write(content_new)

