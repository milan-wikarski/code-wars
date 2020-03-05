if [ "$1" = "" ]; then
  echo "Kata name missing"
  exit 1
fi

if [ "$2" = "" ]; then
  echo "Source URL missing"
  exit 1
fi

mkdir $1
cat "./.templates/example.c" > "$1/$1.c"
echo -e "$2" > "$1/source.txt"