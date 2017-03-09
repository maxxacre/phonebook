reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.150]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.1):($2+0.0011):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'struct' , \
'' using 4:xtic(1) with histogram title 'hash' , \
'' using ($0+0.3):($3+0.0015):3 with labels title ' ', \
'' using ($0+0.5):($4+0.0015):4 with labels title ' '
