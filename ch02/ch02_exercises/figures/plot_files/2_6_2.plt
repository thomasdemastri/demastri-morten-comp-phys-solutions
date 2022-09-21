set datafile separator comma

set title '{\log_{10}(Relative error between s_{up} and s_{down}) vs. log_{10}(N) at single and double precision}'

set style line 1 \
    linecolor rgb '#0060ad' \
    linetype 1 linewidth 1 \
    pointtype 7 pointsize 1.5

set style line 2 \
    linecolor rgb '#dd181f' \
    linetype 1 linewidth 1 \
    pointtype 7 pointsize 1.5

set grid ytics xtics

set xrange [0:12]
set yrange [-17:1]

set size 1


set ylabel 'log10(|s_up-s_down|/s_down)'
set xlabel 'log10(N)'

set key left top



set format y '%.0s'

set output 'figures/2_6_2_loglogplot.png'

f_1(x) = m_1 * x + b_1
fit [2:10] f_1(x) 'data/2_6_2_2_double.dat' using 4:5 via m_1,b_1
f_2(x) = m_2 * x + b_2
fit [2:8] f_2(x) 'data/2_6_2_2_single.dat' using 4:5 via m_2,b_2



plot 'data/2_6_2_2_double.dat' using 4:5 with linespoints linestyle 1 title 'double',\
     'data/2_6_2_2_single.dat' using 4:5 with linespoints linestyle 2 title 'single',\
     [1.5:10.5] f_1(x) title sprintf("y=%.3fx+%.1f",m_1,b_1),\
     [1.5:8.5] f_2(x) title sprintf("y=%.3fx+%.1f",m_2,b_2)
