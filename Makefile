# Compilador e flags
CC = gcc
# Detectar sistema operacional
ifeq ($(OS),Windows_NT)
    # Windows
    CFLAGS = -Wall -Iheader -finput-charset=UTF-8 -fexec-charset=CP1252
else
    # Linux/Mac
    CFLAGS = -Wall -Iheader -finput-charset=UTF-8 -fexec-charset=UTF-8
endif

# Pastas
SRC = src
OBJ = obj
BIN = bin

# Fontes
SRCS = $(SRC)/pacote.c $(SRC)/lista_pacotes.c $(SRC)/drone.c $(SRC)/galpao.c $(SRC)/leitura_de_arquivo.c $(SRC)/inserir_dados.c $(src)/selectionSort.c $(src)/ShellSort.c main.c
OBJS = $(OBJ)/pacote.o $(OBJ)/lista_pacotes.o $(OBJ)/drone.o $(OBJ)/galpao.o $(OBJ)/leitura_de_arquivo.o $(OBJ)/inserir_dados.o $(OBJ)/main.o $(OBJ)/selectionSort.o $(OBJ)/ShellSort.o

# Executável final
TARGET = $(BIN)/entregas.exe

# Regra padrão
all: $(TARGET)

# Linkagem final
$(TARGET): $(OBJS) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Regras de compilação para os .c dentro de src/
$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra específica para o main.c (que está fora da pasta src)
$(OBJ)/main.o: main.c | $(OBJ)
	$(CC) $(CFLAGS) -c main.c -o $(OBJ)/main.o

# Criar pastas se não existirem
$(OBJ):
	mkdir -p $(OBJ)

$(BIN):
	mkdir -p $(BIN)

# Executar o .exe
run: $(TARGET)
	@$(TARGET)

# Limpeza
clean:
	rm -rf $(OBJ)/*.o $(BIN)/*.exe
