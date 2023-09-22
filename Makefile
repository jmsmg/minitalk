CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT = cl
SERVER = s
SERVER_OBJ = $(SERVER_SRCS:.c=.o)
CLIENT_OBJ = $(CLIENT_SRCS:.c=.o)
LIBFT_PATH = libft

SERVER_SRCS = server/server.c
CLIENT_SRCS = client/client.c

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT_PATH) -o $@ -c $<

$(SERVER): $(SERVER_OBJ)
	cd libft && make
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT_PATH)/libft.a -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	cd libft && make
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT_PATH)/libft.a -o $(CLIENT)

all :
	make $(CLIENT)
	make $(SERVER)

clean :
	cd libft && make clean
	rm -f $(CLIENT_OBJ)
	rm -f $(SERVER_OBJ)

fclean : clean
	cd libft && make fclean
	rm -f $(CLIENT)
	rm -f $(SERVER)

re : fclean all

.PHONY : all clean fclean re
