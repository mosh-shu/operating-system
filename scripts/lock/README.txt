Q1. Determine the number of cores on your CPU
by using `grep cpu.cores /proc/cpuinfo | sort -u `, 
`cpu cores	: 4`
(Reference: https://access.redhat.com/ja/solutions/2159401)

Q2. 

\nreal\t0m(\d+\.\d+)s\nuser\t0m(\d+\.\d+)s\nsys\t0m(\d+\.\d+)s
$1,$2,$3