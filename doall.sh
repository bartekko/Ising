python3 init.py >temps.txt
rm avg.dat
rm intermresults/*
rmdir intermresults
mkdir intermresults

cat temps.txt | parallel --colsep ' ' --verbose ./run.sh 

cat intermresults/*>plot.dat
