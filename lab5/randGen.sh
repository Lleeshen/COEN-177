rm unfiltered8192Rand.txt

for i in {1..8192}
do
    od -An -N2 -i /dev/urandom >> unfiltered8192Rand1.txt
    od -An -N2 -i /dev/urandom >> unfiltered8192Rand2.txt
    od -An -N2 -i /dev/urandom >> unfiltered8192Rand3.txt
done
