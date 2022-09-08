gcc ../mains/real_env_main.c ../../*.c ../../../commands/*.c && ./a.out > or_out
gcc ../mains/test_env_main.c && ./a.out > my_out
VARIABLE=$(diff or_out my_out)
if [ -z "$VARIABLE" ]; then
    echo GOOD - REAL ENV VARIABLES ARE CORRECTLY DISPLAYED
else
    echo "BAD - $VARIABLE"
fi
#if [[$VARIABLE == 0]]; then
#printf "GOOD"
rm or_out my_out
rm -rf a.out