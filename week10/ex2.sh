cd ..
mkdir -p Week01
touch Week01/file.txt
echo "Anna" >> Week01/file.txt
link Week01/file.txt week10/_ex2.txt
find . -inum $( ls -li Week01/file.txt | awk '{print $1}' ) >> week10/ex2.txt
find . -inum $( ls -li Week01/file.txt | awk '{print $1}' ) -exec rm {} \; >> week10/ex2.txt

cat week10/ex2.txt
