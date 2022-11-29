EXEC=main.exe
SRC=vector.cpp matrix.cpp main.cpp
OBJs=$(SRC:.cpp=.o)
OBJ_DIR=./obj
OBJ=$(patsubst %.o,${OBJ_DIR}/%.o,${OBJs})
FLAGS=-c
OPT=-O3
comp=g++
.SUFFIXES:.o .cpp

all: ${EXEC}
	@echo "ok"

clean:
	@rm ${OBJ}

${EXEC}: ${OBJ}
	${comp} -o ${EXEC} ${OBJ}

${OBJ_DIR}/%.o: %.cpp
	${comp} ${FLAGS} ${OPT} $< -o $@

