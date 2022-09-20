set xrange [0:12]
set yrange [-15:1]
set format y '%.0s'
plot 'data/2_6_2_2_double.dat' using 3:5 with yerrorbars linestyle 1
