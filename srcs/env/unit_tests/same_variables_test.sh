gcc ../*.c && ./a.out > or_out
gcc ./init_env_test.c && ./a.out > my_out
VARIABLE=$(diff or_out my_out)
if [ -z "$VARIABLE" ]; then
    echo GOOD - REAL ENV VARIABLES ARE CORRECTLY DISPLAYED
else
    echo "BAD - $VARIABLE"
fi
#if [[$VARIABLE == 0]]; then
#printf "GOOD"
rm or_out my_out
