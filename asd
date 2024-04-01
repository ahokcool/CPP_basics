# For .zshrc

alias wd="cd /mnt/daten/GIT/"
alias norminette="/home/astein/path/to/venv/bin/norminette"

asd() {
    local cppDir="/mnt/daten/GIT/CPPs/"
    local targetDir

    if [ "$#" -eq 1 ]; then
        local x="$1"
        targetDir="../ex0${x}"
    elif [ "$#" -eq 2 ]; then
        local x="$1"
        local y="$2"
        targetDir="${cppDir}CPP0${x}/ex0${y}"
    else
        echo "Outside the CPP Folders:"
        echo "Usage: asd <x> <y>; x=CPP0<x>; y=ex0<y>"
        echo "or if you just want to switch the exercise:"
        echo "Usage: asd <x>; x=ex0<x>"
        return 1
    fi

    echo "Cleaning current folder..."
    make fclean || true # Ensures that failure of "make fclean" does not stop the script

    echo "Changing dir..."
    cd "${targetDir}" || return # If cd fails, return with an error
	pwd
}
