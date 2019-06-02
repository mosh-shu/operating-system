echo > result.txt
for i in 1 10 100 1000 10000 100000 1000000 10000000
do
echo THRESHOLD:$i >> result.txt
echo currently running $i
for j in `seq 10`
do
echo trial:$j >> result.txt
(time ./t2-lock-var.out $i) >> result.txt 2>&1
echo >> result.txt
done
echo "-------" >> result.txt
done