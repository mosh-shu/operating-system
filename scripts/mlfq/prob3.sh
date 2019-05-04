./mlfq.py -l 0,100,0:0,100,0 -Q 10,10,10 -c > prob3-0.txt
./mlfq.py -l 0,200,0 -n 3 -c > prob3-1.txt
./mlfq.py -l 0,200,0:100,20,0 -n 3 -c > prob3-2.txt
./mlfq.py -l 0,200,0:50,38,1 -i 4 -n 3 -Sc > prob3-3.txt
./mlfq.py -l 0,200,0:100,100,5:100,100,5 -i 5 -Q 10,10,10 -Sc > prob3-4-1.txt
./mlfq.py -l 0,200,0:100,100,5:100,100,5 -i 5 -Q 10,10,10 -B 50 -Sc > prob3-4-2.txt
./mlfq.py -l 0,140,0:0,140,0 -Q 10,20,40 -A 2,2,2 -c > prob3-5.txt