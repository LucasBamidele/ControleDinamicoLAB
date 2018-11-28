import csv
from itertools import izip
a = izip(*csv.reader(open("Triangular.csv", "rb")))
csv.writer(open("Triangular_Tr.csv", "wb")).writerows(a)