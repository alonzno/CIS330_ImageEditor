#!/bin/ksh

INPUT=~hank/public_html/330/projects/2B/2B_binary_file
CORRECT_OUTPUT=~hank/public_html/330/projects/2B/ASCII_output

if [[ $# != 1 ]] ; then
   echo "Usage: $0 <c file>"
   exit 1
fi

gcc -o proj2B $1
if [[ $? != 0 ]] ; then
   echo "Compile failure!"
   exit 1
fi

rm -f ./ASCII_output
./proj2B $INPUT ASCII_output

if [[ ! -f ASCII_output ]] ; then
   echo "You did not generate the correct file output name."
   exit 1
fi

diff $CORRECT_OUTPUT ASCII_output
if [[ $? != 0 ]] ; then
   echo "Your output is not correct."
   exit 1
fi

echo "Your program appears to be working correctly."
echo "It compiles, runs, and generates the correct output."
echo "Please upload this c file to Canvas, as part of the tar file instructions in the 2B prompt."
echo "Grading will consist of the steps performed by this script, complemented by inspection of your code."

