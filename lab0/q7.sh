mkdir source_1
mkdir source_1/data
cp {q1.txt,results.txt} source_1/data/
cp example.sh source_1
mkdir class_backup
tar -cvf class_backup/backup.tar source_1/*

