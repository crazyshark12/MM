raschet_table = table()

raschet_table.t = [0
1
2
3
4
5]*10^(-6)

writetable(raschet_table, "table_10_1.csv")

f = [0
2
10
20
50
100
200
400
600
800
1000]*10^3
Z = table(f)
writetable(Z, 'table_10_2.csv')

t = [0:0.1:1].'*10^(-6)

B = table(t)

writetable(B, 'table_10_3.csv')

