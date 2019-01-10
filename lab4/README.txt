README for general

    I used 
    base64 /dev/urandom | head -c N > output_name.txt
    to generate large files in the current directory with name output_name.txt.

    For example, when I ran tests with 128M file sizes, I ran
    base64 /dev/urandom | head -c 128M > 128mBytes.txt
    to generate a text file.

    Since reading and writing those files did not take a long time with my choice
    of buffer size, I just executed each test with
    ./executeablename.out fileName.txt
    with executablename.out replaced by the actual executable name and fileName.txt
    replaced by the actual file name with the size I want.

    I ran tests on 128M, 256M, and 512M files for the following operations:
    Sequential Read, Random Read, Sequential Write, Random Write. I used a buffer
    that took in 128 bytes at at time in those programs to run those tests at a
    reasonable speed. It is important that the programs used to test writing speeds
    performs both reading the input file and writing to a different file, so the
    pure writing time is calculated by substracting the reading time in tests
    from the writing time when the tests are both sequential or both random.

README for seqReadTest.c

    I wrote this file to test the time it takes to read files sequentially. The program
    takes in a file path at execution as parameter, then reads that file sequentially
    with a buffer of 128 bytes.

    To do this, I used a file pointer that reads the file 128 bytes at a time. Using
    a while loop, I make sure the program only continues reading when data was read
    the previous time, and stops reading when it reaches end of file.

README for randReadTest.c

    I wrote this file to test the time it takes to read files from random locations in
    the file. Similar to seqReadTest.c, it takes in a file path at execution as a
    parameter. The file is still read 128 bytes at a time, but the starting place for
    each read is different.

    To do this, I first used several system functions to determine the file size of the
    file that was taken in as input during execution. When the program reads the file,
    it generate a random number smaller than the file size to read from. From that random
    location, 128 consecutive bytes is read. This is repeated until the number of
    bytes read is the same as the file size.

README for seqWriteTest.c

    I wrote this file to test the time it takes to read files sequentially. The program
    takes in a file path at execution as parameter. As the program reads that file with
    a 128 bytes buffer, the buffer is used to write the buffer to a new file.

    The way this is done is similar to sequential read. The additions made to that program
    is to include a second file pointer to write files from the buffer and to write the 
    buffer to a new file each time a buffer is read from the input file. This is done until
    the input file is read, at which point the output file is a copy of the input file if
    ran successfully.

README for randWriteTest.c

    I wrote this file to test the time it takes to write files from random locations in
    the input file. Similar to seqWriteTest.c, it takes in a file path at execution as a
    parameter. The file is still written at 128 bytes at a time, but the starting place for
    each write is different. 

    The way this is done is similar to random read. The additions made to that program
    is to include a second file pointer to write files from the buffer and to write the 
    buffer to a new file each time a buffer is read from the input file. This is done until
    the input file has read enough buffers for the output file to be the same size as the
    input file.

README for run.sh

    This shell program is used to run the 4 programs with different file sizes. It will output
    time taken for the operations as raw data to testResults.txt.

Output
    
    I took 5 trials for each read/write, random/sequential with 1G, 2G, and 4G files.
    The raw data can be found in testResults.txt. Below is the the average of the outputs:

    Sequential Read

    128M: 0.05s
    256M: 0.07s
    512M: 0.17s

    Random Read

    128M: 1.74s
    256M: 3.40s
    512M: 6.93s

    Sequential Write

    128M: 0.15s
    256M: 0.27s
    512M: 0.47s

    Random Write

    128M: 1.90s
    256M: 3.74s
    512M: 7.49s

    Those data is plotted in File_IO_Times.png to visualize relative time those operations
    take.

Analysis

    For each of the operations, doubling the file size caused the time for the operation to
    finish to nearly double. This is for whichever File operation is used, the time it takes
    for the operation to finish is proportional to the size of the input file.

    Sequential Read ran 30 to 50 times faster than Random Read for each of the file size.
    This makes sense because sequential read takes advantage of cache much more than
    random read. For a similar reason of less cache misses Sequential Write ran
    10 to 20 times faster than Random Write. Those results mean that in a filesystem,
    we should try to keep the data we are read and write from near each other.

    When comparing sequential read to sequential write, writing took 3 to 4 times longer than
    reading. Since the writing operation tests here involve reading the information first, the
    writing operation by itself only takes 2 to 3 times longer. But this is still significant
    enough in the real world where we should separate data that is mostly read-only and the
    data that are used for both reading and writing.

    Although those operations would not be practical in the real world, the tests for Random
    Write only took 1.05 to 1.2 times as long as Random Read. Taking accoung that those tests
    have to read a file to write something, it suggests that the time it takes to write is
    negligle compared the time it takes to use random access instead of sequential access.
    In the real world, if a system chooses to read and files randomly, there would not be
    a performance gained from separating data that is mostly read-only and data used for
    both reading and writing.
