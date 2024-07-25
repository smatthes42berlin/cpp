#!/bin/bash

clear

make -C ./ex00 fclean
make -C ./ex01 fclean

#!/bin/bash

# Define an array of source folders
source_folders=("ex00" "ex01")

# Define the target base directory
target_base_directory="submission"
rm -rf $target_base_directory


# Create the target base directory if it does not exist
mkdir -p "$target_base_directory"

# Loop through each source folder
for folder in "${source_folders[@]}"; do
    if [ -d "$folder" ]; then
        # Create the corresponding subdirectory in the target base directory
        target_directory="$target_base_directory/$folder"
        mkdir -p "$target_directory"

        # Copy .cpp, .hpp, and Makefile to the corresponding subdirectory
        cp "$folder"/*.cpp "$folder"/*.hpp "$folder"/Makefile "$target_directory" 2>/dev/null
    else
        echo "Directory $folder does not exist."
    fi
done
