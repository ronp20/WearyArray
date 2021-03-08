# WearyArray
Assumptions:
Each line is an array.
The array line will only contain numbers in the format of the file.
If not, undefined behavior is expected.
The supported files are: JSON, CSV, TSV. They will be defined by the file suffix($FILE_NAME.json, $FILE_NAME.csv, $FILE_NAME.tsv)
The array length should be in the max size of (2^16 -1 = 65535).
If not, undefined behavior is expected.
Each array element should be in the range of 0 - (2^32 -1).
If not, undefined behavior is expected.

The executable file can receive from 1to N arguments. 
Each argument is a file path.

Below is an example of how to run an executable with files

cd Debug && make
./WearyArrayTraveler.out ../input_files/* 


