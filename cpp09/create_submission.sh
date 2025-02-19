#!/bin/bash

clear

source_folders=(
    "ex00"
    "ex01"
    "ex02"
)

for folder in "${source_folders[@]}"; do
    make -C $folder fclean
done

target_base_directory="submission"
rm -rf $target_base_directory

mkdir handin
mkdir -p "$target_base_directory"

for folder in "${source_folders[@]}"; do
    if [ -d "$folder" ]; then
        target_directory="$target_base_directory/$folder"
        mkdir -p "$target_directory"
        cp "$folder"/*.cpp "$folder"/*.hpp "$folder"/Makefile "$target_directory" 2>/dev/null
    else
        echo "Directory $folder does not exist."
    fi
done


cp "./ex00/data.csv" "$target_base_directory/ex00/"
cp "./ex00/input.txt" "$target_base_directory/ex00/"

cp "./ex01/test.sh" "$target_base_directory/ex01/"

cp "./ex02/test.sh" "$target_base_directory/ex02/"


