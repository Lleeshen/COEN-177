Lyman Shen
10/30/18
Assignment 3

FIFO

In the FIFO algorithm, I use a queue to represent
 the page table. When a new page number is
 requested, I search in the queue for the page
 number, and there is a page fault if it is not
 there. When the number of pages is less than the
size of the page table, I enqueue  the new page
 number if there is a page fault. Afterwards, I
dequeue the last inserted page number and enqueue
the new page number if there is a page fault. I
 used a circular array to implement the queue
 and made optimizations, which are in the comments
of fifo.c file. Essentially I just increment the
index and then perform modulo with page Size to
do so.

LRU

In the LRU algorithm, I used two arrays to represent
the page table, one to store the page number and the
other to store the recency of the page table. When
there is a new page number, I search for the page in
the page table array, and there is a page fault if 
the page is not found. Unlike FIFO, where nothing is
done when the page is found, I update the recency
of the page to the current number of entries here.
This will help me determine what is the least
recently used page when there is a page fault.
When there is a page fault, I search for the page
number that has the lowest number in the recency
table. That page will be replaced, so I update
the page number to the new page number and set
the recency table to the current number of entries.
Since I will be searching for the new index each time
there is a new page fault, I do not need to increment
the index here.

Second Chance

In the second chance algorithm, I used two arrays to
represent the page table, one to store the page number
and the other to store the reference bit. When there
is a new page number, I search for the page with the
page number. If the page number is found, there is no
page fault and I set the reference bit to 1. If there
is a page fault, I start searching from the current
index to the first index that has reference bit 0. If
an index is found to have reference bit 1, I set the
bit to 0 and continue searching. When I find the page
number with reference bit 0, I set the page to have
the new page number and reference bit 0. I then
increment the index to make sure the page that was
just inserted will be the last page I search the next
time there is a page fault.


To test the correcetness of these algorithms, I ran
each algorithm against sample input and compared the
output to the expected output. I also found how these
algorithms would behave with different cache sizes to
make sure they have similar behavior to an actual page
table. You can see the results in the file
Page_Replacement_Comparison.xlsx
