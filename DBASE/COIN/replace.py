#this workd very good for one file.
import string
with open("general_fall18_11deg_3p.param","r") as file:
    line = file.read()
line=line.replace("/GEN/gscalers", "/GEN/gscalers_fall18")
with open("general_fall18_11deg_4p2.param", "w") as file:
    file.write(line)
