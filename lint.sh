files=$(find tests/ include/ -name "*.cpp" -o -name "*.hpp");
format_file=$(find . -name .clang-format);

if [ -z $format_file+x} ];
  then
    echo "Cannot find .clang-format file";
    exit 1;
fi

for file in $files
do
  clang-format -style=file:${format_file} ${file} -i
done
