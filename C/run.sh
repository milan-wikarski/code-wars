if [ "$1" = "" ]; then
  echo "No arguments provided"
  exit 1
else
  gcc "$1/$1.c" -o "$1/$1.out";
  "./$1/$1.out";
fi