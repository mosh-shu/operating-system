gcc t2-lock-var.c -o t2-lock-var.out -Wall -pthread
threshold=1000
echo THRESHOLD:$threshold >> result.txt
echo currently running $threshold
for j in `seq 10`
do
(time ./t2-lock-var.out) >> result.txt 2>&1
done
echo "-------" >> result.txt