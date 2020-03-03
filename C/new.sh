if [ "$1" = "" ]; then
  echo "No arguments provided"
  exit 1
else
  mkdir $1
  cat "./.templates/example.c" > "$1/$1.c"
fi
