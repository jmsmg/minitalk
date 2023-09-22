CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk
CLIENT = client
SERVER = server
SERVER_OBJ = $(SERVER_SRCS:.c=.o)
CLIENT_OBJ = $(CLIENT_SRCS:.c=.o)
LIBFT_PATH = libft

SERVER_SRCS = server_src/server.c
CLIENT_SRCS = client_src/client.c

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT_PATH) -o $@ -c $<

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT_PATH)/libft.a -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT_PATH)/libft.a -o $(CLIENT)

all :
	make $(NAME)

clean :
	make clean -C libft
	rm -f $(CLIENT_OBJ)
	rm -f $(SERVER_OBJ)

fclean : clean
	make fclean -C libft
	rm -f $(CLIENT)
	rm -f $(SERVER)

re : fclean all

.PHONY : all clean fclean re
