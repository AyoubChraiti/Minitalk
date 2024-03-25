NAME1 = server

NAME2 = client

SRC1 = server.c

OBJ1 = $(SRC1:.c=.o)

SRC2 = client.c

OBJ2 = $(SRC2:.c=.o)

CC = cc

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	$(CC) $(OBJ1) -o $(NAME1)

$(NAME2): $(OBJ2)
	$(CC) $(OBJ2) -o $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ1)
	rm -rf $(OBJ2)

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)

push:
	git add .
	git commit -m "update"
	git push

re: fclean all

.PHONY: clean re all fclean

.SECONDARY: $(OBJ1) $(OBJ2)
