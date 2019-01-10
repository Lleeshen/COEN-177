gcc -o seqReadTest.out seqReadTest.c
gcc -o randReadTest.out randReadTest.c
gcc -o seqWriteTest.out seqWriteTest.c
gcc -o randWriteTest.out randWriteTest.c

cat /dev/null > testResults.txt

echo "Sequential Read" >> testResults.txt

echo "128M" >> testResults.txt

for i in {1..5}
do
    ./seqReadTest.out 128mBytes.txt >> testResults.txt
done

echo "256M" >> testResults.txt

for i in {1..5}
do
    ./seqReadTest.out 256mBytes.txt >> testResults.txt
done

echo "512M" >> testResults.txt

for i in {1..5}
do
    ./seqReadTest.out 512mBytes.txt >> testResults.txt
done

echo "Random Read" >> testResults.txt

echo "128M" >> testResults.txt

for i in {1..5}
do
    ./randReadTest.out 128mBytes.txt >> testResults.txt
done

echo "256M" >> testResults.txt

for i in {1..5}
do
    ./randReadTest.out 256mBytes.txt >> testResults.txt
done

echo "512M" >> testResults.txt

for i in {1..5}
do
    ./randReadTest.out 512mBytes.txt >> testResults.txt
done

echo "Sequential Write" >> testResults.txt

echo "128M" >> testResults.txt

for i in {1..5}
do
    ./seqWriteTest.out 128mBytes.txt >> testResults.txt
done

echo "256M" >> testResults.txt

for i in {1..5}
do
    ./seqWriteTest.out 256mBytes.txt >> testResults.txt
done

echo "512M" >> testResults.txt

for i in {1..5}
do
    ./seqWriteTest.out 512mBytes.txt >> testResults.txt
done

echo "Random Write" >> testResults.txt

echo "128M" >> testResults.txt

for i in {1..5}
do
    ./randWriteTest.out 128mBytes.txt >> testResults.txt
done

echo "256M" >> testResults.txt

for i in {1..5}
do
    ./randWriteTest.out 256mBytes.txt >> testResults.txt
done

echo "512M" >> testResults.txt

for i in {1..5}
do
    ./randWriteTest.out 512mBytes.txt >> testResults.txt
done

rm *.out
rm out.txt
