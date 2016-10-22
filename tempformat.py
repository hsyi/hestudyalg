#!/usr/bin/env python
f1 = "template"
f2 = "template_format"
fout = open(f2,"w")
myfin = open(f1,"r")
for line in myfin.readlines():
    i=0;
    nline=line.split('\r')
    for tline in nline:
        newline=""
        i=0
        while  (i<len(tline) and ( (tline[i]<='9' and tline[i]>='0') or tline[i]==' ') ):
            i=i+1
        newline = tline[i:]
        fout.write(newline+"\n")
fout.close()
myfin.close()
