echo > result.txt
for num_threads in 1 2 3 4 5 6 7 8 9 10 20 30 40 50 60 70 80 90 100 200 300 400 500 600 700 800 900 1000
do 
sed -i 's/\#define NUM_THREADS [0-9]*//' t2-lock-var.c
sed -i '1i#define NUM_THREADS '$num_threads t2-lock-var.c
gcc t2-lock-var.c -o t2-lock-var.out -Wall -pthread
echo NUM_THREADS:$num_threads >> result.txt
echo currently running $num_threads
for j in `seq 10`
do
(time ./t2-lock-var.out) >> result.txt 2>&1
done
echo "-------" >> result.txt
done