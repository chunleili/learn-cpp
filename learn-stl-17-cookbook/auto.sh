if [ "$#" -ne 2 ]; then
    echo "Please give 2 args, the fisrt is chapter, 2nd is section."
	exit 1
else 
	echo "making ch$1/$2" 
	mkdir ch$1/$2 &&\
	cp boilerplate/* ch$1/$2/  &&\
	cd ch$1/$2  &&\
	printf "add_executable(ch%s-%s main.cpp)" $1 $2 > CMakeLists.txt  &&\
	cd ../..  &&\
	printf '\nadd_subdirectory(ch%s/%s)' $1 $2 >> CMakeLists.txt 
fi
