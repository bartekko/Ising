###
SIZE=40
TEMPERATURE=$1
STEPS=20000
RNGSEED=$2
INTERVAL=100
###

./sim $SIZE $TEMPERATURE $STEPS $RNGSEED $INTERVAL> results/$TEMPERATURE.txt


python3 stval.py results/$TEMPERATURE.txt | cat <(echo -n "$TEMPERATURE ") - > intermresults/$TEMPERATURE.txt
